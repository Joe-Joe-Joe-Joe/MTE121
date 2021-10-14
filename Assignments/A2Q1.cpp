#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	//ASSUMING END USERS DON'T INPUT NON-DOUBLES/INTS
	cout << "How much money does Mike have (in $)? ";
	double money = 0;
	cin >> money;
	
	string coffee = "";
	string sweet = "";
	
	if(money >= 1.75)
	{
		money -= 1.75;
		coffee = "Regular";
	}
	else if(money >= 1)
	{
		money -= 1;
		coffee = "Small";
	}
	else
	{
		coffee = "None";
	}
	
	
	if(money >= 1)
	{
		sweet = "Donut";
	}
	else if (money >= 0.6)
	{
		sweet = "Chocolate";
	}
	else if (money >= 0.5)
	{
		sweet = "Mini tart";
	}
	else
	{
		sweet = "None";
	}
	
	cout << "Coffee: " << coffee << endl;
	cout << "Sweet: " << sweet << endl;
	
	return EXIT_SUCCESS;
}

/*
How much money does Mike have (in $)? -1000
Coffee: None
Sweet: None

How much money does Mike have (in $)? 0.7
Coffee: None
Sweet: Chocolate

How much money does Mike have (in $)? 1.5
Coffee: Small
Sweet: Mini tart

How much money does Mike have (in $)? 1.6
Coffee: Small
Sweet: Chocolate

How much money does Mike have (in $)? 2
Coffee: Regular
Sweet: None

How much money does Mike have (in $)? 5
Coffee: Regular
Sweet: Donut

*/






