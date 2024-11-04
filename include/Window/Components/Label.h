//
// Created by James Miller on 11/1/24.
//

#ifndef LABEL_H
#define LABEL_H

#include "Item.h"
#include "../../CrossPlatform.h"

class Label : public Item
{
public:
    Label(int id, int x, int y, int width, int height, const std::string& label);
    ~Label() override = default;

    void draw() const override;

    std::string text; // Text to display
};


#endif //LABEL_H
