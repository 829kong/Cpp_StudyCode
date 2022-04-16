#include <iostream>
#include "SystemFunction.h"
using namespace std;
const int Name_len = 10;



enum Choice
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	ALLSHOW,
	EXIT,
};

int main()
{
	int choice;
	while (1)
	{
		printMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			makeAccount();
			break;

		case DEPOSIT:
			depositMoney();
			break;

		case WITHDRAW:
			withdrawMoney();
			break;

		case ALLSHOW:
			showAllAccount();
			break;

		case EXIT:
			deleteAcc();
			cout << "프로그램을 종료합니다" << endl;
			return 0;

		default:
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			cout << endl;
		}
	}

	return 0;
}