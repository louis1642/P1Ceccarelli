//Point.cpp
#include <stdexcept>
#include "Point.h"
using std::invalid_argument;
Point::Point(double xCord, double yCord){
	setX(xCord);
	setY(yCord);
}
void Point::setX(double xCord){
	if(xCord<0.0 || xCord>20.0){
		throw invalid_argument("x must be >=0.0 and <=20.0");
	}
	x=xCord;
}
void Point::setY(double yCord){
	if(yCord<0.0 || yCord>20.0){
		throw invalid_argument("y must be >=0.0 and <=20.0");
	}
	y=yCord;
}
double Point::getX() const{
	return x;
}
double Point::getY() const{
	return y;
}