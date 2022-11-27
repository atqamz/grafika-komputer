#include <iostream>
#include "obstacle.h"
using namespace std;

int obstacle::getLong() {
	return sizeof(vertices) / sizeof(vertices[0]);
}

float obstacle::getVertices(int i) {
	return vertices[i];
}

float obstacle::getSpeed() {
	return speed;
}

float obstacle::getDistance() {
	return distance;
}

bool obstacle::getCondition() {
	return setup;
}

void obstacle::setCondition(bool inputCondition) {
	setup = inputCondition;
}

void obstacle::setSpeed(float inputSpeed) {
	speed = inputSpeed;
}

void obstacle::setDistance(float inputDistance) {
	distance = inputDistance;
}

void obstacle::setFirstPosition(int order, float distance) {
	if (order == 0) {
		for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
			vertices[i] -= distance;
		}
	}
	else if (order == 1) {
		for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i += 3) {
			vertices[i] += distance;
		}
	}

	setup = true;
}

void obstacle::resetPosition() {
	for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i++) {
		vertices[i] = firstVertices[i];
	}
}

void obstacle::translation(float tx, float ty, float tz) {
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