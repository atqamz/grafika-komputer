#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class menu
{
private:
	int selectMenu = 0;
	float verticesLogo[12] =
	{
		35.0, 175.0, 0.0,
		65.0, 175.0, 0.0,
		65.0, 205.0, 0.0,
		35.0, 205.0, 0.0
	};
	float verticesControl[12] =
	{
		35.0, 130.0, 0.0,
		38.0, 130.0, 0.0,
		38.0, 135.0, 0.0,
		35.0, 135.0, 0.0
	};

public:
	int getSelect();
	int getLong(int object);
	float getVertices(int object, int positionArray);

	void setSelect(int select);
	void translation(float tx, float ty, float tz);

	int getDatabase(int Entries, int Arr[]);
	void readFromFile(char fileName[], int storage[], int &noOfEn);
	void inputToFile(string fileName, int longArray, long contentArray);
};