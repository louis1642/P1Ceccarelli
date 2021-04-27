//driver.cpp
#include <iostream>
#include "Rectangle.h"
using std::cout;
int main(){
	Point point1{6.0,10.0};
	Point point2{18.0,10.0};
	Point point3{18.0,20.0};
	Point point4{6.0,20.0};
	Rectangle rectangle{point1,point2,point3,point4,'-','*'};
	cout<<"Rectangle height: "<<rectangle.height()<<"\n";
	cout<<"Rectangle width: "<<rectangle.width()<<"\n";
	cout<<"Rectangle perimeter: "<<rectangle.perimeter()<<"\n";
	cout<<"Rectangle area: "<<rectangle.area()<<"\n";
	rectangle.draw();
}