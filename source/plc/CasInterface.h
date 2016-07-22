#ifndef CAS_INTERFACE_H
#define CAS_INTERFACE_H
#include "Expression.h"

//computer algebra system interface
class CasInterface {
public:
	virtual void test() = 0;

	virtual ~CasInterface() = default;

private:
	virtual std::unique_ptr<Expression> FullSimplify(Expression const& expr) = 0;
};

#endif //CAS_INTERFACE_H
