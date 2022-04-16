#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char* name)
	{
		strcpy_s(owner, sizeof(owner), name);
	}

	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;

public:
	NotebookComp(const char* name, int initChag)
		:Computer(name), Battery(initChag)
	{}

	void charging() { Battery += 5; }
	void useBattery() { Battery -= 1; }
	void movingCal() 
	{
		if (getBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		useBattery();
	}
	int getBatteryInfo() { return Battery; }
};

class TabletNoteBook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TabletNoteBook(const char* name, int initChag, const char* pen)
		:NotebookComp(name, initChag)
	{
		strcpy_s(regstPenModel,sizeof(regstPenModel), pen);
	}

	void write(const char* PenInfo)
	{
		if (getBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, PenInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;                                                        
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		useBattery();
	}
};

int main()
{
	NotebookComp nc("�̼���", 5);
	TabletNoteBook tn("������", 5, "ISE-241-242");
	nc.movingCal();
	tn.write("ISE-241-242");
	

	return 0;
}