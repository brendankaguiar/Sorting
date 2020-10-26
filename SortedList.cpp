//--------------------------------------------------------------------
//
//  SortedList.cpp
// 
//  Method implementations for the link-based implementation with "is a" relationship
//
//--------------------------------------------------------------------

#include "SortedList.h"
template<class DataType>
SortedList<DataType>::SortedList()
{
} // end default constructor

template<class DataType>
SortedList<DataType>::SortedList(const SortedList<DataType>& sList) : LinkedList<DataType>(sList)
{
} // end copy constructor

template<class DataType>
SortedList<DataType>::~SortedList()
{
} // end destructor

template<class DataType>
bool SortedList<DataType>::insertSorted(const DataType& newEntry)
{
	int newPosition = std::abs(getPosition(newEntry));
	// We need to call the LinkedList version of insert, since the SortedList version does nothing but return false
	return LinkedList<DataType>::insert(newPosition, newEntry);
} // end insertSorted

template<class DataType>
bool SortedList<DataType>::removeSorted(const DataType& anEntry)
{
	int position = getPosition(anEntry);
	bool ableToRemove = position > 0;
	if (ableToRemove)
		ableToRemove = LinkedList<DataType>::remove(position); // Calls Linked List's remove function
	return ableToRemove;
} // end removeSorted

template<class DataType>
int SortedList<DataType>::getPosition(const DataType& anEntry) const
{
	int position = 1;
	int length = LinkedList<DataType>::getLength();
	while ((position <= length) && (anEntry > LinkedList<DataType>::getEntry(position)))
	{
		position++;
	} // end while
	if ((position > length) || (anEntry != LinkedList<DataType>::getEntry(position)))
	{
		position = -position;
	} // end if
	return position;
} // end getPosition

template<class DataType>
bool SortedList<DataType>::insert(int newPosition, const DataType& newEntry) // overrided to prevent position-based insert
{
	return false;
} // end insert