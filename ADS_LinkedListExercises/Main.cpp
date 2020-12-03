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
#include "Song.h"

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
	cout << endl << "Exercises 1 - Implement a Doubly Linked List..." << endl;
	exercise1();

	cout << endl << "Exercises 2 - Modify the Doubly linked list to be a circular linked list..." << endl;
	exercise2();

	cout << endl << "Exercises 3 - Using your Circular linked list, implement a playlist for a Digital audio player..." << endl;
	exercise3();

	cout << endl << "Exercises 4 - Using your doubly linked list, write an application that asks a user to input three numbers..." << endl;
	exercise4();

	cout << endl << "Exercises 5 - Write an application to add 10 values to a linked list remove all odd numbers and display it..." << endl;
	exercise5();

	cout << endl << "Exercises 6 - Write an algorithm to insert an element into the first position of an array..." << endl;
	exercise6();

	cout << endl << "Exercises 7 - Using the algorithm in five, measure how long it takes to add 10, 100, 1,000, 10,000 and 100, 000 elements into this array..." << endl;
	exercise7();
}

/************************** Linked List Exercises **************************/

/// @brief Implement a Doubly Linked List
void exercise1()
{
	//anna, bea, ciara, david (FIFO)
	DoubleLinkedList<string> dList;
	dList.append("anna");
	dList.append("bea");
	dList.append("ciara");
	dList.append("david");
}

/// @brief Modify the Doubly linked list to be a circular linked list.
void exercise2()
{
	//david, ciara, bea, anna (LIFO)
	CircularLinkedList<string> cList;
	cList.prepend("anna");
	cList.prepend("bea");
	cList.prepend("ciara");
	cList.prepend("david");
}

/// @brief Using your Circular linked list, implement a playlist for a Digital audio player.
void exercise3()
{
	cout << endl << "********************* A list of references to Song objects *********************" << endl;

	CircularLinkedList<Song> sList;
	sList.append(Song("the twist"));
	sList.append(Song("smells like teen spirit"));
	sList.append(Song("kashmir"));
	sList.append(Song("something"));

	//how do we access/play the songs?
	CircularLinkedListIterator<Song> it1 = sList.getIterator(sList.getHead());
	for (int i = 0; i < sList.size(); i++) {
		cout << it1.item() << endl;
		it1.next();
	}

	cout << endl << "********************* A list of pointers to Song objects *********************" << endl;

	CircularLinkedList<Song*> sListWithPointers;
	sListWithPointers.append(new Song("Like A Prayer"));
	sListWithPointers.append(new Song("Uptown Funk"));
	sListWithPointers.append(new Song("Shake It Off"));

	//how do we access/play the songs?
	CircularLinkedListIterator<Song*> it2 = sListWithPointers.getIterator(sListWithPointers.getHead());
	for (int i = 0; i < sListWithPointers.size(); i++) {
		//we need to * (dereference) the item because its a pointer to a Song (i.e. Song*) and not a reference to a Song
		cout << *it2.item() << endl;
		it2.next();
	}
}

/// @brief Using your doubly linked list, write an application that asks a user to input three numbers and print them out in reverse order
void exercise4()
{
	int size = 0;
	int number = 0;
	DoubleLinkedList<int> numList;

	cout << "How many numbers do you want to enter?" << endl;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Enter number " << (i + 1) << ":" << endl;
		cin >> number;
		numList.append(number);
	}

	DoubleLinkedListIterator<int> it = numList.getIterator(numList.getTail());

	for (int i = 0; i < numList.size(); i++) {
		cout << it.item() << endl;
		it.previous();
	}
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