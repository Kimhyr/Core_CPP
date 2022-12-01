#ifndef CORE_COMPARE_STRONGORDERING_HPP
#define CORE_COMPARE_STRONGORDERING_HPP

#include "WeakOrdering.hpp"

namespace Core::Compare {
    class StrongOrdering {
    private:
        Compare::Type value;

    private:
        constexpr explicit
        StrongOrdering(Compare::Order order)
        noexcept
                : value(Compare::Type(order)) {}

    public:
        static
        const StrongOrdering Lesser;

        static
        const StrongOrdering Equal;

        static
        const StrongOrdering Equivalent;

        static
        const StrongOrdering Greater;

    public:
        constexpr
        operator PartialOrdering()
        const noexcept { return PartialOrdering(Compare::Order(this->value)); }

        constexpr
        operator WeakOrdering()
        const noexcept { return WeakOrdering(Compare::Order(this->value)); }

    public:
        friend constexpr
        Bool operator ==(StrongOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value == 0; }

        friend constexpr
        Bool operator ==(StrongOrdering, StrongOrdering)
        noexcept = default;

        friend constexpr
        Bool operator <(StrongOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value < 0; }

        friend constexpr
        Bool operator >(StrongOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value > 0; }

        friend constexpr
        Bool operator <=(StrongOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value <= 0; }

        friend constexpr
        Bool operator >=(StrongOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value >= 0; }

        friend constexpr
        Bool operator <(Compare::Unspecified, StrongOrdering rhs)
        noexcept { return 0 < rhs.value; }

        friend constexpr
        Bool operator >(Compare::Unspecified, StrongOrdering rhs)
        noexcept { return 0 > rhs.value; }

        friend constexpr
        Bool operator <=(Compare::Unspecified, StrongOrdering rhs)
        noexcept { return 0 <= rhs.value; }

        friend constexpr
        Bool operator >=(Compare::Unspecified, StrongOrdering rhs)
        noexcept { return 0 >= rhs.value; }

        friend constexpr StrongOrdering
        operator <=>(StrongOrdering lhs, Compare::Unspecified)
        noexcept { return lhs; }

        friend constexpr StrongOrdering
        operator <=>(Compare::Unspecified, StrongOrdering rhs)
        noexcept { return StrongOrdering(Compare::Order(-rhs.value)); }
    };

    inline constexpr StrongOrdering
    StrongOrdering::Lesser(Compare::Order::Lesser);

    inline constexpr StrongOrdering
    StrongOrdering::Equal(Compare::Order::Equivalent);

    inline constexpr StrongOrdering
    StrongOrdering::Equivalent(Compare::Order::Equivalent);

    inline constexpr StrongOrdering
    StrongOrdering::Greater(Compare::Order::Greater);
} // Core::Compare

#endif //CORE_COMPARE_STRONGORDERING_HPP
