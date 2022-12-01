#ifndef CORE_COMPARE_INCLUDE_HPP
#define CORE_COMPARE_INCLUDE_HPP

#include <compare>

#include "../Core.hpp"

namespace Core::Compare {
    using Type = Int8;

    enum class Order : Compare::Type {
        Lesser = -1,
        Equivalent = 0,
        Greater = 1,
    };

    enum class Un : Compare::Type {
        Unordered = 2,
    };

    struct Unspecified {
        constexpr
        Unspecified(Compare::Unspecified *)
        noexcept {}
    };
} // Core::Compare

#endif // CORE_COMPARE_INCLUDE_HPP
