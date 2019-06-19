#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

/*
    Global Variable
*/

/*
    Header
*/
void Init (void);


/*
    Implementation
*/
void Init (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


// Program Main 
int main(int argc, char *argv[])
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  //  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);     
  glutCreateWindow("Anima");

  // glutDisplayFunc(Draw);
  // glutTimerFunc(33, Timer, 1);
  // glutKeyboardFunc(InputKeyboard);
  // glutPassiveMotionFunc(TrackMouse);

  // Init();

  glutMainLoop();
}
