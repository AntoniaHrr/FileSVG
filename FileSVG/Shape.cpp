#include "Shape.h"
#include <cstring>
#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

Shape::Shape() {
	this->color = nullptr;
	this->pointsCount = 0;
	this->points = nullptr;
}

Shape::Shape(size_t pointsCount, char* color) : pointsCount(pointsCount) {
	points = new point[pointsCount];
	int len = strlen(color);
	this->color = new char[len + 1];
	strcpy(this->color, color);
}

void Shape::copyFrom(const Shape& other) {
	points = new point[other.pointsCount];

	int len = strlen(color);
	this->color = new char[len + 1];
	strcpy(this->color, color);

	for (int i = 0; i < other.pointsCount; i++)
	{
		points[i] = other.points[i];
	}
	pointsCount = other.pointsCount;
}
void Shape::free() {
	delete[] points;
	delete[] color;
}

Shape::Shape(const Shape& other) {
	copyFrom(other);
}
Shape& Shape::operator= (const Shape& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Shape::~Shape() {
	free();
}
char* Shape::convertNumbertoArray(char* arr, double number) {
	*(double*)arr = number;
	return arr;
}

Shape::point& Shape::getPointAtIndex(size_t index) const {
	if (index >= pointsCount)
	{
		return points[0];
	}
	return points[index];
}

void Shape::Translate(double x, double y) {
	for (int i = 0; i < pointsCount; i++) {
		setPoint(i, getPointAtIndex(i).x + x, getPointAtIndex(i).y + y);
	}
}

void Shape::setPoint(size_t pointIndex, double x, double y) {
	if (pointIndex >= pointsCount)
	{
		cout << "Invalid index";
	}
	else { points[pointIndex] = point(x, y); }
}
char* Shape::getColor() const {
	return this->color;
}
int Shape::getPointsCount() const {
	return this->pointsCount;
}
