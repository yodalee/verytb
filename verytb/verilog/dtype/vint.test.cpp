// Direct include
#include "verilog/dtype/vint.h"
// C system headers
// C++ standard library headers
// Other libraries' .h files.
#include <gtest/gtest.h>
// Your project's .h files.
using namespace std;
using namespace verilog;

#if 0
///////////////////////////
// Test to C++ native type conversion
// namely value, uvalue, svalue
///////////////////////////
TEST(TestVerilogUnsigned, DISABLED_Value) {
}

TEST(TestVerilogSigned, DISABLED_Value) {
}


///////////////////////////
// Test to hex conversion
///////////////////////////
template<template<unsigned> class IntTmpl>
void ToHexTemplate() {
	IntTmpl<8> v8;
	v8.v[0] = 0x2a;
	v8.ClearUnusedBits();
	EXPECT_EQ(to_hex(v8), "2A");

	v8.v[0] = 0;
	EXPECT_EQ(to_hex(v8), "0");
	EXPECT_EQ(to_hex(v8, true), "00");

	IntTmpl<13> v13;
	v13.v[0] = 0x1a2a;
	v13.ClearUnusedBits();
	EXPECT_EQ(to_hex(v13), "1A2A");

	// Test prefix zero
	IntTmpl<16> v16;
	v16.v[0] = 0xa2a;
	EXPECT_EQ(to_hex(v16), "A2A");
	EXPECT_EQ(to_hex(v16, true), "0A2A");

	IntTmpl<66> v66;
	v66.v[1] = 0x2;
	v66.v[0] = 0x0123456789abcdefllu;
	v66.ClearUnusedBits();
	EXPECT_EQ(to_hex(v66), "20123456789ABCDEF");

	IntTmpl<90> v90;
	v90.v[1] = 0xfllu;
	v90.v[0] = 0x5566556612345678llu;
	v90.ClearUnusedBits();
	EXPECT_EQ(to_hex(v90), "F5566556612345678");
}

TEST(TestVerilogUnsigned, ToHex) {
	ToHexTemplate<vuint>();
}

TEST(TestVerilogSigned, ToHex) {
	ToHexTemplate<vsint>();
}

///////////////////////////
// Test comparison
// NOTE: This test is more difficult than others, it mixes more arith, assign...
///////////////////////////
template<template<unsigned> class IntTmpl>
void CompareTemplate() {
	IntTmpl<7> a7, b7;
	constexpr unsigned is_signed = decltype(a7)::is_signed;

	a7 = 7;
	b7 = 8;
	EXPECT_LE(a7, b7);
	EXPECT_LT(a7, b7);
	EXPECT_GT(b7, a7);
	EXPECT_GE(b7, a7);
	EXPECT_NE(a7, b7);
	EXPECT_GE(a7, 6);
	EXPECT_GT(a7, 6);
	EXPECT_LE(a7, 8);
	EXPECT_LT(a7, 8);
	if constexpr (is_signed) {
		EXPECT_GE(a7, -1);
		EXPECT_GT(a7, -1);
	} else {
		EXPECT_LE(a7, -1);
		EXPECT_LT(a7, -1);
	}

	a7 = -1;
	b7 = -1;
	EXPECT_EQ(a7, b7);
	EXPECT_EQ(a7, -1);
	EXPECT_EQ(b7, -1);
	b7 *= 2;
	EXPECT_LE(b7, -2);
	EXPECT_GE(b7, -2);
	EXPECT_EQ(b7, -2);
	EXPECT_NE(a7, b7);
	// signed: -3 < -2 < -1 < 0 < 3
	// unsigned: while -3(61) < -2(62) < -1(63), -1(63) > 3(3)
	EXPECT_LT(b7, -1);
	EXPECT_LE(b7, -1);
	EXPECT_GT(b7, -3);
	EXPECT_GE(b7, -3);
	if constexpr (is_signed) {
		EXPECT_LT(b7, 0);
		EXPECT_LE(b7, 0);
		EXPECT_LT(b7, 3);
		EXPECT_LE(b7, 3);
	} else {
		EXPECT_GT(b7, 0);
		EXPECT_GE(b7, 0);
		EXPECT_GT(b7, 3);
		EXPECT_GE(b7, 3);
	}
}

TEST(TestVerilogUnsigned, Compare) {
	CompareTemplate<vuint>();
}

TEST(TestVerilogSigned, Compare) {
	CompareTemplate<vsint>();
}

