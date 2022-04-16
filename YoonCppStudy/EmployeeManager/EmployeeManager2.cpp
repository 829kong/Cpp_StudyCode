#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
	string m_name;

public:
	Employee(string name)
		:m_name(name)
	{}

	void showName() const
	{
		cout << "name: " << m_name << endl;
	}

};
class PermanentWorker : public Employee  //정규직
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
		cout << "salary: " << getPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker //영업직
{
private:
	int incentive;

public:
	SalesWorker(string name, int money, int incen)
		:PermanentWorker(name, money), incentive(incen)
	{}

	int getIncentive() const { return incentive; }

	void showSalesInfo() const
	{
		showSalaryInfo();
		cout << "Incentive: " <<
	}

};

class TemporaryWorker : public Employee //임시직(알바)
{
private:
	int timeSalary;
	int workTime;
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