//Rectangle.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>  //Prova a togliere
#include "Rectangle.h"
using std::invalid_argument;
using std::cout;
using std::fabs;

Rectangle::Rectangle(Point a,Point b,Point c,Point d,char fillChar,char perimeterChar){
	setCoord(a,b,c,d);
	setFillCharacter(fillChar);
	setPerimeterCharacter(perimeterChar);
}
void Rectangle::setCoord(Point a,Point b,Point c,Point d){
	//Arrangments of points
	// p4.........p3
	// .          .
	// .          .
	// p1         p2
	
	if(!(point1.getY()==point2.getY() && point2.getX()==point3.getX() && point4.getY()==point3.getY()
		&& point1.getX()==point4.getX())){
		throw invalid_argument("Coordinates don't form a rectangle");
	}
	point1=a;
	point2=b;
	point3=c;
	point4=d;
}
double Rectangle::height() const{
	return fabs(point4.getY() - point1.getY());
}
double Rectangle::width() const{
	return fabs(point2.getX()-point1.getX());
}
double Rectangle::perimeter() const{
	return (width()+height())*2;
}
double Rectangle::area() const{
	return width()*height();
}
bool Rectangle::square() const{
	return width()==height();
}
void Rectangle::draw() const{               //parto dall'alto del foglio
	for(double y{25.0};y>=0.0;--y){         //x rappresenta le colonne,y le righe       
		for(double x{0.0};x<=25.0;++x){
			if((point1.getX()==x && point1.getY()==y) || (point4.getX()==x && point4.getY()==y)){
				while(x<=point2.getX()){
					cout<<perimeterCharacter;
					++x;
				}
				cout<<'.';
			}
			else if((x==point4.getX())&&(point4.getY()>=y && point1.getY()<=y)){
				cout<<perimeterCharacter;
				for(++x;x<point2.getX();){
					cout<<fillCharacter;
					++x;
				}
				cout<<perimeterCharacter;
			}
			else{
				cout<<'.';
			}
		}
		cout<<'\n';
	}
}
void Rectangle::setFillCharacter(char fillChar){
	fillCharacter=fillChar;
}
void Rectangle::setPerimeterCharacter(char perimeterChar){
	perimeterCharacter=perimeterChar;
}







