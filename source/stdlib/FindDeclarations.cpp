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
	cToPlange["short"] = "CShort";
	cToPlange["int"] = "CInt";
	cToPlange["long"] = "CLong";
	cToPlange["long long"] = "CLongLong";
	cToPlange["unsigned short"] = "CUnsignedShort";
	cToPlange["unsigned int"] = "CUnsignedInt";
	cToPlange["unsigned long"] = "CUnsignedLong";
	cToPlange["unsigned long long"] = "CUnsignedLongLong";
	cToPlange["char"] = "Char";
	cToPlange["__ssize_t"] = "CUnsignedInt";
	cToPlange["__off_t"] = "CInt";
	cToPlange["float"] = "Float32";
	cToPlange["double"] = "Float64";
	cToPlange["long double"] = "CLongDouble";
	cToPlange["clock_t"] = "Int64";
	cToPlange["time_t"] = "Int64";
	cToPlange["clockid_t"] = "CInt";
	cToPlange["timer_t"] = "CInt";
	cToPlange["pid_t"] = "CInt";
	cToPlange["__pid_t"] = "CInt";
	cToPlange["__locale_t"] = "Pointer<Void>";
	cToPlange["size_t"] = "CUnsignedInt";
	cToPlange["short int"] = "CShort";
	cToPlange["long int"] = "CLong";
	cToPlange["long long int"] = "CLongLong";
	cToPlange["unsigned short int"] = "CUnsignedShort";
	cToPlange["unsigned long int"] = "CUnsignedLong";
	cToPlange["unsigned long long int"] = "CUnsignedLongLong";
	cToPlange["int32_t"] = "Int32";
	cToPlange["__compar_fn_t"] = "<Pointer<Const<Void>> * ";
	cToPlange["__compar_fn_t"] += "Pointer<Const<Void>> -> Int32>";
	cToPlange["div_t"] = "Div_t";
	cToPlange["ldiv_t"] = "LDiv_t";
	cToPlange["lldiv_t"] = "LLDiv_t";
	cToPlange["void (*)(void)"] = "<Void -> Void>";
	cToPlange["void (*)(int, void *)"] = "<Int32 * Pointer<Void> -> Void>";
	cToPlange["__sighandler_t"] = "<Int32 -> Void>";
	cToPlange["union sigval"] = "CSigval";
	cToPlange["random_data"] = "RandomData";
	cToPlange["drand48_data"] = "Drand48Data";
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
	if (starPos == std::string::npos || (starPos > 0 && s[starPos - 1] == '(')) {
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
	if (starPos == std::string::npos || (starPos > 0 && s[starPos - 1] == '(')) {
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
		bool isArray = false;
		if (sp.size() >= 3 && sp[sp.size() - 1] == ']') {
			if (!(sp[sp.size() - 2] == '1' && sp[sp.size() - 3] == '[')) {
				cStdlib << "Array<";
				isArray = true;
			}
			size_t bracketPos = sp.find('[');
			sp = sp.substr(0, bracketPos - 1);
		}
		if (cToPlange.find(sp) != 
				cToPlange.end()) {
			cStdlib << cToPlange[sp];
		}
		else {
			cStdlib << "TBD";
		}
		if (isArray) {
			cStdlib << ">";
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
		bool secondLevel = false;
		bool secondPointerConst = false;
		if (starPos < s.size()) {
			std::string sAfterStarPos = s.substr(starPos + 1);
			if (sAfterStarPos.find('*') != std::string::npos) {
				secondLevel = true;
			}
			if (sAfterStarPos.find("const") != std::string::npos) {
				secondPointerConst = true;
			}
		}
		std::string snp = s.substr(typeStartChar,
															 starPos - typeStartChar - 1);
		bool isArray = false;
		if (snp.size() >= 3 && snp[snp.size() - 1] == ']') {
			if (!(snp[snp.size() - 2] == '1' && snp[snp.size() - 3] == '[')) {
				cStdlib << "Array<";
				isArray = true;
			}
			size_t bracketPos = snp.find('[');
			snp = snp.substr(0, bracketPos - 1);
		}
    if (cToPlange.find(snp) != 
				cToPlange.end()) {
			if (pointerConst) {
				cStdlib << "Const<";
			}
			cStdlib << "Pointer<";
			if (secondPointerConst) {
				cStdlib << "Const<";
			}
			if (secondLevel) {
				cStdlib << "Pointer<";
			}
			if (constPointer) {
				cStdlib << "Const<";
			}
			cStdlib << cToPlange[snp];
			if (constPointer) {
				cStdlib << ">";
			}
			if (secondLevel) {
				cStdlib << ">";
			}
			if (secondPointerConst) {
				cStdlib << ">";
			}
			if (pointerConst) {
				cStdlib << ">";
			}
			if (isArray) {
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
  cStdlib.open("Plange.CStdLib.Generated._pg", std::fstream::out);
	for (int i = 1; i < argc; ++i) {
		initMap();
	  CXIndex index = clang_createIndex(0, 0);
	  CXTranslationUnit unit = clang_parseTranslationUnit(index,
	                                                      argv[i],
																											  nullptr,
																											  0,
																											  nullptr,
																											  0,
																											  CXTranslationUnit_None);
	  if (unit != nullptr) {
			CXCursor rootCursor = clang_getTranslationUnitCursor(unit);
      clang_visitChildren(rootCursor, printVisitor, NULL);
		}
	  clang_disposeTranslationUnit(unit);
	  clang_disposeIndex(index);
	}
	cStdlib.close();
	return 0;
}
