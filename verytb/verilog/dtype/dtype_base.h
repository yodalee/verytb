#pragma once
// Direct include
// C system headers
// C++ standard library headers
#include <type_traits>
#include <utility>
// Other libraries' .h files.
// Your project's .h files.

namespace verilog {

enum class DataType: unsigned {
	eVInt = 0u,
	eVStruct,
	eVUnion,
	eVEnum,
	eMax,
	eInvalid = eMax
};
[[maybe_unused]]
static const char *dtype_names[unsigned(DataType::eMax)] = {
	"vint",
	"vstruct",
	"vunion",
	"venum",
};
#define TAG_AS_VINT static constexpr auto dtype_tag = ::verilog::DataType::eVInt;
#define TAG_AS_VSTRUCT static constexpr auto dtype_tag = ::verilog::DataType::eVStruct;
#define TAG_AS_VUNION static constexpr auto dtype_tag = ::verilog::DataType::eVUnion;
#define TAG_AS_VENUM static constexpr auto dtype_tag = ::verilog::DataType::eVEnum;
template <bool is_signed, unsigned num_bit> struct vint;

// Check if T has member named X and it is convertible to int
template <typename T, typename = void>
struct has_dtype_tag : std::false_type {};

template <typename T>
struct has_dtype_tag<T, std::void_t<decltype(T::dtype_tag)>> : std::true_type {};

template <typename T>
constexpr DataType get_dtype() {
	if constexpr (has_dtype_tag<T>::value) {
		if constexpr (std::is_same_v<decltype(T::dtype_tag), const DataType>) {
			return T::dtype_tag;
		}
	}
	return DataType::eInvalid;
}

template<typename T> inline constexpr bool is_vtype_v = get_dtype<T>() != DataType::eInvalid;
template<typename T> inline constexpr bool is_vint_v = get_dtype<T>() == DataType::eVInt;
template<typename T> inline constexpr bool is_vstruct_v = get_dtype<T>() == DataType::eVStruct;
template<typename T> inline constexpr bool is_vunion_v = get_dtype<T>() == DataType::eVUnion;
template<typename T> inline constexpr bool is_venum_v = get_dtype<T>() == DataType::eVEnum;
template<typename T> inline constexpr bool is_varray_v = std::extent<T, 0>::value != 0;


} // namespace verilog
