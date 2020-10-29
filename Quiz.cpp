//
// Created by Will Grana on 4/30/20.
//

#include "Quiz.h"
using namespace std;

Quiz::Quiz() {
    numCorrect = 0;
}

Quiz::Quiz(Question a, Question b, Question c, Question d, Question e, Question f, Question g, Question h) {
    numCorrect = 0;
    questions.push_back(a);
    questions.push_back(b);
    questions.push_back(c);
    questions.push_back(d);
    questions.push_back(e);
    questions.push_back(f);
    questions.push_back(g);
    questions.push_back(h);
}

Question Quiz::getQuestion(int questionNumber) {
    return questions[questionNumber];
}

int Quiz::getNumCorrect() {
    return numCorrect;
}



vector<Question> Quiz::getQuestions() {
    return questions;
}

void Quiz::setQuestion(Question q, int questionNumber) {
    questions[questionNumber] = q;
}

void Quiz::setNumCorrect(int c) {
    numCorrect = c;
}



void Quiz::setQuestions(vector<Question> v) {
    questions = v;
}

void Quiz::checkAnswer(string useranswer) {
    if(questions[0].getAnswerSide()==useranswer) {
        numCorrect++;

    }
}

void Quiz::addQuestion(Question q) {
    questions.push_back(q);
}