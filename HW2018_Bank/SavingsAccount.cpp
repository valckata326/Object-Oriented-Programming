#include "pch.h"
#include "SavingsAccount.h"

void SavingsAccount::setType()
{
	this->type = AccountType::SavingsAccount1;
}

void SavingsAccount::setInterestRate(int new_rate)
{
	this->interestRate = new_rate;
}

SavingsAccount::SavingsAccount() : Account()
{
	setType();
	setInterestRate(0);
}

SavingsAccount::SavingsAccount(std::string new_iban, unsigned int new_ownerID, int new_rate) : Account(new_iban, new_ownerID)
{
	setType();
	setInterestRate(new_rate);
}

SavingsAccount::SavingsAccount(const SavingsAccount & other)
{

	*this = other;
}

SavingsAccount::~SavingsAccount()
{
}

SavingsAccount & SavingsAccount::operator=(const SavingsAccount & other)
{
	if (this != &other)
	{
		Account::operator=(other);
		setType();
		setInterestRate(other.getInterestRate());
	}
	return *this;
}

int SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::deposit(double deposit_amount)
{
	setBalance(getBalance() + deposit_amount);
}

bool SavingsAccount::withdraw(double withdraw_amount)
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

void SavingsAccount::display() const
{
	std::cout << "Account type: " << TypeToString(getType()) << std::endl;
	std::cout << "IBAN: " << getIBAN() << std::endl;
	std::cout << "Owner ID: " << getOwnerID() << std::endl;
	std::cout << "Balance: " << getBalance() << std::endl;
	std::cout << "InterestRate: " << getInterestRate() << std::endl;
}

SavingsAccount * SavingsAccount::clone() const
{
	return new SavingsAccount(*this);
}
