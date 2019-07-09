#include "pch.h"
#include "Point3D.h"

Point3D::Point3D() : Point2D()
{
	setZ(0);
}

Point3D::Point3D(double x, double y, double z) : Point2D(x,y)
{
	setZ(z);
}

Point3D::Point3D(const Point3D & other) : Point2D(other.getX(), other.getY())
{
	setZ(other.getZ());
}

double Point3D::getZ() const
{
	return this->z;
}

void Point3D::setZ(double z)
{
	this->z = z;
}

double Point3D::getDistanceTo(const Point3D & other)
{
	return sqrt(pow(this->getX() - other.getX(),2)
		+ pow(this->getY() - other.getY(),2)
		+ pow(this->getZ() - other.getZ(),2));
}

Point3D * Point3D::clone() const
{
	return new Point3D(*this);
}

Point3D & Point3D::operator=(const Point3D & other)
{
	if (this != &other)
	{
		Point2D::operator=(other);
		setZ(other.getZ());
	}
	return *this;
}

void Point3D::print() const
{
	std::cout << "(" << this->getX() << "," << this->getY() << "," << this->getZ() << ") // ";
}
