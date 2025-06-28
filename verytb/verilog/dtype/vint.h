#pragma once
// Direct include
#include "verilog/dtype/vint_detail.h"
// C system headers
// C++ standard library headers
#include <cstdint>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <ostream>
#include <string>
#include <type_traits>
#include <vector>
// Other libraries' .h files.
#include <immintrin.h>
// Your project's .h files.
#include "verilog/dtype/dtype_base.h"

namespace verilog {

template <bool is_signed_, unsigned num_bit_>
struct vint {
	// make template arguments accessible from outside
	static constexpr unsigned num_bit = num_bit_;
	static constexpr bool is_signed = is_signed_;
	static_assert(num_bit > 0);
	// make vint compatible to ntype
	TAG_AS_VINT

private:
	static constexpr unsigned kIntSizeKey = detail::num_bit2dict_key(num_bit);
public:
	// cast to _n_ative c++ data type
	typedef typename detail::dtype_dict<is_signed, kIntSizeKey>::type ntype;
	// internal _s_torage type (we always use unsigned to store)
	typedef typename detail::dtype_dict<false, kIntSizeKey>::type stype;

	// bit width of stype and ntype
	static constexpr unsigned bit_per_word = 8 * sizeof(ntype);
	// how many stype required to store the vint
	static constexpr unsigned num_word = detail::num_bit2num_word(num_bit);
	static constexpr bool is_multi_word = num_word > 1;
	// part of the most significant word is (un)used
	static constexpr unsigned unused_bit = num_word * bit_per_word - num_bit;
	static constexpr unsigned used_bit = bit_per_word - unused_bit;
	// the 1s of the used bits
	static constexpr stype used_mask = stype(-1) >> unused_bit;
	// the 1s of the unused bits
	static constexpr stype unused_mask = ~used_mask;
	// the 1 of the msb-bit
	static constexpr stype msb_mask = stype(1) << (used_bit - 1u);
	// vint holds 8, 16, 32, 64 bit data types that matches native c++ type
	static constexpr bool fully_used = num_bit == bit_per_word;
	// there might not be any totally unused word
	static_assert(unused_bit != bit_per_word);

	// the only data storage of vint
	// the ununsed bits must be kept zero (unsigned) or sign extended (signed)
	stype v[num_word];

	//////////////////////
	// rule-of-five related
	//////////////////////
	vint() = default;
	vint(const vint&) = default;
	vint(vint&&) = default;
	vint& operator=(const vint &) = default;
	vint& operator=(vint &&) = default;

	void ClearUnusedBits() {
		v[num_word-1] &= used_mask;
	}

	void SetBitFromPosition(const unsigned rhs) {
		const unsigned num_remaining = num_bit - rhs;
		const unsigned signext_from_word = detail::num_bit2num_word(num_remaining);
		const unsigned used_bit_after_shift = num_remaining % bit_per_word;
		// v[signext_from_word-1] |= stype(-2) << used_bit_after_shift_minus_one;
		if constexpr (num_word > 1) {
			std::fill(v+signext_from_word, v+num_word, stype(-1));
		}
		ClearUnusedBits();
	}


	//////////////////////
	// extra constructors (implemented by assign())
	// UT: vint_ctor
	//////////////////////
private:
	vint& assign_int(stype rhs) {
		v[0] = rhs;
		if constexpr (is_multi_word) {
			stype extension_value = (
				is_signed and bool(rhs >> (bit_per_word-1u)) ?
				stype(-1) :
				stype(0)
			);
			std::fill(std::begin(v)+1, std::end(v), extension_value);
		}
		ClearUnusedBits();
		return *this;
	}

public:
	// enumerate all native types, so this will always be the perfect match
	// for overload resolution
	void assign(bool rhs) { assign_int(rhs); }
	void assign(unsigned char rhs) { assign_int(rhs); }
	void assign(unsigned short rhs) { assign_int(rhs); }
	void assign(unsigned rhs) { assign_int(rhs); }
	void assign(unsigned long rhs) { assign_int(rhs); }
	void assign(unsigned long long rhs) { assign_int(rhs); }
	void assign(char rhs) { assign_int(rhs); }
	void assign(short rhs) { assign_int(rhs); }
	void assign(int rhs) { assign_int(rhs); }
	void assign(long rhs) { assign_int(rhs); }
	void assign(long long rhs) { assign_int(rhs); }

