//
// Created by dylan on 4/27/2020.
//

#include "rightTriangle.h"
#include "graphics.h"
#include <cmath>



RightTriangle::RightTriangle() : Shape(), sideLength(0) {

}

RightTriangle::RightTriangle(int length) {
    sideLength = length;
}

void RightTriangle::setSideLength(int length){
    sideLength=length;
}

double RightTriangle::getSideLength() {
    return sideLength;
}

void RightTriangle::draw() const {
    glColor3f(1.0, 0, 0.5);
    glBegin(GL_TRIANGLES);
    int vertexX1 = center.x;
    int vertexY1 = center.y + (0.5 *sideLength);
    glVertex2i(vertexX1, vertexY1);
    int vertexX2 = center.x;
    int vertexY2 = center.y + (1.5 *sideLength);
    glVertex2i(vertexX2, vertexY2);
    int vertexX3 = center.x + (0.5 *sideLength);
    int vertexY3 = center.y + (1.5 *sideLength);
    glVertex2i(vertexX3, vertexY3);

    glEnd();

}