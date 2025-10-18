cmake_minimum_required(VERSION 3.10)
project(Chip8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/**.cpp")
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include src)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
endif()

find_package(SDL2 QUIET)
if (SDL2_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
else()
    set(SDL_TEST OFF CACHE BOOL "Disable SDL test programs" FORCE)
    set(SDL_SAMPLES OFF CACHE BOOL "Disable SDL sample programs" FORCE)
    set(SDL_TOOLS OFF CACHE BOOL "Disable SDL tools and utilities" FORCE)
    set(SDL_DOCS OFF CACHE BOOL "Disable SDL documentation generation" FORCE)
    
    add_subdirectory(external/SDL)
    target_include_directories(${PROJECT_NAME} PRIVATE external/SDL/include)

    if(WIN32)
        target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)
        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static)
    else()
        message(STATUS "Compilando para Linux/Unix")
        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2-static)
    endif()
    
endif()

file(COPY ${CMAKE_SOURCE_DIR}/roms DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE external/argparse/include)