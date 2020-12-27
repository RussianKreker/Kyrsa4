#pragma once
#include <string>

using namespace std;

class Stack
{
private:

	void reset_list();

	class StackNode
	{
	public:
		StackNode(string data, StackNode* next = nullptr, StackNode* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		~StackNode() {}

		string data;
		StackNode* next;
		StackNode* prev;
	};

	StackNode* head;
	StackNode* tail;
	size_t size;

public:
	Stack();
	~Stack();

	void push_back(string newElem);
	string pop_back();
	string getTop();
	size_t get_size();
	void clear();
	bool isEmpty();
};