#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
#include <cmath>

void Draw()
{
    GLfloat x1 = 0, y1 = 0, x2 = 500, y2 = 500;
    GLfloat dx, dy, step, x, y, inc_x, inc_y;

    dx = x2 - x1;
    dy = y2 - y1;
    step = dx;

    if (fabs(dy) > fabs(dx))
        step = dy;

    x = x1;
    y = y1;

    inc_x = dx / step;
    inc_y = dy / step;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);

    for (int i = 0; i <= step; i++)
    {
        x += inc_x;
        y += inc_y;

        glVertex2f(round(x), round(y));
    }

    glEnd();

    glFlush();
}

void MyInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argC, char *argV[])
{
    glutInit(&argC, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line");
    MyInit();
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}