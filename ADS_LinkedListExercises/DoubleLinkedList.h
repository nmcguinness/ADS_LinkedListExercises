#pragma once

/// @brief a template class to store the data relevant to a node in the list
/// @tparam T Either a value or reference type (e.g. int, Student, list, map, vector)
template <typename T>
class Node {
public:
	/// @brief a pointer to the data being stored by the stored
	T* pData;

	/// @brief a pointer to the next node in the list
	Node* pNext;

	/// @brief a pointer to the last node in the list
	Node* pLast;
};

/// @brief a template class implementation of a double linked list
/// @tparam T Either a value or reference type (e.g. int, Student, list, map, vector)
template <typename T>
class DoubleLinkedList {
private:
	/// @brief stores address of the first element
	Node* pHead;

	/// @brief stores address of the last element
	Node* pTail;

	/// @brief returns the number of elements in the list
	int size;

public:
	//constructor

	/// @brief Prints all nodes in the list
	//print()

	/// @brief Pushes a new data element onto the end of the list
	//push(???)

	/// @brief Pushes a new data element onto the end of the list
	//pop(???)

	/// @brief Inserts a new data element at a valid user-defined index
	//insertAt()

	/// @brief Returns a data element at a valid user-defined index
	//getAt()

	/// @brief Removes a data element at a valid user-defined index
	//removeAt()

	/// @brief Returns a data element using a user-defined predicate function - see lambda, functor, and function<>
	//removeIf()

	/// @brief Removes all data elements across a valid user-defined range of indices (e.g. 0-2 removes the first three elements)
	//removeFrom()

	/// @brief Returns a count of the number of elements in the list
	//count()

	/// @brief Sorts the data elements using a user-defined predicate function - see function<bool(T, T)>
	//sort()
};