
#include <hornero/utils/hash/fnv1a.hpp>

template <typename HashValueTp>
hornero::utils::hash::Fnv1a<HashValueTp>::hash_value_type
hornero::utils::hash::Fnv1a<HashValueTp>::hash(const hornero::utils::memory::ByteView &bytes) const
{
    hash_value_type hash = OFFSET_BASIS;

    for (std::size_t i = 0; i < bytes.size(); ++i)
    {
        hash ^= static_cast<std::uint8_t>(bytes.data()[i]);
        hash *= PRIME;
    }

    return hash;
}
