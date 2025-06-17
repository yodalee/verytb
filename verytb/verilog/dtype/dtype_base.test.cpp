// Direct include
#include "verilog/dtype/dtype_base.h"
// C system headers
// C++ standard library headers
#include "gtest/gtest.h"
// Other libraries' .h files.
// Your project's .h files.

struct FakeVInt1 {
};

struct FakeVInt2 {
	TAG_AS_VSTRUCT
};

struct FakeVInt3 {
	unsigned dtype_tag = 123;
};

using T1 = int[1];
using T2 = int[2][99];
using T3 = int[][1][9];
using T4 = int;

using namespace verilog;

TEST(dtype_base, CompileTime) {
	static_assert(get_dtype<FakeVInt1>() == DataType::eInvalid);
	static_assert(get_dtype<FakeVInt2>() == DataType::eVStruct);
	static_assert(get_dtype<FakeVInt3>() == DataType::eInvalid);

	static_assert(is_varray_v<T1>);
	static_assert(is_varray_v<T2>);
	static_assert(not is_varray_v<T3>);
	static_assert(not is_varray_v<T4>);
}
