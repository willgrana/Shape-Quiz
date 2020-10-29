//
// Created by Will Grana on 4/27/20.
//

#ifndef WG_DG_FINAL_PROJECT_GRAPHICS_RECTANGLE_H
#define WG_DG_FINAL_PROJECT_GRAPHICS_RECTANGLE_H

#include "shape.h"


class Rectangle : public Shape {
private:
    int sideLengthX;
    int sideLengthY;
public:
    //constructors
    Rectangle();
    Rectangle(int lengthX, int lengthY);

    //deconstructor
    virtual ~Rectangle() = default;
    //getters
    double getSideLengthX();
    double getSideLengthY();
    //setters
    void setSideLengths(int lengthX, int lengthY);

    //draw function
    void draw() const override;

};

#endif //WG_DG_FINAL_PROJECT_GRAPHICS_RECTANGLE_H
