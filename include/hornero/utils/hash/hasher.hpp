
#ifndef HORNERO_UTILS_HASH_HASHER_HPP
#define HORNERO_UTILS_HASH_HASHER_HPP

#include <hornero/utils/memory/byte_view.hpp>

namespace hornero::utils::hash
{
    template <typename HasherValueTp>
    struct HasherTraits
    {
        using hash_value_type = HasherValueTp;
    };

    template <typename HasherValueTp>
    class Hasher
    {
    public:
        using type = Hasher<HasherValueTp>;
        using traits = HasherTraits<HasherValueTp>;
        using hash_value_type = traits::hash_value_type;

        virtual ~Hasher() = default;

        virtual hash_value_type hash(const memory::ByteView &bytes) const = 0;

        inline hash_value_type operator()(const memory::ByteView &bytes) const
        {
            return hash(bytes);
        }

        inline hash_value_type operator()(const std::string &str) const
        {
            return hash(memory::ByteView(str));
        }

        inline hash_value_type operator()(const char *str) const
        {
            return hash(memory::ByteView(str));
        }

        template <typename U>
        inline hash_value_type operator()(const U &value) const
        {
            return hash(memory::ByteView(value));
        }
    };
} // namespace hornero::utils::hash

#endif // HORNERO_UTILS_HASH_HASHER_HPP
