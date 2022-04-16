#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(10000000));
	return res;
}

int main()
{
	using namespace std;
	Timer timer;
	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
	}

	timer.elaped();
	return 0;
}