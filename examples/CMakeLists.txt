file(GLOB sourceFiles LIST_DIRECTORIES false hello_SDL.cpp)

foreach(file ${sourceFiles})

  get_filename_component(filename  ${file} NAME_WLE)

  add_executable(${filename} WIN32 ${file})

  set_target_properties(${filename} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
  target_compile_options(
    ${filename}
    PUBLIC $<$<CXX_COMPILER_ID:MSVC>:
          /W4
          /WX>
          $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug>>:
          /MTd
          /Od>
          $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Release>>:
          /MT
          /O2>)

  target_compile_options(
  ${filename}
  PUBLIC $<$<CXX_COMPILER_ID:Clang,GNU,AppleClang>:
          -pedantic -Wall -Wextra -Werror -Wconversion
          >
          $<$<AND:$<CXX_COMPILER_ID:Clang,GNU,AppleClang>,$<CONFIG:Debug>>:
          -O0>
          $<$<AND:$<CXX_COMPILER_ID:Clang,GNU,AppleClang>,$<CONFIG:Release>>:
          -O2>
  )
  target_link_libraries(${filename} PRIVATE SDL2main SDL2_mixer SDL2_image SDL2_ttf)

endforeach()
