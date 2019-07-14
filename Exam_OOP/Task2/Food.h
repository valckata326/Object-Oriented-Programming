#pragma once
#include <string>
#include"RestaurantItem.h"

class Food : public RestaurantItem{
	std::string name_ofFood;
	double weight;
public:
	Food();
	Food(int quantity, double price, std::string name_offood, double new_weight);
	Food(const Food& other);
	~Food();
	Food& operator=(const Food& other);

	std::string getName() const;
	double getWeight() const;
	virtual Type getType() const override;

	virtual void setType() override;
	void setName(std::string new_name);
	void setWeight(double weight);

	bool operator>(const Food& other);
	virtual void print() const;
	virtual Food* clone() const;
};