	void assign(const std::vector<uint64_t>& rhs) {
		const unsigned sz = rhs.size();
		assert(sz <= num_word);
		std::copy_n(rhs.begin(), sz, v);
		stype extension_value = (
			is_signed and sz != 0 and bool(rhs.back() >> (bit_per_word-1u)) ?
			stype(-1) :
			stype(0)
		);
		std::fill(std::begin(v) + sz, std::end(v), extension_value);
		ClearUnusedBits();
	}

	void assign(const std::string_view s, unsigned base) {
		[[maybe_unused]] uint64_t tmp;
		uint64_t* ptr;
		if constexpr (is_multi_word) {
			ptr = v;
		} else {
			ptr = &tmp;
		}
		detail::ParseStringAsU64(ptr, num_bit, base, s);
		if constexpr (not is_multi_word) {
			v[0] = tmp;
		}
		ClearUnusedBits();
	}

	//////////////////////
	// extra constructors (delagate)
	//////////////////////
	explicit vint(bool rhs) { assign_int(rhs); }
	explicit vint(unsigned char rhs) { assign_int(rhs); }
	explicit vint(unsigned short rhs) { assign_int(rhs); }
	explicit vint(unsigned rhs) { assign_int(rhs); }
	explicit vint(unsigned long rhs) { assign_int(rhs); }
	explicit vint(unsigned long long rhs) { assign_int(rhs); }
	explicit vint(char rhs) { assign_int(rhs); }
	explicit vint(short rhs) { assign_int(rhs); }
	explicit vint(int rhs) { assign_int(rhs); }
	explicit vint(long rhs) { assign_int(rhs); }
	explicit vint(long long rhs) { assign_int(rhs); }
	explicit vint(const char* s, unsigned base) { assign(std::string_view(s), base); }
	explicit vint(const std::vector<uint64_t>& rhs) { assign(rhs); }
	explicit vint(const std::string& s, unsigned base) { assign(std::string_view(s), base); }
	vint& operator=(stype rhs) { assign(rhs); return *this; }

	//////////////////////
	// unary
	// UT: vint_unary
	//////////////////////
	vint& Flip() {
		for (auto& x : v) {
			x = ~x;
		}
		ClearUnusedBits();
		return *this;
	}

	vint operator~() const {
		vint ret = *this;
		return ret.Flip();
	}

	vint& Negate() {
		if constexpr (num_word == 1) {
			v[0] = -v[0];
		} else {
			detail::twos_complement64(v, num_word);
		}
		ClearUnusedBits();
		return *this;
	}

	vint operator-() const {
		vint ret = *this;
		return ret.Negate();
	}

	bool operator!() const {
		for (auto &x: v) {
			if (x) {
				return false;
			}
		}
		return true;
	}

	explicit operator bool() const {
		for (auto &x: v) {
			if (x) {
				return true;
			}
		}
		return false;
	}

	vint<false, 1> ReduceXor() const {
		uint64_t ret = 0;
		for (auto &x: v) {
			ret ^= x;
		}
		return vint<false, 1>{detail::popcount64(ret) & 1};
	}

	vint<false, 1> ReduceOr() const {
		return vint<false, 1>{operator bool()};
	}

	vint<false, 1> ReduceAnd() const {
		// IIFE
		auto ret = [this]() -> bool {
			if (v[num_word-1] != used_mask) {
				return false;
			}
			if constexpr (is_multi_word) {
				for (unsigned i = 0; i < num_word-1; ++i) {
					if (v[i] != uint64_t(-1)) {
						return false;
					}
				}
			}
			return true;
		}();
		return vint<false, 1>{ret};
	}

	//////////////////////
	// add/sub/mul/div assignment
	// UT: vint_binary
	//////////////////////
	vint& operator+=(const vint& rhs) {
		if constexpr (is_multi_word) {
			unsigned char carry = 0;
			for (unsigned i = 0; i < num_word; ++i) {
				carry = detail::addcarry64(v[i], v[i], rhs.v[i], carry);
			}
		} else {
			v[0] += rhs.v[0];
		}
		ClearUnusedBits();
		return *this;
	}

