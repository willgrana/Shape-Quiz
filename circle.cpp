//
// Created by Will Grana on 4/27/20.
//

#include "circle.h"
#include "graphics.h"

Circle::Circle() : Shape(), radius(0) {
}

Circle::Circle(double radius) : Shape() {
    setRadius(radius);
}



double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    if (r < 0) {
        r = 0;
    }
    radius = r;
}


void Circle::draw() const {
    // Set drawing color to fill color
    glColor3f(1.0, 0, 0.5);
    // Draw circle as Triangle Fan
    glBegin(GL_TRIANGLE_FAN);
    // Draw center point
    glVertex2i(center.x, center.y);
    // Draw points on edge of circle
    for (double i = 0; i < 2.0*PI+0.05; i += (2.0*PI)/360.0) {
        glVertex2i(center.x + (radius * cos(i)),
                   center.y + (radius * sin(i)));
    }
    // End Triangle Fan
    glEnd();
}