// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_STATEMENT_HPP
#define INCLUDED_ASM_STATEMENT_HPP

struct ASM_EXPRESSION;
struct ASM_OP;
struct IC;
struct ICR;

struct ASM_STATEMENT {
	erased<ASM_OP> field_1;
	std::optional<std::tuple<
		erased<ICR>,
		erased<ASM_EXPRESSION>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::optional<std::tuple<
				std::vector<erased<IC>>,
				erased<ASM_EXPRESSION>
			>>
		>>
	>> field_2;
	std::vector<erased<IC>> field_3;
};



#endif //INCLUDED_ASM_STATEMENT_HPP
