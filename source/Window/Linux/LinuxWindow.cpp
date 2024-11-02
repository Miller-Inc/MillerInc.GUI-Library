//
// Created by James Miller on 10/31/2024.
//

#include "../../../include/Window/Linux/LinuxWindow.h"

#if defined LINUX || defined DEBUG // Debug to check syntax when on windows

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <iostream>

#include <thread>

LinuxWindow::LinuxWindow(int width, int height, int x, int y, const std::string* title)
    : CustomWindow(width, height, x, y, title), display(XOpenDisplay(nullptr)),
      windowColor(WhitePixel(display, DefaultScreen(display))),
      buttonColor(WhitePixel(display, DefaultScreen(display)))
{
    if (display == nullptr)
    {
        std::cerr << "Cannot open display\n";
        exit(1);
    }

    int screen = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, screen), x, y, width, height, 1,
                                 BlackPixel(display, screen), windowColor);

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

void LinuxWindow::update() {
    XClearWindow(display, window);
    for (const auto& item : WindowItems) {
        item->draw();
    }
    XFlush(display);
    std::cout << "Window updated\n";
}

void LinuxWindow::show()
{
    isRunning = true; // Set the running flag to true
    XMapWindow(display, window);

    XEvent event;
    while (isRunning) {
        XNextEvent(display, &event);

        if (event.type == Expose) {
            // Redraw the window content
            update();
        } else if (event.type == KeyPress) {
            // Handle key press event
        } else if (event.type == ButtonPress) {
            // Handle button press event
            std::cout << "Button pressed at (" << event.xbutton.x << ", " << event.xbutton.y << ")\n";
        } else if (event.type == ClientMessage) {
            if (event.xclient.data.l[0] == wmDeleteMessage) {
                isRunning = false; // Set the running flag to false
                break;
            }
        }
    }
}



void LinuxWindow::setWindowColor(unsigned long color)
{
    windowColor = color;
    XSetWindowBackground(display, window, windowColor);
    XClearWindow(display, window);
}

void LinuxWindow::setButtonColor(unsigned long color)
{
    buttonColor = color;
}

void LinuxWindow::addButton(Button* button) {
    if (auto* linuxButton = dynamic_cast<LinuxButton*>(button)) {
        WindowItems.push_back(linuxButton);
        linuxButton->draw();
    }
}

void LinuxWindow::addLabel(Label* label)
{
    if (auto* linuxLabel = dynamic_cast<LinuxLabel*>(label)) {
        WindowItems.push_back(linuxLabel);
        linuxLabel->draw();
    }
}

#endif //LINUX