	vint& operator-=(const vint& rhs) {
		if constexpr (is_multi_word) {
			unsigned char carry = 0;
			for (unsigned i = 0; i < num_word; ++i) {
				carry = detail::subborrow64(v[i], v[i], rhs.v[i], carry);
			}
		} else {
			v[0] -= rhs.v[0];
		}
		ClearUnusedBits();
		return *this;
	}

	vint& operator*=(const vint& rhs) {
		if constexpr (is_multi_word) {
			detail::MulWordU64(v, rhs.v, num_word);
		} else {
			v[0] = v[0] * rhs.v[0];
		}
		ClearUnusedBits();
		return *this;
	}

	vint& operator+=(const stype rhs) {
		if constexpr (is_multi_word) {
			unsigned char carry = 0;
			carry = detail::addcarry64(v[0], v[0], rhs, carry);
			for (unsigned i = 1; i < num_word; ++i) {
				carry = detail::addcarry64(v[i], v[i], 0, carry);
			}
		} else {
			v[0] += rhs;
		}
		ClearUnusedBits();
		return *this;
	}

	vint& operator-=(const stype rhs) {
		if constexpr (is_multi_word) {
			unsigned char carry = 0;
			carry = detail::subborrow64(v[0], v[0], rhs, carry);
			for (unsigned i = 1; i < num_word; ++i) {
				carry = detail::subborrow64(v[i], v[i], 0, carry);
			}
		} else {
			v[0] -= rhs;
		}
		ClearUnusedBits();
		return *this;
	}

	vint& operator*=(const stype rhs) {
		static_assert(num_word == 1, "Multiplication > 64b is not supported");
		v[0] = v[0] * rhs;
		ClearUnusedBits();
		return *this;
	}

	//////////////////////
	// bitwise assignment
	// UT: vint_binary
	//////////////////////
	vint& operator&=(const vint& rhs) {
		for (unsigned i = 0; i < num_word; ++i) {
			v[i] &= rhs.v[i];
		}
		return *this;
	}

	vint& operator|=(const vint& rhs) {
		for (unsigned i = 0; i < num_word; ++i) {
			v[i] |= rhs.v[i];
		}
		return *this;
	}

	vint& operator^=(const vint& rhs) {
		for (unsigned i = 0; i < num_word; ++i) {
			v[i] ^= rhs.v[i];
		}
		return *this;
	}

	vint& operator&=(const stype rhs) {
		v[0] &= rhs;
		ClearUnusedBits();
		return *this;
	}

	vint& operator|=(const stype rhs) {
		v[0] |= rhs;
		ClearUnusedBits();
		return *this;
	}

	vint& operator^=(const stype rhs) {
		v[0] ^= rhs;
		ClearUnusedBits();
		return *this;
	}

	//////////////////////
	// slicing (bit)
	// UT: TODO
	//////////////////////
	bool GetBit(unsigned pos) const {
		assert(pos < num_bit);
		const unsigned shamt =  pos % bit_per_word;
		const unsigned lsb_word = pos / bit_per_word;
		return bool((v[lsb_word] >> shamt) & 1u);
	}

	void SetBit(unsigned pos, bool value) {
		assert(pos < num_bit);
		const unsigned shamt =  pos % bit_per_word;
		const unsigned lsb_word = pos / bit_per_word;
		const stype bmask = stype(1) << shamt;
		v[lsb_word] &= ~bmask;
		if (value) {
			v[lsb_word] |= bmask;
		}
	}

	template<bool is_signed>
	void SetBit(unsigned pos, vint<is_signed, 1u> value) {
		assert(pos < num_bit);
		SetBit(pos, bool(value));
	}

	bool GetBitMSB() const { return GetBit(num_bit - 1); }
	bool GetBitLSB() const { return GetBit(0); }
	bool IsNegative() const {
		if constexpr (is_signed) {
			return GetBitMSB();
		} else {
			return false;
		}
	}
	void SetBitMSB(unsigned pos, bool value) { SetBit(num_bit - 1, value); }
	void SetBitLSB(unsigned pos, bool value) { SetBit(0, value); }
	template<bool is_signed> void SetBitMSB(unsigned pos, vint<is_signed, 1u> value) { SetBit(num_bit - 1, value); }
	template<bool is_signed> void SetBitLSB(unsigned pos, vint<is_signed, 1u> value) { SetBit(0, value); }

