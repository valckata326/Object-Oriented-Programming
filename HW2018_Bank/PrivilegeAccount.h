#pragma once
#include "Account.h"

class PrivilegeAccount : public Account {
	double overdraft;
	void setType() override;
	
public:
	void setOverdraft(double new_overdraft);
	PrivilegeAccount();
	PrivilegeAccount(std::string new_iban, unsigned int owner_id, double overdraft);
	PrivilegeAccount(const PrivilegeAccount& other);
	~PrivilegeAccount();
	PrivilegeAccount& operator=(const PrivilegeAccount& other);
	double getOverdraft() const;

	virtual void deposit(double deposit_amount) override;
	virtual bool withdraw(double withdraw_deposit) override;
	virtual void display() const override;

	PrivilegeAccount* clone() const override;
};