int main()
{
	ifstream fin("movieViews.txt");
	string lowest_views_title = "";
	double lowest_avg_views = 100000000;
	string cat_title = "";
	int view_sum = 0;
	int movie_count = 0;
	int current_views = 0;
	int avg_views = 0;
	
	
		
	while(fin >> cat_title >> current_views)
	{
		while(current_views > -1)
		{
			movie_count++;
			view_sum += current_views;
			fin >> current_views;
		}
		avg_views = view_sum / movie_count;
		if(avg_views < lowest_avg_views)
		{
			lowest_avg_views = avg_views;
			lowest_views_title = cat_title;
		}
	}
	
	cout << lowest_views_title;

	fin.close();
	return EXIT_SUCCESS;

}
