#ifndef INCLUDED_UTILITIES_BITS_HPP
#define INCLUDED_UTILITIES_BITS_HPP

#include <cstdint>

#ifdef __GNUC__

uint32_t __inline clz(uint32_t const value)
{
	if (value == 0) { return 32; }
	return __builtin_clz(value);
}

#elif _MSC_VER
#include <IntSafe.h>
#include <intrin.h>

uint32_t __inline clz(uint32_t const value)
{
	DWORD leadingZero = 0;

	if (_BitScanReverse(&leadingZero, value)) {
		return 31 - leadingZero;
	}
	return 32;
}

#endif

#endif // INCLUDED_UTILITIES_BITS_HPP
