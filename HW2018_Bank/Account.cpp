#include "pch.h"
#include "Account.h"

void Account::setBalance(double amount)
{
	this->amount = amount;
}

void Account::setIBAN(std::string iban)
{
	this->iban = iban;
}

void Account::setOwnerId(unsigned int id)
{
	this->ownerID = id;
}
std::string Account::TypeToString(AccountType type) const
{
	std::string return_type;
	if (type == AccountType::CurrentAccount1)
	{
		return_type = "CurrentAccount";
	}
	else if(type == AccountType::PrivilegeAccount1)
	{
		return_type = "PrivilegeAccount";
	}
	else if (type == AccountType::SavingsAccount1)
	{
		return_type = "SavingsAccount";
	}
	else
	{
		return_type = "General";
	}
	return return_type;
}
Account::Account()
{
	setIBAN(" ");
	setOwnerId(0);
	setBalance(0);
}
Account::Account(std::string new_iban, unsigned int new_ownerID)
{
	setIBAN(new_iban);
	setOwnerId(new_ownerID);
	setBalance(0);
}

Account::Account(const Account & other)
{
	*this = other;
}

Account::~Account()
{
}

Account & Account::operator=(const Account & other)
{
	if (this != &other)
	{
		setIBAN(other.getIBAN());
		setOwnerId(other.getOwnerID());
		setBalance(other.getBalance());
	}
	return *this;
}

void Account::deposit(double deposit_amount)
{
}

bool Account::withdraw(double withdraw_amount)
{
	return false;
}

void Account::display() const
{
}

double Account::getBalance() const
{
	return this->amount;
}

std::string Account::getIBAN() const
{
	return this->iban;
}

unsigned int Account::getOwnerID() const
{
	return this->ownerID;
}

AccountType Account::getType() const
{
	return this->type;
}
