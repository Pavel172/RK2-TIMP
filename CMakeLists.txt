cmake_minimum_required(VERSION 3.4)

project(RK2-TIMP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(RK2-TIMP STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/Mediator.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(RK2-TIMP PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/examples/demo.cpp)

target_link_libraries(demo RK2-TIMP)
