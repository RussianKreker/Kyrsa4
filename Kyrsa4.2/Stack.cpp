#include <stdexcept>
#include "iostream"
#include "Stack.h"

using namespace std;

void Stack::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

Stack::Stack()
{
	reset_list();
	size = 0;
}

Stack::~Stack()
{
}

void Stack::push_back(string newElem)
{

	if (size == 0) {
		head = new StackNode(newElem);
		tail = head;
	}
	else {
		tail->next = new StackNode(newElem, nullptr, tail);
		tail = tail->next;
	}
	size++;
}

string Stack::pop_back()
{
	string temp;

	if (size == 0) return " ";

	if (size == 1) {
		temp = head->data;
		delete head;
		reset_list();
	}
	else {
		temp = tail->data;
		StackNode* current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
	return temp;
}

string Stack::getTop()
{
	if (size == 0) return " ";
	return tail->data;
}

size_t Stack::get_size()
{
	return size;
}

void Stack::clear()
{
	StackNode* current = head->next;
	while (current->next != nullptr) {
		delete head;
		head = current;
		current = head->next;
	}
	delete head;
	delete tail;
	size = 0;
}

bool Stack::isEmpty() // if empty - true, else false
{
	return !size;
}