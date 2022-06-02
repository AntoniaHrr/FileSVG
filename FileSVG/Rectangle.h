#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	double height, width;
public:
	Rectangle(double x, double y, double width, double height, char* color);

	void setHeight(double height);
	void setWidth(double width);

	double getHeight() const;
	double getWidth() const;

	double getArea() const override;
	double getPerimeter() const override;
	void PrintShapeInfo() override;
	bool CheckIfPointIsInShape(double x, double y) const override;
	bool CheckIfShapeIsInRectangle(double Rectangle_X, double Rectangle_Y, double Rectangle_Height, double Rectangle_Width) override;
	bool CheckIfPointIsInCircle(double Centre_X, double Centre_Y, double Circle_R) override;


	Shape* clone() const override;

};