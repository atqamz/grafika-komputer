#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

void drawCross(int x, int y)
{
    glBegin(GL_POLYGON);
    glVertex2f(x + 0, y + 5);
    glVertex2f(x + 195, y + 200);
    glVertex2f(x + 200, y + 195);
    glVertex2f(x + 5, y + 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x + 195, y + 0);
    glVertex2f(x + 200, y + 5);
    glVertex2f(x + 5, y + 200);
    glVertex2f(x + 0, y + 195);
    glEnd();
}

void drawCircle(int x, int y)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(x + cos(degInRad) * 90, y + sin(degInRad) * 90);
    }
    glEnd();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);
    glVertex2f(200, 0);
    glVertex2f(225, 0);
    glVertex2f(225, 650);
    glVertex2f(200, 650);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(425, 0);
    glVertex2f(450, 0);
    glVertex2f(450, 650);
    glVertex2f(425, 650);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0, 200);
    glVertex2f(0, 225);
    glVertex2f(650, 225);
    glVertex2f(650, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0, 425);
    glVertex2f(0, 450);
    glVertex2f(650, 450);
    glVertex2f(650, 425);
    glEnd();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (x >= 0 && x <= 200 && y >= 0 && y <= 200)
        {
            cout << "Kotak 1" << endl;

            // drawCross(0, 450);
            drawCircle(100, 550);
        }

        if (x >= 225 && x <= 425 && y >= 0 && y <= 200)
        {
            cout << "Kotak 2" << endl;

            // drawCross(225, 450);
            drawCircle(325, 550);
        }

        if (x >= 450 && x <= 650 && y >= 0 && y <= 200)
        {
            cout << "Kotak 3" << endl;

            // drawCross(450, 450);
            drawCircle(550, 550);
        }

        if (x >= 0 && x <= 200 && y >= 225 && y <= 425)
        {
            cout << "Kotak 4" << endl;

            // drawCross(0, 225);
            drawCircle(100, 325);
        }

        if (x >= 225 && x <= 425 && y >= 225 && y <= 425)
        {
            cout << "Kotak 5" << endl;

            // drawCross(225, 225);
            drawCircle(325, 325);
        }

        if (x >= 450 && x <= 650 && y >= 225 && y <= 425)
        {
            cout << "Kotak 6" << endl;

            // drawCross(450, 225);
            drawCircle(550, 325);
        }

        if (x >= 0 && x <= 200 && y >= 450 && y <= 650)
        {
            cout << "Kotak 7" << endl;

            // drawCross(0, 0);
            drawCircle(100, 100);
        }

        if (x >= 225 && x <= 425 && y >= 450 && y <= 650)
        {
            cout << "Kotak 8" << endl;

            // drawCross(225, 0);
            drawCircle(325, 100);
        }

        if (x >= 450 && x <= 650 && y >= 450 && y <= 650)
        {
            cout << "Kotak 9" << endl;

            // drawCross(450, 0);
            drawCircle(550, 100);
        }
    }

    // do an update to board
    glutSwapBuffers();
}

void init()
{
    glClearColor(0.8, 0.8, 0.8, 0.0);
    glMatrixMode(GL_PROJECTION);
    // set 2D transformation as gluOrtho2D(min width, max width, min height, max height)
    gluOrtho2D(0.0, 650, 0.0, 650);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tic Tac Toe - Atqa Munzir");
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();

    return 0;
};
