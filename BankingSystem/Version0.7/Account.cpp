#include "BankingCommonDec1.h"
#include "Account.h"


Account::Account(int _id, string _name, int _balance)
	:m_id(_id), m_name(_name), m_balance(_balance)
{}

Account::Account(const Account& copy)
	:m_id(copy.m_id), m_name(copy.m_name), m_balance(copy.m_balance)
{}

void Account::Deposit(int money)
{
	m_balance += money;
}

int Account::Withdraw(int money)
{
	m_balance -= money;
	return m_balance;
}

int Account::getId() const
{
	return m_id;
}

int Account::getBalance() const
{
	return m_balance;
}

void Account::showAccInfo() const
{
	cout << "°èÁÂID: " << m_id << endl;
	cout << "ÀÌ ¸§: " << m_name << endl;
	cout << "ÀÜ ¾×: " << m_balance << endl;
}