# C++ Shapes Quiz with GUI
This project is a shape recognition quiz. It uses the GLUT GUI to draw circles,
squares, rectangles, equilateral triangles, and right triangles. It then takes in keyboard inputs
for the left and right arrow keys for answer selection. It starts by displaying two shapes and has the user pick
which shape is the correct one using the arrow keys. After all the questions are finished it
displays the users score. The user can then use the escape key to exit the program.

Program draws objects of five different classes.

In the Question class, the drawShapes() function uses polymorphism by drawing
objects of different classes with the overridden virtual method draw() from a vector of
smart pointers of different Shape child classes.

The main function is in graphics.cpp.
