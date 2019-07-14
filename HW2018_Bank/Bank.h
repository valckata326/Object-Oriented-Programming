#pragma once
#include "CurrentAccount.h"
#include "Customer.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include <vector>
class Bank {
	std::string name;
	std::string address;
	std::vector <Customer> customers;
	std::vector <Account*> accounts;

	size_t indexCustomer(unsigned int id);
	size_t indexAccount(std::string IBAN);
	size_t indexAccount(unsigned int customerID);
	void copyAccounts(std::vector<Account*> copy_accounts);

public:
	Bank(std::string new_name, std::string new_address);
	Bank(std::string new_name, std::string new_address, std::vector <Customer> new_customers, std::vector<Account*> new_accounts);
	Bank(const Bank& other);
	~Bank();
	Bank& operator=(const Bank& other);

	void setName(std::string new_name);
	void setAddress(std::string new_address);

	std::string getName() const;
	std::string getAddress() const;

	void addCustomer(unsigned int customerID, std::string name, std::string address);
	void listCustomers() const;
	void deleteCustomer(unsigned int customerID);
	void addAccount(AccountType type, std::string iban, unsigned int ownerid, double amount);
	void deleteAccount(std::string iban);
	void listAccounts() const;
	void listCustomerAccount(unsigned int customerID);
	void transfer(std::string fromIBAN, std::string toIBAN, double amount);
	void display() const;

	bool getAccountByIBAN(std::string IBAN, Account *& Acc);
};