///////////////////////////
// Test bit read/write
///////////////////////////
template<template<unsigned> class IntTmpl>
void BitReadTemplate() {
	IntTmpl<13> v13;
	IntTmpl<127> v127;
	v13.v[0] = 0x123;
	v127.v[1] = 0xa;
	v127.v[0] = 0x5;
	v13.ClearUnusedBits();
	v127.ClearUnusedBits();
	EXPECT_TRUE(v13.Bit(0));
	EXPECT_FALSE(v13.Bit(2));
	EXPECT_FALSE(v13.Bit(12));
	EXPECT_TRUE(v127.Bit(2));
	EXPECT_FALSE(v127.Bit(3));
	EXPECT_FALSE(v127.Bit(64));
	EXPECT_TRUE(v127.Bit(65));
}

TEST(TestVerilogUnsigned, BitRead) {
	BitReadTemplate<vuint>();
}

TEST(TestVerilogSigned, BitRead) {
	BitReadTemplate<vsint>();
}

template<template<unsigned> class IntTmpl>
void BitWriteTemplate() {
	IntTmpl<13> v13;
	IntTmpl<127> v127;
	v13.v[0] = 0xf;
	v127.v[1] = 0xf0;
	v127.v[0] = 0xf;
	v13.ClearUnusedBits();
	v127.ClearUnusedBits();

	v13.SetBit(0, false);
	EXPECT_EQ(v13, 0x0e);
	v13.SetBit(4, true);
	EXPECT_EQ(v13, 0x1e);
	v13.SetBit(0, true);
	EXPECT_EQ(v13, 0x1f);
	v13.SetBit(3, false);
	EXPECT_EQ(v13, 0x17);
	v13.SetBit(4, true);
	EXPECT_EQ(v13, 0x17);

	v127.SetBit(4, false);
	EXPECT_EQ(v127.v[1], 0xf0);
	EXPECT_EQ(v127.v[0], 0xf);
	v127.SetBit(4, true);
	EXPECT_EQ(v127.v[1], 0xf0);
	EXPECT_EQ(v127.v[0], 0x1f);
	v127.SetBit(64, true);
	EXPECT_EQ(v127.v[1], 0xf1);
	EXPECT_EQ(v127.v[0], 0x1f);
	v127.SetBit(71, false);
	EXPECT_EQ(v127.v[1], 0x71);
	EXPECT_EQ(v127.v[0], 0x1f);
	v127.SetBit(3, false);
	EXPECT_EQ(v127.v[1], 0x71);
	EXPECT_EQ(v127.v[0], 0x17);
}

TEST(TestVerilogUnsigned, BitWrite) {
	BitWriteTemplate<vuint>();
}

TEST(TestVerilogSigned, BitWrite) {
	BitWriteTemplate<vsint>();
}

///////////////////////////
// Test slice read/write
///////////////////////////
template<template<unsigned> class IntTmpl>
void SliceReadTemplate() {
	IntTmpl<33> v33;
	IntTmpl<188> v188;
	v33.v[0] = 0x123456789llu;
	v188.v[2] = 0x0765432187654321llu;
	v188.v[1] = 0xabcdabcdabcdabcdllu;
	v188.v[0] = 0x1234567812345678llu;

	{
		vuint<20> tmp;
		tmp = v33.template Slice<0, 20>();
		EXPECT_EQ(tmp, 0x56789);
		tmp = v33.template Slice<4, 20>();
		EXPECT_EQ(tmp, 0x45678);
		tmp = v188.template Slice<64, 20>();
		EXPECT_EQ(tmp, 0xdabcd);
		tmp = v188.template Slice<72, 20>();
		EXPECT_EQ(tmp, 0xbcdab);
		tmp = v188.template Slice<124, 20>();
		EXPECT_EQ(tmp, 0x4321a);
		tmp = v188.template Slice<132, 20>();
		EXPECT_EQ(tmp, 0x65432);
		tmp = v188.template Slice<168, 20>();
		EXPECT_EQ(tmp, 0x76543u);
	}
	{
		vuint<100> tmp;
		tmp = v188.template Slice<0, 100>();
		EXPECT_EQ(tmp.v[1], 0xdabcdabcdllu);
		EXPECT_EQ(tmp.v[0], 0x1234567812345678llu);
		tmp = v188.template Slice<8, 100>();
		EXPECT_EQ(tmp.v[1], 0xbcdabcdabllu);
		EXPECT_EQ(tmp.v[0], 0xcd12345678123456llu);
		tmp = v188.template Slice<56, 100>();
		EXPECT_EQ(tmp.v[1], 0x7654321abllu);
		EXPECT_EQ(tmp.v[0], 0xcdabcdabcdabcd12llu);
		tmp = v188.template Slice<64, 100>();
		EXPECT_EQ(tmp.v[1], 0x187654321llu);
		EXPECT_EQ(tmp.v[0], 0xabcdabcdabcdabcdllu);
		tmp = v188.template Slice<68, 100>();
		EXPECT_EQ(tmp.v[1], 0x218765432llu);
		EXPECT_EQ(tmp.v[0], 0x1abcdabcdabcdabcllu);
		tmp = v188.template Slice<88, 100>();
		EXPECT_EQ(tmp.v[1], 0x765432187llu);
		EXPECT_EQ(tmp.v[0], 0x654321abcdabcdabllu);
	}
}

