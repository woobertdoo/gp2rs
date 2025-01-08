cmake_minimum_version(VERSION 3.13...3.18)

set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_PYTHON OFF CACHE BOOL " " FORCE)
set(NANOGUI_INSTALL OFF CACHE BOOL " " FORCE)

add_subdirectory(libs/nanogui)

set_property(TARGET glfw glfw_objects nanogui PROPERTY FOLDER "dependencies")

add_definitions(${NANOGUI_EXTRA_DEFS})

include_directories(${NANOGUI_EXTRA_INCS})

add_executable(RocksmithCharter main.cpp)

target_link_libraries(RocksmithCharter nanogui ${NANOGUI_EXTRA_LIBS})
