#include <GL\glut.h>
#include <iostream>
#include <windows.h>
using namespace std;

static int pundak = 0, siku = 0, jariAtas1 = 0, jariAtas2 = 0, jariBawah1 = 0, jariBawah2 = 0;
void init(void)
{
    glClearColor(0.5, 0.2, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // pundak
    glTranslatef(-2.5, 0.0, 0.0);
    glRotatef((GLfloat)pundak, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.8, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)siku, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.8, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();

    // pangkal jari atas
    glTranslatef(1.0, 0.25, 0.0);
    glRotatef((GLfloat)jariAtas1, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    // ujung jari atas
    glTranslatef(0.25, 0.0, 0.0);
    glRotatef((GLfloat)jariAtas2, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // pengkal jari bawah
    glTranslatef(1.0, -0.25, 0.0);
    glRotatef((GLfloat)jariBawah1, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    // ujung jari bawah
    glTranslatef(0.25, 0.0, 0.0);
    glRotatef((GLfloat)jariBawah2, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        pundak = (pundak + 5) % 360;
        glutPostRedisplay();
        break;

    case 'w':
        pundak = (pundak - 5) % 360;
        glutPostRedisplay();
        break;

    case 'a':
        siku = (siku + 5) % 360;
        glutPostRedisplay();
        break;

    case 's':
        siku = (siku - 5) % 360;
        glutPostRedisplay();
        break;

    case 'e':
        jariAtas1 = (jariAtas1 + 5) % 360;
        glutPostRedisplay();
        break;

    case 'r':
        jariAtas1 = (jariAtas1 - 5) % 360;
        glutPostRedisplay();
        break;

    case 'd':
        jariAtas2 = (jariAtas2 + 5) % 360;
        glutPostRedisplay();
        break;

    case 'f':
        jariAtas2 = (jariAtas2 - 5) % 360;
        glutPostRedisplay();
        break;

    case 't':
        jariBawah1 = (jariBawah1 + 5) % 360;
        glutPostRedisplay();
        break;

    case 'y':
        jariBawah1 = (jariBawah1 - 5) % 360;
        glutPostRedisplay();
        break;

    case 'g':
        jariBawah2 = (jariBawah2 + 5) % 360;
        glutPostRedisplay();
        break;

    case 'h':
        jariBawah2 = (jariBawah2 - 5) % 360;
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("LENGAN ROBOT - Atqa Munzir - 5221600034");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}