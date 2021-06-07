cmake_minimum_required(VERSION 3.16)

# set the project name
project(main VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(main main.cpp Dungeon.cpp GameCharacter.cpp Item.cpp Player.cpp Room.cpp)

configure_file(config.h.in config.h)
target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
