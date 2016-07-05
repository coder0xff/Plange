#include "MathematicaInterface.h"

#include <utils.hpp>

#include "Addition.h"
#include "Number.h"
#include <thread>
#include <cassert>

std::string magicString = "1a53e49a14cb472eb0e8e5f19caf18ca";

std::string waitFor(std::string const & val, std::istream & in)
{
	int const eof = std::char_traits<char>::eof();
	std::string buffer;
	while (true)
	{
		std::string::const_reverse_iterator i = val.rbegin();
		std::string::const_reverse_iterator j = buffer.rbegin();
		while (i != val.rend())
		{
			if (j == buffer.rend() || *(i++) != *(j++))
			{
				goto keepReading;
			}
		}
		return buffer;
	keepReading:
		int c = eof;
		while (c == eof)
		{
			in.clear();
			c = in.get();
		}
		buffer.append(1, c);
	}
}

MathematicaInterface::MathematicaInterface(std::string const & mathExePath) : proc(mathExePath.c_str(), "")
{
	waitFor("In[1]:=", proc.out());
}

Expression MathematicaInterface::FullSimplify(Expression const & expr)
{
	//"FullSimplify[" << convert(expr) << "]\n"
	throw std::exception("Not implemented.");
}

void MathematicaInterface::test()
{
	assert(evaluate("1+2") == "3");
}

bool outputCompleted(std::string const & output)
{
	std::string::const_reverse_iterator i = magicString.rbegin();
	std::string::const_reverse_iterator j = output.rbegin();

	while (i != magicString.rend())
	{
		if (j == output.rend() || *(i++) != *(j++))
		{
			return false;
		}
	}
	return true;
}

std::string MathematicaInterface::evaluate(std::string const & expr)
{
	proc.in() << "{" << expr << ",\"" << magicString << "\"}\n";
	std::string result = waitFor(magicString, proc.out());
	result = result.substr(0, result.length() - magicString.length() - 2);
	result = result.substr(result.find("=") + 3);
	return result;
}

std::string MathematicaInterface::convert(Expression const & expr)
{
	auto asBinaryOp = dynamic_cast<BinaryOp const *>(&expr);
	if (asBinaryOp)
	{
		return convert(asBinaryOp->left) + to_utf8(asBinaryOp->name()) + convert(asBinaryOp->right);
	}
	auto asNumber = dynamic_cast<Number const *>(&expr);
	throw std::exception("Not implemented.");
}

