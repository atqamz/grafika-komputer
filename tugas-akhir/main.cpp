#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int turn = 0;
int winner = 0;
bool gameover = false;

void DrawBoard()
{
    glColor3f(0, 0, 0);

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
}

void DrawBitmapText(int type, const char *text, float x, float y, float z)
{
    int j = strlen(text);

    glRasterPos3f(x, y, z);

    for (int i = 0; i < j; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void DrawCross(int x, int y)
{
    glColor3f(0, 0, 0);

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

void DrawCircle(int x, int y)
{
    glColor3f(0, 0, 0);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(x + cos(degInRad) * 90, y + sin(degInRad) * 90);
    }
    glEnd();
}

void UpdateBoard()
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == "X")
        {
            if (i == 0)
            {
                DrawCross(0, 450);
            }
            else if (i == 1)
            {
                DrawCross(225, 450);
            }
            else if (i == 2)
            {
                DrawCross(450, 450);
            }
            else if (i == 3)
            {
                DrawCross(0, 225);
            }
            else if (i == 4)
            {
                DrawCross(225, 225);
            }
            else if (i == 5)
            {
                DrawCross(450, 225);
            }
            else if (i == 6)
            {
                DrawCross(0, 0);
            }
            else if (i == 7)
            {
                DrawCross(225, 0);
            }
            else if (i == 8)
            {
                DrawCross(450, 0);
            }
        }
        else if (board[i] == "O")
        {
            if (i == 0)
            {
                DrawCircle(100, 550);
            }
            else if (i == 1)
            {
                DrawCircle(325, 550);
            }
            else if (i == 2)
            {
                DrawCircle(550, 550);
            }
            else if (i == 3)
            {
                DrawCircle(100, 325);
            }
            else if (i == 4)
            {
                DrawCircle(325, 325);
            }
            else if (i == 5)
            {
                DrawCircle(550, 325);
            }
            else if (i == 6)
            {
                DrawCircle(100, 100);
            }
            else if (i == 7)
            {
                DrawCircle(325, 100);
            }
            else if (i == 8)
            {
                DrawCircle(550, 100);
            }
        }
    }
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    DrawBoard();

    UpdateBoard();

    if (gameover)
    {
        glColor3f(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(650, 0);
        glVertex2f(650, 650);
        glVertex2f(0, 650);
        glEnd();

        glColor3f(1, 0, 0);
        DrawBitmapText(0, "Made by Atqa Munzir (5221600034)", 200, 200, 0);
        if (winner == 1)
        {
            DrawBitmapText(0, "Player 1 Wins!", 200, 300, 0);
        }
        else if (winner == 2)
        {
            DrawBitmapText(0, "Player 2 Wins!", 200, 300, 0);
        }
        else if (winner == 3)
        {
            DrawBitmapText(0, "Draw!", 300, 300, 0);
        }
    }

    glutSwapBuffers();
}

void Mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameover == false)
    {
        if (x >= 0 && x <= 200 && y >= 0 && y <= 200)
        {
            cout << "Kotak 1" << endl;
            if (turn == 0)
            {
                board[0] = "X";
            }
            else
            {
                board[0] = "O";
            }

            // DrawCross(0, 450);
            // DrawCircle(100, 550);
        }

        else if (x >= 225 && x <= 425 && y >= 0 && y <= 200)
        {
            cout << "Kotak 2" << endl;
            if (turn == 0)
            {
                board[1] = "X";
            }
            else
            {
                board[1] = "O";
            }

            // DrawCross(225, 450);
            // DrawCircle(325, 550);
        }

        else if (x >= 450 && x <= 650 && y >= 0 && y <= 200)
        {
            cout << "Kotak 3" << endl;
            if (turn == 0)
            {
                board[2] = "X";
            }
            else
            {
                board[2] = "O";
            }

            // DrawCross(450, 450);
            // DrawCircle(550, 550);
        }

        else if (x >= 0 && x <= 200 && y >= 225 && y <= 425)
        {
            cout << "Kotak 4" << endl;
            if (turn == 0)
            {
                board[3] = "X";
            }
            else
            {
                board[3] = "O";
            }

            // DrawCross(0, 225);
            // DrawCircle(100, 325);
        }

        else if (x >= 225 && x <= 425 && y >= 225 && y <= 425)
        {
            cout << "Kotak 5" << endl;
            if (turn == 0)
            {
                board[4] = "X";
            }
            else
            {
                board[4] = "O";
            }

            // DrawCross(225, 225);
            // DrawCircle(325, 325);
        }

        else if (x >= 450 && x <= 650 && y >= 225 && y <= 425)
        {
            cout << "Kotak 6" << endl;
            if (turn == 0)
            {
                board[5] = "X";
            }
            else
            {
                board[5] = "O";
            }

            // DrawCross(450, 225);
            // DrawCircle(550, 325);
        }

        else if (x >= 0 && x <= 200 && y >= 450 && y <= 650)
        {
            cout << "Kotak 7" << endl;
            if (turn == 0)
            {
                board[6] = "X";
            }
            else
            {
                board[6] = "O";
            }

            // DrawCross(0, 0);
            // DrawCircle(100, 100);
        }

        else if (x >= 225 && x <= 425 && y >= 450 && y <= 650)
        {
            cout << "Kotak 8" << endl;
            if (turn == 0)
            {
                board[7] = "X";
            }
            else
            {
                board[7] = "O";
            }

            // DrawCross(225, 0);
            // DrawCircle(325, 100);
        }

        else if (x >= 450 && x <= 650 && y >= 450 && y <= 650)
        {
            cout << "Kotak 9" << endl;
            if (turn == 0)
            {
                board[8] = "X";
            }
            else
            {
                board[8] = "O";
            }

            // DrawCross(450, 0);
            // DrawCircle(550, 100);
        }

        if (turn == 0)
        {
            turn = 1;
        }
        else
        {
            turn = 0;
        }
    }

    // check win
    if (board[0] == "X" && board[1] == "X" && board[2] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[3] == "X" && board[4] == "X" && board[5] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[6] == "X" && board[7] == "X" && board[8] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[0] == "X" && board[3] == "X" && board[6] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[1] == "X" && board[4] == "X" && board[7] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[2] == "X" && board[5] == "X" && board[8] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[0] == "X" && board[4] == "X" && board[8] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[2] == "X" && board[4] == "X" && board[6] == "X")
    {
        cout << "Player 1 Win" << endl;
        winner = 1;
        gameover = true;
    }
    else if (board[0] == "O" && board[1] == "O" && board[2] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }
    else if (board[3] == "O" && board[4] == "O" && board[5] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }
    else if (board[6] == "O" && board[7] == "O" && board[8] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }
    else if (board[0] == "O" && board[3] == "O" && board[6] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }
    else if (board[1] == "O" && board[4] == "O" && board[7] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }
    else if (board[2] == "O" && board[5] == "O" && board[8] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }
    else if (board[0] == "O" && board[4] == "O" && board[8] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }
    else if (board[2] == "O" && board[4] == "O" && board[6] == "O")
    {
        cout << "Player 2 Win" << endl;
        winner = 2;
        gameover = true;
    }

    // check draw
    if (board[0] != " " && board[1] != " " && board[2] != " " && board[3] != " " && board[4] != " " && board[5] != " " && board[6] != " " && board[7] != " " && board[8] != " ")
    {
        cout << "Draw" << endl;
        winner = 3;
        gameover = true;
    }

    glutPostRedisplay();
}

void Setup()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 650.0, 0.0, 650.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tic Tac Toe - Atqa Munzir - 5221600034");
    glutDisplayFunc(Draw);
    glutReshapeFunc(Reshape);

    glutMouseFunc(Mouse);

    Setup();

    glutMainLoop();

    return 0;
};
