#include <iostream>
#include <string>
using namespace std;

enum class Risk_Level
{
	Risk_A = 1, Risk_B, Risk_C
};

class Employee // Data: �̸�
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

	virtual int getPay() const = 0;

	virtual void showSalaryInfo() const = 0;
	 
};
class PermanentWorker : public Employee  //������, Data : �̸�(���),����
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

class SalesWorker : public PermanentWorker //������ Data : �̸�(���),����(���),�μ�Ƽ��
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

class ForeignSalesWorker : public SalesWorker
{
private:
	Risk_Level m_risk;

public:
	ForeignSalesWorker(string name, int money, double ratio, Risk_Level riskLevel)
		:SalesWorker(name, money, ratio),m_risk(riskLevel)
	{}

	int getPay() const
	{
		return SalesWorker::getPay();
	}

	int getRiskPay(Risk_Level Risk) const
	{
		switch (Risk)
		{
		case Risk_Level::Risk_A :
			return getPay() * 0.3;
			break;
		case Risk_Level::Risk_B:
			return getPay() * 0.2;
			break;
		case Risk_Level::Risk_C:
			return getPay() * 0.1;
			break;
		}
	}

	void showSalaryInfo() const
	{
		showName();
		cout << "Salary: " << getPay() << endl;
		cout << "Risk: " << getRiskPay(m_risk) << endl;
		cout << "Sum: " << getPay() + getRiskPay(m_risk) << endl << endl;
	}

};

class TemporaryWorker : public Employee //�ӽ���(�˹�)
{
private:
	int m_timePay;
	int m_workTime;

public:
	TemporaryWorker(string name, int timeSalary)
		:Employee(name), m_timePay(timeSalary), m_workTime(0)
	{}

	void AddWorkTime(int time)
	{
		m_workTime += time;
	}

	int getPay() const
	{
		return m_workTime * m_timePay;
	}

	void showSalaryInfo() const
	{
		showName();
		cout << "Salary: " << getPay() << endl<<endl;
	}
};

class EmployeeHandler //��Ʈ�� Ŭ����
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

int main()
{
	//�ڵ鷯 ��ü����
	EmployeeHandler handler;
	
	//�ؿ� ������ ���
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, Risk_Level::Risk_A);
	fseller1->addSalesResult(7000);
	handler.addEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, Risk_Level::Risk_B);
	fseller2->addSalesResult(7000);
	handler.addEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, Risk_Level::Risk_C);
	fseller3->addSalesResult(7000);
	handler.addEmployee(fseller3);

	handler.showAllSalaryInfo();



	////������
	//handler.addEmployee(new PermanentWorker("Kim", 1000));
	//handler.addEmployee(new PermanentWorker("Lee", 1500));
	////�ӽ���
	//TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);
	//handler.addEmployee(alba);
	////������
	//SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	//seller->addSalesResult(7000);
	//handler.addEmployee(seller);
	//handler.showAllSalaryInfo();
	//handler.showTotalSalary();


	return 0;
}