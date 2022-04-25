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

	Point& operator+=(const Point& ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1,const Point & pos2);
	friend bool operator == (const Point& pos1, const Point& pos2);
	friend bool operator != (const Point& pos1, const Point& pos2);

};

Point operator+(const Point& pos1,const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator == (const Point& pos1, const Point& pos2)
{
	if ((pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos))
		return true;
	else
		return false;
	
}

bool operator != (const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}



int main()
{
	Point pos1(1, 2);
	Point pos2(1, 1);

	if (pos1 == pos2)
	{
		cout << "pos1 == pos2" << endl;
	}
	else if (pos1 != pos2)
	{
		cout << "pos1 != pos2" << endl;
	}

	
	return 0;
}