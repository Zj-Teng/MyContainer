cmake_minimum_required(VERSION 3.23)
project(MyContainer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Container main.cpp my_list.cpp my_list.h my_stack.cpp my_stack.h my_queue.cpp my_queue.h my_tree.cpp my_tree.h)
