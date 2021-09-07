cmake_minimum_required(VERSION 3.20)
project(qgl_tutorial03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5Widgets REQUIRED)

add_executable(qgl_tutorial03 qgl_tutorial03.cpp GLShaders.qrc)
qt5_use_modules(qgl_tutorial03 Widgets)
