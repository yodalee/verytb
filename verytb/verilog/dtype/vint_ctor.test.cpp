// Direct include
#include "verilog/dtype/vint.h"
// C system headers
// C++ standard library headers
// Other libraries' .h files.
#include <gtest/gtest.h>
// Your project's .h files.
using namespace std;
using namespace verilog;

///////////////////////////
// InternalLayout tests the internal storage directly
// Normally user don't need to access the data in this way
///////////////////////////
template<template<unsigned> class IntTmpl>
void InternalLayoutTemplate() {
	IntTmpl<7> v7;
	v7.v[0] = 0x3fu;
	v7.ClearUnusedBits();
	EXPECT_EQ(v7.v[0], uint8_t(0x3fu));
	v7.v[0] = 0x7fu;
	v7.ClearUnusedBits();
	EXPECT_EQ(v7.v[0], uint8_t(0x7fu));
	v7.v[0] = -1;
	v7.ClearUnusedBits();
	EXPECT_EQ(v7.v[0], uint8_t(0x7fu));
	v7.v[0] = 0xffu;
	v7.ClearUnusedBits();
	EXPECT_EQ(v7.v[0], uint8_t(0x7fu));

	IntTmpl<8> v8;
	v8.v[0] = 0x7fu;
	v8.ClearUnusedBits();
	EXPECT_EQ(v8.v[0], uint8_t(0x7fu));
	v8.v[0] = -1;
	v8.ClearUnusedBits();
	EXPECT_EQ(v8.v[0], uint8_t(0xffu));
	v8.v[0] = 0xffu;
	v8.ClearUnusedBits();
	EXPECT_EQ(v8.v[0], uint8_t(0xffu));

	IntTmpl<10> v10;
	v10.v[0] = 0xf00u;
	v10.ClearUnusedBits();
	EXPECT_EQ(v10.v[0], uint16_t(0x300u));

	IntTmpl<31> v31;
	v31.v[0] = 0xf0000000u;
	v31.ClearUnusedBits();
	EXPECT_EQ(v31.v[0], uint32_t(0x70000000u));

	IntTmpl<33> v33;
	v33.v[0] = 0xf00000000llu;
	v33.ClearUnusedBits();
	EXPECT_EQ(v33.v[0], uint64_t(0x100000000llu));

	IntTmpl<127> v127;
	v127.v[0] = 0x0123456701234567llu;
	v127.v[1] = 0x3fffffffffffffffllu;
	v127.ClearUnusedBits();
	EXPECT_EQ(v127.v[0], uint64_t(0x0123456701234567llu));
	EXPECT_EQ(v127.v[1], uint64_t(0x3fffffffffffffffllu));
	v127.v[0] = 0x0123456701234567llu;
	v127.v[1] = 0xffffffffffffffffllu;
	v127.ClearUnusedBits();
	EXPECT_EQ(v127.v[0], uint64_t(0x0123456701234567llu));
	EXPECT_EQ(v127.v[1], uint64_t(0x7fffffffffffffffllu));

	IntTmpl<128> v128;
	v128.v[0] = 0x0123456701234567llu;
	v128.v[1] = 0xffffffffffffffffllu;
	v128.ClearUnusedBits();
	EXPECT_EQ(v128.v[0], uint64_t(0x0123456701234567llu));
	EXPECT_EQ(v128.v[1], uint64_t(0xffffffffffffffffllu));

	static_assert(is_same_v<typename decltype(v7)::stype, uint8_t>);
	static_assert(is_same_v<typename decltype(v8)::stype, uint8_t>);
	static_assert(is_same_v<typename decltype(v10)::stype, uint16_t>);
	static_assert(is_same_v<typename decltype(v31)::stype, uint32_t>);
	static_assert(is_same_v<typename decltype(v33)::stype, uint64_t>);
	static_assert(is_same_v<typename decltype(v127)::stype, uint64_t>);
	static_assert(is_same_v<typename decltype(v128)::stype, uint64_t>);
}

TEST(vint_ctor, internal_layout_uing) {
	InternalLayoutTemplate<vuint>();
}

TEST(vint_ctor, internal_layout_sint) {
	InternalLayoutTemplate<vsint>();
}

///////////////////////////
// Assign C types to vints
///////////////////////////
TEST(vint_ctor, assign_uint) {
	vuint<1> v1;
	vuint<63> v63;
	vuint<64> v64;
	vuint<65> v65;
	vuint<128> v128;
	v1 = 0;
	EXPECT_EQ(v1.v[0], 0);
	v1 = 1;
	EXPECT_EQ(v1.v[0], 1);

	v63 = 0;
	EXPECT_EQ(v63.v[0], 0);
	v63 = 1;
	EXPECT_EQ(v63.v[0], 1);
	v63 = -4;
	EXPECT_EQ(v63.v[0], -4llu<<1>>1);

	v64 = 0;
	EXPECT_EQ(v64.v[0], 0);
	v64 = 1;
	EXPECT_EQ(v64.v[0], 1);
	v64 = -4;
	EXPECT_EQ(v64.v[0], -4llu);

	v65 = 0;
	EXPECT_EQ(v65.v[0], 0);
	EXPECT_EQ(v65.v[1], 0);
	v65 = 1;
	EXPECT_EQ(v65.v[0], 1);
	EXPECT_EQ(v65.v[1], 0);
	v65 = -4;
	EXPECT_EQ(v65.v[0], -4llu);
	EXPECT_EQ(v65.v[1], 0);

	v128 = 0;
	EXPECT_EQ(v128.v[0], 0);
	EXPECT_EQ(v128.v[1], 0);
	v128 = 1;
	EXPECT_EQ(v128.v[0], 1);
	EXPECT_EQ(v128.v[1], 0);
	v128 = -4;
	EXPECT_EQ(v128.v[0], -4llu);
	EXPECT_EQ(v128.v[1], 0);
}

