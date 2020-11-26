#pragma once
#include "Node.h"

/// @brief a template class implementation of an advanced double linked list that adds
/// @tparam T Either a value or reference type (e.g. int, Student, list, map, vector)
template <typename T>
class AdvancedDoubleLinkedList {
private:
	/// @brief stores address of the first element
	Node<T>* pHead;

	/// @brief stores address of the last element
	Node<T>* pTail;

	/// @brief returns the number of elements in the list
	int count;

public:

	/// @brief Construct the list and initialize the member variables
	AdvancedDoubleLinkedList() {
		//set the head and tail to null and set the count to 0
		this->pHead = nullptr;
		this->pTail = nullptr;
		this->count = 0;
	}

	/// @brief Frees the data associated with each node in the list
	~AdvancedDoubleLinkedList() {
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

	/// @brief Pushes a new data element onto the end of the list
	void push(T data) {
		Node<T>* pNew = new Node<T>(data);

		if (pHead == nullptr) {
			pHead = pNew;
		}
		else { //A, B, C, D, nullptr
			Node<T>* pCurrent = this->pHead;

			//loop through until we reach a node that has no pNext (i.e. the last node)
			while (pCurrent->pNext != nullptr) {
				pCurrent = pCurrent->pNext;
			}

			pNew->pPrevious = pCurrent; //attach pLast of new node to previous node
			pCurrent->pNext = pNew; //attach pNext of previous node to new node
			pTail = pNew;			//set the tail to be the new node
		}

		//increment list count
		this->count++;
	}

	/// @brief Pops and returns the last data element from the end of the list
	T pop() {
		//to do...
		return T(); //return default type for T (e.g. int = 0, bool = false, string = "", Student())
	}

	/// @brief Inserts a new data element at a valid user-defined index
	bool insertAt(T data, int index) {
		if (index < 0 || index > this->count)
			throw std::out_of_range("index is invalid!");

		//load the first node
		Node<T>* pCurrent = this->pHead;

		int currentIndex = 0;

		//loop through until we reach a node that has no pNext (i.e. the last node)
		while (pCurrent->pNext != nullptr && currentIndex != index) {
			pCurrent = pCurrent->pNext;
			currentIndex++;
		}

		Node<T>* pNew = new Node<T>(data);
		if (pCurrent->pPrevious != nullptr)
			pCurrent->pPrevious->pNext = pNew;
		else
			pHead = pNew;

		pNew->pNext = pCurrent;
		pCurrent->pPrevious = pNew;

		this->count++;

		return true;
	}

	/// @brief Returns a data element at a valid user-defined index
	//getAt()

	/// @brief Removes a data element at a valid user-defined index
	//removeAt()

	/// @brief Returns a data element using a user-defined predicate function - see lambda, functor, and function<>
	//removeIf()

	/// @brief Removes all data elements across a valid user-defined range of indices (e.g. 0-2 removes the first three elements)
	//removeFrom()

	/// @brief Returns size of the number of elements in the list
	int size() const {
		return this->count;
	}

	//REMOVE - WE WONT ADD THIS METHOD - NOT ENOUGH TIME!
	/// @brief Sorts the data elements using a user-defined predicate function - see function<bool(T, T)>
	//sort()
};