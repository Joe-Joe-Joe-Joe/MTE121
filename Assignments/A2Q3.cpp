#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Explaination of atan2 - https://stackoverflow.com/questions/283406/
int main()
{
	double x = 0;
	double y = 0;
	
	//Assumes no x coord of 0
	cout << "Input coordinates in the form <x> <y>: ";
	
	cin >> x;
	cin >> y;
	
	double radius = sqrt(pow(x, 2) + pow(y, 2));
	
	double theta_rad = atan2(y, x);
	
	double theta_deg = theta_rad / M_PI * 180;
	
	cout << "Radius: " << radius << "\n" << "Theta: " << theta_rad 
	<< " (radians)/" << theta_deg << " (degrees)";
	
	return EXIT_SUCCESS;
}

/*
Input coordinates in the form <x> <y>: -0.5 -0.866
Radius: 0.999978
Theta: -2.09441 (radians)/-120.001 (degrees)

Input coordinates in the form <x> <y>: 1 1
Radius: 1.41421
Theta: 0.785398 (radians)/45 (degrees)

Input coordinates in the form <x> <y>: 3 4
Radius: 5
Theta: 0.927295 (radians)/53.1301 (degrees)

Input coordinates in the form <x> <y>: -999 1
Radius: 999.001
Theta: 3.14059 (radians)/179.943 (degrees)

Input coordinates in the form <x> <y>: 10 -5
Radius: 11.1803
Theta: -0.463648 (radians)/-26.5651 (degrees)
*/