TEST(vint_ctor, assign_sint) {
	vsint<1> v1;
	vsint<63> v63;
	vsint<64> v64;
	vsint<65> v65;
	vsint<128> v128;
	v1 = 0;
	EXPECT_EQ(v1.v[0], 0);
	v1 = 1;
	EXPECT_EQ(v1.v[0], 1);

	v63 = 0;
	EXPECT_EQ(v63.v[0], 0);
	v63 = 1;
	EXPECT_EQ(v63.v[0], 1);
	v63 = -4;
	EXPECT_EQ(v63.v[0], -4llu<<1>>1);

	v64 = 0;
	EXPECT_EQ(v64.v[0], 0);
	v64 = 1;
	EXPECT_EQ(v64.v[0], 1);
	v64 = -4;
	EXPECT_EQ(v64.v[0], -4llu);

	v65 = 0;
	EXPECT_EQ(v65.v[0], 0);
	EXPECT_EQ(v65.v[1], 0);
	v65 = 1;
	EXPECT_EQ(v65.v[0], 1);
	EXPECT_EQ(v65.v[1], 0);
	v65 = -4;
	EXPECT_EQ(v65.v[0], -4llu);
	EXPECT_EQ(v65.v[1], 1);

	v128 = 0;
	EXPECT_EQ(v128.v[0], 0);
	EXPECT_EQ(v128.v[1], 0);
	v128 = 1;
	EXPECT_EQ(v128.v[0], 1);
	EXPECT_EQ(v128.v[1], 0);
	v128 = -4;
	EXPECT_EQ(v128.v[0], -4llu);
	EXPECT_EQ(v128.v[1], -1llu);
}

///////////////////////////
// Assign string to vints
// Note: more testcases using internal API are in vint_detail
///////////////////////////

template<template<unsigned> class IntTmpl>
void StringAssignTemplate() {
	IntTmpl<1> v1;
	IntTmpl<63> v63;
	IntTmpl<64> v64;
	IntTmpl<65> v65;
	IntTmpl<128> v128;
	v1.assign("0", 8);
	EXPECT_EQ(v1.v[0], 0);
	v1.assign("1", 8);
	EXPECT_EQ(v1.v[0], 1);

	v63.assign("0", 8);
	EXPECT_EQ(v63.v[0], 0);
	v63.assign("1", 8);
	EXPECT_EQ(v63.v[0], 1);
	v63.assign("-4", 8);
	EXPECT_EQ(v63.v[0], -4llu<<1>>1);

	v64.assign("0", 8);
	EXPECT_EQ(v64.v[0], 0);
	v64.assign("1", 8);
	EXPECT_EQ(v64.v[0], 1);
	v64.assign("-4", 8);
	EXPECT_EQ(v64.v[0], -4llu);

	v65.assign("0", 8);
	EXPECT_EQ(v65.v[0], 0);
	EXPECT_EQ(v65.v[1], 0);
	v65.assign("1", 8);
	EXPECT_EQ(v65.v[0], 1);
	EXPECT_EQ(v65.v[1], 0);
	v65.assign("-4", 8);
	EXPECT_EQ(v65.v[0], -4llu);
	EXPECT_EQ(v65.v[1], 1);
	v65.assign("f 0000 0000 0000 000f", 16);
	EXPECT_EQ(v65.v[0], 0xf);
	EXPECT_EQ(v65.v[1], 0x1);

	v128.assign("0", 8);
	EXPECT_EQ(v128.v[0], 0);
	EXPECT_EQ(v128.v[1], 0);
	v128.assign("1", 8);
	EXPECT_EQ(v128.v[0], 1);
	EXPECT_EQ(v128.v[1], 0);
	v128.assign("-4", 8);
	EXPECT_EQ(v128.v[0], -4llu);
	EXPECT_EQ(v128.v[1], -1llu);
	v128.assign("-1 0000 0000 0000 000f", 16);
	EXPECT_EQ(v128.v[0], 0xffff'ffff'ffff'fff1llu);
	EXPECT_EQ(v128.v[1], 0xffff'ffff'ffff'fffellu);
	v128.assign("1 0000 0000 0000 000f", 16);
	EXPECT_EQ(v128.v[0], 0xf);
	EXPECT_EQ(v128.v[1], 0x1);
}

TEST(vint_ctor, assign_uint_str) {
	StringAssignTemplate<vuint>();
}

TEST(vint_ctor, assign_sint_str) {
	StringAssignTemplate<vsint>();
}
