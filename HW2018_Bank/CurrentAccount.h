#pragma once
#include "Account.h"

class CurrentAccount: public Account {
	virtual void setType() override;
public:
	CurrentAccount();
	CurrentAccount(std::string new_iban, unsigned int new_ownerID);
	CurrentAccount(const CurrentAccount& other);
	~CurrentAccount();
	CurrentAccount& operator=(const CurrentAccount& other);
	virtual void deposit(double deposit_amount) override;
	virtual bool withdraw(double withdraw_amount) override;
	virtual void display() const override;
	virtual CurrentAccount* clone() const override;
};
