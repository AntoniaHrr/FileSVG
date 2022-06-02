#pragma once
#include "Shape.h"

class CreateShape
{
	Shape** shapes;
	size_t shapesCount;
	size_t capacity;

public:
	CreateShape();
	CreateShape(const CreateShape& other);
	CreateShape& operator=(const CreateShape& other);
	~CreateShape();

	void Read();
	void Save();

	void addRectangle(double, double, double, double, char*);
	void addCircle(double, double, double, char*);
	void addLine(double, double, double, double, double, char*);
	void addShape(Shape*);

	double getPerOfFigureByIndex(size_t) const;
	double getAreaOfFigureByIndex(size_t) const;
	double getIfPointInShapeByIndex(size_t, int, int) const;

	void translateShape(int,double,double);
	void print();
	void deleteShape(int);
	void getAreas();
	void getPer();
	void pointInShapes(double, double);
	void within(char*);

private:
	void free();
	void copy(const CreateShape&);
	void resize();
};