#pragma once
#include "Account.h"
class AccountHandler
{
private:
	Account* acc[100];
	int accountNum;

public:
	AccountHandler(int num);
	void printMenu() const;
	void makeAccount();
	void depositMoney();
	void withdrawMoney();
	void showAllAccount() const;
	~AccountHandler();
};
