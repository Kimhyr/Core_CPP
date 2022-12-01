#ifndef CORE_COLLECTION_ARRAY_HPP
#define CORE_COLLECTION_ARRAY_HPP

#include <array>

#include "../Core.hpp"

namespace Core::Collection {
    template<typename DataT, USize SizeV>
    class Array {
    public:
        constexpr
        DataT &Get(USize index)
        const {  }

        constexpr
        DataT &operator [](USize index) { return this->data[index]; }

        constexpr
        const DataT &operator [](USize index)
        const { return this->data[index]; }

    private:
        DataT data[SizeV];
    };
} // Core::Collection

#endif // CORE_COLLECTION_ARRAY_HPP
