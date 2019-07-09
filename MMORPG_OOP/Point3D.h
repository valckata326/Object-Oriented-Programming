#pragma once
#include "Point2D.h"
class Point3D : public Point2D
{
	double z;
public:
	Point3D();
	Point3D(double x, double y, double z);
	Point3D(const Point3D& other);

	double getZ() const;
	void setZ(double z);

	double getDistanceTo(const Point3D& other);

	virtual Point3D* clone() const;
	Point3D& operator=(const Point3D& other);
	virtual void print() const;
};