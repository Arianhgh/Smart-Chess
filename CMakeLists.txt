cmake_minimum_required(VERSION 3.1.0)
project(chess)
set(CMAKE_CXX_STANDARD 11)
set(SRC_DIRECTORY src)
set(SFML_DIR "C:\\Users\\Arian\\OneDrive\\Documents\\GitHub\\AP-Chess\\SFML-2.6.0\\lib\\cmake\\SFML")
set(INCLUDE_DIRECTORY headers)
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)
set(SOURCES ${SRC_DIRECTORY}/piece.cpp
            ${SRC_DIRECTORY}/kings.cpp
            ${SRC_DIRECTORY}/board.cpp)
include_directories(${INCLUDE_DIRECTORY})
add_executable(${PROJECT_NAME}
              ${SRC_DIRECTORY}/main.cpp
              ${SOURCES})
target_link_libraries(${PROJECT_NAME}
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio)

