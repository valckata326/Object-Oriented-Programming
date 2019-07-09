#pragma once
#include "Point3D.h"
using namespace std;
class Types
{
public:
	enum Type
	{
		PLAYER, NPC, MOB
	};
};

static unsigned long long int id = 1;
class Entity
{
	string name;
	Point2D* location;
protected:
	unsigned long long int ID;
	Types::Type type;
	void setLocation(Point2D* other);
	
	virtual void setType() = 0;
public:
	Entity();
	Entity(const Entity& other);
	Entity(const string name, Point2D* other);
	Entity& operator=(const Entity& other);
	virtual ~Entity();

	virtual bool isAlive() const;
	double getDistanceto2D(const Entity& other) const;
	double getDistanceTo(const Entity& other) const;

	void MoveTo(Point2D& new_point);
	void MoveTo(const Entity& other);

	unsigned long long getID() const;

	void setName(const string name);
	string getName() const;

	Point2D* getLocation() const;
	virtual Types::Type getType() const = 0;
	virtual Entity* clone() = 0;
	virtual void print() const;
};