#ifndef BITS_HPP
#define BITS_HPP

#include <cstdint>

#ifdef __GNUC__
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#elif _MSC_VER
#include <IntSafe.h>
#include <intrin.h>

uint32_t __inline ctz(uint32_t const value)
{
	DWORD trailingZero = 0;

	if (_BitScanForward(&trailingZero, value))	{
		return trailingZero;
	}
	// This is undefined, I better choose 32 than 0
	return 32;
}

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
