#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Enter a number in the thousands: ";
	int number = 0;
	cin >> number;
	int bigger = 0;
	int smaller = 0;
	
	bigger = number / 1000;
	smaller = number % 1000;
	
	
	if (smaller < 0)
	{
		smaller = -smaller;
	}
	
	if(smaller < 10)
	{
		cout << bigger << "," << "00" << smaller;
	}
	else if(smaller < 100)
	{
		cout << bigger << "," << "0" << smaller;
	}
	else
	{
		cout << bigger << "," << smaller;
	}
	
	return EXIT_SUCCESS;
}
