//
// Created by James Miller on 10/30/2024.
//

#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H

#if defined _WIN32 || defined _WIN64
    #define WINDOWS
#elif defined __APPLE__
    #define MACOS
#elif defined __linux__ || defined __unix__
    #define LINUX
#endif

#ifdef WINDOWS
    #include <windows.h>
#elif defined MACOS
    #include <ApplicationServices/ApplicationServices.h>
#elif defined LINUX
    #include <X11/Xlib.h>
#endif

#endif //CROSSPLATFORM_H
