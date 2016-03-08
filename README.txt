# Two approches for this question in this packages

1, Segment implementation (For Object size > 1 million)
  	O(n): data creation
  	O(n): Space
  	O(1) average, O(n) worst: Range Searching
  	**Self-defined stuturce with different sections to store numbers, for example: [-1023,0] [0, 1023], [1024, 2047]......
  	**for example, integer "2016" will be stored in section [1024, 2047].
  	**each section have lowerCount and biggerCount, to record # of integers smaller/larger than the bounder of this section.
  
2, Sort + Binary Search(For object size < 1 million)
  	O(n): data creation
  	O(n log n): sorting
  	O(n): Space
  	O(log n):range searching
  	**Sort all data first,
  	**Use libary function upper_bound/lower_bound finished range searching.
  

# 5 test cases,

	First two testcases small size input(100k integer and 100k float), use Easy Implementation.
	Last two testcase are very large size input(1 million, 10 million, 25 million integers), use Segment implementation. 


# Potential uncertainty

	the RAND_MAX is based on the libary, may varied from machine to machine, and cause different result.
	when I run this program in my machine, RAND_MAX is 2147483647, and I limited all random number here in range of -1000000 to 1000000

# Others
	All data will be save in file for reference, for example, 
	the data for 100 thousand integers will be stored in "100000_integers.txt".
	You could run 'make clean' to remove those files.
	Sample results could seen from 'sampleResult.img'

Thanks for reading and Regards,
Zach

