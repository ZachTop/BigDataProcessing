#include "dataManipulator.h"


using namespace std;


const char* dataManipulator::createRandomInt(int n) {
	srand(time(0));
	int r;
	ostringstream convert;   // stream used for the conversion

	convert << n;      // insert the textual representation of 'Number' in the characters in the stream

	string filename = convert.str() + "_integers.txt";

	const char* file = filename.c_str();
	ofstream testfile(file);
	for (int i = 0; i< n; i++)
	{
		r = rand() % (MAX_RAND-MIN_RAND+1) - MAX_RAND;
		testfile << r << endl;
	}
	testfile.close();
	cout << "Integer generation completed, saved in file:  " << filename << endl;
	return file;
}

const char* dataManipulator::createRandomFloat(int n) {
	srand(time(0));
	float r;
	ostringstream convert;   // stream used for the conversion

	convert << n;      // insert the textual representation of 'Number' in the characters in the stream

	string filename = convert.str() + "_float_numbers.txt";

	const char* file = filename.c_str();
	ofstream testfile(file);
	for (int i = 0; i< n; i++)
	{
		r = MIN_RAND + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (MAX_RAND-MIN_RAND)));
		testfile << r << endl;
	}
	testfile.close();
	cout << "Integer generation completed, saved in file:  " << filename << endl;
	return file;
}

vector<int> dataManipulator::readIntFromFile(const char* filename) {
	vector<int> randomIntegers;
	ifstream testData(filename);
	if (testData.is_open())
	{
		int currdata = 0;
		while (testData >> currdata)
		{
			randomIntegers.push_back(currdata);
		}
		sort(randomIntegers.begin(), randomIntegers.end());
		testData.close();
	}
	else
	{
		cout << "could not open file, please enter correct filename/path" << endl;
	}
	return randomIntegers;
}

vector<float> dataManipulator::readFloatFromFile(const char* filename) {
	vector<float> randomFloats;
	ifstream testData(filename);
	if (testData.is_open())
	{
		float currdata = 0;
		while (testData >> currdata)
		{
			randomFloats.push_back(currdata);
		}
		sort(randomFloats.begin(), randomFloats.end());
		testData.close();
	}
	else
	{
		cout << "could not open file, please enter correct filename/path" << endl;
	}
	return randomFloats;
}

template <typename Type> int dataManipulator::countNumberLarger(vector<Type> vec, Type n)
{
	return vec.end() - upper_bound(vec.begin(), vec.end(), n);
}

template <typename Type> int dataManipulator::countNumberSmaller(vector<Type>vec, Type n)
{
	return lower_bound(vec.begin(), vec.end(), n) - vec.begin();
}

template <typename Type> int dataManipulator::countNumberEquals(vector<Type> vec, Type n)
{
	return upper_bound(vec.begin(), vec.end(), n) - lower_bound(vec.begin(), vec.end(), n);
}

template <typename Type> int dataManipulator::countNumberBetween(vector<Type> vec, Type n1, Type n2)
{
	Type big = max(n1, n2);
	Type small = min(n1, n2);
	return upper_bound(vec.begin(), vec.end(), big) - lower_bound(vec.begin(), vec.end(), small);
}
template <typename Type> void dataManipulator::executeQuery(string queryName, Type target, vector<Type> vec)
{
	int test_start = clock();

	if (queryName == "larger")
	{
		cout << "numbers of Objects larger than  " << target << " :   " << countNumberLarger(vec, target) << endl;
	}
	else if (queryName == "smaller")
	{
		cout << "numbers of Objects smaller than " << target << " :   " << countNumberSmaller(vec, target) << endl;
	}
	else if (queryName == "equals")
	{
		cout << "numbers of Objects equals       " << target << " :   " << countNumberEquals(vec, target) << endl;
	}
	else {
		cout << "Incorrect query type" << endl;
		return;
	}
	int test_stop = clock();
	cout << "query execution time: " << (test_stop - test_start) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl << endl;
	return;
}

template <typename Type> void dataManipulator::executeQuery(string queryName, Type num1, Type num2, vector<Type> vec)
{
	if (queryName == "between")
	{
		cout << "numbers of Objects between " << num1 << " and " << num2 << " :  " << countNumberBetween(vec, num1, num2) << endl;
	}
	else
	{
		cout << "Incorrect query type" << endl;
		return;
	}

}


template void dataManipulator::executeQuery(string queryName, int target, vector<int> vec);
template void dataManipulator::executeQuery(string queryName, float target, vector<float> vec);
template void dataManipulator::executeQuery(string queryName, int num1, int num2, vector<int> vec);
template void dataManipulator::executeQuery(string queryName, float num1, float num2, vector<float> vec);

template int dataManipulator::countNumberLarger(vector<int> vec, int n);
template int dataManipulator::countNumberLarger(vector<float> vec, float n);
template int dataManipulator::countNumberSmaller(vector<int> vec, int n);
template int dataManipulator::countNumberSmaller(vector<float> vec, float n);
template int dataManipulator::countNumberEquals(vector<int> vec, int n);
template int dataManipulator::countNumberEquals(vector<float> vec, float n);
template int dataManipulator::countNumberBetween(vector<int> vec, int n1, int n2);
template int dataManipulator::countNumberBetween(vector<float> vec, float n1, float n2);



//void dataManipulator::cleanGenarated(string filename);


