//--------------------------------------------------------------------
//
//   main.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "LinkedList.cpp"
#include "SortedList.cpp"

// Routes between sorting methods
int startMenu();
// Routes to reset or quit program
int quitMenu();
// Loads unordered list from file
void loadList(LinkedList<int>& rand, string file);

// Finds the largest item in the list
int findIndexOfLargest(LinkedList<int>& rand, int size, int& compCnt, int& swapCnt);
// Sorts the items into sorted list in ascending order
void selectionSort(LinkedList<int>& rand, SortedList<int>& ordered, int n, int& compCnt, int& swapCnt);
// merges broken down list
void merge(LinkedList<int>& rand, int first, int mid, int last, int& compCnt, int& swapCnt);
// Sorts the items into original list in ascending order
void mergeSort(LinkedList<int>& rand, int first, int last, int& compCnt, int& swapCnt);

int main()
{
	int reset = 1;
	while (reset == 1)
	{
		/* Variable Delcaration*/
		int switch_on; // for switch statements
		LinkedList<int> rand1000;
		SortedList<int> ordered1000;
		LinkedList<int> rand10000;
		SortedList<int> ordered10000;
		LinkedList<int> rand100000;
		SortedList<int> ordered100000;
		int swapCnt = 0;
		int compCnt = 0;
		string file1000 = "ordered1000.txt"; // stores file of 1000 rangom integers from 0 to 10^6
		string file10000 = "ordered10000.txt"; // stores file of 10000 rangom integers from 0 to 10^6
		string file100000 = "rand100000.txt"; // stores file of 100000 rangom integers from 0 to 10^6

		int choice = startMenu();
		if (choice == 1) // Selection Sort menu
		{
			cout << "Choose to order the following amount of integers with Selection Sort:";
			cout << "\n1) 1,000 integers \n2) 10,000 integers\n3) 100,000 integers\n";
			cin >> switch_on;
			switch (switch_on)
			{
			case 1: // orders 1,000 integers
				loadList(rand1000, file1000);
				selectionSort(rand1000, ordered1000, rand1000.getLength(), compCnt, swapCnt); // returns an ordered sorted list
				ordered1000.showStructure(); // method used to test sort
				break;
			case 2: // order 10,000 integers
				loadList(rand10000, file10000);
				selectionSort(rand10000, ordered10000, rand10000.getLength(), compCnt, swapCnt); // returns an ordered sorted list
				ordered10000.showStructure();
				break;
			case 3: // order 100,000 integers
				loadList(rand100000, file100000);
				selectionSort(rand100000, ordered100000, rand100000.getLength(), compCnt, swapCnt); // returns an ordered sorted list
				ordered100000.showStructure();
				break;
			default:
				break;
			}
		} // end selection sort menu
		else if (choice == 2)  // Merge Sort menu
		{
			cout << "Choose to order the following amount of integers with Merge Sort:";
			cout << "\n1) 1,000 integers \n2) 10,000 integers\n3) 100,000 integers\n";
			cin >> switch_on;
			switch (switch_on)
			{
			case 1: // orders 1,000 integers
				loadList(rand1000, file1000);
				mergeSort(rand1000, 1, rand1000.getLength(), compCnt, swapCnt); // returns the original list ordered.
				rand1000.showStructure();
				
				break;
			case 2: // order 10,000 integers
				loadList(rand10000, file10000);
				mergeSort(rand10000, 1, rand10000.getLength(), compCnt, swapCnt); // returns the original list ordered.
				rand10000.showStructure();
				break;
			case 3: // order 100,000 integers
				loadList(rand100000, file100000);
				mergeSort(rand100000, 1, rand100000.getLength(), compCnt, swapCnt); // returns the original list ordered.
				rand100000.showStructure();
				break;
			default:
				break;
			}
		} // end Merge Sort menu
		else { cout << "invalid input"; } // end if
		reset = quitMenu(); // resets program
	}
	return 0;
} // end main

