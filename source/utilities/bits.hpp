#ifndef BITS_HPP
#define BITS_HPP

#include <cstdint>

#ifdef __GNUC__
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#elif _MSC_VER
#include <IntSafe.h>
#include <intrin.h>

uint32_t __inline ctz(uint32_t value)
{
	DWORD trailing_zero = 0;

	if (_BitScanForward(&trailing_zero, value))	{
		return trailing_zero;
	} else {
		// This is undefined, I better choose 32 than 0
		return 32;
	}
}

uint32_t __inline clz(uint32_t value)
{
	DWORD leading_zero = 0;

	if (_BitScanReverse(&leading_zero, value)) {
		return 31 - leading_zero;
	} else {
		// Same remarks as above
		return 32;
	}
}
#endif

#endif //BITS_HPP
