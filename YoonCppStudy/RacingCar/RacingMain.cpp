#include "Car.h"

int main()
{
	Car run99;
	char id[] = "run99";
	run99.InitMembers(id, 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}