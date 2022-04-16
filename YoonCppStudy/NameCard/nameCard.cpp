#include <iostream>
#include <string>
using namespace std;

namespace COMP_POS
{
	enum
	{
		CLERK, SENIOR, ASSIST, MANAGER
	};
}

class nameCard
{
private:
	char	*name;
	char	*companyName;
	char	*phoneNum;
	int		rank;

public:
	nameCard(char* myName, char* myComName, char* myPhoneNum, int rank)
	{
		name = new char[strlen(myName) + 1];
		companyName = new char[strlen(myComName) + 1];
		phoneNum = new char[strlen(myPhoneNum) + 1];
		strcpy(name, myName);
		strcpy(companyName, myComName);

	}

	void showNameCardInfo() const
	{

	}
};

int main()
{
	nameCard manCleck("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	nameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	nameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manCleck.showNameCardInfo();
	manSenior.showNameCardInfo();
	manAssist.showNameCardInfo();
	return 0;
}