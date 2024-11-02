//
// Created by James Miller on 11/1/24.
//

#include "../../../include/Window/Components/Label.h"

Label::Label(int id, int x, int y, int width, int height, const std::string& label)
    : Item(id, x, y, width, height, label)
{
}

void Label::draw() const
{
    // Draw the label text
    // This is where the label text would be drawn to the screen
    // using the X11 library
}