TEST(TestVerilogUnsigned, SliceRead) {
	SliceReadTemplate<vuint>();
}

TEST(TestVerilogSigned, SliceRead) {
	SliceReadTemplate<vsint>();
}

template<template<unsigned> class IntTmpl>
void SliceWriteTemplate() {
	IntTmpl<33> v33;
	IntTmpl<188> v188;
	{
		v33 = 0;
		vint<false, 12> v12;
		vint<false, 16> v16;
		vint<false, 72> v72;
		v12 = 0x123;
		v72.v[1] = 0xaa;
		v72.v[0] = 0x4321'ffff'ffff'1234llu;
		v33.template SetSlice<0>(v12);
		EXPECT_EQ(v33.v[0], 0x123);
		v33.template SetSlice<4>(v12);
		EXPECT_EQ(v33.v[0], 0x1233);

		v16 = 0xf;
		v16.template SetSlice<4>(v12);
		EXPECT_EQ(v16.v[0], 0x123f);

		v188 = 0;
		v188.template SetSlice<0>(v12);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0);
		EXPECT_EQ(v188.v[0], 0x123);
		v188.template SetSlice<4>(v12);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0);
		EXPECT_EQ(v188.v[0], 0x1233);
		v188.template SetSlice<56>(v12);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0x1);
		EXPECT_EQ(v188.v[0], 0x2300'0000'0000'1233llu);
		v188.template SetSlice<60>(v12);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0x12);
		EXPECT_EQ(v188.v[0], 0x3300'0000'0000'1233llu);
		v188.template SetSlice<64>(v12);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0x123);
		EXPECT_EQ(v188.v[0], 0x3300'0000'0000'1233llu);
		v188.template SetSlice<68>(v12);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0x1233);
		EXPECT_EQ(v188.v[0], 0x3300'0000'0000'1233llu);

		v188 = 0;
		v188.template SetSlice<0>(v72);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0xaa);
		EXPECT_EQ(v188.v[0], 0x4321'ffff'ffff'1234llu);
		v188.template SetSlice<32>(v72);
		EXPECT_EQ(v188.v[2], 0x0);
		EXPECT_EQ(v188.v[1], 0xaa'4321'ffffllu);
		EXPECT_EQ(v188.v[0], 0xffff'1234'ffff'1234llu);
		v188.template SetSlice<60>(v72);
		EXPECT_EQ(v188.v[2], 0xa);
		EXPECT_EQ(v188.v[1], 0xa'4321'ffff'ffff'123llu);
		EXPECT_EQ(v188.v[0], 0x4fff'1234'ffff'1234llu);
		v188.template SetSlice<64>(v72);
		EXPECT_EQ(v188.v[2], 0xaa);
		EXPECT_EQ(v188.v[1], 0x4321'ffff'ffff'1234llu);
		EXPECT_EQ(v188.v[0], 0x4fff'1234'ffff'1234llu);
		v188.template SetSlice<188-72>(v72);
		EXPECT_EQ(v188.v[2], 0xaa'4321'ffff'ffff'1llu);
		EXPECT_EQ(v188.v[1], 0x2341'ffff'ffff'1234llu);
		EXPECT_EQ(v188.v[0], 0x4fff'1234'ffff'1234llu);
	}
}

TEST(TestVerilogUnsigned, SliceWrite) {
	SliceWriteTemplate<vsint>();
}

TEST(TestVerilogSigned, SliceWrite) {
	SliceWriteTemplate<vsint>();
}

///////////////////////////
// Test Basic Arithmetic
///////////////////////////
template<template<unsigned> class IntTmpl>
void BasicArithTemplate() {
	IntTmpl<10> a10, b10, c10;
	// normal +
	a10.v[0] = 900;
	b10.v[0] = 100;
	c10 = a10 - b10;
	EXPECT_EQ(c10.v[0], 800);
	// normal -
	a10.v[0] = 1000;
	b10.v[0] = 100;
	c10 = a10 - b10;
	EXPECT_EQ(c10.v[0], 900);
	// normal *
	a10.v[0] = 3;
	b10.v[0] = 3;
	c10 = a10 * b10;
	EXPECT_EQ(c10.v[0], 9);
	// overflow +
	a10.v[0] = 1000;
	b10.v[0] = 124;
	c10 = a10 + b10;
	EXPECT_EQ(c10.v[0], 100);
	// underflow -
	a10.v[0] = 1;
	b10.v[0] = 2;
	c10 = a10 - b10;
	EXPECT_EQ(c10.v[0], 0x3ff); // -1
	// overflow *
	a10.v[0] = 50;
	b10.v[0] = 21;
	c10 = a10 * b10;
	EXPECT_EQ(c10.v[0], 26); // 1050-1024
	// underflow *
	a10.v[0] = 50;
	b10.v[0] = 0x3ff; // -1
	c10 = a10 * b10;
	EXPECT_EQ(c10.v[0], 974); // 1024-50

	IntTmpl<127> a127, b127, c127;
	// normal + (no carry)
	a127.v[1] = 1;
	a127.v[0] = -1;
	b127.v[1] = 2;
	b127.v[0] = 1;
	c127 = a127 + b127;
	EXPECT_EQ(c127.v[1], 4);
	EXPECT_EQ(c127.v[0], 0);
	// normal + (carry)
	a127.v[1] = 2;
	a127.v[0] = 0x8000'0000'0000'0001llu;
	b127.v[1] = 2;
	b127.v[0] = 0x8000'0000'0000'0001llu;
	c127 = a127 + b127;
	EXPECT_EQ(c127.v[1], 5);
	EXPECT_EQ(c127.v[0], 2);
	// normal - (borrow)
	a127.v[1] = 12;
	a127.v[0] = 0;
	b127.v[1] = 0;
	b127.v[0] = 10;
	c127 = a127 - b127;
	EXPECT_EQ(c127.v[1], 11);
	EXPECT_EQ(c127.v[0], -10);
	// overflow +
	a127.v[1] = 0x7fff'ffff'ffff'0000;
	a127.v[0] = 0xa000'0000'0000'0003;
	b127.v[1] = 0x7fff'ffff'ffff'0000;
	b127.v[0] = 0x6000'0000'0000'0002;
	c127 = a127 + b127;
	EXPECT_EQ(c127.v[1], 0x7fff'ffff'fffe'0001);
	EXPECT_EQ(c127.v[0], 5);
	// underflow -
	a127.v[1] = 0;
	a127.v[0] = 0;
	b127.v[1] = 0;
	b127.v[0] = 2;
	c127 = a127 - b127;
	EXPECT_EQ(c127.v[1], 0x7fff'ffff'ffff'ffff);
	EXPECT_EQ(c127.v[0], -2);
}

TEST(TestVerilogUnsigned, BasicArith) {
	BasicArithTemplate<vuint>();
}

TEST(TestVerilogSigned, BasicArith) {
	BasicArithTemplate<vsint>();
}

///////////////////////////
// Test shift
///////////////////////////
static const tuple<array<uint16_t, 2>, unsigned> patterns_ru10[] {
	{{0x1a5, 0x01a}, 4u},
	{{0x3a5, 0x3a5}, 0u},
	{{0x3a5, 0x1d2}, 1u},
	{{0x3a5, 0x03a}, 4u},
	{{0x3a5, 0x001}, 9u}
};
static const tuple<array<uint16_t, 2>, unsigned> patterns_rs10[] {
	{{0x1a5, 0x01a}, 4u},
	{{0x3a5, 0x3a5}, 0u},
	{{0x3a5, 0x3d2}, 1u},
	{{0x3a5, 0x3fa}, 4u},
	{{0x3a5, 0x3ff}, 9u}
};
static const tuple<array<uint16_t, 2>, unsigned> patterns_l10[] {
	{{0x3a5, 0x3a5}, 0u},
	{{0x3a5, 0x250}, 4u},
	{{0x3a5, 0x100}, 8u}
};
static const tuple<array<uint64_t, 6>, unsigned> patterns_ru136[] {
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
	}, 0u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'000fllu, 0xfabc'def0'1234'5678llu, 0x90f0'f0f0'f0f0'f0f0llu,
	}, 4u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0000llu, 0xffab'cdef'0123'4567llu, 0x890f'0f0f'0f0f'0f0fllu,
	}, 8u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0000llu, 0x0ffa'bcde'f012'3456llu, 0x7890'f0f0'f0f0'f0f0llu,
	}, 12u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0000llu, 0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu,
	}, 64u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0000llu, 0x0000'0000'0000'000fllu, 0xfabc'def0'1234'5678llu,
	}, 68u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0000llu, 0x0000'0000'0000'0000llu, 0xffab'cdef'0123'4567llu,
	}, 72u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0000llu, 0x0000'0000'0000'0000llu, 0x0000'0000'0000'00ffllu,
	}, 128u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0000llu, 0x0000'0000'0000'0000llu, 0x0000'0000'0000'000fllu,
	}, 132u }
};
static const tuple<array<uint64_t, 6>, unsigned> patterns_rs136[] {
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
	}, 0u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xfabc'def0'1234'5678llu, 0x90f0'f0f0'f0f0'f0f0llu,
	}, 4u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xffab'cdef'0123'4567llu, 0x890f'0f0f'0f0f'0f0fllu,
	}, 8u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xfffa'bcde'f012'3456llu, 0x7890'f0f0'f0f0'f0f0llu,
	}, 12u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xffff'ffff'ffff'ffffllu, 0xabcd'ef01'2345'6789llu,
	}, 64u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xffff'ffff'ffff'ffffllu, 0xfabc'def0'1234'5678llu,
	}, 68u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xffff'ffff'ffff'ffffllu, 0xffab'cdef'0123'4567llu,
	}, 72u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xffff'ffff'ffff'ffffllu, 0xffff'ffff'ffff'ffffllu,
	}, 128u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xffff'ffff'ffff'ffffllu, 0xffff'ffff'ffff'ffffllu,
	}, 132u }
};
static const tuple<array<uint64_t, 6>, unsigned> patterns_l136[] {
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu
	}, 0u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0001llu, 0x2345'6789'0f0f'0f0fllu, 0x0f0f'0f0f'0000'0000llu
	}, 32u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0089llu, 0x0f0f'0f0f'0f0f'0f0fllu, 0x0000'0000'0000'0000llu
	}, 64u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'000fllu, 0x0f0f'0f0f'0000'0000llu, 0x0000'0000'0000'0000llu
	}, 96u},
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'000fllu, 0x0000'0000'0000'0000llu, 0x0000'0000'0000'0000llu,
	}, 128u}
};

