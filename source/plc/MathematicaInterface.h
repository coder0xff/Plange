#ifndef MATHEMATICA_INTERFACE_H
#define MATHEMATICA_INTERFACE_H

#include "CasInterface.h"
#include "exec-stream.h"
#include <memory>

class execution_context;

class MathematicaInterface : public CasInterface {
	exec_stream_t proc;
public:
	virtual ~MathematicaInterface() { }

	MathematicaInterface(std::string const& mathExePath);
	std::unique_ptr<Expression> FullSimplify(Expression const& expr) override;
	void test();
private:
	class context {
	public:
		execution_context & ctx;
		std::string create_placeholder(const Expression& expr);
		std::vector<Expression const *> table;
	};

	std::string evaluate(std::string const& expr);
	std::string convert(std::unique_ptr<Expression> const& expr, context& ctx) const;
	std::unique_ptr<Expression> convert(std::string const& expr);
};

#endif //MATHEMATICA_INTERFACE_H
