//Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"
class Rectangle{
public:
	explicit Rectangle(Point=Point(0.0,1.0), Point=Point(1.0,1.0), Point=Point(1.0,0.0), //cosi inizializzo oggetti
		Point=Point(0.0,0.0), char='*',char='*');
	void setCoord(Point, Point,Point,Point);
	double height() const;
	double width() const;
	double perimeter() const;
	double area() const;
	bool square() const;
	void draw() const;
	void setPerimeterCharacter(char);
	void setFillCharacter(char);
private:
	Point point1;
	Point point2;
	Point point3;
	Point point4;
	char fillCharacter;
	char perimeterCharacter;
};
#endif