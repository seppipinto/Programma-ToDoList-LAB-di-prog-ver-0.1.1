cmake_minimum_required(VERSION 3.12)
project(LAB_TodoList)


set(CMAKE_CXX_STANDARD 11)

add_executable(LAB_TodoList main.cpp Item.h Category.h ToDoList.h)

add_subdirectory(test)

set(SOURCE_FILES ToDoList.h Category.h Item.h)
add_executable(unit_testing_example main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(unit_testing_example core)