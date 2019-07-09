#include "pch.h"
#include "Environment.h"

bool Environment::isEmpty()
{
	return this->getSize() == 0;
}

int Environment::getSize()
{
	return entitles.size();
}

Environment::Environment()
{
}

Environment::Environment(const Environment & other)
{
	*this = other;

}

Environment & Environment::operator=(const Environment & other)
{
	if (this != &other)
	{
		int to_delete = entitles.size();
		for (int index = 0; index < to_delete; index++)
		{
			delete this->entitles[index];
		}
		this->entitles.clear();
		int to_add = other.entitles.size();
		for (int index = 0; index < to_add; index++)
		{
			Entity* temp = nullptr;
			if (other.entitles[index]->getType() == Types::Type(0))
			{
				temp = new Player;
			}
			else if (other.entitles[index]->getType() == Types::Type(1))
			{
				temp = new NPC;
			}
			else if (other.entitles[index]->getType() == Types::Type(2))
			{
				temp = new Mob;
			}
			*temp = *other.entitles[index];
			this->entitles.push_back(temp);
		}
	}
	return *this;
}

Environment::~Environment()
{
	int n = entitles.size();
	for (int index = 0; index < n; index++)
	{
		delete this->entitles[index];
	}
	this->entitles.clear();
}

void Environment::add(Entity * newEntity)
{
	Entity* temp = nullptr;
	if (newEntity->getType() == Types::Type(0))
	{
		temp = new Player;
	}
	else if (newEntity->getType() == Types::Type(1))
	{
		temp = new NPC;
	}
	else
	{
		temp = new Mob;
	}
	temp = newEntity->clone();
	this->entitles.push_back(temp);
}

Entity * Environment::getAt(int index) const
{
	int n = this->entitles.size();
	if (index < 0 || index >= n) return nullptr;
	return this->entitles[index];
}

bool Environment::removeAt(int index)
{
	int n = this->entitles.size();
	if (index < 0 || index >= n)
	{
		cout << "There is no entity with that index to be removed!" << endl;
		return false;
	}
	delete entitles[index];
	this->entitles.erase(this->entitles.begin() + index);
	cout << "Removed successfully!" << endl;
	return true;
}

void Environment::generateEntities()
{
	Point2D first_point(1, 2);
	Point2D second_point(2, 2);
	Point3D third_point(3, 4, 5);

	Player player1("Test_Player_1", &first_point, 20, 30);
	NPC npc1("Test_NPC_1", &second_point);
	NPC npc2("Test_NPC_2", &first_point);
	Mob mob1("Test_Mob_1", &third_point, 10, 15);
	Mob mob2("Test_Mob_2", &first_point, 5, 20);
	Entity* toAdd = &player1;
	this->add(toAdd);
	toAdd = &npc1;
	this->add(toAdd);
	toAdd = &npc2;
	this->add(toAdd);
	toAdd = &mob1;
	this->add(toAdd);
	toAdd = &mob2;
	this->add(toAdd);
	}

void Environment::destroyEntities()
{
	int n = entitles.size();
	for (int index = 0; index < n; index++)
	{
		delete entitles[index];
	}
	this->entitles.clear();
}

Entity * Environment::getClosestAliveEntity(Entity * closestPlayer, Types::Type typeOf)
{
	double minimum_distance = -1;
	int index = -1;
	int n = this->entitles.size();
	for (int i = 0; i < n; i++)
	{
		if (entitles[i]->getType() == typeOf && this->entitles[i]->isAlive())
		{
			double distance = this->entitles[i]->getDistanceTo(*closestPlayer);
			if (minimum_distance == -1 || distance < minimum_distance)
			{
				minimum_distance = distance;
				index = i;
			}
		}
	}
	if (index != -1)
	{
		return entitles[index];
		//return entitles[index]->clone();
	}
	return nullptr;
}

void Environment::sortToClosest(Entity * player)
{
	int n = this->entitles.size();
	double* distances = new double[n];
	for (int index = 0; index < n; index++)
	{
		double current_distance = player->getDistanceTo(*entitles[index]);
		distances[index] = current_distance;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (distances[i] > distances[j])
			{
				double x = distances[i];
				distances[i] = distances[j];
				distances[j] = x;

				Entity * temp = this->entitles[i];
				this->entitles[i] = this->entitles[j];
				this->entitles[j] = temp;
			}
		}
	}

}

void Environment::printEnvironment()
{
	int n = entitles.size();
	for (int index = 0; index < n; index++)
	{
		entitles[index]->print();
	}
}

