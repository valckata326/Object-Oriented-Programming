#pragma once
#include "Enum.h"
class RestaurantItem {
	
	int quantity;
	double price;
protected:
	
	Type type;
public:
	RestaurantItem();
	RestaurantItem(int quantity, double price);
	RestaurantItem(const RestaurantItem& other);
	virtual ~RestaurantItem() = 0;
	RestaurantItem& operator=(const RestaurantItem& other);

	virtual void setType() = 0;
	void setQuantity(int new_quantity);
	void setPrice(double new_price);

	virtual Type getType() const = 0;
	int getQuantity() const;
	double getPrice() const;
	virtual RestaurantItem* clone() const = 0;
	virtual void setName(std::string name) = 0;
	virtual void print() const = 0;
};