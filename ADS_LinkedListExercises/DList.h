#pragma once

/// @brief a template class to store the data relevant to a node in the list
/// @tparam T Either a value or reference type (e.g. int, Student)
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
/// @tparam T Either a value or reference type (e.g. int, Student)
template <typename T>
class DList {
private:
	/// @brief stores address of the first element
	Node* pHead;

	/// @brief stores address of the last element
	Node* pTail;

	/// @brief returns the number of elements in the list
	int size;

public:
	//constructor
	//push(???)
	//pop(???)
	//count()
	//print()
};