//
// Created by James Miller on 11/1/24.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Item.h"

class Button : public Item
{
public:
    Button(int id, int x, int y, int width, int height, const std::string& label);
    ~Button() override = default;

    void draw() const override;

    [[nodiscard]] int getId() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] const std::string& getLabel() const;

    virtual void setPos(int x, int y);
    virtual void setSize(int width, int height);
    void setLabel(const std::string& label) override;
    virtual void setColor(unsigned long color);

protected:
    int id{};
    int x{}, y{}, width{}, height{};
    std::string label;
    unsigned long color{ 0x000000 };
};

#endif // BUTTON_H
