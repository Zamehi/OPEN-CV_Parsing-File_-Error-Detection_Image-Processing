#pragma once
#include <iostream>
using namespace std;


// ****************************************************************************
//                                   STACK
struct node
{
	node* next_add;
	int data;

};



class Stack
{
private:

	node* head;
	node* tail;
	int size;
public:
	// Constructor
	Stack()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	// ---------------------------------------------- PUSH ------------------------------------
	void push(int data)
	{
		node* temp = new node;
		temp->data = data;
		if (head == NULL)
		{
			head = temp;
			head->next_add = NULL;
			size++;

		}
		else
		{
			temp->next_add = head;
			head = temp;
			size++;
		}
	}

	// ----------------------------------------------- POP ---------------------------------------
	void pop()
	{
		if (head->next_add == NULL)
		{
			head = NULL;
			size--;

		}
		else
		{
			node* temp;
			temp = head;
			head = head->next_add;
			delete temp;
			size--;
		}

	}






	// *******************************************************************************************
	// Queue Properties
	// ----------------------------------------------- ENQUE -------------------------------------
	void enque(int d1) 
	{
		// insert at end
		node* temp = new node;
		temp->data = d1;
		//temp->data2 = d2;
		temp->next_add = NULL;
		if (head == NULL) 
		{
			head = tail = temp;

		}
		else 
		{
			tail->next_add = temp;
			tail = temp;
			size++;
		}
	}

	// ---------------------------------------------- DEQUE --------------------------------------
	void deque() 
	{
		// delete from start
		node* temp = head;
		head = head->next_add;
		size--;
		delete temp;
	}
	// ---------------------------------------------- SEARCH -------------------------------------
	int search(int value)
	{
		node* ptr = new node;
		ptr = head;
		int ind = 0;
		while (ptr->next_add != NULL)
		{
			ptr = ptr->next_add;
			ind++;
			if (ptr->data == value)
			{
				return ind;
			}

		}
		return -1;


	}

	// ----------------------------------------------  UPDATE  -------------------------------------
	bool update(int index, int value)
	{
		node* ptr = new node;
		ptr = head;
		int ind = 0;
		int check = 0;
		while (ptr->next_add != NULL)
		{
			ptr = ptr->next_add;
			ind++;
			if (ind == index)
			{
				ptr->data = value;
				return true;

			}
			else
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
		{
			return false;
		}

	}

	// -------------------------------------------  Destructor  -------------------------------------
	~Stack(void)
	{
		node* current = head;
		while (current != NULL)
		{
			node* temp = current;
			current = current->next_add;
			delete temp;
		}
	}

	// -------------------------------------------  DISPLAY  ----------------------------------------
	void display()
	{
		node * current = new node ;
		current = head;
		while (current->next_add != NULL)
		{
			cout << current->data << " ";
			if (current->next_add != NULL)
			{
				current = current->next_add;
			}
		}
		cout << current->data << " ";
		cout << endl;
	}

	// -------------------------------------------  get data  ---------------------------------------
	int get_data()
	{
		return head->data;
	}

	node * get_head()
	{
		return this->head;
	}
	node* get_tail() 
	{
		return this->tail;
	}
	int get_size()
	{
		return size;
	}
	// ------------------------------------------- overloaded data ----------------------------------
	void operator = (const Stack& D)
	{
		this->head = D.head;
		this->size = D.size;
	}
};

