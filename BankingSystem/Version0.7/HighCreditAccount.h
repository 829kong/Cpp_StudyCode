#pragma once
#include "NormalAccount.h"
class HighCreditAccount : public NormalAccount
{
private:
	int m_specialInterate;

public:
	HighCreditAccount(int _id, string _name, int _balance, int _interest, int _specialInterate)
		:NormalAccount(_id, _name, _balance, _interest), m_specialInterate(_specialInterate)
	{}

	int getGrade() const
	{
		if (m_specialInterate == Credit_Grade::Grade_A)
			return 1;
		else if (m_specialInterate == Credit_Grade::Grade_B)
			return 2;
		else if (m_specialInterate == Credit_Grade::Grade_C)
			return 3;
	}

	void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * (m_specialInterate * Percent));
	}

	void showAccInfo() const
	{
		cout << endl;
		NormalAccount::showAccInfo();
		cout << "신용등급: " << getGrade() << endl;
		cout << endl;
	}
};
