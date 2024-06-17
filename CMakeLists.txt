cmake_minimum_required(VERSION 3.28)
project(monkey_lang)

set(CMAKE_CXX_STANDARD 23)

include_directories(src include)

add_executable(monkey_lang main.cpp include/Lexer.h src/Lexer.cpp
        include/Token.h src/Token.cpp)

# Set compile and link options
set(CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS} ${LLVM_CXXFLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LLVM_LDFLAGS}")