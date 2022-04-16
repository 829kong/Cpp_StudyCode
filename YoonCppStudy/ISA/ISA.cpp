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
		cout << "요청 내용을 계산합니다." << endl;
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
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
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
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, PenInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다.";
			return;                                                        
		}
		cout << "필기 내용을 처리합니다." << endl;
		useBattery();
	}
};

int main()
{
	NotebookComp nc("이수종", 5);
	TabletNoteBook tn("정수영", 5, "ISE-241-242");
	nc.movingCal();
	tn.write("ISE-241-242");
	

	return 0;
}