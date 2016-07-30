#include "MathematicaInterface.h"

#include <thread>
#include <cassert>
#include <sstream>
#include <utils.hpp>

#include "Errors.h"
#include "execution_context.h"
#include "plange.h"

#include "AddSubExp.h"
#include "AdditionExp.h"
#include "AllExp.h"
#include "AllocationExp.h"
#include "AndExp.h"
#include "ArrayExp.h"
#include "AsmFunctionExp.h"
#include "BijectionExp.h"
#include "BinaryOpExp.hpp"
#include "BitAndExp.h"
#include "BitOrExp.h"
#include "BitXorExp.h"
#include "BoolExp.h"
#include "CardinalityExp.h"
#include "CastExp.h"
#include "CastsExp.h"
#include "CeilingExp.h"
#include "ComplementExp.h"
#include "CompositionExp.h"
#include "CompoundExp.h"
#include "ConditionalExp.h"
#include "CrossProductExp.h"
#include "DeltaExp.h"
#include "DimensionalNumberExp.h"
#include "DivisionExp.h"
#include "DotProductExp.h"
#include "EqualityExp.h"
#include "ExistsExp.h"
#include "ExistsOneExp.h"
#include "ExponentiationExp.h"
#include "FactorialExp.h"
#include "FloorExp.h"
#include "GreaterThanExp.h"
#include "HasExp.h"
#include "IdentifierExp.h"
#include "IfExp.h"
#include "IffExp.h"
#include "ImplicationExp.h"
#include "InExp.h"
#include "InequalityExp.h"
#include "IntegerDivisionExp.h"
#include "IntersectionExp.h"
#include "InvocationExp.h"
#include "IsExp.h"
#include "KleeneStarExp.h"
#include "LesserThanExp.h"
#include "ListExp.h"
#include "MagnitudeExp.h"
#include "MapExp.h"
#include "MapsToExp.h"
#include "MemberAccessExp.h"
#include "ModulationExp.h"
#include "MultiplicationExp.h"
#include "NandExp.h"
#include "NearestIntegerExp.h"
#include "NegationExp.h"
#include "NonNegativeNumberExp.h"
#include "NorExp.h"
#include "NotExp.h"
#include "NotGreaterThanExp.h"
#include "NotHasExp.h"
#include "NotInExp.h"
#include "NotLesserThanExp.h"
#include "NullCoalesceExp.h"
#include "OrExp.h"
#include "ParentheticalExp.h"
#include "PostDecExp.h"
#include "PostIncExp.h"
#include "PreDecExp.h"
#include "PreIncExp.h"
#include "PrependExp.h"
#include "ProperSubsetExp.h"
#include "ProperSupersetExp.h"
#include "RadicalExp.h"
#include "RangeExp.h"
#include "SetComprehensionExp.h"
#include "SetExp.h"
#include "ShiftLExp.h"
#include "ShiftRExp.h"
#include "StringExp.h"
#include "SubsetExp.h"
#include "SubtractionExp.h"
#include "SupersetExp.h"
#include "SymmetricDifferenceExp.h"
#include "TupleExp.h"
#include "TypeExp.h"
#include "UnaryOpExp.h"
#include "UnionExp.h"
#include "VectorNormExp.h"
#include "XorExp.h"

std::string magicString = "1a53e49a14cb472eb0e8e5f19caf18ca";

std::string waitFor(std::string const& val, std::istream& in) {
	int const eof = std::char_traits<char>::eof();
	std::string buffer;
	while (true) {
		std::string::const_reverse_iterator i = val.rbegin();
		std::string::const_reverse_iterator j = buffer.rbegin();
		while (i != val.rend()) {
			if (j == buffer.rend() || *(i++) != *(j++)) {
				goto keepReading;
			}
		}
		return buffer;
	keepReading:
		int c = eof;
		while (c == eof) {
			in.clear();
			c = in.get();
		}
		buffer.append(1, c);
	}
}

MathematicaInterface::MathematicaInterface(std::string const& mathExePath) : proc(mathExePath.c_str(), "") {
	waitFor("In[1]:=", proc.out());
}

std::unique_ptr<Expression> MathematicaInterface::FullSimplify(Expression const& expr) {
	//"FullSimplify[" << convert(expr) << "]\n"
	throw std::logic_error("Not implemented.");
}