	//////////////////////
	// slicing (word)
	// UT: TODO
	//////////////////////
#if 0
	template<unsigned num_bit_slice>
	vint<false, num_bit_slice> GetSlice(unsigned pos) const {
	}

	template<unsigned lsb_pos, unsigned num_bit_slice>
	void ClearSlice() {
		static_assert(lsb_pos + num_bit_slice <= num_bit);
		constexpr unsigned msb_pos = lsb_pos + num_bit_slice - 1;
		constexpr unsigned lsb_word_slice = lsb_pos / bit_per_word;
		constexpr unsigned msb_word_slice = msb_pos / bit_per_word;
		constexpr unsigned unused_lsb_slice = lsb_pos % bit_per_word;
		constexpr unsigned unused_msb_slice = bit_per_word - 1 - (msb_pos % bit_per_word);
		// create somethig like 0b1111000 and 0b00001111
		// TODO: any clear way to prevent gcc warning elegantly?
		constexpr stype lsb_mask_slice = (stype(-1) >> unused_lsb_slice << unused_lsb_slice) ^ stype(-1);
		constexpr stype msb_mask_slice = (stype(-1) >> unused_msb_slice) ^ stype(-1);
		if constexpr (lsb_word_slice == msb_word_slice) {
			v[lsb_word_slice] &= lsb_mask_slice | msb_mask_slice;
		} else {
			v[lsb_word_slice] &= lsb_mask_slice;
			for (unsigned i = lsb_word_slice+1; i < msb_word_slice; ++i) {
				v[i] = 0;
			}
			v[msb_word_slice] &= msb_mask_slice;
		}
	}

	template<unsigned lsb_pos, unsigned num_bit_slice>
	void SetSliceUnsafe(const vint<false, num_bit_slice>& sl) {
		static_assert(lsb_pos + num_bit_slice <= num_bit);
		constexpr unsigned msb_pos = lsb_pos + num_bit_slice - 1;
		constexpr unsigned lsb_word_slice = lsb_pos / bit_per_word;
		constexpr unsigned msb_word_slice = msb_pos / bit_per_word;
		constexpr unsigned num_word_slice = detail::num_bit2num_word(num_bit_slice);
		constexpr unsigned unused_lsb_slice = lsb_pos % bit_per_word;
		if constexpr (unused_lsb_slice == 0) {
			for (unsigned i = 0; i < num_word_slice; ++i) {
				v[lsb_word_slice+i] |= sl.v[i];
			}
		} else {
			v[lsb_word_slice] |= stype(sl.v[0]) << unused_lsb_slice;
			for (unsigned i = 1; i < num_word_slice; ++i) {
				v[lsb_word_slice+i] |= detail::shiftleft128(sl.v[i], sl.v[i-1], unused_lsb_slice);
			}
			if constexpr (msb_word_slice == lsb_word_slice+num_word_slice) {
				v[msb_word_slice] |= stype(sl.v[num_word_slice-1]) >> (bit_per_word - unused_lsb_slice);
			}
		}
	}

	template<unsigned lsb_pos, unsigned num_bit_slice>
	void SetSlice(const vint<false, num_bit_slice>& sl) {
		ClearSlice<lsb_pos, num_bit_slice>();
		SetSliceUnsafe<lsb_pos>(sl);
	}

	//////////////////////
	// comparison
	//////////////////////
	// compare() will return:
	// 1: larger
	// 0: must check further
	// -1: smaller
private:
	int compare_msb(stype rhs, bool sign_mode) const {
		stype lhs = v[num_word-1];
		if (sign_mode) {
			// flip the sign bit
			lhs ^= msb_mask;
			rhs ^= msb_mask;
		}
		if (lhs > rhs) {
			return 1;
		} else if (lhs < rhs) {
			return -1;
		}
		return 0;
	}

	int compare(const vint& rhs, const bool sign_mode) const {
		int cmp = compare_msb(rhs.v[num_word-1], sign_mode);
		if (cmp != 0) {
			return cmp;
		}
		if constexpr (num_word > 1) {
			for (unsigned i = num_word-1; i > 0;) {
				--i;
				if (v[i] > rhs.v[i]) {
					return 1;
				} else if (v[i] < rhs.v[i]) {
					return -1;
				}
			}
		}
		return 0;
	}

