#include "Circle.h"
#include <iostream>
#pragma warning (disable: 4996)

const double PI = 3.14;
Circle::Circle(double x, double y, double radius,char* color) : Shape(1, color) {
	setPoint(0, x, y);
	this->radius = radius;
}

double Circle::getArea() const {
	return PI * radius * radius;
}
double Circle::getPerimeter() const {
	return 2 * PI * radius;
}
bool Circle::CheckIfPointIsInShape(double x, double y) const {
	Shape::point p(x, y);
	return p.getDistance(getPointAtIndex(0)) <= radius;
}
Shape* Circle::clone() const {
	return new Circle(*this);
}
void Circle::PrintShapeInfo() {
	std::cout << "Circle xC="<< getPointAtIndex(0).x <<" yC=" << getPointAtIndex(0).y<<" R=" << radius<<" "<<getColor();
}

bool Circle::CheckIfShapeIsInRectangle(double xRec, double yRec, double heightRec, double widthRec) {
	if ((getPointAtIndex(0).x - radius) >= xRec && (getPointAtIndex(0).x + radius) <= xRec + widthRec) {
		if ((getPointAtIndex(0).y - radius) >= yRec && (getPointAtIndex(0).y - radius) <= yRec + heightRec) {
			return true;
		}
	}
	return false;
}
bool Circle::CheckIfPointIsInCircle(double xC, double yC, double rC) {
	setPoint(1, xC, yC);
	double distance = getPointAtIndex(0).getDistance(getPointAtIndex(1));
	
	if (rC < radius) {
		return rC + distance <= radius;
	}
		return radius + distance <= rC;

}

void Circle::CheckShape(char* arr) {
	strcpy(arr, "circle");
	arr[strlen("circle") + 1] = '\0';
}

double Circle::getX1() const {
	return getPointAtIndex(0).x;
}
double Circle::getY1() const {
	return getPointAtIndex(0).y;
}
double Circle::getX2() const {
	return 0;
}
double Circle::getY2() const {
	return 0;
}
double Circle::getRadius() const {
	return radius;
}
double Circle::getStroke() const {
	return 0;
}