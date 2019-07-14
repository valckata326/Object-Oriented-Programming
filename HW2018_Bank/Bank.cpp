#include "pch.h"
#include "Bank.h"

size_t Bank::indexCustomer(unsigned int id)
{
	for (size_t index = 0; index < customers.size(); index++)
	{
		if (id == customers[index].getID())
		{
			return index;
		}
	}
	return -1;
}

size_t Bank::indexAccount(std::string IBAN)
{
	for (size_t index = 0; index < accounts.size(); index++)
	{
		if (IBAN == accounts[index]->getIBAN())
		{
			return index;
		}
	}
	return -1;
}

size_t Bank::indexAccount(unsigned int customerID)
{
	for (size_t index = 0; index < accounts.size(); index++)
	{
		if (customerID == accounts[index]->getOwnerID())
		{
			return index;
		}
	}
	return -1;
}

void Bank::copyAccounts(std::vector<Account*> copy_accounts)
{
	for (size_t index = 0; index < copy_accounts.size(); index++)
	{
		accounts.push_back(copy_accounts[index]->clone());
	}
}

Bank::Bank(std::string new_name, std::string new_address)
{
	setName(new_name);
	setAddress(new_address);
}

Bank::Bank(std::string new_name, std::string new_address, std::vector <Customer> new_customers, std::vector<Account*> new_accounts)
{
	setName(new_name);
	setAddress(new_address);
	copyAccounts(new_accounts);
	for (size_t index = 0; index < new_customers.size(); index++)
	{
		customers.push_back(new_customers[index]);
	}
}

Bank::Bank(const Bank & other)
{
	*this = other;
}

Bank::~Bank()
{
	for (size_t index = 0; index < accounts.size(); index++)
	{
		delete accounts[index];
	}
}

Bank & Bank::operator=(const Bank & other)
{
	if(this != &other)
	{
		setName(other.getName());
		setAddress(other.getAddress());
		for (size_t index = 0; index < other.accounts.size(); index++)
		{
			delete accounts[index];
		}
		copyAccounts(other.accounts);
		for (size_t index = 0; index < other.customers.size(); index++)
		{
			customers.push_back(other.customers[index]);
		}
	}
	return *this;
}

void Bank::setName(std::string new_name)
{
	this->name = new_name;
}

void Bank::setAddress(std::string new_address)
{
	this->address = new_address;
}

std::string Bank::getName() const
{
	return this->name;
}

std::string Bank::getAddress() const
{
	return this->address;
}

void Bank::addCustomer(unsigned int customerID, std::string name, std::string address)
{
	if (indexCustomer(customerID) != -1)
	{
		std::cout << "This customer's ID already exists!" << std::endl;
		return;
	}
	else
	{
		Customer toAdd(customerID,name,address);
		customers.push_back(toAdd);

	}
}

void Bank::listCustomers() const
{
	for (size_t index = 0; index < customers.size(); index++)
	{
		customers[index].display();
		std::cout << std::endl;
	}
}

void Bank::deleteCustomer(unsigned int customerID)
{
	size_t is_there = indexCustomer(customerID);
	if (is_there == 0)
	{
		std::cout << "No customer with this ID exists" << std::endl;
	}
	else
	{
		size_t index_inAccounts = indexAccount(customerID);
		while (index_inAccounts != -1)
		{
			deleteAccount(accounts[index_inAccounts]->getIBAN());
			index_inAccounts = indexAccount(customerID);
		}
		customers.erase(customers.begin() + is_there);
		std::cout << "Customer successfully deleted!" << std::endl;
	}
}

void Bank::addAccount(AccountType type, std::string iban, unsigned int ownerid, double amount)
{
	unsigned int customerPosition = indexCustomer(ownerid);
	unsigned int accountPosition = indexAccount(iban);
	if (customerPosition != -1 || accountPosition != -1)
	{
		std::cout << "Cannot add this account. Invalid parameters" << std::endl;
	}
	Account* new_acc;
	if (type == AccountType::CurrentAccount1)
	{
		new_acc = new CurrentAccount(iban, ownerid);
	}
	else if (type == AccountType::SavingsAccount1)
	{
		new_acc = new SavingsAccount(iban, ownerid, 0);
	}
	else  
	{
		new_acc = new PrivilegeAccount(iban, ownerid, 0);
	}
	new_acc->setBalance(amount);
	accounts.push_back(new_acc->clone());
	delete new_acc;
}

void Bank::deleteAccount(std::string iban)
{
	unsigned int index = indexAccount(iban);
	if (index == -1)
	{
		std::cout << "There is no such account with this IBAN!" << std::endl;
	}
	else {
		delete accounts[index];
		accounts.erase(accounts.begin() + index);
		std::cout << "This account was successfully deleted!" << std::endl;
	}
}

void Bank::listAccounts() const
{
	for (size_t index = 0; index < accounts.size(); index++)
	{
		accounts[index]->display();
		std::cout << std::endl;
	}
}

void Bank::listCustomerAccount(unsigned int customerID)
{
	size_t index = indexAccount(customerID);
	for (size_t index_account = 0; index_account < accounts.size(); index_account++)
	{
		if (customerID == accounts[index_account]->getOwnerID())
		{
			accounts[index_account]->display();
			std::cout << std::endl;
		}
	}
	if (index == -1)
	{
		std::cout << "There are no accounts with that customer ID!" << std::endl;
	}
}

void Bank::transfer(std::string fromIBAN, std::string toIBAN, double amount)
{
	size_t fromIndex = indexAccount(fromIBAN);
	size_t toIndex = indexAccount(toIBAN);
	if (fromIndex == -1 || toIndex == -1)
	{
		std::cout << "Cannot make that transfer" << std::endl;
		return;
	}
	else
	{
		accounts[fromIndex]->withdraw(amount);
		accounts[toIndex]->deposit(amount);
		std::cout << "Transfer was made!" << std::endl;
	}
}

void Bank::display() const
{
	std::cout << "Bank: " << getName() << std::endl;
	std::cout << "Located at: " << getAddress() << std::endl;
	std::cout << "Number of customers: " << customers.size() << std::endl;
	std::cout << "Number of accounts: " << accounts.size() << std::endl;
}

bool Bank::getAccountByIBAN(std::string IBAN, Account *& Acc)
{
	size_t index = indexAccount(IBAN);
	if (index == (size_t)-1)
		return false;
	Acc = accounts[index];
	return true;
}