template<template<unsigned> class IntTmpl>
void ShiftTemplate() {
	IntTmpl<10> v10;
	for (auto &p: patterns_ru10) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v10.v[0] = test_data[0];
		// force unsigned
		v10.shiftopr(nshift, false);
		EXPECT_EQ(v10.v[0], test_data[1]) << "rshift " << nshift;
	}
	for (auto &p: patterns_rs10) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v10.v[0] = test_data[0];
		// force signed
		v10.shiftopr(nshift, true);
		EXPECT_EQ(v10.v[0], test_data[1]) << "rshift " << nshift;
	}
	for (auto &p: patterns_l10) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v10.v[0] = test_data[0];
		v10 <<= nshift;
		EXPECT_EQ(v10.v[0], test_data[1]) << "lshift " << nshift;
	}

	IntTmpl<136> v136;
	for (auto &p: patterns_ru136) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v136.v[0] = test_data[2];
		v136.v[1] = test_data[1];
		v136.v[2] = test_data[0];
		// force unsigned
		v136.shiftopr(nshift, false);
		EXPECT_EQ(v136.v[0], test_data[5]) << "rshift " << nshift;
		EXPECT_EQ(v136.v[1], test_data[4]) << "rshift " << nshift;
		EXPECT_EQ(v136.v[2], test_data[3]) << "rshift " << nshift;
	}
	for (auto &p: patterns_rs136) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v136.v[0] = test_data[2];
		v136.v[1] = test_data[1];
		v136.v[2] = test_data[0];
		// force signed
		v136.shiftopr(nshift, true);
		EXPECT_EQ(v136.v[0], test_data[5]) << "lshift " << nshift;
		EXPECT_EQ(v136.v[1], test_data[4]) << "lshift " << nshift;
		EXPECT_EQ(v136.v[2], test_data[3]) << "lshift " << nshift;
	}
	for (auto &p: patterns_l136) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v136.v[0] = test_data[2];
		v136.v[1] = test_data[1];
		v136.v[2] = test_data[0];
		v136 <<= nshift;
		EXPECT_EQ(v136.v[0], test_data[5]) << "lshift " << nshift;
		EXPECT_EQ(v136.v[1], test_data[4]) << "lshift " << nshift;
		EXPECT_EQ(v136.v[2], test_data[3]) << "lshift " << nshift;
	}
}

