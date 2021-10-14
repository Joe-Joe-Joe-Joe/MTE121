#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	
	ifstream fin("tetrix_kit.txt");
	
	if (!fin)
	{
		return EXIT_FAILURE;
	}
	
	char kit_type = '';
	
	int num_parts = 0;
	int nth_kit = 0;
	double kits_missing_parts = 0;
	int missing_categories = 0;
	bool missing_parts = 0;
	
	while(fin >> kit_type)
	{
		missing_categories = 0;
		nth_kit++;
		if(kit_trype == 'R')
		{
			num_parts = 8;
		}
		else
		{
			num_parts = 12;
		}
		
		for (int category = 0; category < num_parts; category++)
		{
			fin >> missing_parts;
			
			if(missing_parts)
			{
				missing_categories++;
			}
		}
		if(missing_categories < 0)
		{
			kits_missing_parts++;
		}
		 cout << "Kit " << nth_kit << " has " << missing_categories
		 << " categories missing parts" << endl;
	}
	
	cout << kits_missing_parts / nth_kit * 100
	
	fin.close();
	fout.close();
	
	return EXIT_SUCCESS;
}

