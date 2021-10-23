int main()
{
	ifstream fin("trailRun.txt");
	
	if(!fin)
	{
		return EXIT_FAILURE;
	}
	
	int start_angle = 0;
	int n_measurements = 0;
	int cur_measurement = 0;
	double driving_left = 0;
	double driving_right = 0;

	
	while(fin >> start_angle >> n_measurements)
	{
		for(int measurement = 0; measurement < n_measurements; measurement++)
		{
			fin >> cur_measurement;
			if(cur_measurement < start_angle)
			{
				driving_left++;
			}
			else if(curr_measurement > start_angle)
			{
				driving_right++;
			}
		}
		
		cout << "Driving left " << driving_left / n_measurements << "% of time;"
		<< " Driving right " << driving_right / n_measurements << "% of time"
		<< endl;
	}
	
	fin.close();
	return EXIT_SUCCESS;
}
