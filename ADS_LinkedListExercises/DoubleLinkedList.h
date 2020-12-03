template <class T> class DoubleLinkedListIterator;
template <class T> class DoubleLinkedList;

#pragma once
#include "Node.h"

/// @brief a template class implementation of a double linked list
/// @tparam T Either a value or reference type (e.g. int, Student, list, map, vector)
template <typename T>
class DoubleLinkedList {
	/// @brief stores address of the first element
	Node<T>* pHead;

	/// @brief stores address of the last element
	Node<T>* pTail;

	/// @brief returns the number of elements in the list
	int count;

public:

	/// @brief Construct the list and initialize the member variables
	DoubleLinkedList() {
		//set the head and tail to null and set the count to 0
		this->pHead = nullptr;
		this->pTail = nullptr;
		this->count = 0;
	}

	/// @brief Frees the data associated with each node in the list
	~DoubleLinkedList() {
		clear();
	}

#pragma region Access & Modify List Methods

	//add to the tail of the linked list
	void append(T data)
	{
		//if list is empty then set it up
		if (pHead == nullptr) {
			pHead = pTail = new Node<T>(data);
		}
		else {
			pTail->insertAfter(data);
			//pTail now becomes the newly added Node
			pTail = pTail->pNext;
		}

		//increase list size
		count++;
	}

	//add to the head of the linked list
	void prepend(T data)
	{
		if (pHead == nullptr) {
			pHead = pTail = new Node<T>(data);
		}
		else {
			pHead->insertBefore(data);
		}

		//increase list size
		count++;
	}

	void removeHead()
	{
		if (pHead == nullptr)
			return;

		if (pHead == pTail)
		{
			count--;

			delete pHead;
			pHead = pTail = nullptr;
		}
		else
		{
			count--;

			Node<T>* pTemp = pHead;
			pHead = pHead->next;

			delete pTemp;
			pTemp = nullptr;
		}
	}

	void removeTail()
	{
		if (pHead == nullptr)
		{
			return;
		}
		else if (pHead == pTail)
		{
			count--;

			delete pTail;
			pHead = pTail = nullptr;
		}
		else
		{
			count--;

			Node<T>* pTemp = pTail;
			pTail = pTail->previous;

			delete pTemp;
			pTemp = nullptr;
		}
	}

	/// @brief Returns size of the number of elements in the list
	int size() const {
		return this->count;
	}

	/// @brief Frees the data associated with each node in the list
	void clear() {
		Node<T>* pCurrent = this->pHead;

		while (pCurrent != nullptr) {
			//store address of the next
			Node<T>* pNext = pCurrent->pNext;

			//free the memory - see https://www.geeksforgeeks.org/delete-in-c/#:~:text=Delete%20is%20an%20operator%20that,are%20created%20by%20new%20expression.&text=New%20operator%20is%20used%20for,operator%20deallocates%20memory%20from%20heap.
			delete pCurrent;

			//move to the next
			pCurrent = pNext;
		}

		//set the head and tail to null and set the count to 0
		this->pHead = nullptr;
		this->pTail = nullptr;
		this->count = 0;
	}

	/// @brief Prints all nodes in the list
	void print() const {
		Node<T>* pCurrent = this->pHead; //A, B, C

		while (pCurrent != nullptr) {
			std::cout << pCurrent->data << std::endl;
			pCurrent = pCurrent->pNext;
		}
	}
#pragma endregion

#pragma region Iterator Specific Methods
	/// @brief Returns an iterator (i.e. a pointer to the specified node within the list) which we use to access each value using it.item()
/// @return An ierator for the list
	DoubleLinkedListIterator<T> getIterator(Node<T>* pNode) {
		return DoubleLinkedListIterator<T>(this, pNode);
	}

	/// @brief Returns a pointer to the head of the list - used by DoubleLinkedListIterator
	/// @return Pointer to the head Node
	Node<T>* getHead() const {
		return this->pHead;
	}

	/// @brief Returns a pointer to the tail of the list - used by DoubleLinkedListIterator
	/// @return Pointer to the tail Node
	Node<T>* getTail() const {
		return this->pTail;
	}
#pragma endregion
};

/// @brief Creates a iterator for a double linked list
/// @tparam T
template <class T>
class DoubleLinkedListIterator {
public:
	Node<T>* pCurrentNode;
	DoubleLinkedList<T>* pList;

	DoubleLinkedListIterator(DoubleLinkedList<T>* pList, Node<T>* node) {
		this->pList = pList;
		this->pCurrentNode = node;
	}

	void next()
	{
		if (pCurrentNode == nullptr)
			return;
		pCurrentNode = pCurrentNode->pNext;
	}
	void previous()
	{
		if (pCurrentNode == nullptr)
			return;
		pCurrentNode = pCurrentNode->pPrevious;
	}
	T item() {
		return pCurrentNode->data;
	}

	bool isEnd() {
		return pCurrentNode == pList->getTail();
	}
	bool isStart() {
		return pCurrentNode == pList->getHead();
	}
};