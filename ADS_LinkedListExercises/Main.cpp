/*****************************************************************//**
 * \file   Main.cpp
 * \brief  Solutions to linked-list exercises
 * \see	   https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_algorithm.htm
 * \author NMCG
 * \date   November 2020
 *********************************************************************/
#include <iostream>
#include "DoubleLinkedList.h"
#include "CircularLinkedList.h"
#include "AdvancedDoubleLinkedList.h"

using namespace std;

//core exercises
void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();
void exercise7();

//additional exercises using AdvancedDoubleLinkedList NOT listed in Exercises PDF in Moodle
void additionalExercise1();
void additionalExercise2();
template <typename T>
void printAllFromHead(Node<T> node);

int main()
{
	cout << "Exercises 1 - Implement a Doubly Linked List..." << endl;
	exercise1();

	cout << "Exercises 2 - Modify the Doubly linked list to be a circular linked list..." << endl;
	exercise2();

	cout << "Exercises 3 - Using your Circular linked list, implement a playlist for a Digital audio player..." << endl;
	exercise3();

	cout << "Exercises 4 - Using your doubly linked list, write an application that asks a user to input three numbers..." << endl;
	exercise4();

	cout << "Additional Exercises..." << endl;
	//additionalExercise2();
}

/************************** Linked List Exercises **************************/

/// @brief Implement a Doubly Linked List
void exercise1()
{
}

/// @brief Modify the Doubly linked list to be a circular linked list.
void exercise2()
{
}

/// @brief Using your Circular linked list, implement a playlist for a Digital audio player.
void exercise3()
{
}

/// @brief Using your doubly linked list, write an application that asks a user to input three numbers and print them out in reverse order
void exercise4()
{
}

/// @brief Write an application to add 10 values to a linked list remove all odd numbers and display it.
void exercise5()
{
}

/// @brief Write an algorithm to insert an element into the first position of an array
void exercise6()
{
}

/// @brief Using the algorithm in five, measure how long it takes to add 10, 100, 1,000, 10,000 and 100, 000 elements into this array.Compare this performance to adding these elements to the head of your linked list.
void exercise7()
{
}

/******************************** Additional Exercises ********************************/

void additionalExercise1()
{
	AdvancedDoubleLinkedList<int> dList;

	/*************************** Testing: push, print, size, clear ***************************/

	//pushing to the list
	dList.push(10);
	dList.push(20);
	dList.push(30);
	dList.push(40);

	//printing the list
	dList.print();

	//show the size
	std::cout << "Size(before clear): " << dList.size() << std::endl;

	//clear the list of contents and free RAM
	dList.clear();

	//show the size
	std::cout << "Size(after clear): " << dList.size() << std::endl;
}

/// @brief Playing with the Node insertBefore() and insertAfter()
void additionalExercise2()
{
	//declare a single Node and put a value of any type inside
	Node<string> node1("monday");

	//add 3 more Nodes (also with data inside) and use 1x insertBefore, 1x insertAfter, 2x of either
	node1.insertBefore("is");
	node1.insertAfter("day?");
	node1.insertAfter("best");
	node1.insertAfter("the");

	//write a little bit of code to traverse the nodes and print the data
	printAllFromHead(node1);

	//call the new method inside Node class
	node1.printAllFromHead();
}

template <typename T>
void printAllFromHead(Node<T> node) {
	//write a little bit of code to traverse the nodes and print the data
	Node<string> current = node;

	//move to the front of the node chain (i.e. to where there is no pPrevious)
	while (current.pPrevious != nullptr) {
		current = *current.pPrevious;
	}

	//now move from the head of the chain to the tail of the chain and print
	cout << current.data << endl;
	do {
		current = *current.pNext;
		cout << current.data << endl;
	} while (current.pNext != nullptr);
}