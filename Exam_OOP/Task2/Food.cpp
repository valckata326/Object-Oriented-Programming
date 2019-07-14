#include "stdafx.h"
#include "Food.h"

Food::Food() : RestaurantItem()
{
	setType();
	setName("0");
	setWeight(0);
}

Food::Food(int quantity, double price, std::string name_offood, double new_weight) : RestaurantItem(quantity, price)
{
	setType();
	setName(name_offood);
	setWeight(new_weight);
}

Food::Food(const Food & other)
{
	*this = other;
}

Food::~Food()
{
}

Food & Food::operator=(const Food & other)
{
	if (this != &other)
	{
		RestaurantItem::operator=(other);
		setType();
		setName(other.getName());
		setWeight(other.getWeight());
	}
	return *this;
}

std::string Food::getName() const
{
	return this->name_ofFood;
}

double Food::getWeight() const
{
	return this->weight;
}

Type Food::getType() const
{
	return this->type;
}

void Food::setType()
{
	type = Type::foods;
}

void Food::setName(std::string new_name)
{
	this->name_ofFood = new_name;
}

void Food::setWeight(double weight)
{
	this->weight = weight;
}

bool Food::operator>(const Food & other)
{
	return this->getWeight() > other.getWeight();
}

void Food::print() const
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
	std::cout << "Weight: " << getWeight() << std::endl;
	std::cout << "Price: " << getPrice() << std::endl;
}

Food * Food::clone() const
{
	return new Food(*this);
}