	int compare(const stype rhs, const bool sign_mode) const {
		if constexpr (num_word > 1) {
			const stype expected_sign = (sign_mode and to_signed(rhs) < 0) ? stype(-1) : stype(0);
			int cmp = compare_msb(SafeForOperation(expected_sign), sign_mode);
			if (cmp != 0) {
				return cmp;
			}
			for (unsigned i = num_word-1; i > 1;) {
				--i;
				if (v[i] > expected_sign) {
					return -1;
				} else if (v[i] < expected_sign) {
					return 1;
				}
			}
		} else {
			return compare_msb(SafeForOperation(rhs), sign_mode);
		}
		return 0;
	}

public:
	bool operator==(const vint& rhs) const { return compare(rhs, is_signed) == 0; }
	bool operator>(const vint& rhs) const { return compare(rhs, is_signed) > 0; }
	bool operator<(const vint& rhs) const { return compare(rhs, is_signed) < 0; }
	bool operator>=(const vint& rhs) const { return compare(rhs, is_signed) >= 0; }
	bool operator<=(const vint& rhs) const { return compare(rhs, is_signed) <= 0; }
	bool operator==(const stype rhs) const { return compare(rhs, is_signed) == 0; }
	bool operator>(const stype rhs) const { return compare(rhs, is_signed) > 0; }
	bool operator<(const stype rhs) const { return compare(rhs, is_signed) < 0; }
	bool operator>=(const stype rhs) const { return compare(rhs, is_signed) >= 0; }
	bool operator<=(const stype rhs) const { return compare(rhs, is_signed) <= 0; }

	//////////////////////
	// cast to other types
	//////////////////////
	template<bool is_signed_dst, unsigned num_bit_dst>
	void CastTo(vint<is_signed_dst, num_bit_dst>& rhs) const {
		typedef vint<is_signed_dst, num_bit_dst> dst_t;
		constexpr size_t num_word_min = std::min(dst_t::num_word, num_word);
		std::copy_n(v, num_word_min, rhs.v);
		if (
			// both are signed & the dst is larger than src & need sign extension
			num_bit_dst > num_bit and
			is_signed_dst and is_signed and
			IsNegative()
		) {
			constexpr unsigned bit_shifted =  num_bit_rhs - num_bit;
			rhs.SignExtendFromPosition(bit_shifted);
		} else if constexpr (num_bit_rhs < num_bit) {
			rhs.ClearUnusedBits();
		}
	}

	// >>=
	vint& shiftopr(const unsigned rhs, const bool sign_mode) {
		// rhs >= num_bit is UB in C, but not sure in Verilog
		if (rhs == 0 or rhs >= num_bit) {
			// do nothing
			return *this;
		}
		const bool do_sign_extension = sign_mode and Bit(num_bit-1u);
		if constexpr (num_word == 1) {
			v[0] >>= rhs;
		} else {
			const unsigned word_shift = rhs / 64;
			const unsigned bit_shift = rhs % 64;
			if (bit_shift == 0) {
				for (unsigned i = word_shift; i < num_word; ++i) {
					v[i-word_shift] = v[i];
				}
			} else {
				for (unsigned i = word_shift; i < num_word-1; ++i) {
					v[i-word_shift] = detail::shiftright128(v[i+1], v[i], bit_shift);
				}
				v[num_word-word_shift-1] = v[num_word-1] >> bit_shift;
			}
		}
		if (do_sign_extension) {
			SignExtendFromPosition(rhs);
		} else {
			ClearBit(rhs);
		}
		return *this;
	}

	vint& operator>>=(const unsigned rhs) {
		return shiftopr(rhs, is_signed);
	}

