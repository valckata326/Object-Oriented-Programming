#include "stdafx.h"
#include "RestaurantItem.h"

RestaurantItem::RestaurantItem()
{
	setQuantity(0);
	setPrice(0);
}

RestaurantItem::RestaurantItem(int quantity, double price)
{
	setQuantity(quantity);
	setPrice(price);
}

RestaurantItem::RestaurantItem(const RestaurantItem & other)
{
	*this = other;
}

RestaurantItem::~RestaurantItem()
{
}

RestaurantItem & RestaurantItem::operator=(const RestaurantItem & other)
{
	if (this != &other)
	{
		setQuantity(other.getQuantity());
		setPrice(other.getPrice());
	}
	return *this;
}

void RestaurantItem::setType()
{
}

void RestaurantItem::setQuantity(int new_quantity)
{
	this->quantity = new_quantity;
}

void RestaurantItem::setPrice(double new_price)
{
	this->price = new_price;
}

Type RestaurantItem::getType() const
{
	return this->type;
}

int RestaurantItem::getQuantity() const
{
	return this->quantity;
}

double RestaurantItem::getPrice() const
{
	return this->price;
}
