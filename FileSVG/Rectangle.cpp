#include "Rectangle.h"
#include "Circle.h"
#include <cstring>
#include <iostream>
#pragma warning (disable: 4996)

Rectangle::Rectangle(double x, double y, double width, double height, char* color) : Shape(4, color) {
	setPoint(0, x, y);
	setPoint(1, x, (height + y));
	setPoint(2, (width + x), y);
	setPoint(3, (width + x), (height + y));
	this->width = width;
	this->height = height;
}
double Rectangle::getArea() const {
	return width * height;
}
double Rectangle::getPerimeter() const {
	return 2 * (height + width);
}

bool Rectangle::CheckIfPointIsInShape(double x, double y) const {
	Shape::point p(x, y);
	return p.x >= getPointAtIndex(0).x && p.x <= getPointAtIndex(2).x &&
		p.y <= getPointAtIndex(1).y && p.y >= getPointAtIndex(0).y;
}
bool Rectangle::CheckIfShapeIsInRectangle(double Rectangle_X, double Rectangle_Y, double Rectangle_Height, double Rectangle_Width) {
	
	for (int i = 0; i < 4; i++) {
		if (!(getPointAtIndex(i).x >= Rectangle_X && getPointAtIndex(i).x <= (Rectangle_X + Rectangle_Width)
			&& getPointAtIndex(i).y >= Rectangle_Y && getPointAtIndex(i).y <= (Rectangle_Y + Rectangle_Height))) {
			return false;
		}
	}
	return true;
}
bool Rectangle::CheckIfPointIsInCircle(double Centre_X, double Centre_Y, double Circle_R) {
	//////// 
	char* color = new char[100];
	strcpy(color, "No color");
	color[strlen("No color") + 1] = '\0';
	Circle circle(Centre_X, Centre_Y, Circle_R, color);
	for (int i = 0; i < 4; i++) {
		if (!circle.CheckIfPointIsInShape(getPointAtIndex(i).x, getPointAtIndex(i).y)) {
			return false;
		}
		return true;
	}
	delete[] color;
}

Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}

void Rectangle::setHeight(double height) {
	this->height = height;
}
void Rectangle::setWidth(double width) {
	this->width = width;
}

double Rectangle::getHeight() const{
	return height;
}
double Rectangle::getWidth() const{
	return width;
}
double Rectangle::getX1() const {
	return getPointAtIndex(0).x;
}
double Rectangle::getY1() const {
	return getPointAtIndex(0).y;
}
double Rectangle::getX2() const {
	return width;
}
double Rectangle::getY2() const {
	return height;
}
double Rectangle::getRadius() const {
	return 0;
}
double Rectangle::getStroke() const {
	return 0;
}

void Rectangle::CheckShape(char* arr) {
	strcpy(arr, "rectangle");
	arr[strlen("rectangle") + 1] = '\0';
}

void Rectangle::PrintShapeInfo() {
	std::cout << "Rectangle x="<<getPointAtIndex(0).x<<" y="<< getPointAtIndex(0).y <<" width="<<width<<" height="<<height<<" "<<getColor();
}