#pragma once
#include "Shape.h"

class Line : public Shape
{
private:
	double stroke_width;
public:
	Line(double x, double y, double x1, double y1, double stroke_width, char* color);

    double getArea() const override;
	double getPerimeter() const override;
	void PrintShapeInfo() override;
	bool CheckIfPointIsInShape(double x, double y) const override;
	bool CheckIfShapeIsInRectangle(double Rectangle_X, double Rectangle_Y, double Rectangle_Height, double Rectangle_Width) override;
	bool CheckIfPointIsInCircle(double Centre_X, double Centre_Y, double Circle_R) override;

	Shape* clone() const override;

};