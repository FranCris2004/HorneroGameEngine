
#ifndef HORNERO_CORE_EVENT_EVENT_HPP
#define HORNERO_CORE_EVENT_EVENT_HPP

#include <concepts>

namespace hornero::core::event
{
    // Event abstract class
    class BaseEvent
    {
    public:
        virtual ~BaseEvent() = default;
    };

    template <typename Tp>
    concept EventType = std::derived_from<Tp, BaseEvent>;
} // namespace hornero

#endif // HORNERO_CORE_EVENT_EVENT_HPP
