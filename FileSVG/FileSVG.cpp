#include <iostream>
#include <cstring>
#include <fstream>
#include "CreateShape.h"
using namespace std;

int main()
{
	CreateShape s;
	s.Read();
	char input[4096];

	while (true) {
		cout << "command: ";
		cin.getline(input, 4096);
		if (strcmp(input, "Menu") == 0) {
			cout << "Print" << endl;
			cout << "Create" << endl;
			cout << "Erase" << endl;
			cout << "Translate" << endl;
			cout << "Within" << endl;
			cout << "PointIn" << endl;
			cout << "Areas" << endl; 
			cout << "Pers" << endl; 
			cout << "Save" << endl;
		}
		else if (strcmp(input, "Save") == 0) {
			s.Save();
		}
		else if (strcmp(input, "Pers") == 0) {
			s.getPer();
		}
		else if (strcmp(input, "Areas") == 0) {
			s.getAreas();
		}
		else if (strcmp(input, "PointIn") == 0) {
			double x, y;
			cout << "Enter X coordinate:";
			cin >> x;
			cin.ignore();
			cout << "Enter Y coordinate:";
			cin >> y;
			cin.ignore();
			s.pointInShapes(x,y);
		}
		else if (strcmp(input, "Within") == 0) {
			char* shape = new char[100];
			s.within(shape);
			delete[] shape;
		}
		else if (strcmp(input, "Translate") == 0) {
			double w, h;
			int index;
			cout << "Enter figure to translate:";
			cin >> index;
			cin.ignore();
			cout << "Enter new width:";
			cin >> w;
			cin.ignore();
			cout << "Enter new height:";
			cin >> h;
			cin.ignore();
			s.translateShape(index, w, h);
		}
		else if (strcmp(input, "Erase") == 0) {
			int index;
			cout << "Which figure would you like to erase?:";
			cin >> index;
			cin.ignore();
			s.deleteShape(index);
		}
		else if (strcmp(input, "Create") == 0) {
			char figure[100];
			cout << "Enter figure:";
			cin.getline(figure,100);
			if (strcmp(figure, "Rectangle") == 0) {
				double x1, y1, x2, y2;
				char color[100];
				cout << "Enter coordinate X:";
				cin >> x1;
				cin.ignore();
				cout << "Enter coordinate Y:";
				cin >> y1;
				cin.ignore();
				cout << "Enter width:";
				cin >> x2;
				cin.ignore();
				cout << "Enter height:";
				cin >> y2;
				cin.ignore();
				cout << "Enter color:";
				cin.getline(color, 100);
				s.addRectangle(x1, y1, x2, y2, color);
			}
			else if (strcmp(figure, "Circle") == 0) {
				double x1, y1, x2;
				char color[100];
				cout << "Enter coordinate X:";
				cin >> x1;
				cin.ignore();
				cout << "Enter coordinate Y:";
				cin >> y1;
				cin.ignore();
				cout << "Enter radius:";
				cin >> x2;
				cin.ignore();
				cout << "Enter color:";
				cin.getline(color, 100);
				s.addCircle(x1, y1, x2, color);
			}
			else if (strcmp(figure, "Line") == 0) {
				double x1, y1, x2, y2, stroke;
				char color[100];
				cout << "Enter coordinate X1:";
				cin >> x1;
				cin.ignore();
				cout << "Enter coordinate Y1:";
				cin >> y1;
				cin.ignore();
				cout << "Enter coordinate X2:";
				cin >> x2;
				cin.ignore();
				cout << "Enter coordinate Y2:";
				cin >> y2;
				cin.ignore();
				cout << "Enter stroke width:";
				cin >> stroke;
				cin.ignore();
				cout << "Enter color:";
				cin.getline(color, 100);
				s.addLine(x1, y1, x2, y2,stroke,color);
			}
		}
		else if (strcmp(input, "Print") == 0) {
			s.print();
		}
	}

	return 0;

}