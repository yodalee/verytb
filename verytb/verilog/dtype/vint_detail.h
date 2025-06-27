#pragma once
// Direct include
// C system headers
// C++ standard library headers
#include <cstdint>
#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iomanip>
#include <ostream>
#include <string>
#include <type_traits>
// Other libraries' .h files.
#include <immintrin.h>
// Your project's .h files.

namespace verilog::detail {

template<bool is_signed, unsigned num_bit> struct dtype_dict;
template<> struct dtype_dict<true, 0u> { typedef int8_t type; };
template<> struct dtype_dict<true, 1u> { typedef int16_t type; };
template<> struct dtype_dict<true, 2u> { typedef int32_t type; };
template<> struct dtype_dict<true, 3u> { typedef int64_t type; };
template<> struct dtype_dict<false, 0u> { typedef uint8_t type; };
template<> struct dtype_dict<false, 1u> { typedef uint16_t type; };
template<> struct dtype_dict<false, 2u> { typedef uint32_t type; };
template<> struct dtype_dict<false, 3u> { typedef uint64_t type; };

// this calculate the type to hold a num_bit integer
constexpr unsigned num_bit2dict_key(unsigned num_bit) {
	return (
		unsigned(num_bit > 8) +
		unsigned(num_bit > 16) +
		unsigned(num_bit > 32)
	);
}

constexpr unsigned num_bit2num_word(unsigned num_bit) {
	return (num_bit+63) / 64;
}

// These functions prevent implementation-defined specific behaviors in C standard
// Or make abstract if not easy to prevent

// _u_nsigned _s_hift _a_rith _r_ight
inline uint8_t usar(uint8_t a, unsigned b) { return uint8_t(int8_t(a) >> b); }
inline uint16_t usar(uint16_t a, unsigned b) { return uint16_t(int16_t(a) >> b); }
inline uint32_t usar(uint32_t a, unsigned b) { return uint32_t(int32_t(a) >> b); }
inline uint64_t usar(uint64_t a, unsigned b) { return uint64_t(int64_t(a) >> b); }

// to_signed
inline int8_t to_signed(uint8_t a) { return int8_t(a); }
inline int16_t to_signed(uint16_t a) { return int16_t(a); }
inline int32_t to_signed(uint32_t a) { return int32_t(a); }
inline int64_t to_signed(uint64_t a) { return int64_t(a); }

// shift n bits from hi to lo (two uint64_t)
// return lo
// 0 < n < 64
inline uint64_t shiftright128(uint64_t hi, uint64_t lo, unsigned n) {
	return (hi << (64-n)) | (lo >> n);
}

// shift n bits from lo to hi (two uint64_t)
// return hi
// 0 < n < 64
inline uint64_t shiftleft128(uint64_t hi, uint64_t lo, unsigned n) {
	return (hi << n) | (lo >> (64-n));
}

inline unsigned char addcarry64(uint64_t &out, uint64_t x, uint64_t y, unsigned char carry_in) {
	// Note: Impelemtnation-defined, modify me when necessary
	return _addcarry_u64(carry_in, x, y, reinterpret_cast<unsigned long long*>(&out));
}

inline unsigned char subborrow64(uint64_t &out, uint64_t x, uint64_t y, unsigned char carry_in) {
	// Note: Impelemtnation-defined, modify me when necessary
	return _subborrow_u64(carry_in, x, y, reinterpret_cast<unsigned long long*>(&out));
}

inline unsigned popcount64(uint64_t v) {
	// Note: Impelemtnation-defined, modify me when necessary
	return __builtin_popcountll(v);
}

inline void twos_complement64(uint64_t* v, unsigned num_word) {
	unsigned char carry = 1;
	for (unsigned i = 0; i < num_word; ++i) {
		carry = detail::addcarry64(v[i], uint64_t(~v[i]), uint64_t(0), carry);
	}
}

// This is not necessary a public API, but I put this here for testing
std::string SanitizeStringInteger_(const std::string_view s);
bool ParseStringAsU64(uint64_t* ptr, unsigned num_bit, unsigned base, const std::string_view s);
void MulWordU64(uint64_t* v, const uint64_t* rhs, unsigned num_word);

} // namespace verilog::detail
