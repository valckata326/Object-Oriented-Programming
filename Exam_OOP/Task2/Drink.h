#pragma once
#include "RestaurantItem.h"

class Drink: public RestaurantItem {
	std::string name;
	double volume;
public:
	Drink();
	Drink(int quantity, double price, std::string name_ofdrink, double new_volume);
	Drink(const Drink& other);
	~Drink();
	Drink& operator=(const Drink& other);

	std::string getName() const;
	double getVolume() const;
	virtual Type getType() const override;

	virtual void setType() override;
	void setName(std::string new_name);
	void setVolume(double volume);

	bool operator>(const Drink& other);
	virtual void print() const;

	virtual Drink* clone() const;
};