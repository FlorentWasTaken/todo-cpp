cmake_minimum_required(VERSION 3.28)
add_executable (todo-cpp "todo-cpp.cpp" "todo-cpp.hpp")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/**/*.hpp")
target_sources(todo-cpp PRIVATE ${SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET todo-cpp PROPERTY CXX_STANDARD 20)
endif()

## Dependencies

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../deps")

find_package(Boost REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(todo-cpp ${Boost_LIBRARIES})
endif()