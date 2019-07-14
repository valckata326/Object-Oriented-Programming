#include "pch.h"
#include "CurrentAccount.h"

void CurrentAccount::setType()
{
	this->type = CurrentAccount1;
}

CurrentAccount::CurrentAccount() : Account()
{
	setType();
}

CurrentAccount::CurrentAccount(std::string new_iban, unsigned int new_ownerID) : Account(new_iban,new_ownerID)
{
	setType();
}

CurrentAccount::CurrentAccount(const CurrentAccount & other)
{
	*this = other;
}

CurrentAccount::~CurrentAccount()
{
}

CurrentAccount & CurrentAccount::operator=(const CurrentAccount & other)
{
	if (this != &other)
	{
		Account::operator=(other);
		setType();
	}
	return *this;
}

void CurrentAccount::deposit(double deposit_amount)
{
	setBalance(getBalance() + deposit_amount);
}

bool CurrentAccount::withdraw(double withdraw_amount)
{
	if (withdraw_amount > getBalance())
	{
		return false;
	}
	else
	{
		setBalance(getBalance() - withdraw_amount);
		return true;
	}
}

void CurrentAccount::display() const
{
	std::cout << "Account type: " << TypeToString(getType()) << std::endl;
	std::cout << "IBAN: " << getIBAN() << std::endl;
	std::cout << "Owner ID: " << getOwnerID() << std::endl;
	std::cout << "Balance: " << getBalance() << std::endl;
}

CurrentAccount * CurrentAccount::clone() const
{
	return new CurrentAccount(*this);
}