void MathematicaInterface::test() {
	assert(evaluate("1+2") == "3");
}

std::string MathematicaInterface::context::create_placeholder(const Expression& expr) {
	table.push_back(&expr);
	return "ZZZplaceholderZZZ" + std::to_string(table.size() - 1);
}

bool outputCompleted(std::string const& output) {
	std::string::const_reverse_iterator i = magicString.rbegin();
	std::string::const_reverse_iterator j = output.rbegin();

	while (i != magicString.rend()) {
		if (j == output.rend() || *(i++) != *(j++)) {
			return false;
		}
	}
	return true;
}

std::string MathematicaInterface::evaluate(std::string const& expr) {
	proc.in() << "{" << expr << ",\"" << magicString << "\"}\n";
	std::string result = waitFor(magicString, proc.out());
	waitFor("]:=", proc.out());
	result = result.substr(0, result.length() - magicString.length() - 2);
	result = result.substr(result.find("=") + 3);
	return result;
}

std::string MathematicaInterface::convert(std::unique_ptr<Expression> const& expr, context& ctx) const {
#define CASE(x) auto as##x = dynamic_cast<x##Exp const *>(&*expr); \
		if (as##x)

	CASE(Allocation) {
		return "shadowedAllocation[" + convert(asAllocation->argument, ctx) + "]";
	}
	CASE(Array) {
		std::stringstream ss;
		ss << "{";
		for (std::unique_ptr<Expression> const & element : asArray->elements) {
			ss << convert(element, ctx) << ",";
		}
		ss.seekp(-1, ss.cur);
		ss << "}";
		return ss.str();
	}
	CASE(AsmFunction) {
		return ctx.create_placeholder(*expr);
	}
	CASE(BinaryOp) {
#define CASE2(x) auto as##x = dynamic_cast<x##Exp const *>(&*expr); if (as##x) return "(" + convert(asBinaryOp->left, ctx) + " " + to_utf8(asBinaryOp->get_name()) + " " + convert(asBinaryOp->right, ctx) + ")"
#define CASE3(x, prefix, separator, postfix) auto as##x = dynamic_cast<x##Exp const *>(&*expr); if (as##x) return prefix + convert(asBinaryOp->left, ctx) + separator + convert(asBinaryOp->right, ctx) + postfix
#define CASE4(x) auto as##x = dynamic_cast<x##Exp const *>(&*expr); if (as##x) { ERROR(NotImplemented, "Mathematica " #x " operator"); }

		CASE2(Addition);
		CASE2(AddSub);
		CASE3(And, "(", "&&", "&&");
		CASE4(Bijection);
		CASE3(BitAnd, "BitAnd[", ",", "]");
		CASE3(BitOr, "BitOr[", ",", "]");
		CASE3(BitXor, "BitXor[", ",", "]");
		CASE4(Casts);
		CASE3(Composition, "Composition[", ",", "]");
		CASE4(Compound);
		CASE3(CrossProduct, "Cross[", ",", "]");
		CASE2(Division);
		CASE3(DotProduct, "Dot[", ",", "]");
		CASE3(Equality, "(", "==", ")");
		CASE2(Exponentiation);
		CASE2(GreaterThan);
		auto asHas = dynamic_cast<HasExp const *>(&*expr); if (asHas) return "Element[" + convert(asBinaryOp->right, ctx) + "," + convert(asBinaryOp->left, ctx) + "]";
		CASE3(Iff, "Equivalent[", ",", "]");
		CASE3(Implication, "Implies[", ",", "]");
		CASE3(In, "Element[", ",", "]");
		CASE2(Inequality);
		auto asIntegerDivision = dynamic_cast<IntegerDivisionExp const *>(&*expr); if (asIntegerDivision) {
			if (plange::is_Collection(*asBinaryOp->left) && plange::is_Integral(*asBinaryOp->right)) {
				ERROR(NotImplemented, "Mathematica set chunk operator");
			}
			return "Quotient[" + convert(asBinaryOp->left, ctx) + ", " + convert(asBinaryOp->right, ctx) + "]";
		}
		CASE3(Intersection, "Intersection[", ",", "]");
		//IsExp
		CASE2(LesserThan);
		//MapsTo
		if (dynamic_cast<MemberAccessExp const *>(&*expr)) return ctx.create_placeholder(*expr);
		CASE3(Modulation, "Mod[", ",", "]");
		CASE2(Multiplication);
		CASE3(Nand, "Nand[", ",", "]");
		CASE3(Nor, "Nor[", ",", "]");
		CASE2(NotGreaterThan);
		auto asNotHas = dynamic_cast<NotHasExp const *>(&*expr); if (asHas) return "!Element[" + convert(asBinaryOp->right, ctx) + "," + convert(asBinaryOp->left, ctx) + "]";
		CASE3(NotIn, "(!Element[", ",", "]");
		CASE2(NotLesserThan);
		CASE3(Or, "(", "||", ")");
		CASE4(ProperSubset);
		CASE4(ProperSuperset);
		CASE3(ShiftL, "(", "*(2^(", ")))");
		CASE3(ShiftR, "(", "*(2^(-(", "))))");
		CASE4(Subset);
		CASE2(Subtraction);
		CASE4(Superset);
		CASE4(SymmetricDifference);
		CASE3(Union, "Union[", ",", "]");
		CASE3(Xor, "Xor[", ",", "]");

/*		CASE(Division) {
			auto leftAsDelta = dynamic_cast<DeltaExp const *>(&asBinaryOp->left);
			if (leftAsDelta) {
				auto rightAsDelta = dynamic_cast<DeltaExp const *>(&asBinaryOp->right);
				if (rightAsDelta) {
					if (rightAsDelta->rank == 1) {
						auto rightSubExpressionAsIdentifier = dynamic_cast<IdentifierExp const *>(&rightAsDelta->sub_expression);
						auto rightSubExpressionAsMemberAccess = dynamic_cast<MemberAccessExp const *>(&rightAsDelta->sub_expression);
						if (rightSubExpressionAsIdentifier || rightSubExpressionAsMemberAccess) {
							auto divisorType = ctx.ctx.type_of(rightAsDelta->sub_expression);
							if (divisorType == plange::get_Real() || divisorType == plange::get_Float() || divisorType == plange::get_Float16() || divisorType == plange::get_Float32() || divisorType == plange::get_Float64() || divisorType == plange::get_Float128()) {
								return "D[" + convert(leftAsDelta->sub_expression, ctx) + ", {(" + convert(rightAsDelta->sub_expression, ctx) + ")^(1/" + std::to_string(leftAsDelta->rank) + ")," + std::to_string(leftAsDelta->rank) + "}]";

							}
						}
					}
				}
			}*/
		//return "(" + convert(asBinaryOp->left, ctx) + to_utf8(asBinaryOp->get_name()) + convert(asBinaryOp->right, ctx) + ")";
#undef CASE2
#undef CASE3
#undef CASE4
	}
	CASE(Bool) {
		return asBool->val ? "True" : "False";
	}
	CASE(String) {
		return "\"" + string_replace(string_replace(string_replace(string_replace(string_replace(asString->val, "\\", "\\\\"), "\n", "\\n"), "\t", "\\t"), "\"", "\\\""), "\\", "\\\\") + "\"";
	}
	CASE(Cast) {
		if (ctx.ctx.evaluate(*asCast->target_type) == plange::get_Int() && ctx.ctx.type_of(*asCast->sub_expression) == plange::get_Real()) {
			return "Floor[" + convert(asCast->sub_expression, ctx) + "]";
		}
		ERROR(NotImplemented, "Mathematica type cast conversion");
	}
	CASE(Ceiling) {
		return "Ceiling[" + convert(asCeiling->sub_expression, ctx) + "]";
	}
	CASE(Complement) {
		//todo: maybe implement as Complement[Reals, x] when elements of x are Numbers
		ERROR(NotImplemented, "Mathematica set compliment");
	}
	CASE(Conditional) {
		return "If[" + convert(asConditional->condition, ctx) + "," + convert(asConditional->true_case, ctx) + "," + convert(asConditional->false_case, ctx) + "]";
	}
	CASE(Delta) {
		ERROR(NotImplemented, "Mathematica delta expression conversion");
	}
	CASE(DimensionalNumber) {
		ERROR(NotImplemented, "Mathematica dimensional analysis");
	}
	CASE(Floor) {
		return "Floor[" + convert(asFloor->sub_expression, ctx) + "]";
	}
	CASE(If) {
		std::stringstream ss;
		for (auto const & pair : asIf->pairs) {
			ss << "if[" << convert(pair.first, ctx) << "," << convert(pair.second, ctx) << ",";
		}
		ss << convert(asIf->else_, ctx) << "]";
		return ss.str();
	}
	CASE(Invocation) {
		auto funcVal = ctx.ctx.evaluate(*asInvocation->function);
		std::string funcName = "";
		if (funcVal == plange::get_global({}, U"acos")) { funcName = "ArcCos"; }
		if (funcVal == plange::get_global({}, U"acosh")) { funcName = "ArcCosh"; }
		if (funcVal == plange::get_global({}, U"acot")) { funcName = "ArcCot"; }
		if (funcVal == plange::get_global({}, U"acoth")) { funcName = "ArcCoth"; }
		if (funcVal == plange::get_global({}, U"asin")) { funcName = "ArcSin"; }
		if (funcVal == plange::get_global({}, U"asinh")) { funcName = "ArcSinh"; }
		if (funcVal == plange::get_global({}, U"atan")) { funcName = "ArcTan"; }
		if (funcVal == plange::get_global({}, U"atanh")) { funcName = "ArcTanh"; }
		if (funcVal == plange::get_global({}, U"cos")) { funcName = "Cos"; }
		if (funcVal == plange::get_global({}, U"cosh")) { funcName = "Cosh"; }
		if (funcVal == plange::get_global({}, U"cot")) { funcName = "Cot"; }
		if (funcVal == plange::get_global({}, U"coth")) { funcName = "Coth"; }
		if (funcVal == plange::get_global({}, U"exp")) { funcName = "Exp"; }
		if (funcVal == plange::get_global({}, U"log")) { funcName = "Log"; }
		if (funcVal == plange::get_global({}, U"sin")) { funcName = "Sin"; }
		if (funcVal == plange::get_global({}, U"sinh")) { funcName = "Sinh"; }
		if (funcVal == plange::get_global({}, U"tan")) { funcName = "Tan"; }
		if (funcVal == plange::get_global({}, U"tanh")) { funcName = "Tanh"; }
		if (funcVal == plange::get_global({}, U"max")) {
			if (asInvocation->arguments.size() == 1) {
				ERROR(NotImplemented, "Mathematica max on collection conversion");
			}
			funcName = "Max";
		}
		if (funcVal == plange::get_global({}, U"min")) {
			if (asInvocation->arguments.size() == 1) {
				ERROR(NotImplemented, "Mathematica min on collection conversion");
			}
			funcName = "Min";
		}
		if (funcName == "") {
			funcName = ctx.create_placeholder(*expr);
		}
		std::stringstream ss;
		ss << funcName << "[";
		for (auto const & arg : asInvocation->arguments) {
			ss << convert(arg, ctx) << ",";
		}
		ss.seekp(-1, ss.cur);
		ss << "]";
		return ss.str();
	}
	CASE(Is) {
		ERROR(NotImplemented, "Mathematica is operator conversion");
	}
	CASE(List) {
		std::stringstream ss;
		ss << "{";
		auto i = asList->elements.begin();
		if (i != asList->elements.end()) {
			ss << convert(*i, ctx);
			++i;
			while (i != asList->elements.end()) {
				ss << "," << convert(*i, ctx);
				++i;
			}
		}
		ss << "}";
		return ss.str();
	}
	CASE(Magnitude) {
		auto subExpType = ctx.ctx.type_of(*asMagnitude->sub_expression);
		if (subExpType == plange::get_Float() || subExpType == plange::get_Float16() || subExpType == plange::get_Float32() || subExpType == plange::get_Float64() || subExpType == plange::get_Float128() || subExpType == plange::get_Int() || subExpType == plange::get_Int8() || subExpType == plange::get_Int16() || subExpType == plange::get_Int32() || subExpType == plange::get_Int64() || subExpType == plange::get_Int128()) {
			return "Abs[" + convert(asMagnitude->sub_expression, ctx) + "]";
		}
		return "Norm[" + convert(asMagnitude->sub_expression, ctx) + "]";
	}
	CASE(Map) {
		std::stringstream ss;
		ss << "<|";
		auto i = asMap->elements.begin();
		if (i != asMap->elements.end()) {
			ss << convert(i->first, ctx) << "->" << convert(i->second, ctx);
			++i;
			while (i != asMap->elements.end()) {
				ss << "," << convert(i->first, ctx) << "->" << convert(i->second, ctx);
				++i;
			}
		}
		ss << "|>";
		return ss.str();
	}
	CASE(MapsTo) {
		ERROR(NotImplemented, "Mathematica MapsTo operator conversion");
	}
	CASE(NearestInteger) {
		return "Round[" + convert(asNearestInteger->sub_expression, ctx) + "]";
	}
	CASE(NonNegativeNumber) {
		return to_utf8(asNonNegativeNumber->as_string);
	}
	CASE(NullCoalesce) {
		ERROR(NotImplemented, "Mathematica NullCoalesce operator conversion");
	}
	CASE(Parenthetical) {
		return "(" + convert(asParenthetical->sub_expression, ctx) + ")";
	}
	CASE(Prepend) {
		return "Prepend[" + convert(asPrepend->right, ctx) + "," + convert(asPrepend->left, ctx) + "]";
	}
	CASE(Radical) {
		return "((" + convert(asRadical->sub_expression, ctx) + ")^0.5)";
	}
	CASE(Range) {
		ERROR(NotImplemented, "Mathematica Range expression conversion");
	}
	CASE(SetComprehension) {
		ERROR(NotImplemented, "Mathematica SetComprehension conversion");
	}
	CASE(Set) {
		std::stringstream ss;
		ss << "<|";
		auto i = asMap->elements.begin();
		if (i != asMap->elements.end()) {
			ss << convert(i->first, ctx) << "->" << convert(i->second, ctx);
			++i;
			while (i != asMap->elements.end()) {
				ss << "," << convert(i->first, ctx) << "->0";
				++i;
			}
		}
		ss << "|>";
		return ss.str();
	}
	CASE(Tuple) {
		std::stringstream ss;
		ss << "{";
		auto i = asTuple->elements.begin();
		if (i != asTuple->elements.end()) {
			ss << convert(*i, ctx);
			++i;
			while (i != asTuple->elements.end()) {
				ss << "," << convert(*i, ctx);
				++i;
			}
		}
		ss << "}";
		return ss.str();
	}
	CASE(Type) {
		ERROR(NotImplemented, "Mathematica Type conversion");
	}
	CASE(VectorNorm) {
		return "Norm[" + convert(asVectorNorm->sub_expression, ctx) + "]";
	}
	CASE(UnaryOp) {
#define CASE2(x) auto as##x = dynamic_cast<x##Exp const *>(&*expr); if (as##x) return (asUnaryOp->get_postfix()) ? "((" + convert(asUnaryOp->sub_expression, ctx) + ")" + to_utf8(asUnaryOp->get_name()) + ")" : "(" + to_utf8(asUnaryOp->get_name()) + "(" + convert(asUnaryOp->sub_expression, ctx) + "))"
#define CASE3(x, name) auto as##x = dynamic_cast<x##Exp const *>(&*expr); if (as##x) return (asUnaryOp->get_postfix()) ? "((" + convert(asUnaryOp->sub_expression, ctx) + ")" name ")" : "(" name "(" + convert(asUnaryOp->sub_expression, ctx) + "))"
#define CASE4(x, name) auto as##x = dynamic_cast<x##Exp const *>(&*expr); if (as##x) return name "[" + convert(asUnaryOp->sub_expression, ctx) + "]"
#define CASE5(x) auto as##x = dynamic_cast<x##Exp const *>(&*expr); if (as##x) { ERROR(NotImplemented, "Mathematica " #x " operator"); }

		CASE4(Cardinality, "Length");
		CASE5(KleeneStar);
		CASE2(Factorial);
		CASE2(Negation);
		CASE5(PostDec);
		CASE5(PostInc);
		CASE5(PreDec);
		CASE5(PreInc);
		CASE4(Radical, "Sqrt");
		CASE3(Not, "!");
		CASE5(All);
		CASE4(Exists, "Exists");
		CASE5(ExistsOne)

#undef CASE2
#undef CASE3
#undef CASE4
#undef CASE5
	}
#undef CASE
	return ctx.create_placeholder(*expr);
}
