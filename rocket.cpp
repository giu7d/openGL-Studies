#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

/*
    Global Variable
*/

GLfloat xInitial = 100.0f;
GLfloat yInitial = 150.0f;
GLfloat windowWidth;
GLfloat windowHeight;
GLsizei rsize = 50, ang = 0;
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat rotationBias = 0.0f;
GLfloat translationXBias = 0.0f;
GLfloat translationYBias = 0.0f;

float rotationSpeed = 5.0;
float translationSpeed = 0.1;

/*
    Header
*/
void InputKeyboard(unsigned char key, int x, int y);
void Draw(void);
void DrawRocket(void);
void Init (void);
void Timer(int value);


/*
    Implementation
*/

// IO (Keyboar & Mouse)
void InputKeyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    printf("Bye");
    exit(0);
    break;
  
  // Rocket Controls
  case 'a':
    translationXBias -= translationSpeed;
    break;
  
  case 'd':
    translationXBias += translationSpeed;
    break;

  case 'w':
    translationYBias += translationSpeed;
    break;

  case 's':
    translationYBias -= translationSpeed;
    break;

  case 'z':
    rotationBias-=rotationSpeed;
    break;
  
  case 'x':
    rotationBias+=rotationSpeed;
    break;

  default:
    break;
  }
}

// DRAW
void Draw(void)
{
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
  DrawRocket();
  glutSwapBuffers();
}

// Rocket
void DrawRocket(void)
{
  glLoadIdentity();

  // Rotate anchor on Point 0,0
  glTranslatef(translationXBias,translationYBias,0.0);
  glRotatef(rotationBias,0,0,1);

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

void Init (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Timer(int value)
{

  if(xInitial > windowWidth-rsize || xInitial < 0)
    xstep = -xstep;
  if(yInitial > windowHeight-rsize || yInitial < 0)
    ystep = -ystep;

  if(xInitial > windowWidth-rsize)
    xInitial = windowWidth-rsize-1;
  if(yInitial > windowHeight-rsize)
    yInitial = windowHeight-rsize-1;

  xInitial += xstep;
  yInitial += ystep;
  glutPostRedisplay();
  glutTimerFunc(33,Timer, 1);
}


// Program Main 
int main(int argc, char *argv[])
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);     
  glutCreateWindow("Rocket");

  glutDisplayFunc(Draw);
  glutTimerFunc(33, Timer, 1);
  glutKeyboardFunc(InputKeyboard);

  Init();

  glutMainLoop();
}
