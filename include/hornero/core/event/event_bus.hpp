
#ifndef HORNERO_CORE_EVENT_EVENT_BUS_HPP
#define HORNERO_CORE_EVENT_EVENT_BUS_HPP

#include <functional>
#include <typeindex>
#include <memory>
#include <unordered_map>
#include <queue>

#include <hornero/core/event/event.hpp>
#include <hornero/core/event/generic_event.hpp>

namespace hornero::core::event
{
    template <EventType Tp>
    using EventCallback = std::function<void(const Tp &)>;

    using BaseEventCallback = EventCallback<BaseEvent>;
    using GenericEventCallback = EventCallback<GenericEvent>;

    class EventBus
    {
    public:
        using subscribers_map_type =
            std::unordered_map<std::type_index, std::vector<BaseEventCallback>>;

        using generic_subscribers_map_type =
            std::unordered_map<GenericEvent::hash_value_type, std::vector<GenericEventCallback>>;

        using event_queue_type =
            std::queue<std::unique_ptr<BaseEvent>>;

        template <GenericEventType Tp>
        static void Subscribe(const std::string &type, const GenericEventCallback &callback);

        template <NonGenericEventType Tp>
        static void Subscribe(const EventCallback<Tp> &callback);

        template <EventType Tp, typename... Args>
        static void Post(Args... args);

        static void DispatchQueued();

        template <GenericEventType Tp>
        static void InmediateDispatch(const Tp &event);

        template <NonGenericEventType Tp>
        static void InmediateDispatch(const Tp &event);

    private:
        EventBus() = default;
        ~EventBus() = default;

        static subscribers_map_type subscribers;
        static generic_subscribers_map_type generic_subscribers;
        static event_queue_type events;
    };
} // namespace hornero::core::event

#include "event_bus.ipp"

#endif // HORNERO_CORE_EVENT_BUS_HPP
