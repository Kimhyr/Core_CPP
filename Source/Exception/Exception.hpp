#ifndef CORE_EXCEPTION_EXCEPTION_HPP
#define CORE_EXCEPTION_EXCEPTION_HPP

#include "../Core.hpp"

namespace Core::Exception {
    class Exception {
    public:
        Exception()
        noexcept {}

        virtual
        ~Exception()
        noexcept = 0;

        Exception(const Exception &) = default;

        Exception(Exception &&) = default;

    public:
        Exception &operator =(const Exception &) = default;

        Exception &operator =(Exception &&) = default;

    public:
        virtual
        const Char8 *GetReason()
        const noexcept = 0;
    };
} // Core::Exception

#endif // CORE_EXCEPTION_EXCEPTION_HPP
