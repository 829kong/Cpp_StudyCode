#include "AccountHandler.h"
#include "BankingCommonDec1.h"

int main()
{
	int choice;
	AccountHandler ah(0);
	while (1)
	{
		ah.printMenu();
		cout << "����: ";
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
			cout << "���α׷��� �����մϴ�" << endl;
			return 0;

		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			cout << endl;
		}
	}

	return 0;
}