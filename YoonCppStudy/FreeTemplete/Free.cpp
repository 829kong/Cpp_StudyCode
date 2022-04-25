#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y)
	{}

	void showPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, const Point& ref);
};

Point operator*(int times, const Point& ref)
{
	Point pos(ref.xpos * times, ref.ypos * times);
	return pos;
}

int main()
{
	Point pos(1, 2);
	Point cpy;
	cpy = pos * 2;
	cpy.showPosition();
	cpy = pos * 2 * 3;
	cpy.showPosition();
	cpy = 2 * pos;
	cpy.showPosition();
	return 0;
}