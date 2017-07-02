// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_HPP
#define INCLUDED_DATE_HPP

struct DATE_YEAR_DAY;
struct DATE_YEAR_MONTH_DAY;

typedef std::variant<
	erased<DATE_YEAR_MONTH_DAY>,
	erased<DATE_YEAR_DAY>
> DATE;

#endif //INCLUDED_DATE_HPP
