#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;


// void drawSquare(void)
// {
//   glClear(GL_COLOR_BUFFER_BIT);
//   glBegin(GL_POLYGON);
//     glVertex3f(0.0, 0.0, 0.0);
//     glVertex3f(0.5, 0.0, 0.0);
//     glVertex3f(0.5, 0.5, 0.0);
//     glVertex3f(0.0, 0.5, 0.0);
//   glEnd();
//   glFlush();
// }

void inputKeyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    printf("Bye");
    exit(0);
    break;
  
  case 'f':
    glutFullScreen();
    break;
  
  case 's':
    glutReshapeWindow(100,100);
    glutPositionWindow(100,100);
    break;
  
  default:
    break;
  }
}

void draw(void) 
{
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

// void init (void) 
// {
//   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
// }

void backgroundStyle(int operation) {

  switch (operation)
  {
  case 0:
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    break;
  
  case 1:
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    break;
  
  case 2:
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    break;
  
  default:  
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    break;
  }
  glutPostRedisplay();
}

void menu() {
  
  int menu = glutCreateMenu(backgroundStyle);

  glutAddMenuEntry("Vermelho", 0);
  glutAddMenuEntry("Verde", 1);
  glutAddMenuEntry("Azul", 2);
  glutAddMenuEntry("Preto", 3);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(100, 100);
  
  glutCreateWindow("OPENGLLABS");
  glutDisplayFunc(draw);

  // Input do Teclado
  glutKeyboardFunc(inputKeyboard);

  backgroundStyle(3);  
  menu();

  glutMainLoop();
  
  return 0;
}