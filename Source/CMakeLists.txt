CMAKE_MINIMUM_REQUIRED(VERSION 3.23)
PROJECT(Core)

ADD_COMPILE_OPTIONS(-Wall -Wextra -Werror)

SET(CMAKE_CXX_STANDARD 20)

ADD_LIBRARY(Core Text/String.hpp Iteration/Iterator.hpp Entry.cpp Core.hpp Collection/Array.cpp Collection/Array.hpp)
