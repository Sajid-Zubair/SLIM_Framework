cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(slim_test)

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
include_directories(/usr/local/include/slim)

add_library(slim SHARED IMPORTED)
set_target_properties(slim PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib/libslim.dylib")

llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD} all)

add_executable(slim_test main.cpp)
target_link_libraries(slim_test slim ${llvm_libs})
