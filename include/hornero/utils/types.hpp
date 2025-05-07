
#ifndef HORNERO_UTILS_TYPES_HPP
#define HORNERO_UTILS_TYPES_HPP

#include <cstdint>
#include <cstddef>

namespace hornero::utils
{
    // Signed integers
    using i8 = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;

    // Unsigned integers
    using u8 = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    // Floating point
    using f32 = float;
    using f64 = double;

    // Size type
    using size_t = std::size_t;

    // Pointer difference type
    using ptrdiff_t = std::ptrdiff_t;
} // namespace hornero::utils

#endif // HORNERO_UTILS_TYPES_HPP
