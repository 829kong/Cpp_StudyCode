#include <iostream>
#include <string>
using namespace std;

class Employee // Data: 이름
{
private:
	string m_name;

public:
	Employee(string name)
		:m_name(name)
	{}

	void showName() const
	{
		cout << "Name: " << m_name << endl;
	}
	 
};
class PermanentWorker : public Employee  //정규직, Data : 이름(상속),연봉
{
private:
	int salary;

public:
	PermanentWorker(string name, int money)
		: Employee(name),salary(money)
	{}

	int getPay() const
	{
		return salary;
	}

	void showSalaryInfo() const
	{
		showName();
		cout << "Salary: " << getPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker //영업직 Data : 이름(상속),연봉(상속),인센티브
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(string name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}

	void addSalesResult(int value)
	{
		salesResult += value;
	}

	int getPay() const
	{
		return PermanentWorker::getPay() + (int)(salesResult * bonusRatio);
	}

	void showSalaryInfo() const
	{
		showName();
		cout << "Salary: " << getPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee //임시직(알바)
{
private:
	int m_timePay;
	int m_workTime;

public:
	TemporaryWorker(string name, int timeSalary)
		:Employee(name), m_timePay(0), m_workTime(0)
	{}

	void AddWorkTime(int time)
	{
		m_workTime += time;
	}

	int GetPay() const
	{
		return m_workTime * m_timePay;
	}

	void ShowPayInfo() const
	{
		showName();
		cout << "Pay: " << GetPay() << endl;
	}
};

class EmployeeHandler //컨트롤 클래스
{
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler()
		:empNum(0)
	{}

	void addEmployee(Employee * emp)
	{
		empList[empNum++] = emp;
	}

	void showAllSalaryInfo() const
	{
		/*for (int i = 0; i < empNum; i++)
			empList[i]->showSalaryInfo();*/
	}

	void showTotalSalary() const
	{
		/*int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->getPay();
		cout << "salary sum: " << sum << endl;*/
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	EmployeeHandler handler;
	handler.addEmployee(new PermanentWorker("Kim", 1000));
	handler.addEmployee(new PermanentWorker("Lee", 1500));
	handler.addEmployee(new PermanentWorker("Jun", 2000));

	handler.showAllSalaryInfo();
	handler.showTotalSalary();

	return 0;
}