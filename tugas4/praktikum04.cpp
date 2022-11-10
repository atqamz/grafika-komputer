#include <iostream>
#include <cmath>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

float angle = 0.0f;
float posX = 0.0f, rotX = 0.0f;
float posY = 0.0f, rotY = 0.0f;
float posZ = 5.0f, rotZ = -1.0f;
float objectAngleX = 0.0f;
float objectAngleY = 0.0f;
float objectAngleZ = 0.0f;
float objectScaleX = 1.0f;
float objectScaleY = 1.0f;
float objectScaleZ = 1.0f;
float objectPositionX = 0.0f;
float objectPositionY = 0.0f;
float objectPositionZ = 0.0f;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // mengatur posisi kamera
    gluLookAt(posX, posY, posZ, rotX, rotY, rotZ, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    // operasi transformasi translasi obyek
    // ke arah sumbu X, Y atau Z
    glTranslatef(objectPositionX, objectPositionY, objectPositionZ);
    // operasi transformasi scaling obyek
    // memperbesar atau mengecilkan obyek
    // ke arah sumbu X, Y atau Z
    glScalef(objectScaleX, objectScaleY, objectScaleZ);
    // operasi transformasi rotasi obyek ke arah kanan-kiri
    glRotatef(objectAngleY, 0.0f, 1.0f, 0.0f);
    glPushMatrix();
    // operasi transformasi rotasi obyek ke arah atas-bawah
    glRotatef(objectAngleX, 1.0f, 0.0f, 0.0f);
    // set warna obyek ke warna hijau (0.0f, 1.0f, 0.0f)
    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidCube(1.0f); // menggambar obyek kubus
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void KeyboardInput(unsigned char key, int x, int y)
{
    float fraction = 0.5f;
    switch (key)
    {
    case 'w':
        objectPositionY += fraction;
        glutPostRedisplay();
        break;
    case 'a':
        objectPositionX -= fraction;
        glutPostRedisplay();
        break;
    case 's':
        objectPositionY -= fraction;
        glutPostRedisplay();
        break;
    case 'd':
        objectPositionX += fraction;
        glutPostRedisplay();
        break;
    case 'q':
        objectPositionZ += fraction;
        glutPostRedisplay();
        break;
    case 'e':
        objectPositionZ -= fraction;
        glutPostRedisplay();
        break;

    case 't':
        objectScaleY += 0.1f;
        glutPostRedisplay();
        break;
    case 'f':
        objectScaleX += 0.1f;
        glutPostRedisplay();
        break;
    case 'g':
        objectScaleY = max(objectScaleY - 0.1f, 1.0f);
        glutPostRedisplay();
        break;
    case 'h':
        objectScaleX = max(objectScaleX - 0.1f, 1.0f);
        glutPostRedisplay();
        break;
    case 'r':
        objectScaleZ += 0.1f;
        glutPostRedisplay();
        break;
    case 'y':
        objectScaleZ = max(objectScaleZ - 0.1f, 1.0f);
        glutPostRedisplay();
        break;

    case 'i':
        objectAngleX += 1.0f;
        glutPostRedisplay();
        break;
    case 'j':
        objectAngleY += 1.0f;
        glutPostRedisplay();
        break;
    case 'k':
        objectAngleX -= 1.0f;
        glutPostRedisplay();
        break;
    case 'l':
        objectAngleY -= 1.0f;
        glutPostRedisplay();
        break;
    case 'u':
        objectAngleZ += 1.0f;
        glutPostRedisplay();
        break;
    case 'o':
        objectAngleZ -= 1.0f;
        glutPostRedisplay();
        break;

    case 27: // bila tombol 'esc' pada keyboard ditekan
        exit(0);
        break;
    }
}

void Init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("5221600034 - Atqa Munzir - Transformasi Kubus");
    Init();
    glutDisplayFunc(Draw);
    glutKeyboardFunc(KeyboardInput);
    glutMainLoop();
    return 0;
}