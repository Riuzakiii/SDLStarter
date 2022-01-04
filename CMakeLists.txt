cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)

set(GLOBAL_APP_NAME "SDL")
project(${GLOBAL_APP_NAME})
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/generated)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/ThirdParties/SDL)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/ThirdParties/SDL_ttf/external/freetype-2.10.4)
add_library(Freetype::Freetype ALIAS freetype)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/ThirdParties/SDL_ttf)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/ThirdParties/SDL_image)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/ThirdParties/SDL_mixer)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/examples)

target_compile_definitions(SDL2_mixer PUBLIC MUSIC_WAV)
install(TARGETS SDL2_image png freetype SDL2_mixer DESTINATION bin)
