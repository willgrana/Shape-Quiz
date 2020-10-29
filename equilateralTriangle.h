//
// Created by dylan on 4/28/2020.
//

#ifndef WG_DG_FINAL_PROJECT_GRAPHICS_EQUILATERALTRIANGLE_H
#define WG_DG_FINAL_PROJECT_GRAPHICS_EQUILATERALTRIANGLE_H

#include "shape.h"

class EquilateralTriangle : public Shape {
private:
    int sideLength;
public:
    EquilateralTriangle();
    EquilateralTriangle(int length);

    virtual ~EquilateralTriangle() = default;

    double getSideLength();
    void setSideLength(int length);

    void draw() const override;

};


#endif //WG_DG_FINAL_PROJECT_GRAPHICS_EQUILATERALTRIANGLE_H
