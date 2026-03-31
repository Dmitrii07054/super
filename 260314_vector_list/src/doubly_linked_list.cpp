#include "doubly_linked_list.hpp"

#include <iostream>

using dim::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node* current = begin;

	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}

	begin = nullptr;
	end = nullptr;
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept
{
	std::size_t count = 0;
	Node* current = begin;
	while (current != nullptr) {
		++count;
		current = current->next;
	}
	return count;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept
{
	Node* current = begin;

	while (current != nullptr) {

		if (current->value == value) {
			return true;
		}
		current = current->next;
	}

	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept
{
	if (begin == nullptr) {
		std::cout << "Empty!";

		return;
	}

	Node* current = begin;

	while (current != nullptr) {
		std::cout << "node = " << current->value << " -> ";
		current = current->next;
	}

	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value)
{
	Node* newNode = new Node(value);

	if (begin == nullptr) {
		begin = newNode;
		end = newNode;

		return;
	}

	Node* prevNode = end;
	prevNode->next = newNode;
	newNode->prev = prevNode;
	end = newNode;

}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept
{
	if (begin == nullptr) {
		std::cout << "Empty!" << std::endl;

		return false;
	}

	Node* current = begin;

	while (current != nullptr) {

		if (current->value != value) {
			current = current->next;

			continue;
		}

		if (begin == end) {
			begin = nullptr;
			end = nullptr;
		}

		else if (begin == current) {
			begin = current->next;
			begin->prev = nullptr;
		}

		else if (end == current) {
			end = current->prev;
			end->next = nullptr;
		}

		else {
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}

		delete current;
		std::cout << "Node " << value << "deleted" << std::endl;

		return true;
	}

	std::cout << "there is no node with " << value << std::endl;
	return false;
}
