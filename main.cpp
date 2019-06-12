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

GLfloat windowWidth;
GLfloat windowHeight;

void Draw(void);
void Timer(int value);
void Init (void);
void ScaleWindow(GLsizei w, GLsizei h);
void DrawHouse(void);


void Draw(void)
{
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
  DrawHouse();

  glutSwapBuffers(); // � o flush para imagens bufferizadas
  // glFlush();
}

void DrawHouse(void)
{  
  glLoadIdentity();
  // Wall
  glColor3ub(0,0,255);
  glRotatef(ang++,0,0,1);

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
  glColor3ub(0,255,0);
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

void ScaleWindow(GLsizei w, GLsizei h)
{

  if(h == 0) h = 1;

  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)  {
		windowHeight = 5.0f*h/w;
		windowWidth = 5.0f;
  }
  else  {
		windowWidth = 5.0f*w/h;
		windowHeight = 5.0f;
  }

  gluOrtho2D(2.5f, windowWidth, 2.5f, windowHeight);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(10,10);     
    glutCreateWindow("Anima");

    glutDisplayFunc(Draw);
    glutReshapeFunc(ScaleWindow);
    glutTimerFunc(33, Timer, 1);

    Init();

    glutMainLoop();
}



// // OpenGL Lab - Studies Code
// // 
// // We Learn (only 2D):
// // Start Project
// // Handle Keyboard
// // Handle Click
// // Draw Menus
// // Draw Background
// // Draw Poligons


// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <GL/glut.h>
// #include <iostream>
// #define WINDOW_SIZE 300

// using namespace std;

// GLint height;
// GLint width;
// GLfloat rate;

// void inputKeyboard(unsigned char key, int x, int y);
// void scaleWindow(GLsizei w, GLsizei h);
// void draw(void);
// void drawBackground(int operation);
// void drawMenu();
// void drawSquare(void);
// void drawHouse(void);
 
// // KEYBOARD
// void inputKeyboard(unsigned char key, int x, int y)
// {
//   switch (key)
//   {
//   case 27:
//     printf("Bye");
//     exit(0);
//     break;
  
//   case 'f':
//     glutFullScreen();
//     break;
  
//   case 's':
//     glutReshapeWindow(100,100);
//     glutPositionWindow(100,100);
//     break;
  
//   default:
//     break;
//   }
// }


// // WINDOW
// void scaleWindow(GLsizei w, GLsizei h)
// {
//   if (h == 0)
//   {
//     h = 1;
//   }

//   width = w/2;
//   height = h;
//   rate = (float) width/height;
//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();

//   gluOrtho2D(-WINDOW_SIZE*h/w, WINDOW_SIZE*h/w,-WINDOW_SIZE, WINDOW_SIZE);

// }


// // DRAW
// void draw(void) 
// {
//   glClear(GL_COLOR_BUFFER_BIT);
//   glViewport(0,0,width, height);
  
//   drawHouse();  
//   drawMenu();  
//   drawSquare();  

//   glFlush();
// }

// void drawBackground(int operation) 
// {

//   switch (operation)
//   {
//   case 0:
//     glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
//     break;
  
//   case 1:
//     glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
//     break;
  
//   case 2:
//     glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//     break;
  
//   default:  
//     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//     break;
//   }
//   glutPostRedisplay();
// }

// void drawMenu()
// {
//   int menu = glutCreateMenu(drawBackground);

//   glutAddMenuEntry("Vermelho", 0);
//   glutAddMenuEntry("Verde", 1);
//   glutAddMenuEntry("Azul", 2);
//   glutAddMenuEntry("Preto", 3);

//   glutAttachMenu(GLUT_RIGHT_BUTTON);
// }

// void drawSquare(void)
// {
//   glBegin(GL_POLYGON);
//     glVertex3f(0.0, 0.0, 0.0);
//     glVertex3f(0.5, 0.0, 0.0);
//     glVertex3f(0.5, 0.5, 0.0);
//     glVertex3f(0.0, 0.5, 0.0);
//   glEnd();
// }

// void drawHouse(void)
// {  
//   // Wall
//   glColor3ub(0,0,255);
//   glBegin(GL_QUADS);
//     glVertex3f(-0.5,-0.5, 0.0);
//     glVertex3f(-0.5,0.0, 0.0);
//     glVertex3f(0.5, 0.0, 0.0);
//     glVertex3f(0.5,-0.5, 0.0);
//   glEnd();
  
//   // Door
//   glColor3ub(255,255,255);
//   glBegin(GL_QUADS);
//     glVertex3f(-0.1,-0.5, 0.0);
//     glVertex3f(-0.1,-0.1, 0.0);
//     glVertex3f(0.1,-0.1, 0.0);
//     glVertex3f(0.1,-0.5, 0.0);
//   glEnd();

//   // Roof
//   glColor3ub(0,255,0);
//   glBegin(GL_TRIANGLE_FAN);
//     glVertex3f(-0.5,0, 0.0);
//     glVertex3f(0.0, 0.5, 0.0);
//     glVertex3f(0.5, 0.0, 0.0);
//   glEnd();
// }



// int main(int argc, char *argv[])
// {
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//   // glutInitWindowSize(height, width);
//   // glutInitWindowPosition(100, 100);
//   glutCreateWindow("OPENGLLABS");
//   glutDisplayFunc(draw);
//   glutKeyboardFunc(inputKeyboard);
//   glutMainLoop();
  
//   return 0;
// }