//
// Created by dylan on 4/27/2020.
//

#ifndef WG_DG_FINAL_PROJECT_GRAPHICS_RIGHTTRIANGLE_H
#define WG_DG_FINAL_PROJECT_GRAPHICS_RIGHTTRIANGLE_H

#include "shape.h"

class RightTriangle : public Shape {
private:
    int sideLength;
public:
    //constructors
    RightTriangle();
    RightTriangle(int length);

    //deconstructor
    virtual ~RightTriangle() = default;

    //getters
    double getSideLength();
    //setters
    void setSideLength(int length);

    //draw function
    void draw() const override;

};

#endif //WG_DG_FINAL_PROJECT_GRAPHICS_RIGHTTRIANGLE_H
