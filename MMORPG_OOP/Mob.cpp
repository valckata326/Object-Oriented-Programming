#include "pch.h"
#include "Mob.h"
#include "Player.h"

void Mob::setType()
{
	this->type = Types::MOB;
}

Mob::Mob() : Entity()
{
	setType();
	setDamage(1);
	setHealth(1);
}

Mob::Mob(const Mob & other) : Entity(other)
{
	*this = other;
}

Mob::Mob(const string name, Point2D * location, int damage, int health) : Entity(name,location)
{
	setType();
	setDamage(damage);
	setHealth(health);
}

Mob & Mob::operator=(const Mob & other)
{
	if (this != &other)
	{
		Entity::operator=(other);
		setType();
		setDamage(other.getDamage());
		setHealth(other.getHealth());
	}
	return *this;
}

Mob::~Mob()
{
}

bool Mob::isAlive() const
{
	return this->health > 0;
}

void Mob::setDamage(int damage)
{
	this->damage = damage;
}

int Mob::getDamage() const
{
	return this->damage;
}

void Mob::setHealth(int health)
{
	this->health = health;
}

int Mob::getHealth() const
{
	return this->health;
}

void Mob::attack(Entity* other)
{
	double distance = this->getDistanceTo(*other);
	Player* castToPlayer = dynamic_cast<Player*>(other);
	if (distance < 5 && other->isAlive())
	{
		if (this->getDamage() > castToPlayer->getHealth())
		{
			castToPlayer->setHealth(0);
		}
		else
		{
			castToPlayer->setHealth(castToPlayer->getHealth() - this->getDamage());
		}
	}
}

Types::Type Mob::getType() const
{
	return this->type;
}

Mob * Mob::clone()
{
	return new Mob(*this);
}

void Mob::print() const
{
	Entity::print();
	cout << "Type: " << this->getType() << " // ";
	cout << "Health: " << this->getHealth() << " // ";
	cout << "Damage: " << this->getDamage() << " // ";
	cout << endl;
}
