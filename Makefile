
output: main.o dataManipulator.o Segment.o
	g++ -std=c++11 main.o dataManipulator.o Segment.o -o output
	./output
	rm *.o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
dataManipulator.o: dataManipulator.cpp dataManipulator.h 
	g++ -std=c++11 -c dataManipulator.cpp Segment.cpp

Segment.o: Segment.cpp Segment.h
	g++ -std=c++11 -c Segment.cpp
clean: 
	rm *.txt *~
