#pragma once
#ifndef DATAMANIPULATOR_H
#define DATAMANIPULATOR_H
#include <cstdlib>
#include <vector>
#include <time.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream> 

#define MAX_RAND 1000000
#define MIN_RAND -1000000
using namespace std;

class dataManipulator {

public:
	const char* createRandomInt(int n);
	const char* createRandomFloat(int n);
	vector<int> readIntFromFile(const char* filename);
	vector<float> readFloatFromFile(const char*filename);
	template <typename Type> int countNumberLarger(vector<Type>vec, Type n);
	template <typename Type> int countNumberSmaller(vector<Type>vec, Type n);
	template <typename Type> int countNumberEquals(vector<Type> vec, Type n);
	template <typename Type> int countNumberBetween(vector<Type> vec, Type n1, Type n2);
	template <typename Type> void executeQuery(string queryName, Type target, vector<Type> vec);
	template <typename Type> void executeQuery(string queryName, Type num1, Type num2, vector<Type> vec);
private:

};

#endif //DATAMANIPULATOR_H
