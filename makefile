# the compiler: g++ for C++ program
CXX = g++ --std=c++11

#compiler flags:
# -g adds debugging inf to executable file
# -Wall turns on most, not all, compiler warnings
CXXFLAGS = -Wall -g

# the build target executable:

Exercise3: main.o LinkedList.o SortedList.o #first line lists dependency of trunk.
	$(CXX) $(CXXFLAGS) -o Exercise3 main.o LinkedList.o SortedList.o

#next line is building the object files with its dependencies.
main.o: LinkedList.cpp LinkedList.h ListInterface.h SortedList.cpp SortedList.h
	$(CXX) $(CXXFLAGS) -c main.cpp

LinkedList.o: LinkedList.h ListInterface.h

#indented line, known as generator line, not needed after first one bc of CXX.

SortedList.o: SortedList.h LinkedList.h ListInterface.h

clean:
	rm Exercise3 main.o LinkedList.o SortedList.o
