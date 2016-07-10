#include "MathematicaInterface.h"

#include <thread>
#include <cassert>
#include <sstream>
#include <utils.hpp>

#include "Errors.h"
#include "execution_context.h"
#include "plange.h"

#include "AllocationExp.h"
#include "ArrayExp.h"
#include "AsmFunctionExp.h"
#include "BoolExp.h"
#include "CastExp.h"
#include "CeilingExp.h"
#include "ConditionalExp.h"
#include "DeltaExp.h"
#include "DimensionalNumberExp.h"
#include "DivisionExp.h"
#include "FactorialExp.h"
#include "FloorExp.h"
#include "IdentifierExp.h"
#include "IfExp.h"
#include "InvocationExp.h"
#include "MagnitudeExp.h"
#include "NearestIntegerExp.h"
#include "NonNegativeNumberExp.h"
#include "ParentheticalExp.h"
#include "RadicalExp.h"
#include "StringExp.h"

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

Expression MathematicaInterface::FullSimplify(Expression const& expr) {
	//"FullSimplify[" << convert(expr) << "]\n"
	throw std::exception("Not implemented.");
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

std::string MathematicaInterface::convert(Expression const& expr, context& ctx) {
#define CASE(x) auto as##x = dynamic_cast<x##Exp const *>(&expr); \
		if (as##x)

	CASE(Allocation) {
		return "shadowedAllocation[" + convert(asAllocation->argument, ctx) + "]";
	}
	CASE(Array) {
		std::stringstream ss;
		ss << "{";
		for (Expression const & element : asArray->elements) {
			ss << convert(element, ctx) << ",";
		}
		ss.seekp(-1, ss.cur);
		ss << "}";
		return ss.str();
	}
	CASE(AsmFunction) {
		return ctx.create_placeholder(expr);
	}
	CASE(BinaryOp) {
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
		return "(" + convert(asBinaryOp->left, ctx) + to_utf8(asBinaryOp->name()) + convert(asBinaryOp->right, ctx) + ")";
	}
	CASE(Bool) {
		return asBool->value ? "True" : "False";
	}
	CASE(String) {
		return "\"" + string_replace(string_replace(string_replace(string_replace(string_replace(asString->value, "\\", "\\\\"), "\n", "\\n"), "\t", "\\t"), "\"", "\\\""), "\\", "\\\\") + "\"";
	}
	CASE(Cast) {
		if (ctx.ctx.evaluate(asCast->target_type) == plange::get_Int() && ctx.ctx.type_of(asCast->value) == plange::get_Real()) {
			return "Floor[" + convert(asCast->value, ctx) + "]";
		}
		emit_NotImplemented("Mathematica type cast conversion");
	}
	CASE(Ceiling) {
		return "Ceiling[" + convert(asCeiling->sub_expression, ctx) + "]";
	}
	CASE(Conditional) {
		return "If[" + convert(asConditional->condition, ctx) + "," + convert(asConditional->true_case, ctx) + "," + convert(asConditional->false_case, ctx) + "]";
	}
	CASE(Delta) {
		emit_NotImplemented("Mathematica delta expression conversion");
		throw;
	}
	CASE(DimensionalNumber) {
		emit_NotImplemented("Mathematica dimensional analysis");
		throw;
	}
	CASE(Factorial) {
		return "(" + convert(asFactorial->sub_expression, ctx) + ")!";
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
		auto funcVal = ctx.ctx.evaluate(asInvocation->function);
		std::string funcName = "";
		if (funcVal == plange::get_global({}, "acos")) { funcName = "ArcCos"; }
		if (funcVal == plange::get_global({}, "acosh")) { funcName = "ArcCosh"; }
		if (funcVal == plange::get_global({}, "acot")) { funcName = "ArcCot"; }
		if (funcVal == plange::get_global({}, "acoth")) { funcName = "ArcCoth"; }
		if (funcVal == plange::get_global({}, "asin")) { funcName = "ArcSin"; }
		if (funcVal == plange::get_global({}, "asinh")) { funcName = "ArcSinh"; }
		if (funcVal == plange::get_global({}, "atan")) { funcName = "ArcTan"; }
		if (funcVal == plange::get_global({}, "atanh")) { funcName = "ArcTanh"; }
		if (funcVal == plange::get_global({}, "cos")) { funcName = "Cos"; }
		if (funcVal == plange::get_global({}, "cosh")) { funcName = "Cosh"; }
		if (funcVal == plange::get_global({}, "cot")) { funcName = "Cot"; }
		if (funcVal == plange::get_global({}, "coth")) { funcName = "Coth"; }
		if (funcVal == plange::get_global({}, "exp")) { funcName = "Exp"; }
		if (funcVal == plange::get_global({}, "log")) { funcName = "Log"; }
		if (funcVal == plange::get_global({}, "sin")) { funcName = "Sin"; }
		if (funcVal == plange::get_global({}, "sinh")) { funcName = "Sinh"; }
		if (funcVal == plange::get_global({}, "tan")) { funcName = "Tan"; }
		if (funcVal == plange::get_global({}, "tanh")) { funcName = "Tanh"; }
		if (funcVal == plange::get_global({}, "max")) {
			if (asInvocation->arguments.size() == 1) {
				emit_NotImplemented("Mathematica max on collection conversion");
			}
			funcName = "Max";
		}
		if (funcVal == plange::get_global({}, "min")) {
			if (asInvocation->arguments.size() == 1) {
				emit_NotImplemented("Mathematica min on collection conversion");
			}
			funcName = "Min";
		}
		if (funcName == "") {
			funcName = ctx.create_placeholder(expr);
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
	CASE(Magnitude) {
		auto subExpType = ctx.ctx.type_of(asMagnitude->sub_expression);
		if (subExpType == plange::get_Float() || subExpType == plange::get_Float16() || subExpType == plange::get_Float32() || subExpType == plange::get_Float64() || subExpType == plange::get_Float128() || subExpType == plange::get_Int() || subExpType == plange::get_Int8() || subExpType == plange::get_Int16() || subExpType == plange::get_Int32() || subExpType == plange::get_Int64() || subExpType == plange::get_Int128()) {
			return "Abs[" + convert(asMagnitude->sub_expression, ctx) + "]";
		}
		return "Norm[" + convert(asMagnitude->sub_expression, ctx) + "]";
	}
	CASE(NearestInteger) {
		return "Round[" + convert(asNearestInteger->sub_expression, ctx) + "]";
	}
	CASE(NonNegativeNumber) {
		return to_utf8(asNonNegativeNumber->as_string);
	}
	CASE(Parenthetical) {
		return "(" + convert(asParenthetical->sub_expression, ctx) + ")";
	}
	CASE(Radical) {
		return "((" + convert(asRadical->sub_expression, ctx) + ")^0.5)";
	}
#undef CASE
	return ctx.create_placeholder(expr);
}
