//
// Created by James Miller on 11/1/24.
//

#ifndef LINUXLABEL_H
#define LINUXLABEL_H

#include "../../../CrossPlatform.h"

#ifdef LINUX

#include <X11/Xlib.h>
#include "../../Components/Label.h"

class LinuxLabel : public Label
{
public:
    LinuxLabel(int id, int x, int y, int width, int height, const std::string& text, Display* display, Window parent);
    void draw() const override;

private:
    Display* display;
    Window parent;
    Window labelWindow;
};

#endif //LINUX

#endif //LINUXLABEL_H