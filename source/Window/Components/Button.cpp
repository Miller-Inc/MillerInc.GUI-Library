//
// Created by James Miller on 11/1/24.
//

#include "../../../include/Window/Components/Button.h"

#include <iostream>

Button::Button(int id, int x, int y, int width, int height, const std::string& label)
    : Item(id, x, y, width, height, label)
{
}

void Button::draw() const
{
    std::cout << "Button drawn at (" << x << ", " << y << ")\n";
}

int Button::getId() const
{
    return id;
}

int Button::getX() const
{
    return x;
}

int Button::getY() const
{
    return y;
}

int Button::getWidth() const
{
    return width;
}

int Button::getHeight() const
{
    return height;
}

const std::string& Button::getLabel() const
{
    return label;
}

void Button::setPos(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Button::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Button::setLabel(const std::string& label)
{
    this->label = label;
}

void Button::setColor(unsigned long color)
{
    this->color = color;
}