TEST(TestVerilogUnsigned, Shift) {
	ShiftTemplate<vuint>();

	vuint<10> v10;
	for (auto &p: patterns_ru10) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v10.v[0] = test_data[0];
		// default unsigned
		v10 >>= nshift;
		EXPECT_EQ(v10.v[0], test_data[1]);
	}

	vuint<136> v136;
	for (auto &p: patterns_ru136) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v136.v[0] = test_data[2];
		v136.v[1] = test_data[1];
		v136.v[2] = test_data[0];
		// force unsigned
		v136.shiftopr(nshift, false);
		EXPECT_EQ(v136.v[0], test_data[5]) << "rshift " << nshift;
		EXPECT_EQ(v136.v[1], test_data[4]) << "rshift " << nshift;
		EXPECT_EQ(v136.v[2], test_data[3]) << "rshift " << nshift;
	}
}

TEST(TestVerilogSigned, Shift) {
	ShiftTemplate<vsint>();

	vsint<10> v10;
	for (auto &p: patterns_rs10) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v10.v[0] = test_data[0];
		// default signed
		v10 >>= nshift;
		EXPECT_EQ(v10.v[0], test_data[1]);
	}

	vuint<136> v136;
	for (auto &p: patterns_rs136) {
		const auto &test_data = get<0>(p);
		const unsigned nshift = get<1>(p);
		v136.v[0] = test_data[2];
		v136.v[1] = test_data[1];
		v136.v[2] = test_data[0];
		// default signed
		v136.shiftopr(nshift, true);
		EXPECT_EQ(v136.v[0], test_data[5]) << "rshift " << nshift;
		EXPECT_EQ(v136.v[1], test_data[4]) << "rshift " << nshift;
		EXPECT_EQ(v136.v[2], test_data[3]) << "rshift " << nshift;
	}
}

