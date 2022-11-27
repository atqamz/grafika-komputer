#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <ctime>

#include "menu.h"
#include "game.h"
using namespace std;

menu menuSetting;
game gameSetting;

static int sceneSetting = 0;

void settingInMainMenu();
void settingInGame();
void settingInInformation();

void timer(int);

void drawBitmapText(int type, const char *text, float x, float y, float z)
{
	int j = strlen(text);

	glRasterPos3f(x, y, z);

	for (int i = 0; i < j; i++)
	{
		if (type == 0)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
		else if (type == 1)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
		else if (type == 2)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
}

void drawScene(void)
{
	srand((unsigned)time(0));
	glClear(GL_COLOR_BUFFER_BIT);

	if (sceneSetting == 0) // main menu
		settingInMainMenu();
	else if (sceneSetting == 1) // in game
		settingInGame();
	else if (sceneSetting == 2) // instruction
		settingInInformation();

	glutSwapBuffers();
}

void settingInMainMenu()
{
	int count, storage[100];
	char fileName[20] = {"database.txt"};
	string highscore;

	menuSetting.readFromFile(fileName, storage, count);
	highscore = to_string(menuSetting.getDatabase(count, storage));

	string s(highscore);
	char cstr[5];
	s.copy(cstr, s.size() + 1);
	cstr[s.size()] = '\0';

	glColor3f(0, 0, 0);
	drawBitmapText(2, "SCALE YOUR BODY !", 28, 240, 0);
	drawBitmapText(1, "Your High Score: ", 34, 230, 0);
	drawBitmapText(1, cstr, 65, 230, 0);
	drawBitmapText(1, "PLAY GAME", 45, 130, 0);
	drawBitmapText(1, "INFORMATION", 45, 110, 0);
	drawBitmapText(1, "QUIT", 45, 90, 0);

	glColor3f(0.1, 0.3, 0.7);
	glBegin(GL_POLYGON);
	for (int i = 0; i < menuSetting.getLong(0); i += 3)
	{
		glVertex3f(menuSetting.getVertices(0, i),
				   menuSetting.getVertices(0, i + 1),
				   menuSetting.getVertices(0, i + 2));
	}
	glEnd();

	glColor3f(0.8, 0.2, 0.4);
	glBegin(GL_POLYGON);
	for (int i = 0; i < menuSetting.getLong(1); i += 3)
	{
		glVertex3f(menuSetting.getVertices(1, i),
				   menuSetting.getVertices(1, i + 1),
				   menuSetting.getVertices(1, i + 2));
	}
	glEnd();
}

void settingInInformation()
{
	glColor3f(0, 0, 0);
	drawBitmapText(1, "5221600034 Atqa Munzir", 25, 250, 0);
	drawBitmapText(1, "Move Left		: Left Arrow", 25, 210, 0);
	drawBitmapText(1, "Move Right		: Right Arrow ", 25, 200, 0);
	drawBitmapText(1, "Scale Up Body	: Up Arrow ", 25, 190, 0);
	drawBitmapText(1, "Scale Down Body	: Down Arrow ", 25, 180, 0);
	drawBitmapText(1, "Press ESC to Back Main Menu", 25, 90, 0);
}

void settingInGame()
{
	string s(to_string(gameSetting.playerSetting.getInfo()));
	char cstr[5];
	s.copy(cstr, s.size() + 1);
	cstr[s.size()] = '\0';

	glColor3f(0, 0, 0);
	drawBitmapText(0, "Score: ", 5, 290, 0);
	drawBitmapText(1, cstr, 5, 280, 0);

	glColor3f(0.1, 0.3, 0.7);
	glBegin(GL_POLYGON);
	for (int i = 0; i < gameSetting.playerSetting.getLong(); i += 3)
	{
		glVertex3f(gameSetting.playerSetting.getVertices(i),
				   gameSetting.playerSetting.getVertices(i + 1),
				   gameSetting.playerSetting.getVertices(i + 2));
	}
	glEnd();

	for (int j = 0; j < 2; j++)
	{
		glColor3f(0.8, 0.2, 0.4);
		glBegin(GL_POLYGON);

		if (!gameSetting.obsSetting[j].getCondition())
		{
			if (j == 0)
				gameSetting.obsSetting[j].setDistance(rand() % 50 + 15);
			else if (j == 1)
			{
				while (gameSetting.obsSetting[j].getDistance() <= gameSetting.obsSetting[j - 1].getDistance())
				{
					gameSetting.obsSetting[j].setDistance(rand() % 50 + 15);
				}
			}

			gameSetting.obsSetting[j].setFirstPosition(j, gameSetting.obsSetting[j].getDistance());
			gameSetting.obsSetting[j].setCondition(true);
		}

		for (int i = 0; i < gameSetting.obsSetting[j].getLong(); i += 3)
		{
			glVertex3f(gameSetting.obsSetting[j].getVertices(i),
					   gameSetting.obsSetting[j].getVertices(i + 1),
					   gameSetting.obsSetting[j].getVertices(i + 2));
		}
		glEnd();
	}
}

void timer(int)
{
	if (sceneSetting == 1)
	{
		glutPostRedisplay();
		glutTimerFunc(1000 / 60, timer, 0);

		gameSetting.fallingObstacle();

		if (gameSetting.getGameOver())
		{
			gameSetting.resetStats();
			sceneSetting = 0;
			gameSetting.setGameOver(false);
		}
	}
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 300.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		gameSetting.resetStats();
		sceneSetting = 0;
		break;

	case 13:
		if (menuSetting.getSelect() == 0)
		{
			sceneSetting = 1;
			glutTimerFunc(0, timer, 0);
		}
		else if (menuSetting.getSelect() == 1)
			sceneSetting = 2;
		else if (menuSetting.getSelect() == 2)
			exit(0);
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (sceneSetting == 0)
		{
			if (menuSetting.getSelect() == 1)
			{
				menuSetting.translation(0.0, 20.0, 0.0);
				menuSetting.setSelect(0);
			}
			else if (menuSetting.getSelect() == 2)
			{
				menuSetting.translation(0.0, 20.0, 0.0);
				menuSetting.setSelect(1);
			}
		}
		else if (sceneSetting == 1)
		{
			gameSetting.controlPlayer(0);
		}
		break;

	case GLUT_KEY_DOWN:
		if (sceneSetting == 0)
		{
			if (menuSetting.getSelect() == 0)
			{
				menuSetting.translation(0.0, -20.0, 0.0);
				menuSetting.setSelect(1);
			}
			else if (menuSetting.getSelect() == 1)
			{
				menuSetting.translation(0.0, -20.0, 0.0);
				menuSetting.setSelect(2);
			}
		}
		else if (sceneSetting == 1)
		{
			gameSetting.controlPlayer(1);
		}
		break;

	case GLUT_KEY_LEFT:
		gameSetting.controlPlayer(2);
		break;

	case GLUT_KEY_RIGHT:
		gameSetting.controlPlayer(3);
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 800);
	glutInitWindowPosition(900, 100);

	glutCreateWindow("Scale Your Body");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKey);

	glutTimerFunc(0, timer, 0);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}