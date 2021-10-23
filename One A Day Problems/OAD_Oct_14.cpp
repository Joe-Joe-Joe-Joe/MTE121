int main()
{
	ifstream fin("movie.txt");
	string lowest_rating_title = "";
	double lowest_avg_rating = 6;
	string movie_title = "";
	int rating_sum = 0;
	int current_rating = 0;
	int avg_rating = 0;
	const int WATCHES = 10;
	
	
		
	while(fin >> movie_title)
	{
		for(int view = 0; view < 10; view++)
		{
			fin >> current_rating;
			rating_sum += current_rating;
		}
		avg_rating = round(rating_sum / WATCHES);
		cout << movie_title;
		for (int stars = 0; stars < avg_rating; stars++)
		{
			cout << '*'
		}
		cout << endl;
		if(avg_views < lowest_avg_views)
		{
			lowest_avg_rating = avg_rating;
			lowest_rating_title = movie_title;
		}
	}
	
	cout << "She hates " lowest_rating_title << " " << lowest_avg_rating;

	fin.close();
	return EXIT_SUCCESS;

}
