#include "game.h"

void game::resetStats() {
	int count, storage[100];
	char fileName[20] = { "database.txt" };

	menuSetting.readFromFile(fileName, storage, count);

	if (menuSetting.getDatabase(count, storage) < playerSetting.getInfo())
		menuSetting.inputToFile("database.txt", 1, playerSetting.getInfo());

	playerSetting.resetPosition();
	obsSetting[0].resetPosition();
	obsSetting[1].resetPosition();

	obsSetting[0].setCondition(false);
	obsSetting[1].setCondition(false);

	obsSetting[0].setSpeed(-0.5);
	obsSetting[1].setSpeed(-0.5);

	scorePlus = 0;
	gameOver = true;
	playerSetting.setScore(0);
}

void game::checkCollision() {
	playerObj.x = playerSetting.getVertices(0);
	playerObj.y = playerSetting.getVertices(1);
	playerObj.width = playerSetting.getVertices(3) - playerSetting.getVertices(0);
	playerObj.height = playerSetting.getVertices(7) - playerSetting.getVertices(4);

	obstacleObj1.x = obsSetting[0].getVertices(0);
	obstacleObj1.y = obsSetting[0].getVertices(1);
	obstacleObj1.width = obsSetting[0].getVertices(3) - obsSetting[0].getVertices(0);
	obstacleObj1.height = obsSetting[0].getVertices(7) - obsSetting[0].getVertices(4);

	obstacleObj2.x = obsSetting[1].getVertices(0);
	obstacleObj2.y = obsSetting[1].getVertices(1);
	obstacleObj2.width = obsSetting[1].getVertices(3) - obsSetting[1].getVertices(0);
	obstacleObj2.height = obsSetting[1].getVertices(7) - obsSetting[1].getVertices(4);

	// collision w/ obs1
	if (playerObj.x <= obstacleObj1.x + obstacleObj1.width &&
		playerObj.x + playerObj.width >= obstacleObj1.x &&
		playerObj.y <= obstacleObj1.y + obstacleObj1.height &&
		playerObj.y + playerObj.height >= obstacleObj1.y) {
		resetStats();
	}

	// collision w/ obs2
	if (playerObj.x <= obstacleObj2.x + obstacleObj2.width &&
		playerObj.x + playerObj.width >= obstacleObj2.x &&
		playerObj.y <= obstacleObj2.y + obstacleObj2.height &&
		playerObj.y + playerObj.height >= obstacleObj2.y) {
		resetStats();
	}
}

void game::fallingObstacle() {
	srand((unsigned)time(0));

	obsSetting[0].translation(0.0, obsSetting[0].getSpeed(), 0.0);
	obsSetting[1].translation(0.0, obsSetting[1].getSpeed(), 0.0);

	if (playerSetting.getVertices(1) >= obsSetting[0].getVertices(7) && scorePlus == 0) {
		playerSetting.setScore(playerSetting.getScore() + 1);
		scorePlus = 1;
	}
	else if (playerSetting.getVertices(1) <= obsSetting[0].getVertices(7)) {
		scorePlus = 0;
	}

	if (obsSetting[0].getVertices(7) <= 0 && obsSetting[1].getVertices(7) <= 0) {
		obsSetting[0].setSpeed(obsSetting[0].getSpeed() - 0.05);
		obsSetting[1].setSpeed(obsSetting[1].getSpeed() - 0.05);

		obsSetting[0].resetPosition();
		obsSetting[1].resetPosition();

		for (int j = 0; j < 2; j++) {
			obsSetting[j].setCondition(false);

			if (!obsSetting[j].getCondition()) {
				if (j == 0)
					obsSetting[j].setDistance(rand() % 50 + 15);
				else if (j == 1) {
					while (obsSetting[j].getDistance() <= obsSetting[j - 1].getDistance()) {
						obsSetting[j].setDistance(rand() % 50 + 15);
					}
				}

				obsSetting[j].setFirstPosition(j, obsSetting[j].getDistance());
				obsSetting[j].setCondition(true);
			}
		}
	}

	checkCollision();
}

void game::controlPlayer(int key) {
	switch (key) {
	case 0:
		if (playerSetting.getVertices(0) > 0 && playerSetting.getVertices(9) > 0 &&
			playerSetting.getVertices(3) < 100 && playerSetting.getVertices(6) < 100)
			playerSetting.scalling(1.05, 1.0, 1.0);
		break;

	case 1:
		if (playerSetting.getVertices(0) > 0 && playerSetting.getVertices(9) > 0 &&
			playerSetting.getVertices(3) < 100 && playerSetting.getVertices(6) < 100)
			playerSetting.scalling(0.95, 1.0, 1.0);
		break;

	case 2:
		if (playerSetting.getVertices(0) > 0 && playerSetting.getVertices(9) > 0)
			playerSetting.translation(-1.3, 0.0, 0.0);
		break;

	case 3:
		if (playerSetting.getVertices(3) < 100 && playerSetting.getVertices(6) < 100)
			playerSetting.translation(1.3, 0.0, 0.0);
		break;
	}
}

bool game::getGameOver() {
	return gameOver;
}

void game::setGameOver(bool inputGameOver) {
	gameOver = inputGameOver;
}