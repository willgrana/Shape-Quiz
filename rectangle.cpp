//
// Created by Will Grana on 4/27/20.
//

#include "rectangle.h"
#include "graphics.h"

Rectangle::Rectangle() : Shape(), sideLengthX(0), sideLengthY(0) {

}

Rectangle::Rectangle(int lengthX, int lengthY) {
    sideLengthX = lengthX;
    sideLengthY = lengthY;
}

void Rectangle::setSideLengths(int lengthX, int lengthY){
    sideLengthX=lengthX;
    sideLengthY=lengthY;
}

double Rectangle::getSideLengthX() {
    return sideLengthX;
}

double Rectangle::getSideLengthY() {
    return sideLengthY;
}

void Rectangle::draw() const {
    glColor3f(1.0, 0, 0.5);
    glBegin(GL_QUADS);
    int vertexX1 = center.x + (.5*sideLengthX);
    int vertexY1 = center.y + (.5*sideLengthY);
    glVertex2i(vertexX1, vertexY1);
    glVertex2i(vertexX1, vertexY1+sideLengthY);
    glVertex2i(vertexX1-sideLengthX, vertexY1+sideLengthY);
    glVertex2i(vertexX1-sideLengthX, vertexY1);

    glEnd();

}

