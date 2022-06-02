#include "CreateShape.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include <iostream>
#include <fstream>
#pragma warning (disable: 4996)

void CreateShape::Save() {
	std::ofstream outfile("Figures.txt", std::ios::app);
	if (!outfile.is_open())
	{
		std::cout << "File could not be opened" << std::endl;
		return;
	}
	outfile << "The number " << "is not present in the array." << std::endl;
	outfile.close();

}

void CreateShape::Read() {
	std::ifstream myfile;
	myfile.open("Figures.txt", std::ios::in);

	if (!myfile.is_open()) {
		std::cout << "Cant open file";
		return;
	}
	while (!myfile.eof()) {
	    char* line;
		line = new char[1000];
		myfile.getline(line, 1000);
		if (line[2] == 'r') {
			double x = 0;
			double y = 0;
			int i = 0;
			int l = 0;
			int ten = 10;
			double width = 0;
			double height = 0;
			for (i = 10; line[i] != '"'; i++) {
				x = ten * x + (line[i] - '0');
			}
			for (l = i + 5; line[l] != '"'; l++) {
				y = ten*y + (line[l] - '0');
			}
			for (i = l + 9; line[i] != '"'; i++) {
				width = ten*width + (line[i] - '0');
			}
			for (l = i + 10; line[l] != '"'; l++) {
				height = ten * height + (line[l] - '0');
			}
			char* color;
			color = new char[100];
			int n = 0;
			for (i = l + 8; line[i] != '"'; i++) {
				color[n] = line[i];
				n++;
			}
			color[n] = '\0';
			addRectangle(x, y, width, height, color);
			delete[] color;
		}
		else if (line[2] == 'c') {
			double x = 0;
			double y = 0;
			double radius=0;
			int i = 0;
			int l = 0;
			int ten = 10;
			for (i = 13; line[i] != '"'; i++) {
				x = ten *x+ (line[i] - '0');
			}
			for (l = i + 6; line[l] != '"'; l++) {
				y = ten *y +(line[l] - '0');
			}
			for (i = l + 5; line[i] != '"'; i++) {
				radius= ten*radius + (line[i] - '0');
			}
			char* color;
			color = new char[100];
			int n = 0;
			for (l = i + 8; line[l] != '"'; l++) {
				color[n] = line[l];
				n++;
			}
			color[n] = '\0';
			addCircle(x, y, radius, color);
			delete[] color;
		}
		else if (line[2] == 'l') {
			double x = 0;
			double y = 0;
			double x2 = 0;
			double y2 = 0;
			double stroke_width = 0;
			int i = 0;
			int l = 0;
			int ten = 1;
			for (i = 12; line[i] != '"'; i++) {
				x = ten * x + (line[i] - '0');
			}
			for (l = i + 6; line[l] != '"'; l++) {
				y = ten * y + (line[l] - '0');
			}
			for (i = l + 6; line[i] != '"'; i++) {
				x2=x2*ten + (line[i] - '0');
			}
			ten = 1;
			for (i = l + 6; line[i] != '"'; i++) {
				y2=y2* ten + (line[i] - '0');
			}
			char* color = new char[100];
			int n = 0;
			for (l = i + 10; line[l] != '"'; l++) {
				color[n] = line[l];
				n++;
			}
			color[n] = '\0';
			for (i = l + 16; line[i] != '"'; i++) {
				stroke_width = stroke_width * ten + (line[i] + '0');
			}
			addLine(x,y,x2,y2,stroke_width,color);
			delete[] color;

		}
	}
	myfile.close();
}

void CreateShape::free() {
	for (size_t i = 0; i < shapesCount; i++)
		delete shapes[i];
	delete[] shapes;
}
void CreateShape::copy(const CreateShape& other) {
	shapes = new Shape * [other.shapesCount];
	shapesCount = other.shapesCount;
	capacity = other.capacity;

	for (size_t i = 0; i < shapesCount; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}
}

void CreateShape::resize() {
	Shape** temp = new Shape * [capacity *= 2];
	for (size_t i = 0; i < shapesCount; i++) {
		temp[i] = shapes[i];
	}
	delete[] shapes;
	shapes = temp;
}

CreateShape::CreateShape() {
	capacity = 1;
	shapesCount = 0;
	shapes = new Shape * [capacity];
}

