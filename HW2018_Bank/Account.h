#pragma once
#include <string>
#include <iostream>
#include "Enum.h"
class Account {
	std::string iban;
	unsigned int ownerID;
	double amount;

protected:
	
	std::string TypeToString(AccountType type) const;
	virtual void setType() = 0;
	AccountType type;
public:
	Account();
	Account(std::string new_iban , unsigned int new_ownerID);
	Account(const Account& other);
	virtual ~Account();
	Account& operator=(const Account& other);

	void setBalance(double amount);
	void setIBAN(std::string iban);
	void setOwnerId(unsigned int id);

	virtual void deposit(double deposit_amount) = 0;
	virtual bool withdraw(double withdraw_amount) = 0;
	virtual void display() const = 0;

	double getBalance() const;
	std::string getIBAN() const;
	unsigned int getOwnerID() const;
	AccountType getType() const;
	virtual Account* clone() const = 0;
};
