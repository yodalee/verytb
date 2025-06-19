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

string SanitizeStringInteger_(const string_view s) {
	string result;
	result.reserve(s.size());

	bool keep_minus = true;
	for (char c: s) {
		if (isalnum(c) or c == '-' and keep_minus) {
			result.push_back(c);
			keep_minus = false;
		}
	}

	return result;
}

bool ParseStringAsU64(uint64_t* ptr, unsigned num_bit, unsigned base, const string_view s) {
	if (ptr == nullptr or base < 2 or base > 62) {
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
		// truncate to num_bit bits
		mpz_fdiv_r_2exp(truncated, value, num_bit);
		// export to U64
		memset(ptr, 0, num_word * sizeof(uint64_t));
		size_t count = 0;
		mpz_export(ptr, &count, -1, sizeof(uint64_t), 0, 0, value);
	}
	mpz_clear(truncated);
	mpz_clear(value);

	if (is_negative) {
		unsigned carry = 1u;
		for (unsigned i = 0; i < num_word; ++i) {
			ptr[i] = (~ptr[i]) + carry;
			if (ptr[i] != 0u) {
				carry = 0u;
			}
		}
	}

	return true;
}

} // namespace verilog::detail
