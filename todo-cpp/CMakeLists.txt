add_executable (todo-cpp "todo-cpp.cpp" "todo-cpp.hpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET todo-cpp PROPERTY CXX_STANDARD 20)
endif()
