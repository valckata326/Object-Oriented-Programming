#include "pch.h"
#include "Player.h"

Player::Player() : Entity()
{
	setHealth(1);
	setDamage(1);
	setType();	
}

Player::Player(const string name, Point2D * location, int damage, int health) : Entity(name,location)
{
	setDamage(damage);
	setHealth(health);
	setType();
}

Player::Player(const Player & other) : Entity(other)
{
	*this = other;
	/*setHealth(other.getHealth());
	setDamage(other.getDamage());
	setType();*/
}

Player & Player::operator=(const Player & other)
{
	if (this != &other)
	{
		Entity::operator=(other);
		setHealth(other.getHealth());
		setDamage(other.getDamage());
		setType();
	}
	return *this;
}

Player::~Player()
{
}

bool Player::isAlive() const
{
	return this->health > 0;
}

void Player::setDamage(int damage)
{
	this->damage = damage;
}

int Player::getDamage() const
{
	return this->damage;
}

void Player::setHealth(int health)
{
	this->health = health;
}

int Player::getHealth() const
{
	return this->health;
}

void Player::setType()
{
	this->type = Types::PLAYER;
}

void Player::attack(Entity* other)
{
	double distance = this->getDistanceTo(*other);
	if (distance < 5 && other->isAlive())
	{
		Player* castToPlayer = dynamic_cast<Player*>(other);
		if (castToPlayer != nullptr)
		{
			if (castToPlayer->getHealth() - this->getDamage() < 0)
			{
				castToPlayer->setHealth(0);
			}
			else
			{
				castToPlayer->setHealth(castToPlayer->getHealth() - this->getDamage());
			}
		}
		Mob* castToMob = dynamic_cast<Mob*>(other);
		if (castToMob != nullptr)
		{
			if (castToMob->getHealth() - this->getDamage()  < 0)
			{
				castToMob->setHealth(0);
			}
			else
			{
				castToMob->setHealth(castToMob->getHealth() - this->getDamage());
			}
		}
	}
}

Types::Type Player::getType() const
{
	return this->type;
}

Player* Player::clone()
{
	return new Player(*this);
}

void Player::print() const
{
	Entity::print();
	cout <<"Type: "<< this->getType()<<" // ";
	cout << "Health: " << this->getHealth() << " // ";
	cout << "Damage: " << this->getDamage() << " // ";
	cout << endl;
}
