#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void init()

{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0.8, 0.8, 0.8, 0.0);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 800, 0.0, 600);
}

void display()

{
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(100 + cos(degInRad) * 50, 100 + sin(degInRad) * 50);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(300 + cos(degInRad) * 50, 100 + sin(degInRad) * 50);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(160 + cos(degInRad) * 50, 150 + sin(degInRad) * 50);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(240 + cos(degInRad) * 50, 150 + sin(degInRad) * 50);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(160 + cos(degInRad) * 50, 50 + sin(degInRad) * 50);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(240 + cos(degInRad) * 50, 50 + sin(degInRad) * 50);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(200 + cos(degInRad) * 50, 100 + sin(degInRad) * 50);
    }
    glEnd();

    // Process all OpenGL routine s as quickly as possible
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    /* kontrol tombol pada keyboard:
      "a": kiri
      "d": kanan
      "w": atas
      "s": bawah
      */
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(-10.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(10.0, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 10.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, -10.0, 0.0);
        break;
    case 'q':
    case 'Q':
        glScalef(0.9, 0.9, 0.0);
        break;
    case 'e':
    case 'E':
        glScalef(1.1, 1.1, 0.0);
        break;
    }
    display();
}

int main(int argc, char **argv)

{
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(720, 480);
    // Create display window with the given title
    glutCreateWindow("OBJEK BERGERAK - ATQA MUNZIR - 5221600034");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(display);
    // Display everything and wait.
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}