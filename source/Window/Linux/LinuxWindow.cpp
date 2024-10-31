//
// Created by James Miller on 10/31/2024.
//

#ifdef LINUX || DEBUG // Debug to check syntax when on windows

#include "../../../include/Window/Linux/LinuxWindow.h"
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <iostream>

LinuxWindow::LinuxWindow(int width, int height, int x, int y, const std::string* title)
    : Window(width, height, x, y, title), display(XOpenDisplay(NULL)), window(width, height, x, y, title)
{
    if (display == NULL)
    {
        std::cerr << "Cannot open display\n";
        exit(1);
    }

    int screen = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, screen), x, y, width, height, 1,
                                 BlackPixel(display, screen), WhitePixel(display, screen));

    XStoreName(display, window, title->c_str());

    wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDeleteMessage, 1);

    XSelectInput(display, window, ExposureMask | KeyPressMask);
}

LinuxWindow::~LinuxWindow()
{
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

void LinuxWindow::show()
{
    XMapWindow(display, window);

    XEvent event;
    while (true) {
        XNextEvent(display, &event);

        if (event.type == Expose) {
            // Handle expose event
        } else if (event.type == KeyPress) {
            // Handle key press event
        } else if (event.type == ClientMessage) {
            if (event.xclient.data.l[0] == wmDeleteMessage) {
                break;
            }
        }
    }
}

#endif //LINUX