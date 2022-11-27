#pragma once
#include <iostream>
using namespace std;

class obstacle
{
private:
	bool setup;
	float speed = -0.5;
	float distance;
	float firstVertices[12] =
	{
		10.0, 300.0, 0.0,
		60.0, 300.0, 0.0,
		60.0, 350.0, 0.0,
		10.0, 350.0, 0.0
	};
	float vertices[12] =
	{
		10.0, 300.0, 0.0,
		60.0, 300.0, 0.0,
		60.0, 350.0, 0.0,
		10.0, 350.0, 0.0
	};

public:
	int getLong();
	float getVertices(int positionArray);
	float getSpeed();
	float getDistance();
	bool getCondition();

	void setCondition(bool);
	void setSpeed(float);
	void setDistance(float);
	void setFirstPosition(int order, float distance);

	void resetPosition();
	void translation(float tx, float ty, float tz);
};