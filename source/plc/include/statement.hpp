#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "match.hpp"

namespace plc {

class statement {
public:
	static statement * from_code(parlex::match m);
};

}

#endif //STATEMENT_HPP