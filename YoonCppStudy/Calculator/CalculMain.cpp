#include <iostream>
using namespace std;

class Calculator
{
private:
	double a, b, result;
	int Acount,Dcount,Mcount,Xcount;
public:
	void init();
	double Add(double a, double b);
	double Div(double a, double b);
	double Min(double a, double b);
	void ShowOpCount();
};

void Calculator::init()
{
	a = 0;
	b = 0;
	result = 0;
	Acount = 0;
	Dcount = 0;
	Mcount = 0;
	Xcount = 0;
}
double Calculator::Add(double a, double b)
{
	result = a + b;
	Acount++;
	return result;
}
double Calculator::Div(double a, double b)
{
	result = a / b;
	Dcount++;
	return result;
}
double Calculator::Min(double a, double b)
{
	result = a - b;
	Mcount++;
	return result;
}
void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << Acount<<" ";
	cout << "»¬¼À: " << Mcount<<" ";
	cout << "°ö¼À: " << Xcount<<" ";
	cout << "³ª´°¼À: " << Dcount << endl;
}

int main() 
{
	Calculator cal;
	cal.init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}