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
		cout << "계좌ID: " << m_id << endl;
		cout << "이 름: " << m_name << endl;
		cout << "잔 액: " << m_balance << endl;
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
		cout << "이자율: " << m_interRate << "%" << endl;
		
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
		cout << "신용등급: " << getGrade()  << endl;
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
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4.계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
	}

	void makeAccount()
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
			acc[accountNum++] = new NormalAccount(id, name, balance,interRate);
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
		}
		cout << "유효하지 않은 ID입니다." << endl;
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

	void showAllAccount() const
	{
		cout << "[모든 계좌정보]" << endl;
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
			cout << i + 1 << " 번째 계좌 초기화 완료!" << endl;
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