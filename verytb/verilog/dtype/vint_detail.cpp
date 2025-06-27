// Direct include
#include "verilog/dtype/vint_detail.h"
// C system headers
// C++ standard library headers
#include <cctype>
#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>
// Other libraries' .h files.
#include <gmp.h>
// Your project's .h files.

using namespace std;

namespace verilog::detail {

// In this file, all uint64_t pointers passed to API are assumed to be LSB first.

// Remove non-alphanumeric and keep only the first minus sign if present
string SanitizeStringInteger_(const string_view s) {
	string result;
	result.reserve(s.size());

	bool keep_minus = true;
	for (char c: s) {
		if (isalnum(c) || (c == '-' && keep_minus)) {
			result.push_back(c);
			keep_minus = false;
		}
	}

	return result;
}

// Parse a string as an unsigned integer and store the result in ptr
bool ParseStringAsU64(uint64_t* ptr, unsigned num_bit, unsigned base, const string_view s) {
	if (ptr == nullptr || base < 2 || base > 62) {
		return false;
	}

	string str = SanitizeStringInteger_(s);
	if (s.empty()) {
		return false;
	}
	const bool is_negative = s[0] == '-';
	const unsigned num_word = (num_bit + 63) / 64;

	mpz_t value, truncated;
	mpz_init(value);
	mpz_init(truncated);
	if (mpz_set_str(value, str.c_str(), base) == 0) {
		// Truncate to num_bit bits
		mpz_fdiv_r_2exp(truncated, value, num_bit);
		// Export to U64 array
		memset(ptr, 0, num_word * sizeof(uint64_t));
		size_t count = 0;
		mpz_export(ptr, &count, -1, sizeof(uint64_t), 0, 0, value);
	}
	mpz_clear(truncated);
	mpz_clear(value);

	if (is_negative) {
		// If negative, convert to two's complement
		twos_complement64(ptr, num_word);
	}

	return true;
}

// Multi-word unsigned multiplication: v = v * rhs, result truncated to num_word words
void MulWordU64(uint64_t* v, const uint64_t* rhs, unsigned num_word) {
	mpz_t a, b, prod;
	mpz_init(a);
	mpz_init(b);
	mpz_init(prod);

	// Import v and rhs as big integers
	mpz_import(a, num_word, -1, sizeof(uint64_t), 0, 0, v);
	mpz_import(b, num_word, -1, sizeof(uint64_t), 0, 0, rhs);
	// Perform multiplication
	mpz_mul(prod, a, b);
	// Truncate to 64*num_word bits
	mpz_fdiv_r_2exp(prod, prod, 64 * num_word);
	// Export back to v
	memset(v, 0, num_word * sizeof(uint64_t));
	size_t count = 0;
	mpz_export(v, &count, -1, sizeof(uint64_t), 0, 0, prod);

	mpz_clear(prod);
	mpz_clear(b);
	mpz_clear(a);
}

} // namespace verilog::detail
