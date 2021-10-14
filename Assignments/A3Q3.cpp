#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	
	float side_1 = 0;
	float side_2 = 0;
	float angle = 0;
	bool bad_input = false;
	
	const float SIDE_TOLERANCE = 0.1;
	const float ANGLE_TOLERANCE = 0.5;
	
	
	cout << "Input the length of two adjacent sides (in cm) and the angle "
	<< "between them (in degrees) (<side 1> <side 2> <angle>): " << endl;
	cin >> side_1 >> side_2 >> angle;
	
	if(!(0 < angle && angle < 180 && 0 < side_1 && 0 < side_2))
	{
		cout << "Input data out of range";
	}
	else
	{
		if (fabs(side_1 - side_2) < SIDE_TOLERANCE && 
		fabs(angle-90) < ANGLE_TOLERANCE)
		{
			cout << "Square";
		}
		else if (fabs(angle-90) < ANGLE_TOLERANCE)
		{
			cout << "Rectangle";
		}
		else
		{
			cout << "Parallelogram";
		}
	}
	
	return EXIT_SUCCESS;
}

/*

*/
