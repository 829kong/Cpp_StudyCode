#include "Monster.h"
using namespace std;

int main()
{
	Position2D pos1(1, 1);
	Monster mon1("Sanson", pos1);

	//while (1)
	{
		mon1.moveTo(pos1);
		cout << mon1 << endl;
	}
	return 0;
}