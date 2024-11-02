//
// Created by James Miller on 10/30/2024.
//

#ifndef GUI_H
#define GUI_H

// Full Include List
#include "library.h"
#include "CrossPlatform.h"

#include "Window/CustomWindow.h"
#ifdef WINDOWS
#include "Window/Windows/WindowsWindow.h"
#elif defined MACOS
#throw "MacOS is not supported yet."
#elif defined LINUX
#include "Window/Linux/LinuxWindow.h"
#endif

#include "Window/Components.h"

#endif //GUI_H
