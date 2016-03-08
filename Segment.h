#pragma once
#ifndef SEGMENT_H
#define SEGMENT_H
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<vector>
#include<unordered_map>
#include <algorithm>

#define MAX_RAND 1000000
#define MIN_RAND -1000000
using namespace std;

struct section
{
	int lowerCount; // count how many numbers is larger than the max number of this section
	int biggerCount;// count how many numbers is smaller than the min number of this section
	vector<int> sectionData;
};

class Segment {

public:

	Segment()
	{	
		int start = MIN_RAND/ 1024, end = MAX_RAND/1024;
		for(int i=start; i<=end;i++){
			vector<int> temp;		
			sectionCount[i].lowerCount =0;
			sectionCount[i].biggerCount = 0;
			sectionCount[i].sectionData = temp;	
		}	
	}
	const char* createRandomInt(int n);
	const char* createRandomFloat(int n);
	void addValue(int n);
	void getAllCounts();
	void query(string queryType, int target);
	void query(string queryType, int num1, int num2);
	void readFromFile(const char* filename);

private:
	vector<vector<int> > data;
	unordered_map<int,section> sectionCount;
};

#endif // !SEGMENT_H

