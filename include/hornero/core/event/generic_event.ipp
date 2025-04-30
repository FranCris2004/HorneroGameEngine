
#include <hornero/core/event/generic_event.hpp>
#include <algorithm>

inline hornero::core::event::GenericEvent::hash_type
fnv1a_hash(const std::string &str)
{
    hornero::core::event::GenericEvent::hash_type hash = 0x811C9DC5;

    for (hornero::core::event::GenericEvent::hash_type c : str)
        hash = (hash ^ c) * 0x01000193;

    return hash;
}

inline hornero::core::event::GenericEvent::GenericEvent(const std::string &type)
    : type_hash(HashType(type))
{
}

inline hornero::core::event::GenericEvent::GenericEvent(const std::string &type, const std::vector<std::pair<const std::string, const std::string>> &fields_values)
    : type_hash(HashType(type)), fields(fields_values.begin(), fields_values.end())
{
}

// Getters

inline hornero::core::event::GenericEvent::hash_type
hornero::core::event::GenericEvent::GetTypeHash() const
{
    return type_hash;
}

inline std::vector<std::string>
hornero::core::event::GenericEvent::GetFieldNames() const
{
    std::vector<std::string> field_names;

    for (auto &&kv : fields)
        field_names.push_back(kv.first);

    return field_names;
}

inline std::vector<std::pair<std::string, std::string>>
hornero::core::event::GenericEvent::GetFieldPairs() const
{
    return std::vector<std::pair<std::string, std::string>>(fields.begin(), fields.end());
}

// Setters

inline void
hornero::core::event::GenericEvent::SetType(const std::string &type)
{
    type_hash = HashType(type);
}

inline hornero::core::event::GenericEvent::hash_type
hornero::core::event::GenericEvent::HashType(const std::string &type)
{
    return fnv1a_hash(type.c_str());
}

inline std::string &
hornero::core::event::GenericEvent::operator[](const std::string &name)
{
    return static_cast<std::string &>(fields[name]);
    std::unordered_map<int, int>::mapped_type a;
}

inline std::string
hornero::core::event::GenericEvent::operator[](const std::string &name) const
{
    return static_cast<const std::string &>(fields.at(name));
}
