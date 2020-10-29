//
// Created by Will Grana on 4/29/20.
//


#ifndef WG_DG_FINAL_PROJECT_GRAPHICS_QUESTION_H
#define WG_DG_FINAL_PROJECT_GRAPHICS_QUESTION_H

#include <string.h>
#include "shape.h"
#include "circle.h"
#include "square.h"
#include "rightTriangle.h"
#include "rectangle.h"
#include "equilateralTriangle.h"
#include <vector>
#include <memory>
using namespace std;

class Question {
private:
    string questionText;
    string answer;
    string answerSide;
    vector<shared_ptr<Shape>> shapes;
public:
    //Constructors
    Question();
    Question(shared_ptr<Shape> a, shared_ptr<Shape> b, string question, string ansr, string aSide);
    //Getters
    string getQuestionText();
    string getCorrectAnswer();
    string getAnswerSide();
    string getAnswer();
    //Setters
    void setQuestionText(string question);
    void setCorrectAnswer(string a);
    void setAnswerSide(string aSide);

    //sets left and right center points and draws shapes
    void drawShapes(point2D leftCenter, point2D rightCenter);
};

#endif //WG_DG_FINAL_PROJECT_GRAPHICS_QUESTION_H
