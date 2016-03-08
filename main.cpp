#include "dataManipulator.h"
#include <cstdlib>
#include <iostream>
#include "Segment.h"
using namespace std;

int main()
{
	int start_s =0, stop_s =0, test_start= 0, test_stop =0;
	dataManipulator dm;
	Segment segData;
	start_s = clock();
	cout << "***************  program starts  "<<"*****************************" << endl;
	//*****************First test case: 100 thousand random integer
	cout<<endl<<"First test case: 10 thousand random Integer: "<<endl;	
	cout<<"Creating random Integers from -100000000 to 100000000.."<<endl;
	const char* testfile1 = dm.createRandomInt(100000);
	cout<<"Read data from file....."<<endl;	
	vector<int> RanIntData = dm.readIntFromFile(testfile1);	
	cout<<"Data read completed, data stored."<<endl;
	cout<<endl<<"Execute some sample query:"<<endl<<endl;
	dm.executeQuery("larger", 10000, RanIntData);	
	dm.executeQuery("smaller", 10000, RanIntData);
	dm.executeQuery("equals",10000,RanIntData);
	dm.executeQuery("larger", 33333,RanIntData);	
	dm.executeQuery("smaller", 20160307, RanIntData);
	dm.executeQuery("between", 33333,20160307, RanIntData);
	dm.executeQuery("between", 10000,33333,RanIntData);
	//****************second test case: 100 thousand random floats
	cout<<endl<<endl<<"Second test case: 100 thousand random Floats: "<<endl;	
	start_s = clock();	
	cout<<"Creating random Float from -100000000 to 100000000.."<<endl;
	const char* testfile2 = dm.createRandomFloat(100000);
	cout<<"Read data from file....."<<endl;	
	vector<float> RanFloatData = dm.readFloatFromFile(testfile2);	
	cout<<"Data read completed, data stored."<<endl;
	cout<<endl<<"Execute some sample query:"<<endl<<endl;
	dm.executeQuery("larger", (float)123.45, RanFloatData);	
	dm.executeQuery("smaller",(float) 123.45, RanFloatData);
	dm.executeQuery("equals",(float)123.45,RanFloatData);
	dm.executeQuery("larger", (float)333.33,RanFloatData);	
	dm.executeQuery("smaller", (float)2016.00, RanFloatData);
	dm.executeQuery("between", (float)-500.0, (float)500.0, RanFloatData);

	//*****************Third test case: 1 Million random integers
	cout << endl << "Third test case: 1 Million random Integer: " << endl;
	start_s = clock();
	cout << "Creating random Integers from -1000000 to 1000000.." << endl;
	const char* testfile3 = segData.createRandomInt(1000000);
	cout << "Read data from file....." << endl;
	segData.readFromFile(testfile3);
	cout<<endl<<"Execute some sample query:"<<endl<<endl;
	segData.getAllCounts();
	segData.query("smaller", 2000);
	segData.query("larger", 2000);
	segData.query("equals",2000);
	segData.query("between",0,1025);
	//*****************Fourth test case: 10 Million random integers
	cout << endl << "Fourth test case: 10 Million random Integer: " << endl;
	start_s = clock();
	cout << "Creating random Integers from -1000000 to 1000000.." << endl;
	const char* testfile4 = segData.createRandomInt(10000000);
	cout << "Read data from file....." << endl;
	segData.readFromFile(testfile4);
	cout<<"Data read completed, data stored."<<endl;
	cout<<endl<<"Execute some sample query:"<<endl<<endl;
	segData.getAllCounts();
	segData.query("smaller", 2000);
	segData.query("larger", 2000);
	segData.query("equals",2000);
	segData.query("between",0,1025);
	//****************Fifth test case: 50 Million random integers
	cout << endl << "Fifth test case: 25 Million random Integer: " << endl;
	start_s = clock();
	cout << "Creating 25 Million random Integers from -1000000 to 1000000.." << endl;
	const char* testfile5 = segData.createRandomInt(25000000);
	cout << "Read data from file....." << endl;
	segData.readFromFile(testfile5);
	cout<<"Data read completed, data stored."<<endl;
	cout<<endl<<"Execute some sample query:"<<endl<<endl;
	segData.getAllCounts();
	segData.query("smaller", 2000);
	segData.query("larger", 2000);
	segData.query("equals",2000);
	segData.query("between",0,1025);
	cout << endl << "*************** End of the program. Total time cost :";
	stop_s = clock();
	cout << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << " ms  " << "*****************************" << endl;
	cout<<"Wish you have a good one! ---Zhichao(Zach)."<<endl;
	return 0;
}
