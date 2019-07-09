#include "pch.h"
#include "Point2D.h"

Point2D::Point2D()
{
	setX(0);
	setY(0);
}

Point2D::Point2D(double x, double y)
{
	setX(x);
	setY(y);
}

Point2D::Point2D(const Point2D & other)
{
	setX(other.getX());
	setY(other.getY());
}

double Point2D::getX() const
{
	return this->x;
}

void Point2D::setX(double x)
{
	this->x = x;
}

double Point2D::getY() const
{
	return this->y;
}

void Point2D::setY(double y)
{
	this->y = y;
}

double Point2D::getDistanceTo(const Point2D& other) const
{
	return sqrt(pow(other.getX() - this->getX(), 2) + pow(other.getY() - this->getY(), 2));
}

Point2D * Point2D::clone() const
{
	return new Point2D(*this);
}

Point2D & Point2D::operator=(const Point2D & other)
{
	if (this != &other)
	{
		setX(other.getX());
		setY(other.getY());
	}
	return *this;
}

void Point2D::print() const
{
	std::cout << "(" << getX() << "," << getY() << ") // ";
}
