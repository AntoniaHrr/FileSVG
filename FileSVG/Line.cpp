#include "line.h"
#include <iostream>
#pragma warning (disable: 4996)

Line::Line(double x1, double y1, double x2, double y2, double width, char* color) : Shape(2, color) {
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	this->stroke_width = width;
}
double Line::getX1() const {
	return getPointAtIndex(0).x;
}
double Line::getY1() const {
	return getPointAtIndex(0).y;
}
double Line::getX2() const {
	return getPointAtIndex(1).x;
}
double Line::getY2() const {
	return getPointAtIndex(1).y;
}
double Line::getRadius() const {
	return 0;
}
double Line::getStroke() const {
	return stroke_width;
}

double Line::getArea() const {
	return 0;
}
double Line::getPerimeter() const {
	return 0;
}

bool Line::CheckIfPointIsInShape(double x, double y) const {
	Shape::point newP(x, y);
	Shape::point p1 = getPointAtIndex(0);
	Shape::point p2 = getPointAtIndex(1);

	return (((newP.y - p1.y) / (p2.y)) == ((newP.x - p1.x) / (p2.x - p1.x)));
	
}
Shape* Line::clone() const {
	return new Line(*this);
}

void Line::PrintShapeInfo() { ///////
	std::cout << "Line x1="<<getPointAtIndex(0).x<<" y1="<< getPointAtIndex(0).y << " x2="<<getPointAtIndex(1).x<<" y2="<< getPointAtIndex(1).y
		<< " stroke width="<<stroke_width<<" "<<getColor();
}

bool Line::CheckIfShapeIsInRectangle(double Rectangle_X, double Rectangle_Y, double Rectangle_Height, double Rectangle_Width) {
	if (getPointAtIndex(0).x >= Rectangle_X && getPointAtIndex(0).x <= (Rectangle_X + Rectangle_Width) &&
		getPointAtIndex(0).y >= Rectangle_Y && getPointAtIndex(0).y <= (Rectangle_Y + Rectangle_Height)) {
		if (getPointAtIndex(1).x >= Rectangle_X && getPointAtIndex(1).x <= (Rectangle_X + Rectangle_Width) &&
			getPointAtIndex(1).y >= Rectangle_Y && getPointAtIndex(1).y <= (Rectangle_Y + Rectangle_Height)) {
			return true;
	    }
	}
	return false;
}
bool Line::CheckIfPointIsInCircle(double Centre_X, double Centre_Y, double Circle_R) {

	Shape::point p1(getPointAtIndex(0).x, getPointAtIndex(0).y);
	Shape::point p2(getPointAtIndex(1).x, getPointAtIndex(1).y);

	return p1.getDistance(getPointAtIndex(0)) <= Circle_R && p2.getDistance(getPointAtIndex(0)) <= Circle_R;
}

void Line::CheckShape(char* arr) {
	strcpy(arr, "line");
	arr[strlen("line") + 1] = '\0';
	
}