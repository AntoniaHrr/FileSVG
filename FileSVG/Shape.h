#pragma once
#include <cmath>

class Shape {
protected:
	struct point {
		point() {
			x = 0;
			y = 0;
		}
		point(double x, double y) {
			this->x = x;
			this->y = y;
		}
		double x;
		double y;
		double getDistance(const point& other) const {
			double distanceX = x - other.x;
			double distanceY = y - other.y;
			return sqrt(distanceX * distanceX + distanceY * distanceY);
		}
	};
	point& getPointAtIndex(size_t index) const;
private:
	point* points;
	size_t pointsCount;
	//double x, y;
	char* color;
	void copyFrom(const Shape& other);
	void free();
public:
	Shape();
	Shape(size_t number, char* color);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	void setPoint(size_t pointIndex, double x, double y);
	void Translate(double, double);
	char* convertNumbertoArray(char*, double);


	virtual double getX1() const =0;
	virtual double getY1() const = 0;
	virtual double getX2() const = 0;
	virtual double getY2() const = 0;
	virtual double getRadius() const = 0;
	virtual double getStroke() const = 0;

	virtual void CheckShape(char*) = 0;
	virtual double getArea() const = 0;
	virtual double getPerimeter()  const = 0;
	virtual void PrintShapeInfo() = 0;
	virtual bool CheckIfPointIsInShape(double, double) const = 0;
	virtual bool CheckIfShapeIsInRectangle(double, double, double, double) = 0;
	virtual bool CheckIfPointIsInCircle(double, double, double) = 0;
	virtual Shape* clone() const = 0;

	char* getColor() const;
	int getPointsCount() const;
};