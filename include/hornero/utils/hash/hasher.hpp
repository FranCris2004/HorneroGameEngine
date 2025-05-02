
#ifndef HORNERO_UTILS_HASH_HASHER_HPP
#define HORNERO_UTILS_HASH_HASHER_HPP

#include <hornero/utils/memory/byte_view.hpp>

namespace hornero::utils::hash
{
    template <template <typename HasherValueTp> class HasherTp>
    struct HasherTraits
    {
        using type = HasherTp;
        using hash_value_type = HasherValueTp;
    };

    template <typename HasherValueTp>
    class Hasher
    {
    public:
        using typename HasherTraits<HasherValueTp>::type;
        using typename HasherTraits<HasherValueTp>::hash_value_type;

        virtual ~Hasher() = default;

        virtual hash_value_type hash(const ByteView &bytes) const = 0;

        inline hash_value_type operator()(const ByteView &bytes) const
        {
            return hash(bytes);
        }

        inline hash_value_type operator()(const std::string &str) const
        {
            return hash(ByteView(str));
        }

        inline hash_value_type operator()(const char *str) const
        {
            return hash(ByteView(str));
        }

        template <typename U>
        inline hash_value_type operator()(const U &value) const
        {
            return hash(ByteView(value));
        }
    };
} // namespace hornero::utils::hash

#endif // HORNERO_UTILS_HASH_HASHER_HPP
