#include "pch.h"
#include "PrivilegeAccount.h"

void PrivilegeAccount::setType()
{
	this->type = AccountType::PrivilegeAccount1;
}

void PrivilegeAccount::setOverdraft(double new_overdraft)
{
	this->overdraft = new_overdraft;
}

PrivilegeAccount::PrivilegeAccount() : Account()
{
	setType();
	setOverdraft(0);
}

PrivilegeAccount::PrivilegeAccount(std::string new_iban, unsigned int owner_id, double overdraft) : Account(new_iban, owner_id)
{
	setType();
	setOverdraft(overdraft);
}

PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount & other)
{
}

PrivilegeAccount::~PrivilegeAccount()
{
}

PrivilegeAccount & PrivilegeAccount::operator=(const PrivilegeAccount & other)
{
	if (this != &other)
	{
		Account::operator=(other);
		setType();
		setOverdraft(other.getOverdraft());
	}
	return *this;
}

double PrivilegeAccount::getOverdraft() const
{
	return this->overdraft;
}

void PrivilegeAccount::deposit(double deposit_amount)
{
	setBalance(getBalance() + deposit_amount);
}

bool PrivilegeAccount::withdraw(double withdraw_deposit)
{
	if (withdraw_deposit > getBalance() + getOverdraft())
	{
		return false;
	}
	else
	{
		setBalance(getBalance() - withdraw_deposit);
	}
}

void PrivilegeAccount::display() const
{
	std::cout << "Account type: " << TypeToString(getType()) << std::endl;
	std::cout << "IBAN: " << getIBAN() << std::endl;
	std::cout << "Owner ID: " << getOwnerID() << std::endl;
	std::cout << "Balance: " << getBalance() << std::endl;
	std::cout << "Overdraft: " << getOverdraft() << std::endl;
}

PrivilegeAccount * PrivilegeAccount::clone() const
{
	return new PrivilegeAccount(*this);
}
