#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
class Point2D
{
	double x;
	double y;
public:
	Point2D();
	Point2D(double x, double y);
	Point2D(const Point2D& other);

	double getX() const;
	void setX(double x);

	double getY() const;
	void setY(double y);

	virtual double getDistanceTo(const Point2D& other) const;
	virtual Point2D* clone() const;

	Point2D& operator=(const Point2D& other);
	virtual void print() const;

};
