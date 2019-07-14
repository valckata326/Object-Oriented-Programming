#include "pch.h"
#include "Customer.h"

void Customer::setId(unsigned int new_id)
{
	this->ID = new_id;
	id++;
}

Customer::Customer()
{
	setId(id);
	setName("Unknown");
	setAddress("Unknown");
}

Customer::Customer(unsigned int new_id,std::string new_name, std::string new_address)
{
	setId(new_id);
	setName(new_name);
	setAddress(new_address);
}

Customer::Customer(const Customer & other)
{
	*this = other;
}

Customer::~Customer()
{
	//
}

Customer & Customer::operator=(const Customer & other)
{
	if (this != &other)
	{
		setId(other.getID());
		setName(other.getName());
		setAddress(other.getAddress());
	}
	return *this;
}

unsigned int Customer::getID() const
{
	return this->ID;
}

std::string Customer::getName() const
{
	return this->name;
}

void Customer::setName(std::string new_name)
{
	this->name = new_name;
}

std::string Customer::getAddress() const
{
	return this->address;
}

void Customer::setAddress(std::string new_address)
{
	this->address = new_address;
}

Customer * Customer::clone() const
{
	return new Customer(*this);
}

void Customer::display() const
{
	std::cout << "ID: " << getID() << " " << "Name: " << getName() << " " << "Address: " << getAddress() << std::endl;
}
