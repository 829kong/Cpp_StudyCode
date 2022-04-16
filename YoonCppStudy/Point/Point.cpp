#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	void init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	void showPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class circle
{
private:
	int radius;
	Point point;

public:
	void init(int xpos,int ypos, int rad)
	{
		point.init(xpos, ypos);
		radius = rad;
	}

	void showCircleInfo() const
	{
		cout << "radius: " << radius;
		point.showPointInfo();
	}
};

class Ring
{

};

int main()
{

	return 0;
}