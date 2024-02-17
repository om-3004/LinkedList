#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>

template <typename T>
struct Node {
	T m_Data;
	std::shared_ptr<Node<T>> m_Next;

	Node(T data) : m_Data{ data }, m_Next{ nullptr } {}
};

template <typename T>
class LinkedList {
	std::shared_ptr<Node<T>> head;

public:
	LinkedList() : head{ nullptr } {}
	LinkedList(const std::initializer_list<T>&);

	void insertNodeStart(const T& data);
	void insertNodeEnd(const T& data);
	void insertNodePos(unsigned int pos, const T& data);
	unsigned int getLength() const ;

	void deleteNodeStart();
	void deleteNodeEnd();
	void deleteNodePos(unsigned int pos);

	void displayList();
};

//constructor taking initializer list as arguemnt
template <typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T>& list) {
	for (auto& val : list) {
		insertNodeEnd(val);
	}
}

template <typename T>
void LinkedList<T>::insertNodeStart(const T& data) {
	if (head == nullptr) {
		head = std::make_shared<Node<T>>(data);
		return;
	}
	auto newNode = std::make_shared<Node<T>>(data);
	newNode->m_Next = head;
	head = newNode;
}

template <typename T>
void LinkedList<T>::insertNodeEnd(const T& data) {

	if (head == nullptr) {
		head = std::make_shared<Node<T>>(data);
		return;
	}
	auto newNode = std::make_shared<Node<T>>(data);
	auto temp = head;

	while (temp->m_Next != nullptr) {
		temp = temp->m_Next;
	}
	temp->m_Next = newNode;
}

template <typename T>
void LinkedList<T>::insertNodePos(unsigned int pos, const T& data) {
	if (pos == 1) {
		insertNodeStart(data);
		return;
	}
	if (pos == getLength() + 1) {
		insertNodeEnd(data);
		return;
	}
	if (pos > getLength()) {
		std::cout << "Can't insert. Position is larger than size" << '\n';
		return;
	}

	auto temp = head;
	auto cnt{ 1 };
	while (cnt != pos - 1) {
		temp = temp->m_Next;
		cnt++;
	}

	auto newNode = std::make_shared<Node<T>>(data);
	newNode->m_Next = temp->m_Next;
	temp->m_Next = newNode;
}

template <typename T>
unsigned int LinkedList<T>::getLength() const {
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

template <typename T>
void LinkedList<T>::deleteNodeStart() {
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

template <typename T>
void LinkedList<T>::deleteNodeEnd() {
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

template <typename T>
void LinkedList<T>::deleteNodePos(unsigned int pos) {
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

template <typename T>
void LinkedList<T>::displayList() {
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

#endif