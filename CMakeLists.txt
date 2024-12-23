cmake_minimum_required(VERSION 3.22)
project(LR7)


add_library(String STATIC Main_Task.cpp)

add_executable(AddressSan Asan_Main_Task.cpp)
target_compile_options(AddressSan PRIVATE -fsanitize=address)
target_link_options(AddressSan PRIVATE -fsanitize=address)



add_executable(ThreadSan Tsan_Main_Task.cpp)
target_compile_options(ThreadSan PRIVATE -fsanitize=thread)
target_link_options(ThreadSan PRIVATE -fsanitize=thread)

enable_testing()