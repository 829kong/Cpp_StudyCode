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
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl;
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
			cout << " 0보다 작은 수를 입력할 수 없습니다." << endl;
			return;
		}
		numOfApples += seller.saleApples(money);
		myMoney -= money;
	}

	void showBuyResult() const
	{
		cout << "현제 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main()
{
	fruitSeller seller(1000,20,0);
	

	fruitBuyer buyer(5000);
	
	buyer.buyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.showSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.showBuyResult();

	return 0;
}