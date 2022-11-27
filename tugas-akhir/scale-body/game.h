#pragma once
#include <ctime>
#include "menu.h"
#include "player.h"
#include "obstacle.h"

class game
{
public:
	struct object
	{
		float x = 0.0;
		float y = 0.0;
		float width;
		float height;
	};

	object playerObj;
	object obstacleObj1;
	object obstacleObj2;

	menu menuSetting;
	player playerSetting;
	obstacle obsSetting[2];

	int scorePlus;
	bool gameOver;

	void resetStats();
	void checkCollision();
	void fallingObstacle();
	void controlPlayer(int key);

	void setGameOver(bool inputGameOver);
	bool getGameOver();
};