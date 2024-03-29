
# CMake configuration

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(Algo)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(
    SOURCE_FILES
    src/main.cpp
    src/Engine/Engine.cpp
    src/Renderer/Renderer.cpp
    src/Sorting/Util/Utils.cpp
    src/Sorting/MergeSort/MergeSort.cpp
    src/Sorting/InsertionSort/InsertionSort.cpp
    src/Sorting/SelectionSort/SelectionSort.cpp
    src/Sorting/QuickSort/QuickSort.cpp
    src/Sorting/ShellSort/ShellSort.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_TTF REQUIRED)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_ttf::SDL2_ttf)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIR})
