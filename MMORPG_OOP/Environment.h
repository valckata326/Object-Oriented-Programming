#pragma once
#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include <vector>

class Environment
{
	std::vector <Entity*> entitles;
	bool isEmpty();
	
public:
	int getSize();
	Environment();
	Environment(const Environment& other);
	Environment& operator=(const Environment& other);
	~Environment();

	void add(Entity* newEntity);
	Entity* getAt(int index) const;
	bool removeAt(int index);
	void generateEntities();
	void destroyEntities();
	Entity* getClosestAliveEntity(Entity* closestPlayer, Types::Type typeOf);
	void sortToClosest(Entity* player);
	void printEnvironment();
};