cmake_minimum_required(VERSION 3.28)
project(lilcraft)

set(BINARY_DIR ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${BINARY_DIR})
make_directory(${BINARY_DIR})

set(SDLIMAGE_AVIF OFF)

add_subdirectory(lib/SDL)
add_subdirectory(lib/SDL_image)
add_subdirectory(lib/SDL_ttf)
add_executable(lilcraft WIN32
    src/main.cpp
)
set_target_properties(lilcraft PROPERTIES CXX_STANDARD 23)
target_link_libraries(lilcraft PUBLIC SDL3::SDL3)
target_link_libraries(lilcraft PUBLIC SDL3_image::SDL3_image)
target_link_libraries(lilcraft PUBLIC SDL3_ttf::SDL3_ttf)

configure_file(LICENSE.txt ${BINARY_DIR} COPYONLY)
configure_file(README.md ${BINARY_DIR} COPYONLY)