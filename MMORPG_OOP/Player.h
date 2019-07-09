#pragma once
#include "Entity.h"
#include "Mob.h"

class Player : public Entity
{
	int damage;
	int health;
	void setType();
public:
	Player();
	Player(const string name, Point2D* location, int damage, int health);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();

	bool isAlive() const override;

	void setDamage(int damage);
	int getDamage() const;

	void setHealth(int health);
	int getHealth() const;

	
	void attack(Entity* other);

	Types::Type getType() const override;
	virtual Player* clone() override;
	virtual void print() const override;
};