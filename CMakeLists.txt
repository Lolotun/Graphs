cmake_minimum_required(VERSION 3.10)
project(GraphProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указание директории с заголовочными файлами
include_directories(include)

# Добавление исполняемого файла и исходных файлов
add_executable(GraphProject
    src/main.cpp
    src/Graph.cpp
    src/ListGraph.cpp
)