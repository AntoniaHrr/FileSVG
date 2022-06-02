#pragma once
#include "Shape.h"

class Circle : public Shape {

	double radius;

public:
	Circle(double, double, double, char*);

	double getX1() const override;
	double getY1() const override;
	double getX2() const override;
	double getY2() const override;
	double getRadius() const override;
	double getStroke() const override;

	void CheckShape(char*) override;
	void PrintShapeInfo() override;
	double getArea() const override;
	double getPerimeter() const override;
	bool CheckIfPointIsInShape(double, double) const override;
	bool CheckIfShapeIsInRectangle(double, double, double, double) override;
	bool CheckIfPointIsInCircle(double, double, double) override;


	Shape* clone() const override;
};