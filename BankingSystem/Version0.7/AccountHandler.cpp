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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::makeAccount()
{
	int id, balance, num, interRate, grade;
	string name;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌" << " " << "2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> num;

	switch (num)
	{
	case 1:
		cout << "계좌ID: ";
		cin >> id;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << "이자율: ";
		cin >> interRate;
		acc[accountNum++] = new NormalAccount(id, name, balance, interRate);
		break;

		case 2:
			cout << "계좌ID: ";
			cin >> id;
			cout << "이 름: ";
			cin >> name;
			cout << "입금액: ";
			cin >> balance;
			cout << "이자율: ";
			cin >> interRate;
			cout << "신용등급(1toA,2toB,3toC): ";
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
		cout << "[입 금]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "입금액: ";
		cin >> deposit;
		for (int count = 0; count < accountNum; count++)
		{
			if (acc[count]->getId() == id)
			{
				acc[count]->Deposit(deposit);
				cout << "입금완료" << endl;
				return;
			}
		}
		cout << "유효하지 않은 ID입니다." << endl;
	}

	void AccountHandler::withdrawMoney()
	{
		int id = 0;
		int withdraw = 0;
		cout << "[출 금]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "출금액: ";
		cin >> withdraw;
		for (int count = 0; count < accountNum; count++)
		{
			if (acc[count]->getId() == id)
			{
				if (acc[count]->getBalance() < withdraw)
				{
					cout << "잔액 부족" << endl;
					return;
				}
				acc[count]->Withdraw(withdraw);
				cout << "출금완료" << endl;
				return;
			}
		}
	}

	void AccountHandler::showAllAccount() const
	{
		cout << "[모든 계좌정보]" << endl;
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
			cout << i + 1 << " 번째 계좌 초기화 완료!" << endl;
		}
	}