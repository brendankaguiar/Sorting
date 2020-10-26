//--------------------------------------------------------------------
//
//  LinkedList.h
// 
//  Class declaration for the link-based implementation of the ListInterface ADT.
//
//--------------------------------------------------------------------

#ifndef LinkedList_H
#define LinkedList_H

#include "ListInterface.h"


template <typename DataType>
class LinkedList : public ListInterface<DataType> {

public:

	LinkedList();
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	virtual ~LinkedList();

	bool insert(int newPosition, const DataType& newDataItem);
	bool remove(int position);
	int getLength() const;
	bool isEmpty() const;
	void clear();
	DataType getEntry(int position) const throw (logic_error);

	void showStructure() const;

private:
	class Node {
	public:
		Node(const DataType& nodeData, Node* nextPtr);

		DataType dataItem;
		Node* next;
		auto getNext() const->Node*;
		void setNext(Node*);
	};
	Node* headPtr;
	int itemCount;
	auto getNodeAt(int position)  const throw (logic_error)->Node*;
};
#endif		//#ifndef LinkedList_H