///////////////////////////
// Test rotate
///////////////////////////
static const tuple<array<uint16_t, 2>, unsigned> rotate_ru10[] {
	{{0x3a5, 0x3a5}, 0u},
	{{0x3a5, 0x3d2}, 1u},
	{{0x3a5, 0x34b}, 9u}
};

static const tuple<array<uint64_t, 6>, unsigned> rotate_ru136[] {
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
	}, 0u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00fallu, 0xbcde'f012'3456'7890llu, 0xf0f0'f0f0'f0f0'f0ffllu,
	}, 4u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00abllu, 0xcdef'0123'4567'890fllu, 0x0f0f'0f0f'0f0f'0fffllu,
	}, 8u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0089llu, 0x0f0f'0f0f'0f0f'0f0fllu, 0xffab'cdef'0123'4567llu,
	}, 64u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'0090llu, 0xf0f0'f0f0'f0f0'f0ffllu, 0xfabc'def0'1234'5678llu,
	}, 68u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'000fllu, 0x0f0f'0f0f'0f0f'0fffllu, 0xabcd'ef01'2345'6789llu,
	}, 72u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'000fllu, 0xffab'cdef'0123'4567llu, 0x890f'0f0f'0f0f'0f0fllu,
	}, 128u },
	{{
		0x0000'0000'0000'00ffllu, 0xabcd'ef01'2345'6789llu, 0x0f0f'0f0f'0f0f'0f0fllu,
		0x0000'0000'0000'00ffllu, 0xfabc'def0'1234'5678llu, 0x90f0'f0f0'f0f0'f0f0llu,
	}, 132u }
};

