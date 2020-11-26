/*****************************************************************//**
 * \file   Main.cpp
 * \brief  Solutions to linked-list exercises
 * \see	   https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_algorithm.htm
 * \author NMCG
 * \date   November 2020
 *********************************************************************/
#include <iostream>
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

//additional exercises using AdvancedDoubleLinkedList
void additionalExercise1();

int main()
{
	cout << "Exercises 1..." << endl;
	exercise1();
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