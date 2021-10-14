const int DAYS_IN_WEEK = 7;


int main()
{
	ifstream fin("daily_walk.txt");
	if(!fin)
	{
		return EXIT_FAILURE;
	}
	
	string date = "";
	float shortest_trip = 0;
	while(fin >> date)
	{
		int days_walking = 0;
		float dist_walked_total = 0;
		
		for(int day = 0; day < DAYS_IN_WEEK; day++)
		{
			float dist_walked_today = 0;
			fin >> dist_walked_today;
			if(dist_walked_today > 0)
			{
				days_walking++;
				if (dist_walked_today > shortest_trip)
				{
				shortest_trip = dist_walked_today;
				}
			}
			
			dist_walked_total += dist_walked_today;
		}
		//No div by 0 error since all input has at least 1 walk > 0 km
		cout << "Walked average " << dist_walked_total / days_walking << " km"
		<< " the week of " << date << endl;
		
	}
	
	fin.close();
	return EXIT_SUCCESS;

}