TEST(TestVerilogUnsigned, Rotate) {
	vuint<10> v10;
	for (auto &p: rotate_ru10) {
		const auto &test_data = get<0>(p);
		const unsigned nrotate = get<1>(p);
		v10.v[0] = test_data[0];
		// default unsigned
		v10.RotateRight(nrotate);
		EXPECT_EQ(v10.v[0], test_data[1]) << nrotate;
		v10.RotateLeft(nrotate);
		EXPECT_EQ(v10.v[0], test_data[0]) << nrotate;
	}

	vuint<136> v136;
	for (auto &p: rotate_ru136) {
		const auto &test_data = get<0>(p);
		const unsigned nrotate = get<1>(p);
		v136.v[0] = test_data[2];
		v136.v[1] = test_data[1];
		v136.v[2] = test_data[0];
		v136.RotateLeft(nrotate);
		EXPECT_EQ(v136.v[0], test_data[5]) << nrotate;
		EXPECT_EQ(v136.v[1], test_data[4]) << nrotate;
		EXPECT_EQ(v136.v[2], test_data[3]) << nrotate;
		v136.RotateRight(nrotate);
		EXPECT_EQ(v136.v[0], test_data[2]) << nrotate;
		EXPECT_EQ(v136.v[1], test_data[1]) << nrotate;
		EXPECT_EQ(v136.v[2], test_data[0]) << nrotate;
	}
}

TEST(TestVerilogUnsigned, DeathRotate) {
	vuint<10> v10(0x3a5);
	vuint<136> v136;
	v136.v[0] = 0x8C17378EEE08E2A3;
	v136.v[1] = 0xA6C1298488B890AC;
	v136.v[2] = 0x60;
	ASSERT_DEATH(v10.RotateLeft(11), "rhs < num_bit' failed");
	ASSERT_DEATH(v10.RotateRight(11), "rhs < num_bit' failed");
	ASSERT_DEATH(v136.RotateLeft(137), "rhs < num_bit' failed");
	ASSERT_DEATH(v136.RotateRight(137), "rhs < num_bit' failed");
}

