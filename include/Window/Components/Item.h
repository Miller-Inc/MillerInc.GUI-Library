//
// Created by jwmiller on 11/1/24.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <utility>

class Item {
public:
    Item(const int id, const int x, const int y, const int width, const int height, std::string  label)
        : id(id), x(x), y(y), width(width), height(height), label(std::move(label)) {}

    virtual ~Item() = default;

    virtual void draw() const = 0;

    [[nodiscard]] int getId() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] const std::string& getLabel() const;

    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    virtual void setLabel(const std::string& label);

protected:
    int id; // Unique identifier for the item
    int x, y, width, height;
    std::string label;


};


#endif //ITEM_H
