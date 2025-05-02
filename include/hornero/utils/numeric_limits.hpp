
#ifndef HORNERO_UTILS_NUMERIC_LIMITS_HPP
#define HORNERO_UTILS_NUMERIC_LIMITS_HPP

#include <limits>
#include <hornero/utils/numeric_types.hpp>

namespace hornero::utils
{
    constexpr i8 I8_MIN = std::numeric_limits<i8>::min();
    constexpr i8 I8_MAX = std::numeric_limits<i8>::max();
    constexpr u8 U8_MAX = std::numeric_limits<u8>::max();

    constexpr i16 I16_MIN = std::numeric_limits<i16>::min();
    constexpr i16 I16_MAX = std::numeric_limits<i16>::max();
    constexpr u16 U16_MAX = std::numeric_limits<u16>::max();

    constexpr i32 I32_MIN = std::numeric_limits<i32>::min();
    constexpr i32 I32_MAX = std::numeric_limits<i32>::max();
    constexpr u32 U32_MAX = std::numeric_limits<u32>::max();

    constexpr i64 I64_MIN = std::numeric_limits<i64>::min();
    constexpr i64 I64_MAX = std::numeric_limits<i64>::max();
    constexpr u64 U64_MAX = std::numeric_limits<u64>::max();

    const f32 F32_MIN = std::numeric_limits<f32>::lowest();
    const f32 F32_MAX = std::numeric_limits<f32>::max();

    const f64 F64_MIN = std::numeric_limits<f64>::lowest();
    const f64 F64_MAX = std::numeric_limits<f64>::max();
} // namespace hornero::utils

#endif // HORNERO_UTILS_NUMERIC_LIMITS_HPP