CreateShape::CreateShape(const CreateShape& other) {
	copy(other);
}
CreateShape& CreateShape::operator=(const CreateShape& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}
CreateShape::~CreateShape() {
	free();
}

void CreateShape::addShape(Shape* shape) {
	if (shapesCount == capacity)
		resize();
	shapes[shapesCount++] = shape;
}
//const color maybe
void CreateShape::addRectangle(double x, double y, double width, double height, char* color) {
	Rectangle* rect = new Rectangle(x, y, width, height, color);
	addShape(rect);
}
//const color maybe
void CreateShape::addCircle(double x, double y, double radius, char* color) {
	Circle* circlce = new Circle(x, y, radius, color);
	addShape(circlce);

}

//const color maybe
void CreateShape::addLine(double x1, double y1, double x2, double y2, double width,char* color) {
	Line* line = new Line(x1, y1, x2, y2, width, color);
	addShape(line);
}


double CreateShape::getPerOfFigureByIndex(size_t ind) const {
	if (ind >= shapesCount) {
		std::cout << "Out of range in shapes collection" << std::endl;;
	}
	return shapes[ind]->getPerimeter();
}
double CreateShape::getAreaOfFigureByIndex(size_t ind) const {
	if (ind >= shapesCount) {
		std::cout << "Out of range in shapes collection" << std::endl;;
	}
	return shapes[ind]->getArea();
}
double CreateShape::getIfPointInShapeByIndex(size_t ind, int x, int y) const {
	if (ind >= shapesCount) {
		std::cout << "Out of range in shapes collection" << std::endl;;
	}
	return shapes[ind]->CheckIfPointIsInShape(x, y);
}

void CreateShape::translateShape(int index, double x, double y) {
	shapes[index]->Translate(x,y);
}

void CreateShape::print() {
	int count = 1;
	for (int i = 0; i < shapesCount; i++) {
		if (shapes[i] != nullptr) {
			std::cout << count << ". ";
			shapes[i]->PrintShapeInfo();
			std::cout<<'\n';
			count++;
		}
	}
}

void CreateShape::deleteShape(int index) {
	delete shapes[index];
	for (int i = index; i < shapesCount -1; i++) {
		shapes[i] = shapes[i + 1];
	}
	shapesCount--;
}

void CreateShape::getAreas() {
	int count = 1;
	for (int i = 0; i < shapesCount; i++) {
		if (shapes[i] != nullptr) {
			std::cout << count << ". "<< shapes[i]->getArea() << std::endl;
			count++;
		}
	}
}

void CreateShape::getPer() {
	int count = 1;
	for (int i = 0; i < shapesCount; i++) {
		if (shapes[i] != nullptr) {
			std::cout << count << ". "<< shapes[i]->getPerimeter() << std::endl;
			count++;
		}
	}
}

void CreateShape::pointInShapes(double x, double y) {
	for (int i = 0; i < capacity; i++) {
		if (shapes[i] != nullptr) {
			if (shapes[i]->CheckIfPointIsInShape(x, y)) {
				std::cout << "The point is in shape: " << i << std::endl;
			}
		}
	}
}

void CreateShape::within(char* shape) {
	if (strcmp(shape, "rectangle") == 0) {
		double x = 0, y = 0, height = 0, width = 0;
		std::cout << "Enter x1: ";
		std::cin >> x;
		std::cout << "Enter y1: ";
		std::cin >> y;
		std::cout << "Enter width: ";
		std::cin >> width;
		std::cout << "Enter height: ";
		std::cin >> height;

		for (int i = 0; i < capacity; i++) {
			if (shapes[i] != nullptr) {
				if (shapes[i]->CheckIfShapeIsInRectangle(x, y, height, width)) {
					std::cout << "Figure with index: " << i << " is in this region!" << std::endl;
				}
			}
		}
	}
	if (strcmp(shape, "circle") == 0) {
		double x = 0, y = 0, radius = 0;
		std::cout << "Enter x: ";
		std::cin >> x;
		std::cout << "Enter y: ";
		std::cin >> y;
		std::cout << "Enter radius: ";
		std::cin >> radius;

		for (int i = 0; i < capacity; i++) {
			if (shapes[i] != nullptr) {
				if (shapes[i]->CheckIfPointIsInCircle(x, y, radius)) {
					std::cout << "Figure with index: " << i << " is in this region!" << std::endl;
				}
			}
		}
	}
}