cmake_minimum_required(VERSION 3.10)
project(GraphProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
# Указание директории с заголовочными файлами
include_directories(include)

# Добавление исполняемого файла и исходных файлов
add_executable(GraphProject
    src/main.cpp
    src/Graph.cpp
    src/ListGraph.cpp
    src/ArcGraph.cpp
    src/MatrixGraph.cpp
    src/SetGraph.cpp
)