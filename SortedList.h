//--------------------------------------------------------------------
//
//  SortedList.h
// 
//  Class declaration for the link-based implementation with an "is a" relationship
//--------------------------------------------------------------------
#ifndef SORTED_LIST_IS_A_
#define SORTED_LIST_IS_A_
#include "LinkedList.h"
template<class DataType>
class SortedList : public LinkedList<DataType>
{
public:
	SortedList();
	SortedList(const SortedList<DataType>& sList);
	virtual ~SortedList();
	bool insertSorted(const DataType& newEntry);
	bool removeSorted(const DataType& anEntry);
	int getPosition(const DataType& anEntry) const;
	// The inherited methods remove, clear, getEntry, isEmpty, and getLength have the same specifications as in ListInterface
	// The following methods must be overridden to disable their effect on a sorted list
	bool insert(int newPosition, const DataType& newEntry) override;
}; // end SortedList

#endif