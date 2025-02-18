cmake_minimum_required(VERSION 3.10)

project(GP2RSXML)

include_directories(include)
add_subdirectory(src)
link_directories(src)
add_executable(GP2RSXML main.cpp)
target_link_libraries(GP2RSXML PUBLIC gp2rs zip pugixml)
