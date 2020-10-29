//
// Created by Will Grana on 4/27/20.
//

#ifndef WG_DG_FINAL_PROJECT_GRAPHICS_SQUARE_H
#define WG_DG_FINAL_PROJECT_GRAPHICS_SQUARE_H

#include "shape.h"


class Square : public Shape {
private:
    int sideLength;
public:
    //constructors
    Square();
    Square(int length);

    //deconstructor
    virtual ~Square() = default;

    //getters
    double getSideLength();
    //setters
    void setSideLength(int length);

    //draw function
    void draw() const override;

};

#endif //WG_DG_FINAL_PROJECT_GRAPHICS_SQUARE_H
