#include "pch.h"
#include "NPC.h"

NPC::NPC() : Entity()
{
	setType();
}

NPC::NPC(const NPC & other) : Entity(other)
{
	setType();
}

NPC & NPC::operator=(const NPC & other)
{
	if (this != &other)
	{
		Entity::operator=(other);
	}
	return *this;
}

NPC::~NPC()
{
}

NPC::NPC(const string name, Point2D * location) : Entity(name, location)
{
	setType();
}

bool NPC::isAlive() const
{
	return true;
}

Types::Type NPC::getType() const
{
	return this->type;
}

NPC * NPC::clone()
{
	return new NPC(*this);
}

void NPC::print() const
{
	Entity::print();
	cout << "Type: " << this->getType() << " ";
	cout << endl;
}

void NPC::setType()
{
	this->type = Types::NPC;
}
