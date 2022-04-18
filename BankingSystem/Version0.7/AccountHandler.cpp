#include "BankingCommonDec1.h"
#include "AccountHandler.h"
#include "Account.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

AccountHandler::AccountHandler(int num)
		:accountNum(num)
	{}

void AccountHandler::printMenu() const
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::makeAccount()
{
	int id, balance, num, interRate, grade;
	string name;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���" << " " << "2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> num;

	switch (num)
	{
	case 1:
		cout << "����ID: ";
		cin >> id;
		cout << "�� ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "������: ";
		cin >> interRate;
		acc[accountNum++] = new NormalAccount(id, name, balance, interRate);
		break;

		case 2:
			cout << "����ID: ";
			cin >> id;
			cout << "�� ��: ";
			cin >> name;
			cout << "�Աݾ�: ";
			cin >> balance;
			cout << "������: ";
			cin >> interRate;
			cout << "�ſ���(1toA,2toB,3toC): ";
			cin >> grade;
			switch (grade)
			{
			case 1:
				acc[accountNum++] = new HighCreditAccount(id, name, balance, interRate, Credit_Grade::Grade_A);
				break;
			case 2:
				acc[accountNum++] = new HighCreditAccount(id, name, balance, interRate, Credit_Grade::Grade_B);
				break;
			case 3:
				acc[accountNum++] = new HighCreditAccount(id, name, balance, interRate, Credit_Grade::Grade_C);
				break;
			}
		}
	}

	void AccountHandler::depositMoney()
	{
		int id;
		int deposit;
		cout << "[�� ��]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "�Աݾ�: ";
		cin >> deposit;
		for (int count = 0; count < accountNum; count++)
		{
			if (acc[count]->getId() == id)
			{
				acc[count]->Deposit(deposit);
				cout << "�ԱݿϷ�" << endl;
				return;
			}
		}
		cout << "��ȿ���� ���� ID�Դϴ�." << endl;
	}

	void AccountHandler::withdrawMoney()
	{
		int id = 0;
		int withdraw = 0;
		cout << "[�� ��]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "��ݾ�: ";
		cin >> withdraw;
		for (int count = 0; count < accountNum; count++)
		{
			if (acc[count]->getId() == id)
			{
				if (acc[count]->getBalance() < withdraw)
				{
					cout << "�ܾ� ����" << endl;
					return;
				}
				acc[count]->Withdraw(withdraw);
				cout << "��ݿϷ�" << endl;
				return;
			}
		}
	}

	void AccountHandler::showAllAccount() const
	{
		cout << "[��� ��������]" << endl;
		for (int count = 0; count < accountNum; ++count)
		{
			acc[count]->showAccInfo();
		}
		cout << endl;
	}

	AccountHandler::~AccountHandler()
	{
		for (int i = 0; i < accountNum; i++)
		{
			delete acc[i];
			cout << i + 1 << " ��° ���� �ʱ�ȭ �Ϸ�!" << endl;
		}
	}