#ifndef INCLUDING_MPL_HEAD_HPP
#define INCLUDING_MPL_HEAD_HPP

namespace mpl {

template<typename THead, typename... TTail>
using head = THead;

#define INCLUDED_MPL_HEAD_HPP
#elif !defined(INCLUDED_MPL_HEAD_HPP)
#	error circular inclusion
#endif