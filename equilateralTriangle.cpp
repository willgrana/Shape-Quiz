//
// Created by dylan on 4/28/2020.
//


#include "equilateralTriangle.h"
#include "graphics.h"
#include <cmath>

EquilateralTriangle::EquilateralTriangle() : Shape(), sideLength(0) {

}

EquilateralTriangle::EquilateralTriangle(int length) {
    sideLength = length;
}

void EquilateralTriangle::setSideLength(int length){
    sideLength=length;
}

double EquilateralTriangle::getSideLength() {
    return sideLength;
}

void EquilateralTriangle::draw() const {
    glColor3f(1.0, 0, 0.5);
    glBegin(GL_TRIANGLES);
    int vertexX1 = center.x + (.5 * sideLength);
    int vertexY1 = sideLength+ center.y + (tan(PI/6)* .5 *sideLength)+20;
    glVertex2i(vertexX1, vertexY1);
    int vertexX2 = center.x - (.5 * sideLength);
    int vertexY2 = sideLength + center.y + (tan(PI/6)* .5 *sideLength)+20;
    glVertex2i(vertexX2, vertexY2);
    int vertexX3 = center.x;
    int vertexY3 = vertexY1 - (tan(PI/3)* .5 *sideLength);
    glVertex2i(vertexX3, vertexY3);

    glEnd();

}