//
// Created by Will Grana on 4/27/20.
//

#ifndef WG_DG_FINAL_PROJECT_GRAPHICS_CIRCLE_H
#define WG_DG_FINAL_PROJECT_GRAPHICS_CIRCLE_H

#include "shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    /* Constructors */
    Circle();
    explicit Circle(double radius);


    /* Destructor */
    virtual ~Circle() = default;

    /* Getter */
    double getRadius() const;

    /* Setter */
    void setRadius(double r);
    

    /* Draw */
    void draw() const override;

};

#endif //WG_DG_FINAL_PROJECT_GRAPHICS_CIRCLE_H
