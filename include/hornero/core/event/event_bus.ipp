
#include <hornero/core/event/event_bus.hpp>

inline hornero::core::event::EventBus::subscribers_map_type
    hornero::core::event::EventBus::subscribers;

inline hornero::core::event::EventBus::generic_subscribers_map_type
    hornero::core::event::EventBus::generic_subscribers;

inline hornero::core::event::EventBus::event_queue_type
    hornero::core::event::EventBus::events;

// Helper for safe handling of dynamic_cast
template <hornero::core::event::EventType Tp>
auto safe_dispatch(const hornero::core::event::BaseEvent &event, const hornero::core::event::EventCallback<Tp> &callback) -> void
{
    if (const auto *casted = dynamic_cast<const Tp *>(&event))
        callback(*casted);

    // TODO - Log fail
}

template <hornero::core::event::GenericEventType Tp>
inline void
hornero::core::event::EventBus::Subscribe(const std::string &type, const GenericEventCallback &callback)
{
    generic_subscribers[GenericEvent::HashType(type)].emplace_back(
        [callback = std::move(callback)](const GenericEvent &event)
        {
            callback(static_cast<const Tp &>(event));
        });
}

template <hornero::core::event::NonGenericEventType Tp>
inline void
hornero::core::event::EventBus::Subscribe(const EventCallback<Tp> &callback)
{
    subscribers[std::type_index(typeid(Tp))].emplace_back(
        [callback = std::move(callback)](const BaseEvent &event)
        {
            safe_dispatch(event, callback);
        });
}

template <hornero::core::event::EventType Tp, typename... Args>
inline void hornero::core::event::EventBus::Post(Args... args)
{
    events.push(std::make_unique<Tp>(std::forward<Args>(args)...));
}

inline void
hornero::core::event::EventBus::DispatchQueued()
{
    for (; !events.empty(); events.pop())
        InmediateDispatch(*events.front());
}

template <typename Map, typename Key>
inline void
DispatchCallbacks(Map &map, const Key &key, const auto &event)
{
    const auto it = map.find(key);

    if (it != map.end())
        for (const auto &callback : it->second)
            callback(event);
}

template <hornero::core::event::GenericEventType Tp>
inline void
hornero::core::event::EventBus::InmediateDispatch(const Tp &event)
{
    DispatchCallbacks(generic_subscribers, event.GetTypeHash(), event);
}

template <hornero::core::event::NonGenericEventType Tp>
inline void
hornero::core::event::EventBus::InmediateDispatch(const Tp &event)
{
    DispatchCallbacks(subscribers, std::type_index(typeid(Tp)), event);
}
