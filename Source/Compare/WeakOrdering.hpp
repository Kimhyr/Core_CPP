#ifndef CORE_COMPARE_WEAKORDERING_HPP
#define CORE_COMPARE_WEAKORDERING_HPP

#include "PartialOrdering.hpp"

namespace Core::Compare {
    class WeakOrdering {
    public:
        static
        const WeakOrdering Lesser;

        static
        const WeakOrdering Equivalent;

        static
        const WeakOrdering Greater;

    public:
        constexpr
        operator PartialOrdering()
        const noexcept { return PartialOrdering(Compare::Order(this->value)); }

    public:
        friend constexpr
        Bool operator ==(WeakOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value == Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator ==(WeakOrdering, WeakOrdering)
        noexcept = default;

        friend constexpr
        Bool operator <(WeakOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value < Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator >(WeakOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value > Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator <=(WeakOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value <= Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator >=(WeakOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value >= Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator <(Compare::Unspecified, WeakOrdering rhs)
        noexcept { return rhs.value > Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator >(Compare::Unspecified, WeakOrdering rhs)
        noexcept { return rhs.value < Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator <=(Compare::Unspecified, WeakOrdering rhs)
        noexcept { return rhs.value >= Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator >=(Compare::Unspecified, WeakOrdering rhs)
        noexcept { return rhs.value <= Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        WeakOrdering operator <=>(WeakOrdering lhs, Compare::Unspecified)
        noexcept { return lhs; }

        friend constexpr
        WeakOrdering operator <=>(Compare::Unspecified, WeakOrdering rhs)
        noexcept { return WeakOrdering(Compare::Order(-rhs.value)); }

    private:
        Compare::Type value;

    private:
        explicit constexpr
        WeakOrdering(Compare::Order order)
        noexcept
                : value(Compare::Type(order)) {}

    private:
        friend class StrongOrder;
    };

    inline constexpr
    WeakOrdering WeakOrdering::Lesser(Compare::Order::Lesser);

    inline constexpr
    WeakOrdering WeakOrdering::Equivalent(Compare::Order::Equivalent);

    inline constexpr
    WeakOrdering WeakOrdering::Greater(Compare::Order::Greater);
};

#endif //CORE_COMPARE_WEAKORDERING_HPP
