cmake_minimum_required(VERSION 3.10)
project(Chip8)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chip8 main.cpp)

# Configurações da SDL

add_subdirectory(external/SDL)
target_include_directories(${PROJECT_NAME} PRIVATE external/SDL/include)

if(WIN32)
    message(STATUS "Compilando para Windows")
    target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static)
else()
    message(STATUS "Compilando para Linux/Unix")
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2-static)
endif()

add_subdirectory(external/CLI11)
target_include_directories(${PROJECT_NAME} PRIVATE external/CLI11/include)
target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11)