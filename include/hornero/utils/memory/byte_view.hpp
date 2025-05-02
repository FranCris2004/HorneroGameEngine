
#ifndef HORNERO_UTILS_MEMORY_BYTE_VIEW_HPP
#define HORNERO_UTILS_MEMORY_BYTE_VIEW_HPP

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string_view>
#include <span>
#include <array>
#include <type_traits>

namespace hornero::utils::memory
{
    class ByteView
    {
    public:
        using SpanType = std::span<const std::byte>;

        // Construir desde std::string_view o const char*
        constexpr ByteView(const char *str)
            : m_span{reinterpret_cast<const std::byte *>(str), std::char_traits<char>::length(str)} {}

        constexpr ByteView(std::string_view sv)
            : m_span{reinterpret_cast<const std::byte *>(sv.data()), sv.size()} {}

        // Desde std::span de std::byte
        constexpr ByteView(std::span<const std::byte> s) : m_span{s} {}

        // Desde std::array<T, N>
        template <typename T, std::size_t N>
        constexpr ByteView(const std::array<T, N> &arr)
            requires std::is_trivially_copyable_v<T>
            : m_span{reinterpret_cast<const std::byte *>(arr.data()), N * sizeof(T)}
        {
        }

        // Desde T* y tamaño
        template <typename T>
        constexpr ByteView(const T *ptr, std::size_t count)
            requires std::is_trivially_copyable_v<T>
            : m_span{reinterpret_cast<const std::byte *>(ptr), count * sizeof(T)}
        {
        }

        // Desde tipo trivial individual
        template <typename T>
        constexpr ByteView(const T &value)
            requires std::is_trivially_copyable_v<T>
            : m_span{reinterpret_cast<const std::byte *>(&value), sizeof(T)}
        {
        }

        // Desde void* + tamaño
        constexpr ByteView(const void *ptr, std::size_t size)
            : m_span{reinterpret_cast<const std::byte *>(ptr), size} {}

        constexpr const std::byte *data() const { return m_span.data(); }

        constexpr std::size_t size() const { return m_span.size(); }

        constexpr SpanType span() const { return m_span; }

    private:
        SpanType m_span;
    };
} // namespace hornero::utils::memory

#endif // HORNERO_UTILS_MEMORY_BYTE_VIEW_HPP