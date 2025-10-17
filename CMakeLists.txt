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

# --- BLOC0 DE CONFIGURAÇÃO DO SDL2 ---

# 1. Tenta encontrar o SDL2 instalado no sistema
find_package(SDL2 QUIET)

if (SDL2_FOUND)
    # Se o SDL2 for encontrado, usa a versão do sistema
    message(STATUS "SDL2 encontrado no sistema. Utilizando a versão instalada.")
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
else()
    # Se o SDL2 NÃO for encontrado, compila a versão do submodule
    message(STATUS "SDL2 NÃO encontrado no sistema. Compilando o submodule em 'external/SDL'.")

    # Garante que as variáveis de configuração do submodule não causem problemas
    set(SDL_TEST OFF CACHE BOOL "Disable SDL test programs" FORCE)
    set(SDL_SAMPLES OFF CACHE BOOL "Disable SDL sample programs" FORCE)
    set(SDL_TOOLS OFF CACHE BOOL "Disable SDL tools and utilities" FORCE)
    set(SDL_DOCS OFF CACHE BOOL "Disable SDL documentation generation" FORCE)
    
    # Adiciona o diretório do submodule SDL2
    add_subdirectory(external/SDL)

    # Configura inclusões e links para o SDL compilado
    target_include_directories(${PROJECT_NAME} PRIVATE external/SDL/include)

    if(WIN32)
        message(STATUS "Compilando para Windows")
        target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)
        # O target do SDL2 compilado é geralmente 'SDL2::SDL2' ou 'SDL2'
        # Em muitos casos, se você adicionar o subdiretório, o nome do target será o nome do projeto (SDL2)
        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static)
    else()
        message(STATUS "Compilando para Linux/Unix")
        # Links para as bibliotecas estáticas do SDL2 compiladas localmente
        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2-static)
    endif()
    
endif()

# Adiciona o CLI11 (exemplo de outro submodule)
# add_subdirectory(external/CLI11)
# target_include_directories(${PROJECT_NAME} PRIVATE external/CLI11/include)
# target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11)