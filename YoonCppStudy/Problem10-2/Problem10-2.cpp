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
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point& operator-()
	{
		Point pos;
		pos.xpos = -xpos;
		pos.ypos = -ypos;
		return pos;
	}

	const Point operator++(int)
	{
		const Point retobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return retobj;
	}
	friend Point& operator~(Point& ref);
};

Point& operator~(Point& ref)
{
	Point pos;
	pos.xpos = ref.ypos;
	pos.ypos = ref.xpos;
	return pos;
}

int main()
{
	Point pos1(1, 2);
	Point pos2 = -pos1;
	Point pos3 = ~pos1;

	pos1.showPosition();
	pos2.showPosition();
	pos3.showPosition();

	return 0;
}