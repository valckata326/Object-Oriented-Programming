#pragma once
#include <iostream>
#include <string>
static unsigned int id = 1;
class Customer
{
	unsigned int ID;
	std::string name;
	std::string address;
	void setId(unsigned int id);
public:
	Customer();
	Customer(unsigned int ID, std::string new_name, std::string new_address);
	Customer(const Customer& other);
	~Customer();
	Customer& operator=(const Customer& other);

	unsigned int getID() const;

	std::string getName() const;
	void setName(std::string new_name);

	std::string getAddress() const;
	void setAddress(std::string new_address);

	Customer* clone() const;

	void display() const;
};
