#include <iostream>
#include <cstring>
using namespace std;
const int Name_len = 10;

class Account
{
private:
	int id;
	char *name;
	int balance;

public:
	Account(int _id, char *_name, int _balance)
		:id(_id),balance(_balance)
	{
		name = new char[strlen(_name + 1)];
		strcpy_s(name, sizeof(name), _name);
	}
	~Account()
	{
		delete[] name;
	}

	int Deposit(int money)
	{
		balance += money;
		return balance;
	}

	int Withdraw(int money)
	{
		balance -= money;
		return balance;
	}

	int getId() const
	{
		return id;
	}

	int getBalance() const
	{
		return balance;
	}

	void showAccInfo() const
	{
		cout << "����ID: " << id << endl;
		cout << "�� ��: " << name << endl;
		cout << "�� ��: " << balance << endl;
		cout << endl;
	}
};

Account* acc[100];
int accountNum = 0;

void printMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void makeAccount()
{
	int id, balance;
	char name[Name_len];
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	acc[accountNum++] = new Account(id, name, balance);
}

void depositMoney()
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
		else
			cout << "��ȿ���� ���� ID�Դϴ�." << endl;
	}
}

void withdrawMoney()
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

void showAllAccount()
{
	cout << "[��� ��������]" << endl;
	for (int count = 0; count < accountNum; ++count)
	{
		acc[count]->showAccInfo();
	}
}

void deleteAcc()
{
	for (int i = 0; i < accountNum; i++)
		delete acc[i];
}