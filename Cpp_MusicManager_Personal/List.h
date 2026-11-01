#pragma once
#include "Node.h"
template <typename T>

class List //so we can do it automatically
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	bool empty() const
	{
		return head == nullptr;
	}
	
	// Inside your List class in List.h
	bool findAndEraseByID(int targetID) {
		Node<T>* current = head;

		while (current != nullptr) {
			if (current->data.getID() == targetID) {

				//head
				if (current == head) {
					head = current->next;
					if (head != nullptr) {
						head->prev = nullptr;
					}
					else {
						tail = nullptr; // List is now completely empty
					}
				}
				//tail
				else if (current == tail) {
					tail = current->prev;
					if (tail != nullptr) {
						tail->next = nullptr;
					}
					else {
						head = nullptr;
					}
				}
				//middle
				else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}

				//Delete the actual node from heap memory completely!
				delete current;
				size--;
				return true; 
				
			}
			current = current->next;
		}
		return false;
	}

	bool entryExist(int targetID)
	{
		Node<T>* current = head;

		while (current != nullptr) {
			if (current->data.getID() == targetID) {

				//head
				if (current == head) {
					head = current->next;
					if (head != nullptr) {
						head->prev = nullptr;
					}
					else {
						tail = nullptr; // List is now completely empty
					}
				}
				//tail
				else if (current == tail) {
					tail = current->prev;
					if (tail != nullptr) {
						tail->next = nullptr;
					}
					else {
						head = nullptr;
					}
				}
				//middle
				else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}

				cout << current->data << endl;


				size--;
				return true;

			}
			current = current->next;
		}
		return false;
	}

	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	~List()
	{
		//TODO- write code here
	}
	//public interface
	void push_back(T newData)
	{
		Node<T>* newnode = new Node<T>(newData);
		size++;

		if (tail == nullptr)
		{
			head = newnode;
			tail = newnode;

		}
		else
		{
			newnode->prev = tail;
			tail->next = newnode;

			tail = newnode;

		}
	}
	void push_front(T newData)
	{
		Node<T>* newnode = new Node<T>(newData); //new node in new address
		size++;

		if (head == nullptr)
		{
			head = newnode;

			tail = newnode;

		}
		else //basically similar to push_back 
		{
			head->prev = newnode;
			newnode->next = head;

			head = newnode;

		}
	}

	void pop_back()
	{
		if (tail == nullptr)
			throw exception("pop_back() ignored - list is empty");

		if (size == 1) {
			Node<T>* temp = head;
			head = tail = nullptr;
			size = 0;
			delete temp;
		}
		else {
			Node<T>* temp = tail;
			Node<T>* before = tail->prev;

			before->next = nullptr;
			tail = before;
			delete temp;
		}
		size--;
	}

	void pop_front()
	{

	}
	
	
	
	Node <T>* find(T searchKey)
	{
		Node<T>* curr = head;
		while (curr != nullptr)
		{

			if (curr->data == searchKey)
			{
				return curr;
			}
			curr = curr->next; //find the key until its found
		}
		return nullptr;

	}
	
	//
	//delete a node given its data value
	bool erase(T searchKey)
	{
		Node<T>* curr = find(searchKey);
		if (curr == nullptr)
		{
			return false; //didnt find
		}
		if (curr == head) {
			pop_front(); //easier
		}
		else if (curr == tail)
		{
			pop_back(); //easier
		}
		else
		{
			Node<T>* before = curr->prev;
			Node<T>* after = curr->next; //our neighbors 
			before->next = after;
			after->prev = before; //"goodbye" in betweener!

			delete curr;
			size--; //important last two.

		}

		return true;

	}

	//show list
	friend ostream& operator << (ostream& sout, const List& dl)
	{
		sout << "Personal Playlist: " <<
			"Size: " << dl.size << ", Starting Song Address: " << dl.head << ", Ending song Address: " << dl.tail << endl;

		//Traverse the list
		Node<T>* curr = dl.head; //start at head
		while (curr != nullptr)//the end
		{
			sout << "\t" << *curr << endl;
			curr = curr->next;

		}

		return sout;

	}

	
	



};



