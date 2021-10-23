const int ONE_DAY = 2400;

int main()
{
	ifstream fin("flight.dat");

	ofstream fout("longFlight.dat");
	string lf_flight = "";
	string lf_dest = "";
	double lf_time_total = 0;

	string cur_flight = "";
	string cur_dest = "";
	double cur_time = 0;
	double last_time = 0;
	double cur_time_total = 0;
	int int_stops = 0;

	fout << "Flight " << "Destination " << "Hrs" << endl;

	while(fin >> cur_flight >> cur_dest >> int_stops)
	{
		if(int_stops)
		{
			fin >> last_time >> cur_time;

			if(last_time > curr_time)
			{
				curr_time += ONE_DAY;
			}

			cur_time_total = cur_time - last_time;
			fout << setw(6) << cur_flight
				<< setw(12) << cur_dest
				<< setw(5) << cur_time_total
				<< endl;
				
			if(cur_time_total > lf_time_total)
			{
				lf_time_total = cur_time_total;
				lf_flight = cur_flight;
				lf_dest = cur_dest;
			}
		}
		else
		{
			for(int stop = 0; stop < int_stops; stop++)
			{
				fin >> curr_time;
			}
		}
		
		
	}
	
	fout << "Longest is " << lf_flight << " to " << lf_dest
	<< " at " << lf_time_total;
	fout.close();
	fin.close();
	
	return EXIT_SUCCESS
}
