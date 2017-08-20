#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "clang-c/Index.h"

std::fstream cStdlib;
std::unordered_map<std::string, std::string> cToPlange;

void initMap() {
	cToPlange["void"] = "Void";
	cToPlange["int"] = "Int32";
	cToPlange["long"] = "Int32";
	cToPlange["char"] = "Char";
	cToPlange["__ssize_t"] = "Int";
	cToPlange["__off_t"] = "Int";
	cToPlange["float"] = "Float32";
	cToPlange["double"] = "Float64";
	cToPlange["long double"] = "Float128";
	cToPlange["clock_t"] = "Int64";
	cToPlange["time_t"] = "Int64";
	cToPlange["clockid_t"] = "Int";
	cToPlange["timer_t"] = "Int";
	cToPlange["pid_t"] = "Int";
	cToPlange["__locale_t"] = "Pointer<Void>";
}

bool startsWith(std::string const& input, std::string const& match) {
	return match.size() <= input.size() && 
	       std::equal(match.begin(), match.end(), input.begin());
}

bool endsWith(std::string const& input, std::string const& match) {
	return match.size() <= input.size() && 
	       std::equal(match.rbegin(), match.rend(), input.rbegin());
}

void addOpaquePointer(std::string const& s) {
	int typeStartChar = 0;
	size_t starPos = s.find('*');
	if (starPos == std::string::npos) {
		return;
	}
	bool constPointer = false;
	if (startsWith(s, "const struct ")) {
		typeStartChar = 13;
		constPointer = true;
	}
	else if (startsWith(s, "const ")) {
		typeStartChar = 6;
		constPointer = true;
	}
	else if (startsWith(s, "struct ")) {
		typeStartChar = 7;
	}
  bool pointerConst = true;
  std::string sKey = s.substr(typeStartChar);
	if (!endsWith(s, "const")) {
		sKey = s.substr(typeStartChar, starPos - typeStartChar + 1);
		pointerConst = false;
	}
	if (constPointer) {
		sKey = "const " + sKey;
	}
	if (cToPlange.find(sKey) != cToPlange.end()) {
		return;
	}
	std::string sInMap = s.substr(typeStartChar, starPos - typeStartChar - 1);
	if (cToPlange.find(sInMap) != cToPlange.end()) {
		return;
	}	
	if (!constPointer) {
		cToPlange[sKey] = sInMap + "Pointer";
	}
	else {
		cToPlange[sKey] = "Const" + sInMap + "Pointer";
	}
	cStdlib << cToPlange[sKey] << " := ";
	cStdlib << "type_abstraction(";
	if (pointerConst) {
		cStdlib << "Const<";
	}
	cStdlib << "Pointer<";
	if (constPointer) {
		cStdlib << "Const<";
	}
	cStdlib << "Void";
	if (constPointer) {
		cStdlib << ">";
	}
	if (pointerConst) {
		cStdlib << ">";
	}
	cStdlib << ">)" << std::endl;
}

void toCStdlib(std::string const& s) {
	int typeStartChar = 0;
	size_t starPos = s.find('*');
	if (starPos == std::string::npos) {
		bool isConst = false;
		if (startsWith(s, "const struct ")) {
			cStdlib << "Const<";
			typeStartChar = 13;
			isConst = true;
		}
		else if (startsWith(s, "const ")) {
			cStdlib << "Const<";
			typeStartChar = 6;
			isConst = true;
		}
		else if (startsWith(s, "struct ")) {
			typeStartChar = 7;
		}
    std::string sp = s.substr(typeStartChar);
		if (cToPlange.find(sp) != 
				cToPlange.end()) {
			cStdlib << cToPlange[sp];
		}
		else {
			cStdlib << "TBD";
		}
		if (isConst) {
			cStdlib << ">";
		}
	}
	else {
		bool pointerConst = false;
		bool constPointer = false;
		if (startsWith(s, "const struct ")) {
			typeStartChar = 13;
			constPointer = true;
		}
		else if (startsWith(s, "const ")) {
			typeStartChar = 6;
			constPointer = true;
		}
		else if (startsWith(s, "struct ")) {
			typeStartChar = 7;
		}
		if (endsWith(s, "const")) {
			pointerConst = true;
		}
		std::string snp = s.substr(typeStartChar,
															 starPos - typeStartChar - 1);
		if (cToPlange.find(snp) != 
				cToPlange.end()) {
			if (pointerConst) {
				cStdlib << "Const<";
			}
			cStdlib << "Pointer<";
			if (constPointer) {
				cStdlib << "Const<";
			}
			cStdlib << cToPlange[snp];
			if (constPointer) {
				cStdlib << ">";
			}
			if (pointerConst) {
				cStdlib << ">";
			}
			cStdlib << ">";
		}
		else {
			if (pointerConst) {
				std::string sKey = s.substr(typeStartChar);
				if (constPointer) {
					sKey = "const " + sKey;
				}
				cStdlib << cToPlange[sKey];
			}
			else {
				std::string sKey = s.substr(typeStartChar,
				                            starPos - typeStartChar + 1);
				if (constPointer) {
					sKey = "const " + sKey;
				}
				cStdlib << cToPlange[sKey];
			}
		}
	}
}

