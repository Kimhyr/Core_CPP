#ifndef CORE_ITERATION_ITERATOR_HPP
#define CORE_ITERATION_ITERATOR_HPP

#include <iterator>

#include "../Core.hpp"

namespace Core::Iteration {
    template<typename DataT>
    struct Iterator {
    protected:
        virtual constexpr
        USize GetSize()
        const noexcept = 0;

        virtual constexpr
        const DataT *GetIterator()
        const noexcept = 0;

        virtual constexpr
        const DataT *GetBegin()
        const noexcept = 0;

        virtual constexpr
        const DataT *GetEnd()
        const noexcept = 0;
    };
} // Core::Iteration

#endif // CORE_ITERATION_ITERATOR_HPP
