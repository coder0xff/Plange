#ifndef MATHEMATICA_INTERFACE_H
#define MATHEMATICA_INTERFACE_H

#include "CasInterface.h"
#include "exec-stream.h"

class MathematicaInterface : public CasInterface
{
	exec_stream_t proc;
public:
	virtual ~MathematicaInterface()
	{
	}

	MathematicaInterface(std::string const & mathExePath);
	Expression FullSimplify(Expression const & expr) override;
	void test();
private:
	std::string evaluate(std::string const & expr);
	std::string convert(Expression const & expr);
	Expression convert(std::string const & expr);
};

#endif //MATHEMATICA_INTERFACE_H