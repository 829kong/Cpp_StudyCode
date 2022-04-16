#include <iostream>
using namespace std;

class fruitSeller
{
private:
	int apple_Price;
	int numOfApples;
	int myMoney;

public:
	fruitSeller(int price, int num, int money)
	{
		apple_Price = price;
		numOfApples = num;
		myMoney = money;
	}

	int saleApples(int money)
	{
		int num = money / apple_Price;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void showSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl;
	}
};

class fruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	fruitBuyer(int money) 
	{
		myMoney = money;
		numOfApples = 0;
	}

	void buyApples(fruitSeller& seller, int money) 
	{
		if (money <= 0)
		{
			cout << " 0���� ���� ���� �Է��� �� �����ϴ�." << endl;
			return;
		}
		numOfApples += seller.saleApples(money);
		myMoney -= money;
	}

	void showBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main()
{
	fruitSeller seller(1000,20,0);
	

	fruitBuyer buyer(5000);
	
	buyer.buyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.showSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.showBuyResult();

	return 0;
}