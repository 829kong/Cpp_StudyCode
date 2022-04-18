#include <iostream>
#include <string>
using namespace std;
const int Name_len = 10;
const double Percent = 0.01;

enum Choice
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	ALLSHOW,
	EXIT,
};

namespace Credit_Grade
{
	enum { Grade_A = 7, Grade_B = 4, Grade_C = 2, };
}

class Account
{
private:
	int m_id;
	string m_name;
	int m_balance;

public:
	Account(int _id, string _name, int _balance)
		:m_id(_id), m_name(_name), m_balance(_balance)
	{}

	Account(const Account& copy)
		:m_id(copy.m_id), m_name(copy.m_name), m_balance(copy.m_balance)
	{}

	virtual void Deposit(int money)
	{
		m_balance += money;
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

	virtual void showAccInfo() const
	{
		cout << "����ID: " << m_id << endl;
		cout << "�� ��: " << m_name << endl;
		cout << "�� ��: " << m_balance << endl;
	}
};

class NormalAccount : public Account
{
private:
	int m_interRate;

public:
	NormalAccount(int _id, string _name, int _balance,int _interRate)
		:Account(_id,_name,_balance),m_interRate(_interRate)
	{}

	void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (m_interRate * Percent));
	}

	void showAccInfo() const
	{
		Account::showAccInfo();
		cout << "������: " << m_interRate << "%" << endl;
		
	}
};

class HighCreditAccount : public NormalAccount
{
private:
	int m_specialInterate;

public:
	HighCreditAccount(int _id, string _name, int _balance, int _interest, int _specialInterate)
		:NormalAccount(_id,_name,_balance,_interest),m_specialInterate(_specialInterate)
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
		cout << "�ſ���: " << getGrade()  << endl;
		cout << endl;
	}
}; 

class AccountHandler
{
private:
	Account* acc[100];
	int accountNum;

public:
	AccountHandler(int num)
		:accountNum(num)
	{}

	void printMenu() const
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
			acc[accountNum++] = new NormalAccount(id, name, balance,interRate);
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
		}
		cout << "��ȿ���� ���� ID�Դϴ�." << endl;
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

	void showAllAccount() const
	{
		cout << "[��� ��������]" << endl;
		for (int count = 0; count < accountNum; ++count)
		{
			acc[count]->showAccInfo();
		}
		cout << endl;
	}

	~AccountHandler()
	{
		for (int i = 0; i < accountNum; i++)
		{
			delete acc[i];
			cout << i + 1 << " ��° ���� �ʱ�ȭ �Ϸ�!" << endl;
		}
	}
};


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