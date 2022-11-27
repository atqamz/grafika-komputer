#include "menu.h"

int menu::getSelect() {
	return selectMenu;
}

int menu::getLong(int object) {
	if (object == 0)
		return sizeof(verticesLogo) / sizeof(verticesLogo[0]);
	else if (object == 1)
		return sizeof(verticesControl) / sizeof(verticesControl[0]);
}

float menu::getVertices(int object, int i) {
	if (object == 0)
		return verticesLogo[i];
	else if (object == 1)
		return verticesControl[i];
}

void menu::setSelect(int select) {
	selectMenu = select;
}

void menu::translation(float tx, float ty, float tz) {
	for (int i = 0; i < sizeof(verticesControl) / sizeof(verticesControl[0]); i += 3) {
		verticesControl[i] += tx;
	}

	for (int i = 1; i < sizeof(verticesControl) / sizeof(verticesControl[0]); i += 3) {
		verticesControl[i] += ty;
	}

	for (int i = 2; i < sizeof(verticesControl) / sizeof(verticesControl[0]); i += 3) {
		verticesControl[i] += tz;
	}
}

int menu::getDatabase(int Entries, int Arr[]) {
	for (int i = 0; i < Entries; i++) {
		return Arr[i];
	}
}

void menu::readFromFile(char fileName[], int storage[], int& noOfEn) {
	ifstream take(fileName);
	take >> noOfEn;

	for (int i = 0; i < noOfEn; i++) {
		take >> storage[i];
	}
}

void menu::inputToFile(string fileName, int longArray, long contentArray) {
	ofstream file(fileName);
	file << longArray << endl << contentArray;
	file.close();
}