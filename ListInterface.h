//--------------------------------------------------------------------
//
//   ListInterface.h
// 
//  Class declaration of the abstract class interface to be used as
//  the basis for implementations of the ListInterface ADT.
//
//--------------------------------------------------------------------

#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

template <typename DataType>
class ListInterface {
public:

	virtual ~ListInterface();
	virtual bool insert(int newPosition, const DataType& newDataItem) = 0;
	virtual bool remove(int position) = 0;
	virtual int getLength() const = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual DataType getEntry(int position) const throw (logic_error) = 0;

	virtual void showStructure() const = 0; //used only for test purposes
};

template <typename DataType>
ListInterface<DataType>::~ListInterface()
// Not worth having a separate class implementation file for the destuctor
{}

#endif	