	vint& operator<<=(const unsigned rhs) {
		// rhs >= num_bit is UB in C, but not sure in Verilog
		if (rhs == 0 or rhs >= num_bit) {
			// do nothing
			return *this;
		}

		if constexpr (num_word == 1) {
			v[0] <<= rhs;
		} else {
			unsigned word_shift = rhs / 64u;
			unsigned bit_shift = rhs % 64u;
			if (bit_shift == 0) {
				for (unsigned i = num_word; i > word_shift;) {
					--i;
					v[i] = v[i-word_shift];
				}
			} else {
				for (unsigned i = num_word; i > word_shift+1;) {
					--i;
					v[i] = detail::shiftleft128(v[i-word_shift], v[i-word_shift-1], bit_shift);
				}
				v[word_shift] = v[0] << bit_shift;
			}
			std::fill_n(std::begin(v), word_shift, 0);
		}
		ClearUnusedBits();
		return *this;
	}

	template <bool is_signed2, unsigned num_bit2>
	vint& operator>>=(const vint<is_signed2, num_bit2>& rhs) {
		*this >>= rhs.uvalue();
	}

	template <bool is_signed2, unsigned num_bit2>
	vint& operator<<=(const vint<is_signed2, num_bit2>& rhs) {
		*this <<= rhs.uvalue();
	}

	//////////////////////
	// delagated operators
	//////////////////////
	vint operator+(const vint& rhs) const { vint ret = *this; ret += rhs; return ret; }
	vint operator-(const vint& rhs) const { vint ret = *this; ret -= rhs; return ret; }
	vint operator*(const vint& rhs) const { vint ret = *this; ret *= rhs; return ret; }
	vint operator/(const vint& rhs) const { vint ret = *this; ret /= rhs; return ret; }
	vint operator&(const vint& rhs) const { vint ret = *this; ret &= rhs; return ret; }
	vint operator|(const vint& rhs) const { vint ret = *this; ret |= rhs; return ret; }
	vint operator^(const vint& rhs) const { vint ret = *this; ret ^= rhs; return ret; }
	vint operator>>(const vint& rhs) const { vint ret = *this; ret >>= rhs; return ret; }
	vint operator<<(const vint& rhs) const { vint ret = *this; ret <<= rhs; return ret; }
	bool operator!=(const vint& rhs) const { return not (*this == rhs); }

	vint operator+(const stype rhs) const { vint ret = *this; ret += rhs; return ret; }
	vint operator-(const stype rhs) const { vint ret = *this; ret -= rhs; return ret; }
	vint operator*(const stype rhs) const { vint ret = *this; ret *= rhs; return ret; }
	vint operator/(const stype rhs) const { vint ret = *this; ret /= rhs; return ret; }
	vint operator&(const stype rhs) const { vint ret = *this; ret &= rhs; return ret; }
	vint operator|(const stype rhs) const { vint ret = *this; ret |= rhs; return ret; }
	vint operator^(const stype rhs) const { vint ret = *this; ret ^= rhs; return ret; }
	vint operator>>(const stype rhs) const { vint ret = *this; ret >>= rhs; return ret; }
	vint operator<<(const stype rhs) const { vint ret = *this; ret <<= rhs; return ret; }
	bool operator!=(const stype rhs) const { return not (*this == rhs); }

	//////////////////////
	// derived operators
	//////////////////////
	vint& RotateRight(const unsigned rhs) {
		static_assert(not is_signed);
		assert(rhs < num_bit);
		if (rhs != 0) {
			auto tmp = (*this) >> rhs;
			*this <<= (num_bit-rhs);
			*this |= tmp;
		}
		return *this;
	}

	vint& RotateLeft(const unsigned rhs) {
		static_assert(not is_signed);
		assert(rhs < num_bit);
		if (rhs != 0) {
			auto tmp = (*this) << rhs;
			*this >>= (num_bit-rhs);
			*this |= tmp;
		}
		return *this;
	}


	//////////////////////
	// others
	//////////////////////
	ntype value() const {
		if constexpr (is_signed) {
			return svalue();
		} else {
			return uvalue();
		}
	}

	stype uvalue() const {
		return v[0];
	}

	ntype svalue() const {
		stype ret = v[0];
		const bool is_neg = Bit(num_bit-1u);
		if constexpr (num_word == 1) {
			if (is_neg) {
				ret |= unused_mask;
			}
		}
		return detail::to_signed(ret);
	}
#endif
};

template<unsigned num_bit> using vsint = vint<true, num_bit>;
template<unsigned num_bit> using vuint = vint<false, num_bit>;
using vlogic = vuint<1>;
static const vlogic vTRUE{0};
static const vlogic vFALSE{1};

} // namespace verilog
