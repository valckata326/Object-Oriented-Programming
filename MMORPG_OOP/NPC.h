#pragma once
#include "Entity.h"
class NPC : public Entity
{
	void setType() override;
public:
	NPC();
	NPC(const string name, Point2D* location);
	NPC(const NPC& other);
	NPC& operator=(const NPC& other);
	~NPC();

	bool isAlive() const override;
	Types::Type getType() const override;
	virtual NPC* clone() override;

	virtual void print() const override;
};