#include <GL/glut.h>

void init()

{

    // Set display window color to as glClearColor(R,G,B,Alpha)

    glClearColor(0.0, 0.0, 0.7, 0.0);

    // Set projection parameters.

    glMatrixMode(GL_PROJECTION);

    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)

    gluOrtho2D(0.0, 800, 0.0, 600);
}

void home()

{

    glClear(GL_COLOR_BUFFER_BIT); // Clear display window

    // Set line segment color as glColor3f(R,G,B)

    glColor3f(1, 1, 1);

    // Neightboorhood

    glBegin(GL_POLYGON);

    glVertex2i(0, 0);

    glVertex2i(0, 200);

    glVertex2i(100, 300);

    glVertex2i(200, 200);

    glVertex2i(200, 0);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(200, 0);

    glVertex2i(200, 200);

    glVertex2i(300, 300);

    glVertex2i(400, 200);

    glVertex2i(400, 0);

    glEnd();

    // Cloud

    glBegin(GL_POLYGON);

    glVertex2i(100, 500);

    glVertex2i(150, 550);

    glVertex2i(200, 550);

    glVertex2i(250, 500);

    glVertex2i(200, 450);

    glVertex2i(150, 450);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(300, 500);

    glVertex2i(350, 550);

    glVertex2i(400, 550);

    glVertex2i(450, 500);

    glVertex2i(400, 450);

    glVertex2i(350, 450);

    glEnd();

    // Tree Log with Brown Color

    glColor3f(0.5, 0.35, 0.05);

    glBegin(GL_POLYGON);

    glVertex2i(600, 0);

    glVertex2i(600, 200);

    glVertex2i(650, 200);

    glVertex2i(650, 0);

    glEnd();

    // VERY BIG SUN

    glColor3f(1, 1, 0);

    glPointSize(80);

    glBegin(GL_POINTS);

    glVertex2i(550, 500);

    glEnd();

    // 3 Row Tree Leaves using Green Color and Triangle

    glColor3f(0, 1, 0);

    glBegin(GL_TRIANGLES);

    glVertex2i(550, 200);

    glVertex2i(700, 200);

    glVertex2i(625, 350);

    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex2i(550, 300);

    glVertex2i(700, 300);

    glVertex2i(625, 450);

    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex2i(550, 400);

    glVertex2i(700, 400);

    glVertex2i(625, 550);

    glEnd();

    // Roof

    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);

    glVertex2i(100, 250);

    glVertex2i(300, 250);

    glVertex2i(350, 175);

    glVertex2i(150, 175);

    glEnd();

    // Top of Front Wall

    glColor3f(1, 0.7, 0.2);

    glBegin(GL_TRIANGLES);

    glVertex2i(100, 250);

    glVertex2i(50, 175);

    glVertex2i(150, 175);

    glEnd();

    // Front Wall

    glColor3f(0.7, 0.1, 1);

    glBegin(GL_POLYGON);

    glVertex2i(50, 175);

    glVertex2i(150, 175);

    glVertex2i(150, 50);

    glVertex2i(50, 50);

    glEnd();

    // Front Door

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    glVertex2i(75, 125);

    glVertex2i(125, 125);

    glVertex2i(125, 50);

    glVertex2i(75, 50);

    glEnd();

    // Front Door Lock

    glColor3f(0.3, 0.7, 0.9);

    glPointSize(10);

    glBegin(GL_POINTS);

    glVertex2i(85, 85);

    glEnd();

    // Side Wall

    glColor3f(0.5, 0.5, 1);

    glBegin(GL_POLYGON);

    glVertex2i(150, 175);

    glVertex2i(350, 175);

    glVertex2i(350, 50);

    glVertex2i(150, 50);

    glEnd();

    // window

    glColor3f(0.2, 0.4, 0.8);

    glBegin(GL_POLYGON);

    glVertex2i(215, 160);

    glVertex2i(275, 160);

    glVertex2i(275, 115);

    glVertex2i(215, 115);

    glEnd();

    // line of window

    glColor3f(0.1, 0.2, 0.5);

    glLineWidth(3);

    glBegin(GL_LINES);

    glVertex2i(245, 160);

    glVertex2i(245, 115);

    glVertex2i(215, 136);

    glVertex2i(275, 136);

    glEnd();

    // Entrance Path

    glColor3f(0.3, 0.3, 0.3);

    glLineWidth(3);

    glBegin(GL_POLYGON);

    glVertex2i(50, 50);

    glVertex2i(150, 50);

    glVertex2i(105, 0);

    glVertex2i(20, 0);

    glEnd();

    // Grass

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex2i(0, 0);

    glVertex2i(800, 0);

    glVertex2i(800, 50);

    glVertex2i(0, 50);

    glEnd();

    // Car Body

    glColor3f(0.8, 0.7, 1);

    glBegin(GL_POLYGON);

    glVertex2i(500, 50);

    glVertex2i(600, 50);

    glVertex2i(600, 100);

    glVertex2i(500, 100);

    glEnd();

    // Car Wheel

    glColor3f(0.0, 0.0, 0.0);

    glPointSize(10);

    glBegin(GL_POINTS);

    glVertex2i(525, 50);

    glVertex2i(575, 50);

    glEnd();

    // Car Window

    glColor3f(0.2, 0.4, 0.8);

    glBegin(GL_POLYGON);

    glVertex2i(525, 75);

    glVertex2i(575, 75);

    glVertex2i(575, 100);

    glVertex2i(525, 100);

    glEnd();

    // Manuk

    glColor3f(0.0, 0.0, 0.0);

    glPointSize(10);

    glBegin(GL_POINTS);

    glVertex2i(200, 400);

    glVertex2i(200, 450);

    glEnd();

    glLineWidth(3);

    glBegin(GL_LINES);

    glVertex2i(200, 400);

    glVertex2i(175, 425);

    glVertex2i(200, 400);

    glVertex2i(225, 425);

    glVertex2i(200, 450);

    glVertex2i(175, 475);

    glVertex2i(200, 450);

    glVertex2i(225, 475);

    glEnd();

    // Cloud

    glColor3f(1, 1, 1);

    glPointSize(10);

    glBegin(GL_POINTS);

    glVertex2i(400, 600);

    glVertex2i(425, 600);

    glVertex2i(450, 600);

    glVertex2i(475, 600);

    glVertex2i(500, 600);

    glVertex2i(525, 600);

    glVertex2i(550, 600);

    glVertex2i(575, 600);

    glVertex2i(600, 600);

    glVertex2i(625, 600);

    glVertex2i(650, 600);

    glVertex2i(675, 600);

    glVertex2i(700, 600);

    glVertex2i(725, 600);

    glVertex2i(750, 600);

    glVertex2i(775, 600);

    glEnd();

    // Process all OpenGL routine s as quickly as possible

    glFlush();
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

    glutCreateWindow("RUMAH 2D - ATQA MUNZIR - 5221600034");

    // Execute initialization procedure

    init();

    // Send graphics to display window

    glutDisplayFunc(home);

    // Display everything and wait.

    glutMainLoop();
}