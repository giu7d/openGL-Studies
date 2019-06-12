// #include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50, ang = 0;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
GLfloat translationXBias = 0.0f;

GLfloat windowWidth;
GLfloat windowHeight;

void Draw(void);
void Timer(int value);
void Init (void);
void ScaleWindow(GLsizei w, GLsizei h);
void DrawHouse(void);
void DrawMissil(void);

// KEYBOARD
void inputKeyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    printf("Bye");
    exit(0);
    break;
  
  case 'a':
    translationXBias-=0.1;
    break;
  
  case 'd':
    translationXBias+=0.1;
    break;
  
  default:
    break;
  }
}


void Draw(void)
{
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
  DrawMissil();

  glutSwapBuffers(); // � o flush para imagens bufferizadas
  // glFlush();
}


void DrawMissil(void)
{

  glLoadIdentity();
  glRotatef(ang++,0,0,1);
  glTranslatef(0.0 + translationXBias,0.0,0.0);

  // Tip
  glColor3ub(0,0,255);
  glBegin(GL_QUADS);
    glVertex2f(0.0,0.0);
    glVertex2f(0.10,0.0);
    glVertex2f(0.05,0.10);
    glVertex2f(0.0,0.0);
  glEnd();
  

  // Body
  glColor3ub(0,255,0);
  glBegin(GL_QUADS);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.0);
    glVertex2f(0.1,-0.4);
    glVertex2f(0.0,-0.4);
    glVertex2f(0.0,0.0);
  glEnd();

  //Left Wing 
  glColor3ub(255,0,0);
  glBegin(GL_QUADS);
    glVertex2f(0.0,-0.4);
    glVertex2f(-0.1,-0.4);
    glVertex2f(0.0,-0.2);
    glVertex2f(0.0,-0.4);
  glEnd();


  //Right Wing 
  glColor3ub(255,0,0);
  glBegin(GL_QUADS);
    glVertex2f(0.1,-0.4);
    glVertex2f(0.2,-0.4);
    glVertex2f(0.1,-0.2);
    glVertex2f(0.1,-0.4);
  glEnd();

  // Fire Red
  glColor3ub(255,0,0);
  glBegin(GL_QUADS);
    glVertex2f(0.0,-0.4);
    glVertex2f(0.1,-0.4);
    glVertex2f(0.05,-0.6);
    glVertex2f(0.0,-0.4);
  glEnd();
  // Fire Yellow
  glColor3ub(255,255,0);
  glBegin(GL_QUADS);
    glVertex2f(0.0,-0.4);
    glVertex2f(0.1,-0.4);
    glVertex2f(0.05,-0.5);
    glVertex2f(0.0,-0.4);
  glEnd();

  glLoadIdentity();
}

void DrawHouse(void)
{  
  // Wall
  glColor3ub(0,0,255);

  glBegin(GL_QUADS);
    glVertex3f(-0.5,-0.5, 0.0);
    glVertex3f(-0.5,0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.5,-0.5, 0.0);
  glEnd();
  
  // Door
  glColor3ub(255,255,255);
  glBegin(GL_QUADS);
  
    glVertex3f(-0.1,-0.5, 0.0);
    glVertex3f(-0.1,-0.1, 0.0);
    glVertex3f(0.1,-0.1, 0.0);
    glVertex3f(0.1,-0.5, 0.0);
  glEnd();

  // Roof
  glLoadIdentity();
  glColor3ub(0,255,0);
  glRotatef(ang++,0,0,1);

  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(-0.5,0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
  glEnd();

  glLoadIdentity();


}

void Timer(int value)
{

  if(x1 > windowWidth-rsize || x1 < 0)
    xstep = -xstep;
  if(y1 > windowHeight-rsize || y1 < 0)
    ystep = -ystep;

  if(x1 > windowWidth-rsize)
    x1 = windowWidth-rsize-1;
  if(y1 > windowHeight-rsize)
    y1 = windowHeight-rsize-1;

  x1 += xstep;
  y1 += ystep;
  glutPostRedisplay();
  glutTimerFunc(33,Timer, 1);
}

void Init (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


int main(int argc, char *argv[])
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  //  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);     
  glutCreateWindow("Anima");

  glutDisplayFunc(Draw);
  glutTimerFunc(33, Timer, 1);
  glutKeyboardFunc(inputKeyboard);

  Init();

  glutMainLoop();
}
