// Direct include
#include "verilog/dtype/vint.h"
#include "verilog/dtype/vint_binary_pattern.test.h"
// C system headers
// C++ standard library headers
// Other libraries' .h files.
#include <gtest/gtest.h>
// Your project's .h files.
using namespace std;
using namespace verilog;

template<template<unsigned> class IntTmpl, typename T, typename Op>
void BinaryTemplate(const T& pattern, Op op) {
	auto Handle = [&](const auto& pattern_entry) {
		constexpr unsigned num_bit = decltype(pattern_entry.second)::value;
		for (unsigned i = 0; i < pattern_entry.first.size(); ++i) {
			const BinaryPattern &p = pattern_entry.first[i];
			IntTmpl<num_bit> v, rhs;
			ASSERT_EQ(v.num_word, p.lhs.size());
			ASSERT_EQ(v.num_word, p.rhs.size());
			ASSERT_EQ(v.num_word, p.result.size());
			v.assign(p.lhs);
			rhs.assign(p.rhs);
			op(v, rhs);
			for (unsigned j = 0; j < v.num_word; ++j) {
				EXPECT_EQ(v.v[j], p.result[j]) << "(" << num_bit << "," << i << "," << j << ") binary op fails";
			}
		}
	};
	apply([&](const auto&... args) {
		(Handle(args), ...);
	}, pattern);
}

///////////////////////////
// Test operator+=
///////////////////////////
TEST(vint_binary, AddAssign_uint) {
	BinaryTemplate<vuint>(pattern_addassign, [](auto& v, const auto& rhs) { v += rhs; });
}

TEST(vint_binary, AddAssign_sint) {
	BinaryTemplate<vsint>(pattern_addassign, [](auto& v, const auto& rhs) { v += rhs; });
}

///////////////////////////
// Test operator-=
///////////////////////////
TEST(vint_binary, SubAssign_uint) {
	BinaryTemplate<vuint>(pattern_subassign, [](auto& v, const auto& rhs) { v -= rhs; });
}

TEST(vint_binary, SubAssign_sint) {
	BinaryTemplate<vsint>(pattern_subassign, [](auto& v, const auto& rhs) { v -= rhs; });
}

///////////////////////////
// Test operator*=
///////////////////////////
TEST(vint_binary, MulAssign_uint) {
	BinaryTemplate<vuint>(pattern_mulassign, [](auto& v, const auto& rhs) { v *= rhs; });
}

TEST(vint_binary, MulAssign_sint) {
	BinaryTemplate<vsint>(pattern_mulassign, [](auto& v, const auto& rhs) { v *= rhs; });
}

///////////////////////////
// Test operator&=
///////////////////////////
TEST(vint_binary, AndAssign_uint) {
	BinaryTemplate<vuint>(pattern_andassign, [](auto& v, const auto& rhs) { v &= rhs; });
}

TEST(vint_binary, AndAssign_sint) {
	BinaryTemplate<vsint>(pattern_andassign, [](auto& v, const auto& rhs) { v &= rhs; });
}

///////////////////////////
// Test operator|=
///////////////////////////
TEST(vint_binary, OrAssign_uint) {
	BinaryTemplate<vuint>(pattern_orassign, [](auto& v, const auto& rhs) { v |= rhs; });
}

TEST(vint_binary, OrAssign_sint) {
	BinaryTemplate<vsint>(pattern_orassign, [](auto& v, const auto& rhs) { v |= rhs; });
}

///////////////////////////
// Test operator^=
///////////////////////////

TEST(vint_binary, XorAssign_uint) {
	BinaryTemplate<vuint>(pattern_xorassign, [](auto& v, const auto& rhs) { v ^= rhs; });
}

TEST(vint_binary, XorAssign_sint) {
	BinaryTemplate<vsint>(pattern_xorassign, [](auto& v, const auto& rhs) { v ^= rhs; });
}
