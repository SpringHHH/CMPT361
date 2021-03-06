cmake_minimum_required(VERSION 2.8)
project(FruitTetris)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set source files
set(SOURCE_FILES
        include/game_manager.h
        include/init_shader.h
        include/lib_consts.h
        include/lib_gl.h
        src/game_manager.cc
        src/fruit_tetris.cc
        src/init_shader.cc
        fshader_unix.glsl
        vshader_unix.glsl
        fshader_mac.glsl
        vshader_mac.glsl)

# Add header include directories
include_directories(include src cmake)

# Find OpenGL
find_package(OpenGL)
include_directories(${OPENGL_INCLUDE_DIRS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

# Find GLUT
find_package(GLUT)
include_directories(${GLUT_INCLUDE_DIRS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

# Find GLEW
find_package(GLEW)
include_directories(${GLEW_INCLUDE_DIRS})
if(NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif(NOT GLEW_FOUND)

# Target
add_executable(Fruittetris ${SOURCE_FILES})
target_link_libraries(Fruittetris ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES})

