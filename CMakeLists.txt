cmake_minimum_required(VERSION 3.14)
project(cass_lion CXX)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM3 REQUIRED gtkmm-3.0)

INCLUDE_DIRECTORIES(${GTKMM3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM3_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} main.cpp MainWindow.cpp MainWindow.h AbstractKeyEventedWindow.cpp AbstractKeyEventedWindow.h KeyCombination.cpp KeyCombination.h AbstractWindowWithShortcuts.cpp AbstractWindowWithShortcuts.h)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTKMM3_LIBRARIES})

