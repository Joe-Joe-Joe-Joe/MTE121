#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	string day = "";
	bool school_night = false;
	int start_time = 0;
	string game = "";
	
	cout << "Enter day, whether it is a school night, and time: ";
	cin >> day >> school_night >> start_time;
	
	
	if (day == "Fri" or day == "Sat")
	{
		game = "Ticket to Ride";
	}
	else if (start_time == 6)
	{
		if (day == "Mon" or day == "Tue" or day == "Wed" or day == "Thurs")
		{
			game ="Spirit Island";
		}
		else if (day == "Sun")
		{
			game = "Flash Point";
		}
	}
	else if (start_time == 9)
	{
		if (day == "Mon" or day == "Tue" or day == "Wed" or day == "Thurs" or
		day == "Sun")
		{
			if (school_night)
			{
				game = "Pandemic";
			}
			else
			{
				game = "Settlers of Catan";
			}
		}
	}
	
	
	cout << "Play " << game;
	return EXIT_SUCCESS;
}

/*
Enter day, whether it is a school night, and time: Sat 0 6
Play Ticket to Ride

Enter day, whether it is a school night, and time: Mon 1 9
Play Pandemic

Enter day, whether it is a school night, and time: Sun 1 6
Play Flash Point

Enter day, whether it is a school night, and time: Wed 0 9
Play Settlers of Catan

Enter day, whether it is a school night, and time: Thurs 1 6
Play Spirit Island
*/
