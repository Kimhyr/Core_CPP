#ifndef CORE_COMPARE_PARTIALORDERING_HPP
#define CORE_COMPARE_PARTIALORDERING_HPP

#include "Compare.hpp"

namespace Core::Compare {
    class PartialOrdering {
    public:
        static
        const PartialOrdering Lesser;

        static
        const PartialOrdering Equivalent;

        static
        const PartialOrdering Greater;

        static
        const PartialOrdering Unordered;

    public:
        friend constexpr
        Bool operator ==(PartialOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value == Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator ==(PartialOrdering, PartialOrdering)
        noexcept = default;

        friend constexpr
        Bool operator <(PartialOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value == Compare::Type(Compare::Order::Lesser); }

        friend constexpr
        Bool operator <(Compare::Unspecified, PartialOrdering rhs)
        noexcept { return rhs.value == Compare::Type(Compare::Order::Greater); }

        friend constexpr
        Bool operator >(PartialOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value == Compare::Type(Compare::Order::Greater); }

        friend constexpr
        Bool operator >(Compare::Unspecified, PartialOrdering rhs)
        noexcept { return rhs.value == Compare::Type(Compare::Order::Lesser); }

        friend constexpr
        Bool operator <=(PartialOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value <= Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        Bool operator <=(Compare::Unspecified, PartialOrdering rhs)
        noexcept { return rhs.value == Compare::Type(rhs.value & Compare::Type(Compare::Order::Greater)); }

        friend constexpr
        Bool operator >=(PartialOrdering lhs, Compare::Unspecified)
        noexcept { return lhs.value == Compare::Type(lhs.value & Compare::Type(Compare::Order::Greater)); }

        friend constexpr
        Bool operator >=(Compare::Unspecified, PartialOrdering rhs)
        noexcept { return rhs.value <= Compare::Type(Compare::Order::Equivalent); }

        friend constexpr
        PartialOrdering operator <=>(PartialOrdering lhs, Compare::Unspecified)
        noexcept { return lhs; }

        friend constexpr
        PartialOrdering operator <=>(Compare::Unspecified, PartialOrdering rhs)
        noexcept {
            return (rhs.value & Compare::Type(Compare::Order::Greater))
                   ? PartialOrdering(Compare::Order(-rhs.value))
                   : rhs;
        }

    private:
        Compare::Type value;

    private:
        explicit constexpr
        PartialOrdering(Compare::Order order)
        noexcept
                : value(Compare::Type(order)) {}

        explicit constexpr
        PartialOrdering(Compare::Un un)
        noexcept
                : value(Compare::Type(un)) {}
    private:
        friend class WeakOrdering;
        friend class StrongOrdering;
    };

    inline constexpr
    PartialOrdering PartialOrdering::Lesser(Compare::Order::Lesser);

    inline constexpr
    PartialOrdering PartialOrdering::Equivalent(Compare::Order::Equivalent);

    inline constexpr
    PartialOrdering PartialOrdering::Greater(Compare::Order::Greater);

    inline constexpr
    PartialOrdering PartialOrdering::Unordered(Compare::Un::Unordered);
} // Core::Compare

#endif // CORE_COMPARE_PARTIALORDERING_HPP
