#pragma once
#include "BankingCommonDec1.h"
#include "Account.h"
class NormalAccount : public Account
{
private:
	int m_interRate;

public:
	NormalAccount(int _id, string _name, int _balance, int _interRate)
		:Account(_id, _name, _balance), m_interRate(_interRate)
	{}

	void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (m_interRate * Percent));
	}

	void showAccInfo() const
	{
		Account::showAccInfo();
		cout << "ÀÌÀÚÀ²: " << m_interRate << "%" << endl;

	}
};
