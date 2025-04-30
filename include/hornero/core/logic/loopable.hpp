
#ifndef HORNERO_CORE_LOGIC_LOOPABLE_HPP
#define HORNERO_CORE_LOGIC_LOOPABLE_HPP

namespace hornero::core::logic
{
    class Loopable
    {
    public:
        ~Loopable() = default;

        virtual void FrameLoop() = 0;

        virtual void FixedLoop() = 0;
    };
} // namespace hornero::core::logic

#endif // HORNERO_CORE_LOGIC_LOOPABLE_HPP
