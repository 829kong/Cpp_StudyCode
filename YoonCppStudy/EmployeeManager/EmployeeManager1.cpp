#include <iostream>
#include <string>
using namespace std;

class PermanentWorker //정규직
{
private:
	string m_name;
	int salary;

public:
	PermanentWorker(string name, int money)
		: salary(money),m_name(name)
	{}

	int getPay() const
	{
		return salary;
	}

	void showSalaryInfo() const
	{
		cout << "name: " << m_name << endl;
		cout << "salary: " << getPay() << endl<<endl;
	}
};

class EmployeeHandler //컨트롤 클래스
{
private:
	PermanentWorker* empList[50];
	int empNum;

public:
	EmployeeHandler()
		:empNum(0)
	{}

	void addEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}

	void showAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->showSalaryInfo();
	}

	void showTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->getPay();
		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

//int main()
//{
//	EmployeeHandler handler;
//	handler.addEmployee(new PermanentWorker("Kim", 1000));
//	handler.addEmployee(new PermanentWorker("Lee", 1500));
//	handler.addEmployee(new PermanentWorker("Jun", 2000));
//
//	handler.showAllSalaryInfo();
//	handler.showTotalSalary();
//
//	return 0;
//}