#include "../include/linkedlist.h";
#include <iostream>s

LinkedList::LinkedList(const std::initializer_list<int>& list) {
	for (auto& val : list) {
		insertNodeEnd(val);
	}
}

void LinkedList::insertNodeStart(int data) {
	if (head == nullptr) {
		head = std::make_shared<Node>(data);
		return;
	}
	auto newNode = std::make_shared<Node>(data);
	newNode->m_Next = head;
	head = newNode;
}

void LinkedList::insertNodeEnd(int data) {

	if (head == nullptr) {
		head = std::make_shared<Node>(data);
		return;
	}
	auto newNode = std::make_shared<Node> (data);
	auto temp = head;

	while (temp->m_Next != nullptr) {
		temp = temp->m_Next;
	}
	temp->m_Next = newNode;
}
void LinkedList::insertNodePos(unsigned int pos, int data) {
	if (pos == 1) {
		insertNodeStart(data);
		return;
	}
	if (pos == getLength()+1) {
		insertNodeEnd(data);
		return;
	}
	if (pos > getLength()) {
		std::cout << "Can't insert. Position is larger than size" << '\n';
		return;
	}

	auto temp = head;
	auto cnt{ 1 };
	while (cnt != pos-1) {
		temp = temp->m_Next;
		cnt++;
	}

	auto newNode = std::make_shared<Node>(data);
	newNode->m_Next = temp->m_Next;
	temp->m_Next = newNode;
}

int LinkedList::getLength() const {
	if (head == nullptr) {
		return 0;
	}
	if (head->m_Next == nullptr) {
		return 1;
	}
	auto len{ 0 };
	auto curr = head;

	while (curr != nullptr) {
		len++;
		curr = curr->m_Next;
	}

	return len;
}

void LinkedList::deleteNodeStart() {
	if (head == nullptr) {
		std::cout << "Can't delete, your Linked List is empty" << '\n';
		return;
	}
	if (head->m_Next == nullptr) {
		head = nullptr;
		return;
	}

	auto temp = head;
	head = head->m_Next;
	temp->m_Next = nullptr;
}

void LinkedList::deleteNodeEnd() {
	if (head == nullptr) {
		std::cout << "Can't delete. Your Linked List is empty" << '\n';
		return;
	}
	if (head->m_Next == nullptr) {
		head = nullptr;
		return;
	}

	auto curr = head;
	auto prev = curr;

	while (curr->m_Next != nullptr) {
		prev = curr;
		curr = curr->m_Next;
	}

	prev->m_Next = nullptr;
}

void LinkedList::deleteNodePos(unsigned int pos) {
	if (head == nullptr) {
		std::cout << "Can't delete. Your Linked List is empty" << '\n';
		return;
	}
	if (head->m_Next == nullptr && pos == 1) {
		head = nullptr;
		return;
	}

	if (pos > getLength()) {
		std::cout << "Can't delete. Entered position is out of range. Your linked list is of length: " << getLength() << '\n';
		return;
	}

	if (pos == 1) {
		head = head->m_Next;
		return;
	}

	auto cnt{ 1 };
	auto curr = head;
	auto prev = head;
	
	while (cnt != pos) {
		prev = curr;
		curr = curr->m_Next;
		cnt++;
	}

	prev->m_Next = curr->m_Next;
	curr->m_Next = nullptr;
}

void LinkedList::displayList() {
	if (head == nullptr) {
		std::cout << "Can't display. Your linked list is empty" << '\n';
		return;
	}

	auto temp = head;

	while (temp->m_Next != nullptr) {
		std::cout << temp->m_Data << "->";
		temp = temp->m_Next;
	}
	std::cout << temp->m_Data << '\n';
}