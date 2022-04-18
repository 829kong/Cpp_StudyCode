#pragma once
#include "BankingCommonDec1.h"
class Account
{
private:
	int m_id;
	std::string m_name;
	int m_balance;

public:
	Account(int _id, std::string _name, int _balance);

	Account(const Account& copy);

	virtual void Deposit(int money);

	int Withdraw(int money);

	int getId() const;

	int getBalance() const;

	virtual void showAccInfo() const;
};
