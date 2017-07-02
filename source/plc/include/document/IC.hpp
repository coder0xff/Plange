// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IC_HPP
#define INCLUDED_IC_HPP

struct COMMENT;
struct EMBEDDED_COMMENT;
struct END_OF_LINE_COMMENT;
struct WS;

typedef std::variant<
	erased<COMMENT>,
	erased<EMBEDDED_COMMENT>,
	erased<END_OF_LINE_COMMENT>,
	erased<WS>
> IC;

#endif //INCLUDED_IC_HPP
