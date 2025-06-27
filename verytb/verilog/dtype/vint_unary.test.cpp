// Direct include
#include "verilog/dtype/vint.h"
#include "verilog/dtype/vint_unary_patterns.test.h"
// C system headers
// C++ standard library headers
// Other libraries' .h files.
#include <gtest/gtest.h>
// Your project's .h files.
using namespace std;
using namespace verilog;

///////////////////////////
// Test negate
///////////////////////////
template<template<unsigned> class IntTmpl>
void NegateTemplate() {
	auto Handle = [](const auto& pattern_entry) {
		constexpr unsigned num_bit = decltype(pattern_entry.second)::value;
		for (unsigned i = 0; i < pattern_entry.first.size(); ++i) {
			const NegatePattern &p = pattern_entry.first[i];

			IntTmpl<num_bit> v;
			ASSERT_EQ(v.num_word, p.value1.size()) ;
			ASSERT_EQ(v.num_word, p.value2.size()) << "(" << num_bit << "," << i << ") pattern format is incorrect";
			v.assign(p.value1);
			v.Negate();
			for (unsigned j = 0; j < v.num_word; ++j) {
				EXPECT_EQ(v.v[j], p.value2[j]) << "(" << num_bit << "," << i << "," << j << ") forward Negate() fails";
			}
			v.Negate();
			for (unsigned j = 0; j < v.num_word; ++j) {
				EXPECT_EQ(v.v[j], p.value1[j]) << "(" << num_bit << "," << i << "," << j << ") backward Negate() fails";
			}
		}
	};
	apply([&](const auto&... args) {
		(Handle(args), ...);
	}, pattern_negate);
}

TEST(vint_unary, Negate_uint) {
	NegateTemplate<vuint>();
}

TEST(vint_unary, Negate_sint) {
	NegateTemplate<vsint>();
}

///////////////////////////
// Test flip
///////////////////////////

template<template<unsigned> class IntTmpl>
void FlipTemplate() {
	auto Handle = [](const auto& pair) {
		constexpr unsigned num_bit = decltype(pair.second)::value;
		for (unsigned i = 0; i < pair.first.size(); ++i) {
			const FlipPattern &p = pair.first[i];

			IntTmpl<num_bit> v;
			ASSERT_EQ(v.num_word, p.value1.size()) ;
			ASSERT_EQ(v.num_word, p.value2.size()) << "(" << num_bit << "," << i << ") pattern format is incorrect";
			v.assign(p.value1);
			v.Flip();
			for (unsigned j = 0; j < v.num_word; ++j) {
				EXPECT_EQ(v.v[j], p.value2[j]) << "(" << num_bit << "," << i << "," << j << ") forward Flip() fails";
			}
			v.Flip();
			for (unsigned j = 0; j < v.num_word; ++j) {
				EXPECT_EQ(v.v[j], p.value1[j]) << "(" << num_bit << "," << i << "," << j << ") backward Flip() fails";
			}
		}
	};
	apply([&](const auto&... args) {
		(Handle(args), ...);
	}, pattern_flip);
}

TEST(vint_unary, Flip_uint) {
	FlipTemplate<vuint>();
}

TEST(vint_unary, Flip_sint) {
	FlipTemplate<vsint>();
}

///////////////////////////
// Test ReduceAnd
///////////////////////////

template<template<unsigned> class IntTmpl>
void ReduceAndTemplate() {
	auto Handle = [](const auto& pair) {
		constexpr unsigned num_bit = decltype(pair.second)::value;
		for (unsigned i = 0; i < pair.first.size(); ++i) {
			const ReduceAndPattern &p = pair.first[i];
			IntTmpl<num_bit> v;
			ASSERT_EQ(v.num_word, p.value.size());
			v.assign(p.value);
			EXPECT_EQ(bool(v.ReduceAnd()), p.result) << "(" << num_bit << "," << i << ") ReduceAnd fails";
		}
	};
	apply([&](const auto&... args) {
		(Handle(args), ...);
	}, pattern_reduceand);
}

TEST(vint_unary, ReduceAnd_uint) {
	ReduceAndTemplate<vuint>();
}

TEST(vint_unary, ReduceAnd_sint) {
	ReduceAndTemplate<vsint>();
}

///////////////////////////
// Test ReduceOr
///////////////////////////

template<template<unsigned> class IntTmpl>
void ReduceOrTemplate() {
	auto Handle = [](const auto& pair) {
		constexpr unsigned num_bit = decltype(pair.second)::value;
		for (unsigned i = 0; i < pair.first.size(); ++i) {
			const ReduceOrPattern &p = pair.first[i];
			IntTmpl<num_bit> v;
			ASSERT_EQ(v.num_word, p.value.size());
			v.assign(p.value);
			EXPECT_EQ(bool(v.ReduceOr()), p.result) << "(" << num_bit << "," << i << ") ReduceOr fails";
			EXPECT_EQ(bool(v), p.result) << "(" << num_bit << "," << i << ") operator bool() fails";
			EXPECT_EQ(not v, not p.result) << "(" << num_bit << "," << i << ") operator! fails";
		}
	};
	apply([&](const auto&... args) {
		(Handle(args), ...);
	}, pattern_reduceor);
}

TEST(vint_unary, ReduceOr_uint) {
	ReduceOrTemplate<vuint>();
}

TEST(vint_unary, ReduceOr_sint) {
	ReduceOrTemplate<vsint>();
}

///////////////////////////
// Test ReduceXor
///////////////////////////

template<template<unsigned> class IntTmpl>
void ReduceXorTemplate() {
	auto Handle = [](const auto& pair) {
		constexpr unsigned num_bit = decltype(pair.second)::value;
		for (unsigned i = 0; i < pair.first.size(); ++i) {
			const ReduceXorPattern &p = pair.first[i];
			IntTmpl<num_bit> v;
			ASSERT_EQ(v.num_word, p.value.size());
			v.assign(p.value);
			EXPECT_EQ(bool(v.ReduceXor()), p.result) << "(" << num_bit << "," << i << ") ReduceXor fails";
		}
	};
	apply([&](const auto&... args) {
		(Handle(args), ...);
	}, pattern_reducexor);
}

TEST(vint_unary, ReduceXor_uint) {
	ReduceXorTemplate<vuint>();
}

TEST(vint_unary, ReduceXor_sint) {
	ReduceXorTemplate<vsint>();
}
