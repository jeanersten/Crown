cmake_minimum_required(VERSION 3.28)

project(Crown LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/bin")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendor/SDL2/SDL)
add_subdirectory(vendor/GLAD)

add_executable(Crown
  source/Game.cpp
  source/Main.cpp

  source/Game.h
)

if (TARGET SDL2::SDL2main)
  target_link_libraries(Crown PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(Crown PRIVATE
  SDL2::SDL2
  glad
)

target_compile_definitions(Crown PRIVATE
  $<$<CONFIG:Debug>:CROWN_DEBUG_BUILD>
  $<$<CONFIG:Debug>:CROWN_RELEASE_BUILD>
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Crown)
