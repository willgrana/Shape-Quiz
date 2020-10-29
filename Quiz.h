//
// Created by Will Grana on 4/29/20.
//

#ifndef WG_DG_FINAL_PROJECT_GRAPHICS_QUIZ_H
#define WG_DG_FINAL_PROJECT_GRAPHICS_QUIZ_H

#include "Question.h"

class Quiz {
private:
    vector<Question> questions;
    int numCorrect;

public:

    Quiz();
    Quiz(Question a,Question b,Question c, Question d, Question e, Question f, Question g, Question h);

    //Getters
    Question getQuestion(int questionNumber);
    int getNumCorrect();
    vector<Question> getQuestions();

    //Setters
    void setQuestion(Question q, int questionNumber);
    void setNumCorrect(int c);
    void setQuestions(vector<Question> v);

    //checks to see if user entered the correct response and adds correct responses to score count
    void checkAnswer(string useranswer);
    //pushes quetions onto question vector
    void addQuestion(Question q);

};

#endif //WG_DG_FINAL_PROJECT_GRAPHICS_QUIZ_H
