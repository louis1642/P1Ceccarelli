//Point.h
#ifndef POINT_H
#define POINT_H

class Point{
public:
	explicit Point(double=0.0,double=0.0);
	void setX(double);
	void setY(double);
	double getX() const;
	double getY() const;
private:
	double x;
	double y;
};
#endif