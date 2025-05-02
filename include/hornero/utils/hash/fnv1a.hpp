
#ifndef HORNERO_UTILS_HASH_FNV1A_HPP
#define HORNERO_UTILS_HASH_FNV1A_HPP

#include <hornero/utils/hash/hasher.hpp>
#include <hornero/utils/types.hpp>

namespace hornero::utils::hash
{
    template <typename HashValueTp>
    struct Fnv1aTraits
    {
    };

    template <>
    struct Fnv1aTraits<u32>
    {
        static constexpr u32 PRIME = 0x01000193;
        static constexpr u32 OFFSET_BASIS = 0x811C9DC5;
    };

    template <>
    struct Fnv1aTraits<u64>
    {
        static constexpr u64 PRIME = 0x00000100000001B3;
        static constexpr u64 OFFSET_BASIS = 0xCBF29CE484222325;
    };

    template <typename HashValueTp>
    class Fnv1a : public Hasher<HashValueTp>
    {
    public:
        using hash_value_type = HasherTraits<HashValueTp>::hash_value_type;
        using fnv1a_traits = Fnv1aTraits<hash_value_type>;

        hash_value_type hash(const memory::ByteView &bytes) const override;

    private:
        static constexpr hash_value_type PRIME = fnv1a_traits::PRIME;
        static constexpr hash_value_type OFFSET_BASIS = fnv1a_traits::OFFSET_BASIS;
    };

    using Fnv1a32 = Fnv1a<u32>;
    using Fnv1a64 = Fnv1a<u64>;

    Fnv1a32 fnv1a32;
    Fnv1a64 fnv1a64;
} // namespace hornero::utils::hash

#include "fnv1a.ipp"

#endif // HORNERO_UTILS_HASH_FNV1A_HPP
