cmake_minimum_required(VERSION 3.19)
project(ct_raytracer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(${PROJECT_SOURCE_DIR}/library/json)
include_directories(${PROJECT_SOURCE_DIR}/library/json/include)

include_directories(${PROJECT_SOURCE_DIR}/library/eigen-git-mirror)
include_directories(${PROJECT_SOURCE_DIR}/library/gzip-hpp/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/library/zlib)
include_directories(${PROJECT_SOURCE_DIR}/library/zlib)

include_directories(${PROJECT_SOURCE_DIR}/library/cpp-base64)
add_library(cpp_base64 ${PROJECT_SOURCE_DIR}/library/cpp-base64/base64.cpp)

file(GLOB ct_rt_src ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(ct_raytracer ${ct_rt_src})
target_link_libraries(ct_raytracer cpp_base64 nlohmann_json::nlohmann_json zlibstatic)

macro(show_var)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
endmacro()

#show_var()