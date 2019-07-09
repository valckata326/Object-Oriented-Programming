#include "pch.h"
#include "Entity.h"
using namespace std;
void Entity::setLocation(Point2D* other)
{
	if (other == nullptr || this->location == other) return;
	this->location = other->clone();
}

void Entity::setType()
{
}


Entity::Entity() : Entity("", nullptr)
{
	ID = id++;
}

Entity::Entity(const Entity & other)
{
	ID = id++;
	this->operator=(other);
}

Entity::Entity(const string name, Point2D* other)
{
	ID = id++;
	setName(name);
	setLocation(other);
}

Entity & Entity::operator=(const Entity & other)
{
	if (this != &other)
	{
		setName(other.getName());
		setLocation(other.getLocation());
		//setType(other.getType());
	}
	return *this;
}

Entity::~Entity()
{
	delete this->location;
}

bool Entity::isAlive() const
{
	return true;
}

double Entity::getDistanceto2D(const Entity & other) const
{
	double distance = this->location->getDistanceTo(*other.getLocation());
	return distance;

}

double Entity::getDistanceTo(const Entity & other) const
{
	Point3D* castThisTo3D = dynamic_cast<Point3D*>(this->location);
	Point3D* castOtherTo3D = dynamic_cast<Point3D*>(other.getLocation());
	if (castThisTo3D == nullptr || castOtherTo3D == nullptr)
	{
		return getDistanceto2D(other);
	}
	double result = castThisTo3D->getDistanceTo(*(castOtherTo3D));
	return result;
}

void Entity::MoveTo(Point2D & new_point)
{
	Point3D* castThisTo3D = dynamic_cast<Point3D*>(this->location);
	Point3D* castOtherTo3D = dynamic_cast<Point3D*>(&new_point);
	if (castThisTo3D == nullptr && castOtherTo3D == nullptr)
	{
		delete this->location;
		setLocation(&new_point);
	}
	else if (castThisTo3D == nullptr && castOtherTo3D != nullptr)
	{
		this->location->setX(new_point.getX());
		this->location->setY(new_point.getY());
	}
	else if (castThisTo3D != nullptr && castOtherTo3D == nullptr)
	{
		delete this->location;
		setLocation(&new_point);
	}
	else
	{
		delete this->location;
		setLocation(&new_point);
	}
}

void Entity::MoveTo(const Entity & other)
{
	this->MoveTo(*other.getLocation());
}

unsigned long long Entity::getID() const
{
	return this->ID;
}

void Entity::setName(const string name)
{
	this->name = name;
}

string Entity::getName() const
{
	return this->name;
}

Point2D * Entity::getLocation() const
{
	return this->location;
}
void Entity::print() const
{
	cout <<"ID: "<< this->getID()<<" // ";
	cout <<"Name: "<< this->name.c_str()<<" // ";
	this->location->print();
}
/*
Entity* Entity::clone() 
{
	//return new Entity(*this);
}*/
