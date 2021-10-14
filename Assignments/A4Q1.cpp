#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	float total_dist = 0;
	float total_cost = 0;
	float longest_trip = -1;
	float cheapest_trip = 3.40282e+038;
	const float VIP_COST = 0.75;
	const float COST_PER_KM = 2.60;
	
	ifstream fin("taxi.txt");
	
	if (!fin)
	{
		return EXIT_FAILURE;
	}
	
	ofstream fout("report.txt");
	fout << fixed << setprecision(2);
	fout << "trip# " << "VIP " << "stops " << "tripDist " << "tripCost "
	<< "totalDist " << "totalCost" << endl;
	
	int count = 0;
	int total_stops = 0;
	int vip = 0;
	
	while(fin >> vip >> total_stops)
	{
		count++;
		float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		float trip_dist = 0;
		for(int curr_stop = 0; curr_stop < total_stops; curr_stop++)
		{
			fin >> x2 >> y2;
			trip_dist += pow(pow(x2-x1, 2) + pow(y2-y1, 2), 0.5);
			x1 = x2;
			y1 = y2;
		}
		//trip to origin
		trip_dist += pow(pow(x1, 2) + pow(y1, 2), 0.5);
		float trip_cost = 15 + COST_PER_KM * trip_dist;
		if(vip)
		{
			trip_cost *= VIP_COST;
		}
		
		if(trip_cost < cheapest_trip)
		{
			cheapest_trip = trip_cost;
		}
		if (trip_dist > longest_trip)
		{
			longest_trip = trip_dist;
		}
		total_dist += trip_dist;
		total_cost += trip_cost;
		
		if (count < 5 or count % 10 == 4)
		{
			fout << setw(5) << count << setw(4) << vip << setw(6) 
			<< total_stops << setw(9) << trip_dist << setw(9) << trip_cost 
			<< setw(10) << total_dist << setw(10) << total_cost << endl;
		}
	}
	
	fout << "Total distance travelled this month: " << total_dist << endl
	<< "Total revenue this month: " << total_cost << endl
	<< "Longest trip this month: " << longest_trip << endl
	<< "Least expensive trip this month: " << cheapest_trip << endl;
	
	fin.close();
	fout.close();
	
	return EXIT_SUCCESS;
}

/*
trip# VIP stops tripDist tripCost totalDist totalCost
    1   0     1    20.40    68.04     20.40     68.04
    2   1     2    13.07    36.73     33.47    104.77
    3   0     4    40.72   120.86     74.18    225.63
    4   0     3    25.83    82.16    100.02    307.80
   14   0     4    26.46    83.79    410.38   1178.59
   24   1     2    25.01    60.02    752.64   2112.59
   34   0     3    21.75    71.55   1053.62   2972.71
   44   0     2    19.87    66.66   1307.69   3712.96
   54   0     5    33.90   103.14   1597.49   4508.18
   64   0     2    19.57    65.89   1874.82   5313.29
   74   1     2    13.53    37.63   2142.17   6103.02
Total distance travelled this month: 2244.09
Total revenue this month: 6406.70
Longest trip this month: 51.39
Least expensive trip this month: 34.51
*/
