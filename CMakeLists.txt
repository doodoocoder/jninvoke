cmake_minimum_required(VERSION 3.12)
project(jninvoke)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--add-stdcall-alias")
include_directories("C:/Program Files (x86)/Java/jdk1.8.0_111/include"
        "C:/Program Files (x86)/Java/jdk1.8.0_111/include/win32")
add_library(jninvoke SHARED HelloWorld.cpp)
#add_executable(HelloWorldx HelloWorld.cpp)


