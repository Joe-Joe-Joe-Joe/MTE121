int main()
{
	const char PITCHER = 'P';
	const int ERA_CONST = 9;
	const int FIELDER_STATS = 10;
	
	
	ifstream fin("baseball.txt");
	if(!fin)
	{
		return EXIT_FAILURE;
	}
	
	string p_name = "";
	char p_pos = '';
	float fielder_stat = 0;
	float earned_runs = 0;
	float innings_pitched = 0;
	float strike_outs = 0;
	float era = 0;
	
	float max_era = 0;
	string max_era_name = "";
	

	
	while(fin >> p_name >> p_pos)
	{
		if(p_pos == PITCHER)
		{
			fin >> earned_runs >> innings_pitched >> strike_outs;
			era = ERA_CONST * earned_runs / innings_pitched;
			if(era > max_era)
			{
				max_era = era;
				max_era_name = p_name;
			}
		}

		else
		{
			for(int stat = 0; stat < FIELDER_STATS; stat++)
			{
				fin >> fielder_stat;
			}
		}

	}
	
	cout << "The best pitcher is " << max_era_name
	<< " with " << max_era << " ERA";
	
	fin.close();
	return EXIT_SUCCESS;
}