CXChildVisitResult printVisitor(CXCursor cursor, 
                                CXCursor parent, 
																CXClientData clientData) {
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0) {
		return CXChildVisit_Continue;
	}
	CXType cursorType = clang_getCursorType(cursor);
	CXCursorKind kind = clang_getCursorKind(cursor);
	if (kind == CXCursor_FunctionDecl) {
		int numArgs = clang_Cursor_getNumArguments(cursor);
		std::vector<std::string> argTypeStrVec(numArgs + 1);
		for (int i = 0; i < numArgs; ++i) {
			CXType cursorArgType = clang_getArgType(cursorType, i);
			CXString argType = clang_getTypeSpelling(cursorArgType);
			std::string argTypeStr = clang_getCString(argType);
			addOpaquePointer(argTypeStr);
			argTypeStrVec[i] = argTypeStr;
		}
		CXType cursorRetType = clang_getResultType(cursorType);
		CXString retType = clang_getTypeSpelling(cursorRetType);
		std::string retStr = clang_getCString(retType);
		addOpaquePointer(retStr);
		argTypeStrVec[numArgs] = retStr;
		cStdlib << "extern <";
		for (int i = 0; i < numArgs; ++i) {
			toCStdlib(argTypeStrVec[i]);
			cStdlib << " ";
			if (i != numArgs - 1) {
				cStdlib << "* ";
			}
		}
		CXString typeSpelling = clang_getTypeSpelling(cursorType);
		std::string typeStr = clang_getCString(typeSpelling);
		if (typeStr.size() > 4 && 
				typeStr.substr(typeStr.size() - 4, 3) == "...") {
			if (numArgs) {
				cStdlib << "* UInt * Pointer<Void>^ ";
			}
			else {
				cStdlib << "UInt * Pointer<Void>^ ";
			}
		}
		else if (!numArgs) {
			cStdlib << "Void ";
		}
		cStdlib << "-> "; 
		toCStdlib(argTypeStrVec[numArgs]);
		cStdlib << "> ";
		CXString name = clang_getCursorSpelling(cursor);
		std::string nameStr = clang_getCString(name);
		cStdlib << nameStr << ";" << std::endl;
		std::cout << nameStr << ": ";
		for (int i = 0; i <= numArgs; ++i) {
			std::cout << argTypeStrVec[i] << " ";
		}
		std::cout << std::endl;
	}
	return CXChildVisit_Recurse;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}
	initMap();
	CXIndex index = clang_createIndex(0, 0);
	CXTranslationUnit unit = clang_parseTranslationUnit(index,
	                                                    argv[1],
																											nullptr,
																											0,
																											nullptr,
																											0,
																											CXTranslationUnit_None);
	if (unit != nullptr) {
	  CXCursor rootCursor = clang_getTranslationUnitCursor(unit);
		std::string outFileName = argv[1];
		size_t start = outFileName.find_last_of('/');
		if (start == std::string::npos) {
			start = -1;
		}
		size_t pos = outFileName.find('.');
		if (pos != std::string::npos) {
			outFileName = outFileName.substr(start + 1, pos - start - 1) + "lib.txt";
		}
		else {
			outFileName += "lib.txt";
		}
    cStdlib.open(outFileName.c_str(), std::fstream::out);	
		clang_visitChildren(rootCursor, printVisitor, NULL);
		cStdlib.close();
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);
	return 0;
}
