#include "player.h"

int player::getLong() {
	return sizeof(vertices) / sizeof(vertices[0]);
}

float player::getVertices(int i) {
	return vertices[i];
}

int player::getInfo() {
	return score;
}

int player::getScore() {
	return score;
}

void player::setScore(int inputScore) {
	score = inputScore;
}

void player::resetPosition() {
	for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i++) {
		vertices[i] = firstVertices[i];
	}
}

void player::translation(float tx, float ty, float tz) {
	for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
		vertices[i] += tx;
	}

	for (int i = 1; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
		vertices[i] += ty;
	}

	for (int i = 2; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
		vertices[i] += tz;
	}
}

void player::scalling(float rx, float ry, float rz) {
	for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
		vertices[i] *= rx;
	}

	for (int i = 1; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
		vertices[i] *= ry;
	}

	for (int i = 2; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
		vertices[i] *= rz;
	}
}