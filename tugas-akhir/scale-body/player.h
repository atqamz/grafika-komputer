#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class player
{
private:
	int score = 0;
	float firstVertices[12] =
	{
		30.0, 30.0, 0.0,
		70.0, 30.0, 0.0,
		70.0, 70.0, 0.0,
		30.0, 70.0, 0.0
	};
	float vertices[12] =
	{
		30.0, 30.0, 0.0,
		70.0, 30.0, 0.0,
		70.0, 70.0, 0.0,
		30.0, 70.0, 0.0
	};

public:
	int getLong();
	float getVertices(int positionArray);
	int getInfo();
	int getScore();

	void setScore(int inputScore);
	void resetPosition();

	void translation(float tx, float ty, float tz);
	void scalling(float rx, float ry, float rz);
};