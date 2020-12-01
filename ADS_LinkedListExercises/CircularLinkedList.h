#pragma once

#include "Node.h"

/// @brief a template class implementation of a double linked list
/// @tparam T Either a value or reference type (e.g. int, Student, list, map, vector)
template <typename T>
class CircularLinkedList {
	/// @brief stores address of the first element
	Node<T>* pHead;

	/// @brief stores address of the last element
	Node<T>* pTail;

	/// @brief returns the number of elements in the list
	int count;

public:

	/// @brief Construct the list and initialize the member variables
	CircularLinkedList() {
		//set the head and tail to null and set the count to 0
		this->pHead = nullptr;
		this->pTail = nullptr;
		this->count = 0;
	}

	/// @brief Frees the data associated with each node in the list
	~CircularLinkedList() {
		clear();
	}

	/// @brief Frees the data associated with each node in the list
	void clear() {
		Node<T>* pCurrent = this->pHead;

		while (pCurrent->pNext != pHead) {
			//store address of the next
			Node<T>* pNext = pCurrent->pNext;

			//free the memory - see https://www.geeksforgeeks.org/delete-in-c/#:~:text=Delete%20is%20an%20operator%20that,are%20created%20by%20new%20expression.&text=New%20operator%20is%20used%20for,operator%20deallocates%20memory%20from%20heap.
			delete pCurrent;

			//move to the next
			pCurrent = pNext;
		}

		//delete the last element not covered by the loop above
		delete this->pTail;

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

	//add to the tail of the linked list
	void append(T data)
	{
		//if list is empty then set it up
		if (pHead == nullptr) {
			pHead = pTail = new Node<T>(data);
			//if this is a circular linked list
			pHead->pPrevious = pTail;
		}
		else {
			pTail->insertAfter(data);
			//pTail now becomes the newly added Node
			pTail = pTail->pNext;
		}

		//this node now points to the head node (since we are making a circular linked list)
		pTail->pNext = pHead;

		//increase list size
		count++;
	}

	//add to the head of the linked list
	void prepend(T data)
	{
		if (pHead == nullptr) {
			pHead = pTail = new Node<T>(data);
			pHead->pPrevious = pTail;
			pTail->pNext = pHead;
		}
		else {
			pHead->insertBefore(data);
			pHead = pHead->pPrevious;
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
			pHead->previous = pTail;

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
			pTail->next = pHead;

			delete pTemp;
			pTemp = nullptr;
		}
	}

	/// @brief Returns size of the number of elements in the list
	int size() const {
		return this->count;
	}
};