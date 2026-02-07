cmake_minimum_required(VERSION 3.20)
project(NetChess LANGUAGES CXX)

# TODO: make a script to generate files instead of GLOB as it is discouraged
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(NetChess ${SOURCES})

target_include_directories(NetChess PRIVATE include)
target_compile_features(NetChess PRIVATE cxx_std_17)