#pragma once

#include "Node.h"

/// @brief a template class implementation of a simple double linked list that adds
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

	/// @brief Frees the data associated with each node in the list
	void clear() {
		Node<T>* pCurrent = this->pHead;

		while (pCurrent != nullptr) {
			//store address of the next
			Node<T>* pNext = pCurrent->pNext;

			//free the current by assigning to null
			pCurrent = nullptr;

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

	void append(T item)
	{
	}

	void prepend(T item)
	{
	}

	void removeHead()
	{
	}

	void removeTail()
	{
	}

	/// @brief Returns size of the number of elements in the list
	int size() const {
		return this->count;
	}

	//to do...
	//DoubleLinkedList(DoubleLinkedList<T>& list);
	//DoubleLinkedListIterator<T> getIterator();
	//void insert(DoubleLinkedListIterator<T>& iter, T item);
	//DoubleLinkedListIterator<T> remove(DoubleLinkedListIterator<T>& iter);
};