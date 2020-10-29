//
// Created by Will Grana on 4/26/20.
//
#include <experimental/optional>
#include <memory>
#include "graphics.h"
#include "circle.h"
#include "square.h"
#include "rightTriangle.h"
#include "rectangle.h"
#include "equilateralTriangle.h"
#include "Question.h"
#include "Quiz.h"
#include <vector>
#include <string.h>


using namespace std;

GLdouble width, height;
int wd;
Quiz Q = Quiz();
int entries = 0;

void init() {
    width = 1000;
    height = 700;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
    point2D left;
    point2D right;
    left.x = 300;
    left.y = 350;
    right.x = 700;
    right.y = 350;
    if (entries==8) {
        string end = "Thanks for playing! You got a " + to_string(Q.getNumCorrect()) +"/8. Use 'ESC' to exit!";
        char e[end.size() + 1];
        strcpy(e, end.c_str());
        drawText(e);
    }

    string str = Q.getQuestion(0).getQuestionText();
    char e[str.size() + 1];
    strcpy(e, str.c_str());

    drawText(e);
    Q.getQuestion(0).drawShapes(left,right);

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT: {
            if (entries==8) {
                Q.checkAnswer("left");
                break;
            }
            Q.checkAnswer("left");
            vector<Question> questionvec = Q.getQuestions();
            questionvec.erase(questionvec.begin());
            Q.setQuestions(questionvec);
            entries++;
            break;
        }
        case GLUT_KEY_RIGHT: {
            if (entries==8) {
                Q.checkAnswer("right");
                break;
            }
            Q.checkAnswer("right");
            vector<Question> questionvec = Q.getQuestions();
            questionvec.erase(questionvec.begin());
            Q.setQuestions(questionvec);
            entries++;
            break;
        }
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(1000, timer, dummy);
}

void drawText(char e[]) {

    int length = strlen(e);
    int L[length];
    for (int t = 0; t<length; t++) {
        L[t] = int(e[t]);
    }
    glRasterPos2f(0., 0.);
    /* Centre in the middle of the window */
    glRasterPos2f(20, 100);
    glColor3f(1., 0., 0.);
    for (int i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, L[i]);
    }
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    shared_ptr<Shape> s1 = make_shared<Square>(160);
    shared_ptr<Shape> s2 = make_shared<EquilateralTriangle>(160);
    shared_ptr<Shape> s3 = make_shared<Rectangle>(160,100);
    shared_ptr<Shape> s4 = make_shared<Circle>(80);
    shared_ptr<Shape> s5 = make_shared<RightTriangle>(160);
    shared_ptr<Shape> exit1 = make_shared<RightTriangle>(0);
    shared_ptr<Shape> exit2 = make_shared<RightTriangle>(0);



    Question q1 = Question(s2,s5,"Use the left arrow or right arrow to choose the equilateral triangle:","EQUILATERALTRIANGLE","left");
    Question q2 = Question(s1,s3,"Use the left arrow or right arrow to choose the square:","SQUARE","left");
    Question q3 = Question(s2,s4,"Use the left arrow or right arrow to choose the Circle:","CIRCLE","right");
    Question q4 = Question(s2,s5,"Use the left arrow or right arrow to choose the Right Triangle:","RIGHTTRIANGLE","right");
    Question q5 = Question(s3,s1,"Use the left arrow or right arrow to choose the Rectangle:","CIRCLE","left");
    Question q6 = Question(s2,s3,"Use the left arrow or right arrow to choose the Equilateral Triangle:","CIRCLE","left");
    Question q7 = Question(s2,s1,"Use the left arrow or right arrow to choose the Square:","SQUARE","right");
    Question q8 = Question(s4,s5,"Use the left arrow or right arrow to choose the Circle:","CIRCLE","left");
    Question q9 = Question(exit1,exit2,"","CIRCLE","none");




    Q.addQuestion(q1);
    Q.addQuestion(q2);
    Q.addQuestion(q3);
    Q.addQuestion(q4);
    Q.addQuestion(q5);
    Q.addQuestion(q6);
    Q.addQuestion(q7);
    Q.addQuestion(q8);
    Q.addQuestion(q9);

    init();

    glutInit(&argc, argv);          // Initialize GLUT
    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Shapes Quiz" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}