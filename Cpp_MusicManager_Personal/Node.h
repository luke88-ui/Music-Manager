#pragma once
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
struct Node
{
	//Data Member
	T data;
	Node <T>* prev;
	Node <T>* next;

	//constructor

	Node(T newData)
	{
		data = newData;
		prev = nullptr;
		next = nullptr;

	}

	//show node
	friend ostream& operator << (ostream& sout, const Node<T>& n)
	{
		sout << &n << " Node [ prev: " << n.prev << ", next: " << n.next << ", data: " << n.data << "]";
		//'this' dont work for this case, so use &n
		return sout;

	}
};
