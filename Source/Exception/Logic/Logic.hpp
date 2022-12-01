#ifndef CORE_EXCEPTION_LOGIC_LOGIC_HPP
#define CORE_EXCEPTION_LOGIC_LOGIC_HPP

#include "../Exception.hpp"

namespace Core::Exception::Logic {
    class Logic : public Exception {
    public:
        explicit
        Logic();

    private:
        // String message;
    };
} // Core::Exception::Logic

#endif //CORE_EXCEPTION_LOGIC_LOGIC_HPP
