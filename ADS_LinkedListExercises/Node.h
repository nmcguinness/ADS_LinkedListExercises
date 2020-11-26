#pragma once

/// @brief a template class to store the data relevant to a node in the list
/// @tparam T Either a value or reference type (e.g. int, Student, list, map, vector)
template <typename T>
class Node {
public:
	/// @brief a pointer to the data being stored by the stored
	T data;

	/// @brief a pointer to the next node in the list
	Node* pNext;

	/// @brief a pointer to the last node in the list
	Node* pPrevious;

	/// @brief Constructs a new Node object with the data specified
	/// @param data
	Node(T data) {
		//store address of incoming data
		this->data = data;
		//initialize the pointers
		this->pNext = this->pPrevious = nullptr; //semi-colon
	}

	~Node() {
		//free both the pointers
		pNext = nullptr;
		pPrevious = nullptr;
		//	delete pNext;
		//	delete pPrevious;

		//set to default for data (e.g. nullptr for object, 0 for int, false for bool)
		data = T();
	}

	/// @brief Inserts a new Node object after this Node
	/// @param data Data to be stored by the new Node
	void insertAfter(T data)
	{
		Node<T>* temp = new Node<T>(data);
		temp->pPrevious = this;
		temp->pNext = this->pNext;
		if (this->pNext != nullptr)
		{
			this->pNext->pPrevious = temp;
		}
		this->pNext = temp;
	}

	/// @brief Inserts a new Node object before this Node
	/// @param data Data to be stored by the new Node
	void insertBefore(T data)
	{
		Node<T>* temp = new Node<T>(data);
		temp->pNext = this;
		temp->pPrevious = this->pPrevious;
		if (this->pPrevious != nullptr)
		{
			this->pPrevious->pNext = temp;
		}
		this->pPrevious = temp;
	}

	void printAllFromHead() {

		//write a little bit of code to traverse the nodes and print the data
		Node<T> current = *this;

		//move to the front of the node chain (i.e. to where there is no pPrevious)
		while (current.pPrevious != nullptr) {
			current = *current.pPrevious;
		}

		//now move from the head of the chain to the tail of the chain and print
		std::cout << current.data << std::endl;
		do {
			current = *current.pNext;
			std::cout << current.data << std::endl;
		} while (current.pNext != nullptr);
	}
};