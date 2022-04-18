#include "AccountHandler.h"
#include "BankingCommonDec1.h"

int main()
{
	int choice;
	AccountHandler ah(0);
	while (1)
	{
		ah.printMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			ah.makeAccount();
			break;

		case DEPOSIT:
			ah.depositMoney();
			break;

		case WITHDRAW:
			ah.withdrawMoney();
			break;

		case ALLSHOW:
			ah.showAllAccount();
			break;

		case EXIT:
			cout << "프로그램을 종료합니다" << endl;
			return 0;

		default:
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			cout << endl;
		}
	}

	return 0;
}