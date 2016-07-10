#ifndef MATHEMATICA_INTERFACE_H
#define MATHEMATICA_INTERFACE_H

#include "CasInterface.h"
#include "exec-stream.h"

class execution_context;

class MathematicaInterface : public CasInterface {
	exec_stream_t proc;
public:
	virtual ~MathematicaInterface() { }

	MathematicaInterface(std::string const& mathExePath);
	Expression FullSimplify(Expression const& expr) override;
	void test();
private:
	class context {
	public:
		execution_context & ctx;
		std::string create_placeholder(const Expression& expr);
		std::vector<Expression const *> table;
	};

	std::string evaluate(std::string const& expr);
	std::string convert(Expression const& expr, context& ctx);
	Expression convert(std::string const& expr);
};

#endif //MATHEMATICA_INTERFACE_H
