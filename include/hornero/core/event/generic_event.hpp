
#ifndef HORNERO_CORE_EVENT_GENERIC_EVENT_HPP
#define HORNERO_CORE_EVENT_GENERIC_EVENT_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include <hornero/core/event/event.hpp>
#include <hornero/utils/numeric_types.hpp>

namespace hornero::core::event
{
    // Intended to be used by modules such as scripting to use their own event types at runtime
    class GenericEvent : public BaseEvent
    {
    public:
        using hash_type = utils::u32;
        using field_key_type = std::string;
        using field_value_type = std::string;
        using fields_type = std::unordered_map<field_key_type, field_value_type>;

        GenericEvent(const std::string &type);

        GenericEvent(const std::string &type, const std::vector<std::pair<const std::string, const std::string>> &fields_values);

        // Getters

        hash_type GetTypeHash() const;

        std::vector<std::string> GetFieldNames() const;

        std::vector<std::pair<std::string, std::string>> GetFieldPairs() const;

        // Setters

        void SetType(const std::string &type);

        std::string &operator[](const std::string &n);

        std::string operator[](const std::string &n) const;

        // Static Methods

        static hash_type HashType(const std::string &type);

    private:
        hash_type type_hash;

        fields_type fields;
    };

    template <typename Tp>
    concept GenericEventType = std::derived_from<Tp, GenericEvent>;

    template <typename Tp>
    concept NonGenericEventType = EventType<Tp> && !GenericEventType<Tp>;

} // namespace hornero::core::event

#include "generic_event.ipp"

#endif // HORNERO_CORE_EVENT_GENERIC_EVENT_HPP