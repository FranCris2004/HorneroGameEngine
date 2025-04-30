
#ifndef HORNERO_CORE_LOGIC_RENDERABLE_HPP
#define HORNERO_CORE_LOGIC_RENDERABLE_HPP

#include <hornero/core/logic/loopable.hpp>

namespace hornero::core::logic
{
    class Renderable : public Loopable
    {
    public:
        ~Renderable() = default;

        virtual void Render() = 0;
    };
} // namespace hornero::core::logic

#endif // HORNERO_CORE_LOGIC_RENDERABLE_HPP
