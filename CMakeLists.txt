cmake_minimum_required(VERSION 3.22)
project(MillerInc_GUI_Library)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
#    target_link_libraries(MillerInc_GUI_Library X11)
elseif (UNIX)
    find_package(X11 REQUIRED)
    include_directories(${X11_INCLUDE_DIR})
#    target_link_libraries(MillerInc_GUI_Library ${X11_LIBRARIES})
endif()

add_library(MillerInc_GUI_Library STATIC source/library.cpp
        include/library.h
        include/GUI.h
        include/Window/CustomWindow.h
        source/Window/CustomWindow.cpp
        include/CrossPlatform.h
        include/Window/Windows/WindowsWindow.h
        source/Window/Windows/WindowsWindow.cpp
        source/Window/Linux/LinuxWindow.cpp
        include/Window/Linux/LinuxWindow.h
        include/Window/Linux/Components/LinuxButton.h
        include/Window/Linux/Components/LinuxButton.h
        include/Window/Components/Button.h
        source/Window/Components/Button.cpp
        source/Window/Components/Button.cpp
        source/Window/Linux/Components/LinuxButton.cpp
        include/Window/Components/Item.h
        include/Window/Components/Item.h
        include/Window/Components/Item.h
        include/Window/Components/Item.h
        source/Window/Components/Item.cpp
        include/Window/Components/Label.h
        include/Window/Components/Label.h
        source/Window/Components/Label.cpp
        source/Window/Components/Label.cpp
        include/Window/Components.h
        include/Window/Components.h
        include/Window/Linux/Components/LinuxLabel.h
        include/Window/Linux/Components/LinuxLabel.h
        source/Window/Linux/Components/LinuxLabel.cpp
        source/Window/Linux/Components/LinuxLabel.cpp
        include/Window/Linux/LinuxComponents.h
        include/Window/Linux/LinuxComponents.h
        include/Window/Windows/WindowsComponents.h
        include/Window/Windows/WindowsComponents.h
        include/Window/Windows/Components/WindowsButton.h
        source/Window/Windows/WindowsButton.cpp
        include/Window/Windows/Components/WindowsLabel.h
        source/Window/Windows/WindowsLabel.cpp
)

if (WIN32)
#    target_link_libraries(MillerInc_GUI_Library X11)
elseif (UNIX)
    find_package(X11 REQUIRED)
    target_link_libraries(MillerInc_GUI_Library ${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
endif()