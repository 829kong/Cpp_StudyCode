#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient
{
private:
	string m_name;
	vector<Doctor> m_doctors;
public:
	Patient(const string name_in)
		:m_name(name_in)
	{}
	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}
};

class Doctor
{
private:
	string m_name;
public:
	Doctor(const string name_in)
		:m_name(name_in)
	{}
};

int main()
{
	Patient* p1 = new Patient("Jack Jack");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	delete p1, p2, p3;
	delete d1, d2;

	return 0;
}