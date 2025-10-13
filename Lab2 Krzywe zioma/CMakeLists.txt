cmake_minimum_required(VERSION 3.15)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Root directory of the project")

project(Curve LANGUAGES CXX C)

set(src 
  "Main.cpp"
)

add_subdirectory(Renderer)
add_subdirectory(vendor/glfw)

add_executable(Curve ${src})

target_link_libraries(Curve OpenGLRenderer)
