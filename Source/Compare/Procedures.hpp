#ifndef CORE_COMPARE_PROCEDURES_HPP
#define CORE_COMPARE_PROCEDURES_HPP

#include "PartialOrdering.hpp"

namespace Core::Compare {
    constexpr
    Bool IsEQV(PartialOrdering comparison)
    noexcept { return comparison == 0; }

    constexpr
    Bool IsNEQ(PartialOrdering comparison)
    noexcept { return comparison != 0; }

    constexpr
    Bool IsLRT(PartialOrdering comparison)
    noexcept { return comparison < 0; }

    constexpr
    Bool IsLEQ(PartialOrdering comparison)
    noexcept { return comparison <= 0; }

    constexpr
    Bool IsGRT(PartialOrdering comparison)
    noexcept { return comparison > 0; }

    constexpr
    Bool IsGEQ(PartialOrdering comparison)
    noexcept { return comparison >= 0; }
} // Core::Compare

#endif //CORE_COMPARE_PROCEDURES_HPP
