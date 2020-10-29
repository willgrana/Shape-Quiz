//
// Created by Will Grana on 4/29/20.
//

#include "Question.h"
using namespace std;

Question::Question() {

}

Question::Question(shared_ptr<Shape> a, shared_ptr<Shape> b, string question, string ansr, string aSide) {
    shapes.push_back(move(a));
    shapes.push_back(move(b));
    questionText = question;
    answer = ansr;
    answerSide = aSide;
}

string Question::getQuestionText() {
    return questionText;
}

string Question::getCorrectAnswer() {
    return answer;
}

string Question::getAnswerSide() {
    return answerSide;
}

string Question::getAnswer() {
    return answer;
}

void Question::setQuestionText(string question) {
    questionText = question;
}

void Question::setCorrectAnswer(string a) {
    answer = a;
}

void Question::setAnswerSide(string aSide) {
    answerSide = aSide;
}

void Question::drawShapes(point2D leftCenter, point2D rightCenter) {
    shapes[0]->setCenter(leftCenter);
    shapes[1]->setCenter(rightCenter);
    for (int i=0; i<shapes.size(); i++) {
        shapes[i]->draw();
    }
}

