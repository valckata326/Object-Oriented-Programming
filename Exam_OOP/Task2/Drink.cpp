#include "stdafx.h"
#include "Drink.h"
#include <string>
Drink::Drink() : RestaurantItem()
{
	setType();
	setName("0");
	setVolume(0);
}

Drink::Drink(int quantity, double price, std::string name_ofdrink, double new_volume) :RestaurantItem(quantity, price)
{
	setType();
	setName(name_ofdrink);
	setVolume(new_volume);
}

Drink::Drink(const Drink & other)
{
	*this = other;
}

Drink::~Drink()
{
}

Drink & Drink::operator=(const Drink & other)
{
	if (this != &other)
	{
		RestaurantItem::operator=(other);
		setType();
		setName(other.getName());
		setVolume(other.getVolume());
	}
	return *this;
}

std::string Drink::getName() const
{
	return this->name;
}

double Drink::getVolume() const
{
	return this->volume;
}

Type Drink::getType() const
{
	return this->type;
}

void Drink::setType()
{
	this->type = Type::drinks;
}

void Drink::setName(std::string new_name)
{
	this->name = new_name;
}

void Drink::setVolume(double volume)
{
	this->volume = volume;
}

bool Drink::operator>(const Drink & other)
{
	return getVolume() > other.getVolume();
}

void Drink::print() const
{
	std::string type_tostring;
	if (type == 0)
	{
		type_tostring = "Foods";
	}
	else if (type == 1)
	{
		type_tostring = "Drinks";
	}
	std::cout << "Type: " << type_tostring << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Quantity: " << getQuantity() << std::endl;
	std::cout << "Volume: " << getVolume() << std::endl;
	std::cout << "Price: " << getPrice() << std::endl;
}

Drink * Drink::clone() const
{
	return new Drink(*this);
}
