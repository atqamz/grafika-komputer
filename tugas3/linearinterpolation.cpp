#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
#include <cmath>

using namespace std;

GLfloat LinearInterpolation(GLfloat a, GLfloat b, GLfloat t)
{
    return a + (b - a) * t;
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (float t = 0.0; t < 1.0; t += 0.01)
    {
        GLfloat x = LinearInterpolation(0.0, 1.0, t);
        GLfloat y = LinearInterpolation(0.0, 1.0, t);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

void Animate()
{
    static float t = 0.0;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    GLfloat x = LinearInterpolation(0.0, 1.0, t);
    GLfloat y = LinearInterpolation(0.0, 1.0, t);
    glVertex2f(x, y);
    glEnd();
    glFlush();
    t += 0.01;
    if (t > 1.0)
        t = 0.0;
}

void Init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Linear Interpolation");
    Init();
    glutDisplayFunc(Draw);
    glutIdleFunc(Animate);
    glutMainLoop();
    return 0;
}