//
// Created by James Miller on 11/1/24.
//

#include "../../../include/Window/Components/Item.h"

void Item::setX(int x)
{
    this->x = x;
}


void Item::setY(const int y)
{
    this->y = y;
}

void Item::setWidth(const int width)
{
    this->width = width;
}

void Item::setHeight(const int height)
{
    this->height = height;
}

void Item::setLabel(const std::string& label)
{
    this->label = label;
}

void Item::draw() const
{
}