///////////////////////////
// Test cast
///////////////////////////
TEST(TestVerilogUnsigned, ExplicitCast) {
	// We cast from singed to unsigned in this test,
	// so this test does not have TestVerilogSigned version

	// 5b <-> 130b
	{
		vuint<5> vu5;
		vsint<5> vs5;
		vuint<130> vu130;
		vsint<130> vs130;
		// positive short to long: no sign extension U2S and U2U
		vu5.v[0] = 12;
		vu130 = static_cast<vuint<130>>(vu5);
		vs130 = static_cast<vsint<130>>(vu5);
		EXPECT_EQ(vu130.v[0], 12);
		EXPECT_EQ(vu130.v[1], 0);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 12);
		EXPECT_EQ(vs130.v[1], 0);
		EXPECT_EQ(vs130.v[2], 0);

		// positive short to long: no sign extension S2S and S2U
		vs5.v[0] = 12;
		vu130 = static_cast<vuint<130>>(vs5);
		vs130 = static_cast<vsint<130>>(vs5);
		EXPECT_EQ(vu130.v[0], 12);
		EXPECT_EQ(vu130.v[1], 0);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 12);
		EXPECT_EQ(vs130.v[1], 0);
		EXPECT_EQ(vs130.v[2], 0);

		// negative short to long: no sign extension U2S and U2U
		vu5.v[0] = 0x10;
		vu130 = static_cast<vuint<130>>(vu5);
		vs130 = static_cast<vsint<130>>(vu5);
		EXPECT_EQ(vu130.v[0], 0x10);
		EXPECT_EQ(vu130.v[1], 0);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 0x10);
		EXPECT_EQ(vs130.v[1], 0);
		EXPECT_EQ(vs130.v[2], 0);

		// negative short to long: only sign extension for S2S, not for S2U
		vs5.v[0] = 0x10;
		vu130 = static_cast<vuint<130>>(vs5);
		vs130 = static_cast<vsint<130>>(vs5);
		EXPECT_EQ(vu130.v[0], 0x10);
		EXPECT_EQ(vu130.v[1], 0);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 0xffff'ffff'ffff'fff0llu);
		EXPECT_EQ(vs130.v[1], 0xffff'ffff'ffff'ffffllu);
		EXPECT_EQ(vs130.v[2], 0x0000'0000'0000'0003llu);

		// positive long to short
		vu130.v[0] = 0xf0;
		vu130.v[1] = 0x123;
		vu130.v[2] = 0x456;
		vu5 = static_cast<vuint<5>>(vu130);
		vs5 = static_cast<vsint<5>>(vu130);
		EXPECT_EQ(vu5.v[0], 0x10);
		EXPECT_EQ(vs5.v[0], 0x10);

		// positive long to short
		vs130.v[0] = 0xf0;
		vs130.v[1] = 0x123;
		vs130.v[2] = 0x456;
		vu5 = static_cast<vuint<5>>(vs130);
		vs5 = static_cast<vsint<5>>(vs130);
		EXPECT_EQ(vu5.v[0], 0x10);
		EXPECT_EQ(vs5.v[0], 0x10);
	}

	// 68b <-> 130b
	{
		vuint<68> vu68;
		vsint<68> vs68;
		vuint<130> vu130;
		vsint<130> vs130;
		// positive short to long: no sign extension U2S and U2U
		vu68.v[0] = 0xabc;
		vu68.v[1] = 0x7;
		vu130 = static_cast<vuint<130>>(vu68);
		vs130 = static_cast<vsint<130>>(vu68);
		EXPECT_EQ(vu130.v[0], 0xabc);
		EXPECT_EQ(vu130.v[1], 0x7);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 0xabc);
		EXPECT_EQ(vs130.v[1], 0x7);
		EXPECT_EQ(vs130.v[2], 0);

		// positive short to long: no sign extension S2S and S2U
		vs68.v[0] = 0xabc;
		vs68.v[1] = 0x7;
		vu130 = static_cast<vuint<130>>(vs68);
		vs130 = static_cast<vsint<130>>(vs68);
		EXPECT_EQ(vu130.v[0], 0xabc);
		EXPECT_EQ(vu130.v[1], 0x7);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 0xabc);
		EXPECT_EQ(vs130.v[1], 0x7);
		EXPECT_EQ(vs130.v[2], 0);

		// negative short to long: no sign extension U2S and U2U
		vu68.v[0] = 0xabc;
		vu68.v[1] = 0x8;
		vu130 = static_cast<vuint<130>>(vu68);
		vs130 = static_cast<vsint<130>>(vu68);
		EXPECT_EQ(vu130.v[0], 0xabc);
		EXPECT_EQ(vu130.v[1], 0x8);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 0xabc);
		EXPECT_EQ(vs130.v[1], 0x8);
		EXPECT_EQ(vs130.v[2], 0);

		// negative short to long: only sign extension for S2S, not for S2U
		vs68.v[0] = 0xabc;
		vs68.v[1] = 0x8;
		vu130 = static_cast<vuint<130>>(vs68);
		vs130 = static_cast<vsint<130>>(vs68);
		EXPECT_EQ(vu130.v[0], 0xabc);
		EXPECT_EQ(vu130.v[1], 0x8);
		EXPECT_EQ(vu130.v[2], 0);
		EXPECT_EQ(vs130.v[0], 0xabc);
		EXPECT_EQ(vs130.v[1], 0xffff'ffff'ffff'fff8llu);
		EXPECT_EQ(vs130.v[2], 0x0000'0000'0000'0003llu);

		// positive long to short
		vu130.v[0] = 0xf0;
		vu130.v[1] = 0x123;
		vu130.v[2] = 0x456;
		vu68 = static_cast<vuint<68>>(vu130);
		vs68 = static_cast<vsint<68>>(vu130);
		EXPECT_EQ(vu68.v[0], 0xf0);
		EXPECT_EQ(vu68.v[1], 0x3);
		EXPECT_EQ(vs68.v[0], 0xf0);
		EXPECT_EQ(vs68.v[1], 0x3);

		// positive long to short
		vs130.v[0] = 0xf0;
		vs130.v[1] = 0x123;
		vs130.v[2] = 0x456;
		vu68 = static_cast<vuint<68>>(vs130);
		vs68 = static_cast<vsint<68>>(vs130);
		EXPECT_EQ(vu68.v[0], 0xf0);
		EXPECT_EQ(vu68.v[1], 0x3);
		EXPECT_EQ(vs68.v[0], 0xf0);
		EXPECT_EQ(vs68.v[1], 0x3);
	}
}

///////////////////////////
// Test pack
///////////////////////////
TEST(TestVerilogUnsigned, Concat) {
	vuint<4> v4;
	vuint<12> v12;
	vuint<72> v72;
	v4 = 0x1;
	v12 = 0xabc;
	v72.v[1] = 0xef;
	v72.v[0] = 0x12345678abcdabcdllu;
	{
		vuint<16> v16;
		v16 = concat(v4, v12);
		EXPECT_EQ(v16, 0x1abc);
		v16 = concat(v12, v4);
		EXPECT_EQ(v16, 0xabc1);
	}
	{
		vuint<28> v28;
		v28 = concat(v12, v4, v12);
		EXPECT_EQ(v28, 0xabc1abc);
	}
	{
		vuint<88> v88;
		v88 = concat(v4, v72, v12);
		EXPECT_EQ(v88.v[1], 0x1'ef123);
		EXPECT_EQ(v88.v[0], 0x45678'abcdabcd'abcllu);
	}
}
#endif
