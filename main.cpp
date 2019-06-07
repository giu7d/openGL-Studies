// Exercise 02
// Main (In progress)
// 

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

void draw(void) 
{
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}


int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(100, 100);
  
  glutCreateWindow("OPENGLLABS");
  // glutDisplayFunc(draw);

  // Input do Teclado
  // glutKeyboardFunc(inputKeyboard);

  // drawBackground(3);  
  // drawMenu();
  // drawSquare();

  glutMainLoop();
  
  return 0;
}