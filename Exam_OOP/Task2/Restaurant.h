#pragma once
#include "Food.h"
#include "Drink.h"
#include <vector>
class Restaurant {
	std::vector <RestaurantItem*> products;
public:
	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	~Restaurant();
	void addProduct(const RestaurantItem* to_add);
	void removeProduct(int index);
	void changePrice(int index, double price);
	void changeName(int index, std::string name);

	void print() const;
	void printAlcohols() const;
};