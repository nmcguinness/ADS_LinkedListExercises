#pragma once

template <typename T>
class Node {
public:
	T* pData;
	Node* pNext;
	Node* pLast;
};

template <typename T>
class DList {
private:
	Node* pHead;
	//int count; do we need?

public:
	//constructor
	//push(???)
	//pop(???)
	//count()
	//print()
};