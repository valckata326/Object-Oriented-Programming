#pragma once
#include "Entity.h"

class Mob : public Entity {
	int damage;
	int health;
	void setType() override;
public:
	Mob();
	Mob(const Mob& other);
	Mob(const string name, Point2D* location, int damage, int health);
	Mob& operator=(const Mob& other);
	~Mob();

	bool isAlive() const override;

	void setDamage(int damage);
	int getDamage() const;

	void setHealth(int health);
	int getHealth() const;

	void attack(Entity* other);

	Types::Type getType() const;
	
	virtual Mob* clone() override;
	virtual void print() const override;
};