int startMenu()
{
	cout << "\nThis program compares the time complexity of the selection sort and merge sort algorithms.";
	cout << "\nChoose between merge sort and selection sort to order up to 100,000 integers from 1 to 1,000,000.";
	cout << "\nMake a Selection : \n1) Selection Sort\n2) Merge Sort\nType value and press enter.\n";
	int value;
	cin >> value;
	return value;
} // end startMenu

int quitMenu()
{
	cout << "Would you like to restart the program?\n1) yes\n0) No\n";
	int value;
	cin >> value;
	return value;
} // end quitMenu

void loadList(LinkedList<int>& rand, string file)
{
	ifstream fin;
	fin.open(file);
	cout << "Reading into list..." << endl;
	int input; // value to hold file input
	int n = 1; // value of position
	while (!fin.eof())
	{
		fin >> input;
		rand.insert(n++, input);
	}
	cout << "list read successfully." << endl;
} // end loadlist

int findIndexOfLargest(LinkedList<int>& rand, int size, int& compCnt, int& swapCnt)
{
	int index = 1; // index of largest entry so far
	for (int currIndex = 2; currIndex < size; currIndex++)
	{
		if (rand.getEntry(currIndex) > rand.getEntry(index))
		{
			index = currIndex;
			compCnt++;
		}
	} // end for
	return index; // index of largest entry
} // end findIndextOfLargest

void selectionSort(LinkedList<int>& rand, SortedList<int>& ordered, int n, int& compCnt, int& swapCnt)
{
	for (int last = n - 1; last >= 1; last--)
	{
		int largest = findIndexOfLargest(rand, last + 1, compCnt, swapCnt);
		int p = rand.getEntry(largest);
		int q = rand.getEntry(last);
		rand.remove(largest);
		rand.remove(last);
		int temp = p; // swapping method for linked list.
		p = q;
		q = temp;
		ordered.insertSorted(q); // inserts smallest item
		swapCnt++;
	}
} // end selectionSort

void merge(LinkedList<int>& rand, int first, int mid, int last, int& compCnt, int& swapCnt)
{
	LinkedList<int> tempList; // Temporary array
// Initialize the local indices to indicate the subarrays
	int first1 = first; // Beginning of first subarray
	int last1 = mid; // End of first subarray
	int first2 = mid + 1; // Beginning of second subarray
	int last2 = last; // End of second subarray
	// While both subarrays are not empty, copy the smaller item into the
	// temporary list with temp values added to fill the positions

	for (int i = 1; i <= first; i++) // sets the initial positions of list.
	{
		tempList.insert(i, 0);
	}
	int index = first1; // next available location in tempArray
	while ((first1 <= last1) && (first2 <= last2))
	{
		// At this point, tempArray[first..index-1] is in order
		if (rand.getEntry(first1) <= rand.getEntry(first2))
		{
			tempList.insert(index, rand.getEntry(first1));
			first1++;
		}
		else
		{
			tempList.insert(index, rand.getEntry(first2));
			first2++;
		} // end if
		index++;
		compCnt++;
	} // end while

	while ((first1 <= last1))
	{
		// at this point, tempArray[first..index-1] is in order
		tempList.insert(index, rand.getEntry(first1));
		first1++;
		index++;
		compCnt++;
	} // end while
	// Finish off the second subarray, if necessary
	while (first2 <= last2)
	{
		// at this point, tempArray[first..index-1] is in order
		tempList.insert(index, rand.getEntry(first2));
		first2++;
		index++;
		compCnt++;
	} // end for

	// Copy the result back into the original array
	for (index = first; index <= last; index++)
	{
		rand.remove(index);
		rand.insert(index, tempList.getEntry(index));
		swapCnt++;
	}
} // end merge

void mergeSort(LinkedList<int>& rand, int first, int last, int& compCnt, int& swapCnt)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort(rand, first, mid, compCnt, swapCnt);
		mergeSort(rand, (mid + 1), last, compCnt, swapCnt);
		merge(rand, first, mid, last, compCnt, swapCnt);
	} // end if
} // end mergeSort