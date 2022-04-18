#include <iostream>
#include <string>
using namespace std;
const int Name_len = 10;

class Account
{
private:
	int m_id;
	string m_name;
	int m_balance;

public:
	Account(int _id, string _name, int _balance)
		:m_id(_id),m_name(_name), m_balance(_balance)
	{
		
	}

	Account(const Account& copy)
		:m_id(copy.m_id),m_name(copy.m_name),m_balance(copy.m_balance)
	{

	}

	int Deposit(int money)
	{
		m_balance += money;
		return m_balance;
	}

	int Withdraw(int money)
	{
		m_balance -= money;
		return m_balance;
	}

	int getId() const
	{
		return m_id;
	}

	int getBalance() const
	{
		return m_balance;
	}

	void showAccInfo() const
	{
		cout << "계좌ID: " << m_id << endl;
		cout << "이 름: " << m_name << endl;
		cout << "잔 액: " << m_balance << endl;
		cout << endl;
	}
};

Account* acc[100];
int accountNum = 0;

void printMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void makeAccount()
{
	int id, balance;
	char name[Name_len];
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	acc[accountNum++] = new Account(id, name, balance);
}

void depositMoney()
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
		else
			cout << "유효하지 않은 ID입니다." << endl;
	}
}

void withdrawMoney()
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

void showAllAccount()
{
	cout << "[모든 계좌정보]" << endl;
	for (int count = 0; count < accountNum; ++count)
	{
		acc[count]->showAccInfo();
	}
}

void deleteAcc()
{
	for (int i = 0; i < accountNum; i++)
	{
		delete acc[i];
		cout << i + 1 << " 번째 계좌 초기화 완료!" << endl;
	}
}