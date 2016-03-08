#include "Segment.h"
using namespace std;

const char* Segment::createRandomInt(int n)
{
	srand(time(0));
	int r;
	string filename = to_string(n) + "_integers.txt";
	const char* file = filename.c_str();
	ofstream testfile(file);
	for (int i = 0; i< n; i++)
	{
		r = rand() % (MAX_RAND-MIN_RAND+1) - MAX_RAND;
		testfile << r << endl;
	}
	testfile.close();
	cout << n << " Integer generation completed, saved in file:  " << filename << endl;
	return file;
}

void Segment::addValue(int n) 
{
	int key = n / 1024;
	sectionCount[key].sectionData.push_back(n);
}

void Segment::readFromFile(const char* filename) 
{
	ifstream testData(filename);
	if (testData.is_open())
	{
		int currdata = 0;
		while (testData >> currdata)
		{			
			addValue(currdata);
		}
		testData.close();
	}
	else
	{
		cout << "could not open file, please enter correct filename/path" << endl;
	}
	return;
}

void Segment::getAllCounts() 
{
	int start = -100000000/ (2 * 1024), end = 100000000/(2*1024);
	for (int i = start+1; i <= end; i++) 
	{
		sectionCount[i].lowerCount = sectionCount[i - 1].lowerCount + sectionCount[i - 1].sectionData.size();
	}

	for (int i = end - 1;i >= start;i--) 
	{
		sectionCount[i].biggerCount = sectionCount[i + 1].biggerCount + sectionCount[i + 1].sectionData.size();
	}
}

void Segment::query(string queryType, int target) 
{
	int key = target / 1024, count = 0;
	if(target > MAX_RAND)
	{
		key = MAX_RAND/1024;
	}
	if(target < MIN_RAND)
	{
		key = MIN_RAND/1024;
	}	
	vector<int> temp = sectionCount[key].sectionData;
	int test_start = clock();
	if (queryType == "larger") 
	{
		count = sectionCount[key].biggerCount;
		for (int i = 0;i < temp.size(); i++) 
		{
			if (temp[i] > target) 
			{
				count++;
			}				
		}
		cout << "numbers of Objects larger than  " << target << " :   " <<  count << endl;
	}
	else if (queryType == "smaller")
	{
		count = sectionCount[key].lowerCount;
		for (int i = 0;i < temp.size(); i++)
		{
			if (temp[i] < target) 
			{
				count++;
			}
		}
		cout << "numbers of Objects smaller than " << target << " :   " << count << endl;
	}
	else if (queryType == "equals") 
	{
		for (int i = 0; i < temp.size(); i++) 
		{
			if (temp[i] == target) 
			{
				count++;
			}
		}
		cout << "numbers of Objects equals       " << target << " :   " << count << endl;
	}
	else 
	{
		cout << "Incorrect query type" << endl;
	}
	int test_stop = clock();
	cout << "query execution time: " << (test_stop - test_start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl << endl;	
	return;

}

void Segment::query(string queryType, int num1, int num2) 
{
	int test_start = clock();
	int small = min(num1, num2);
	int big = max(num1, num2);
	int count = 0, smallKey = small / 1024, bigKey = big / 1024;	
	vector<int> tempvb = sectionCount[bigKey].sectionData, tempvs = sectionCount[smallKey].sectionData;
	if (queryType == "between")
	{
		for (int i = 0;i < tempvb.size();i++) 
		{
			if (tempvb[i] < big) 
			{
				count++;
			}
		}
		for (int i = 0; i < tempvs.size(); i++) 
		{
			if (tempvs[i] > small)
			{
				count++;
			}
		}
		cout << "numbers of Objects between " << num1 << " and " << num2 << " :  " << count << endl;
	}
	else
	{
		cout << "Incorrect query type" << endl;
	}
	int test_stop = clock();
	cout << "query execution time: " << (test_stop - test_start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl << endl;	

	return;
}
