//--------------------------------------------------------------------
//
//  LinkedList.cpp
// 
//  Method implementations for the link-based implementation of the Stack ADT.
//
//--------------------------------------------------------------------

#include "LinkedList.h"
template <typename DataType>
LinkedList<DataType>::LinkedList() :headPtr(nullptr), itemCount(0)
{}
// end LinkedList constructor

template <typename DataType>
LinkedList<DataType>::Node::Node(const DataType& nodeData, Node* nextPtr) : dataItem(nodeData), next(nextPtr)
{}
// end Node constructor

template<typename DataType>
LinkedList<DataType>::LinkedList(const LinkedList& other)
{
	*this = other; // uses overloaded operator
} // end Copy Constructor

template <typename DataType>
LinkedList<DataType>::~LinkedList()
{
	clear();
} // end destructor

template<typename DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList& other)
{  // creates new node instantiated with other stack and this stack's headPtr
   // ends when other stack points to nullptr
	for (Node* temp = other.headPtr; temp != nullptr; temp = temp->next) {
		Node* NextNewNodePtr = new Node(temp->dataItem, headPtr);
		headPtr = NextNewNodePtr;
		itemCount++;
	} // end for
	return *this;
} // end Copy Constructor



template<class DataType>
void LinkedList<DataType>::Node::setNext(Node* nextPtr)
{
	next = nextPtr;
} // end setNext

template<class DataType>
auto LinkedList<DataType>::Node::getNext() const -> Node*
{
	return next;
} // end getNext

template<class DataType>
auto LinkedList<DataType>::getNodeAt(int position) const throw (logic_error) -> Node*
{
	// debugging check of precondition
	if ((position >= 1) && (position <= itemCount))
	{
		// Count from the beginning of the chain to the node's position
		Node* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++)
			curPtr = curPtr->getNext();
		return curPtr;
	}
	else
		throw logic_error("Position error.");
} // end getNodeAt

template <typename DataType>
bool LinkedList<DataType>::insert(int newPosition, const DataType& newDataItem)
{ // pushes newDataItem onto stack and points headPtr to nextNode
	bool ableToInsert = ((newPosition >= 1) && (newPosition <= itemCount + 1));
	if (ableToInsert)
	{
		// Create a new node containing the new entry
		// Attach a new node to chain
		if (newPosition == 1)
		{
			// Insert new node at beginning of chain
			Node* newNodePtr = new Node(newDataItem, headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			// Insert new node to take the previous position
			// Point previous node to new node
			Node* prevPtr = getNodeAt(newPosition - 1);
			Node* newNodePtr = new Node(newDataItem, prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++; // Increase count of entries
	} // end if
	return ableToInsert;
} // end insert

template<typename DataType>
bool LinkedList<DataType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			// Find node that is before the one to remove 
			Node* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			curPtr = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(curPtr->getNext());
		} // end if
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--; // Decrease itemCount
	} // end if
	return ableToRemove;
} // end remove

template <typename DataType>
int LinkedList<DataType>::getLength() const
{
	return itemCount;
} // end GetLength

template <typename DataType>
bool LinkedList<DataType>::isEmpty() const
{
	if (itemCount == 0)
		return true;
	else
		return false;
} // end isEmpty

template<typename DataType>
void LinkedList<DataType>::clear()
{ // clears node.
	while (!isEmpty())
	{
		remove(1); // uses remove() to clear
	} // end while
} // end clear

template<typename DataType>
DataType LinkedList<DataType>::getEntry(int position) const throw (logic_error)
{
	// enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node* nodePtr = getNodeAt(position);
		return nodePtr->dataItem;
	}
	else
		throw logic_error("Invalid entry.");
}

template <typename DataType>
void LinkedList<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Top\t";
		for (Node* temp = headPtr; temp != nullptr; temp = temp->next) {
			if (temp == headPtr) {
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}
} // end showStructure