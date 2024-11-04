//
// Created by James Miller on 11/1/2024.
//

#ifndef WINDOWSLABEL_H
#define WINDOWSLABEL_H

#include "../../Components/Label.h"

#ifdef WINDOWS

class WindowsLabel : public Label {
public:
    WindowsLabel(int id, int width, int height, int x, int y, const std::string& text);
    void draw() const override;
};

#endif

#endif //WINDOWSLABEL_H
