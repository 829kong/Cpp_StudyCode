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
		cout << "����: ";
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
			cout << "���α׷��� �����մϴ�" << endl;
			return 0;

		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			cout << endl;
		}
	}

	return 0;
}