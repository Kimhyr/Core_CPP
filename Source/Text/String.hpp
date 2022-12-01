#ifndef CORE_TEXT_STRING_HPP
#define CORE_TEXT_STRING_HPP

#include <string>

#include "../Iteration/Iterator.hpp"
#include "../Core.hpp"

namespace Core::Text {
    template<typename SymbolT>
    class String : public Iteration::Iterator<SymbolT> {
    public:
        using Symbol = SymbolT;

    public:
        static constexpr
        const USize NPOS = static_cast<USize>(-1);

    public:
        [[nodiscard]]
        constexpr
        USize GetSize()
        const noexcept { return this->size; }

        constexpr
        const SymbolT *GetIterator()
        const noexcept { return this->data; }

        constexpr
        const SymbolT *GetBegin()
        const noexcept { return this->data; }

        constexpr
        const SymbolT *GetEnd()
        const noexcept { return this->data + this->size; }

    private:
        USize size;
        const SymbolT *data;
    };

    using String8 = String<Char8>;
    using String16 = String<Char16>;
    using String32 = String<Char32>;
} // Core::Text

#endif // CORE_TEXT_STRING_HPP
