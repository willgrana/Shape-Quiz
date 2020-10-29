//
// Created by Will Grana on 4/27/20.
//

#include "square.h"
#include "graphics.h"

Square::Square() : Shape(), sideLength(0) {

}

Square::Square(int length) {
    sideLength = length;
}

void Square::setSideLength(int length){
    sideLength=length;
}

double Square::getSideLength() {
    return sideLength;
}

void Square::draw() const {
    glColor3f(1.0, 0, 0.5);
    glBegin(GL_QUADS);
    int vertexX1 = center.x + (.5*sideLength);
    int vertexY1 = center.y + (.5*sideLength);
    glVertex2i(vertexX1, vertexY1);
    glVertex2i(vertexX1, vertexY1+sideLength);
    glVertex2i(vertexX1-sideLength, vertexY1+sideLength);
    glVertex2i(vertexX1-sideLength, vertexY1);

    glEnd();

}