#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
#include <cmath>

using namespace std;

GLfloat CosineInterpolation(GLfloat a, GLfloat b, GLfloat x)
{
    GLfloat ft = x * 3.1415927;
    GLfloat f = (1 - cos(ft)) * 0.5;
    return a * (1 - f) + b * f;
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    for (GLfloat x = 0.0; x <= 1.0; x += 0.01)
    {
        GLfloat y = CosineInterpolation(0.0, 1.0, x);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

void Animate()
{
    static GLfloat x = 0.0;
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(x, CosineInterpolation(0.0, 1.0, x));
    glEnd();
    x += 0.01;
    if (x > 1.0)
        x = 0.0;
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
    glutCreateWindow("Cosine Interpolation");
    Init();
    glutDisplayFunc(Draw);
    glutIdleFunc(Animate);
    glutMainLoop();
    return 0;
}