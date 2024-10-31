cmake_minimum_required(VERSION 3.29)
project(MillerInc_GUI_Library)

set(CMAKE_CXX_STANDARD 20)

add_library(MillerInc_GUI_Library STATIC source/library.cpp
        include/library.h
        include/GUI.h
        include/Window/Window.h
        source/Window/Window.cpp
        include/CrossPlatform.h
        include/Window/Windows/WindowsWindow.h
        source/Window/Windows/WindowsWindow.cpp)
