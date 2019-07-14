#include "stdafx.h"
#include "Restaurant.h"

Restaurant::Restaurant()
{
}

Restaurant::Restaurant(const Restaurant & other)
{
	*this = other;
}

Restaurant & Restaurant::operator=(const Restaurant & other)
{
	if (this != &other)
	{
		for (int i = 0; i < products.size(); i++)
		{
			products.erase(products.begin() + i);
		}
		products.clear();
		for (size_t i = 0; i < other.products.size(); i++)
		{
			this->addProduct(other.products[i]);
		}
	}
	return *this;
}

Restaurant::~Restaurant()
{
	for (int i = 0; i < products.size(); i++)
	{
		products.erase(products.begin() + i);
	}
	products.clear();
}

void Restaurant::addProduct(const RestaurantItem * to_add)
{
	products.push_back(to_add->clone());
}

void Restaurant::removeProduct(int index)
{
	if (index > 0 || index < products.size())
	{
		products.erase(products.begin() + index);
	}
}

void Restaurant::changePrice(int index, double price)
{
	if (index > 0 || index < products.size())
	{
		products[index]->setPrice(price);
	}
}

void Restaurant::changeName(int index, std::string name)
{
	if (index > 0 || index < products.size())
	{
		products[index]->setName(name);
	}
}

void Restaurant::print() const
{
	for (size_t i = 0; i < products.size(); i++)
	{
		products[i]->print();
		std::cout << std::endl;
	}
}

void Restaurant::printAlcohols() const
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i]->getType() == Type::drinks)
		{
			if (((Drink*)products[i])->getVolume() == 0)
			{
				products[i]->print();
			}
		}
	}
}
