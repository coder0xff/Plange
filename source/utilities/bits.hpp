#ifndef BITS_HPP
#define BITS_HPP

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
	// Same remarks as above
	return 32;
}

#endif

#endif //BITS_HPP
