cmake_minimum_required(VERSION 3.14)
project(Infographie)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

find_package(OpenGL REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

message("Including GLEW")
include_directories(Dependencies/GLEW_STATIC/include)

message("Linking GLEW")
link_directories(Dependencies/GLEW_STATIC/lib/Release/x64/glew32s.lib)

message("Including GLFW")
include_directories("Dependencies/GLFW/include")
message("Linking GLFW")
link_directories("Dependencies/GLFW/lib-mingw")

message("Including GLM")
include_directories(Dependencies/GLM)
add_subdirectory(Dependencies/GLM)

add_executable(Infographie src/main.cpp
        src/Geometry.cpp
        src/Geometry.h
        src/VAO.h
        src/VAO.cpp
        src/VBO.h
        src/VBO.cpp
        src/ShaderProgram.h
        src/ShaderProgram.cpp)

target_link_libraries(Infographie glfw3 glew32s.lib ${OPENGL_LIBRARIES})
