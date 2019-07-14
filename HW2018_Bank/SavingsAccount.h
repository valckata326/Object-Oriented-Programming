#pragma once
#include "Account.h"

class SavingsAccount : public Account {
	int interestRate;
	void setType() override;

public:
	SavingsAccount();
	SavingsAccount(std::string new_iban, unsigned int new_ownerID, int new_rate);
	SavingsAccount(const SavingsAccount& other);
	~SavingsAccount();
	SavingsAccount& operator=(const SavingsAccount& other);

	int getInterestRate() const;
	void setInterestRate(int new_rate);
	virtual void deposit(double deposit_amount) override;
	virtual bool withdraw(double withdraw_amount) override;
	virtual void display() const override;

	virtual SavingsAccount* clone() const override;
};