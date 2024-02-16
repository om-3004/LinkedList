#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>

struct Node {
	int m_Data{ 0 };
	std::shared_ptr<Node> m_Next{ nullptr };

	Node() : m_Data{ 0 }, m_Next{ nullptr } {}
	Node(int data) : m_Data{ data }, m_Next{ nullptr } {}
};

class LinkedList {
	std::shared_ptr<Node> head;

public:
	LinkedList() : head{ nullptr } {}
	LinkedList(const std::initializer_list<int>&);

	void insertNodeStart(int);
	void insertNodeEnd(int);
	void insertNodePos(unsigned int, int );
	int getLength() const ;

	void deleteNodeStart();
	void deleteNodeEnd();
	void deleteNodePos(unsigned int);

	void displayList();
};


#endif