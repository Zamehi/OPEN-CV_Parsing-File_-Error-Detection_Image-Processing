#pragma once
/*Name : Zunaira Amir   ,    email:  i210780@nu.edu.pk*/
#include <iostream>
using namespace std;


// ****************************************************************************
//                                   STACK
template<class T>
struct Node
{
	Node* next_add;
	T data;

};
template<class T>
class Stack
{
private:

	Node<T>* head;
	Node<T>* tail;
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
	void push(T data)
	{
		Node<T>* temp = new Node<T>;
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

	// ----------------------------------------------- POP --------------------------------------
	void pop()
	{
		if (head->next_add == NULL)
		{
			head = NULL;
			size--;

		}
		else
		{
			Node<T>* temp;
			temp = head;
			head = head->next_add;
			delete temp;
			size--;
		}

	}
	// ---------------------------------------------- SEARCH -------------------------------------
	int search(int value)
	{
		Node<T>* ptr = new Node<T>;
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
		Node<T>* ptr = new Node<T>;
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
		Node<T>* current = head;
		while (current != NULL)
		{
			Node<T>* temp = current;
			current = current->next_add;
			delete temp;
		}
	}

	// -------------------------------------------  DISPLAY  ----------------------------------------
	void display()
	{
		Node<T>* current = new Node<T>;
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
	T get_data()
	{
		return head->data;
	}
	Node<T>* get_head()
	{
		return this->head;
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
	// ---------------------------------------------- INSERTION ------------------------------------------
	void insert(int index, T value)
	{
		int ind = 0;
		Node<T>* temp = new Node<T>;
		temp->data = value;

		if (index == 0)
		{
			// --------------
			//Node* temp = new Node;		
			if (head == NULL)
			{
				head = temp;
				temp->next_add = NULL;
				tail = temp;
				size++;
			}
			else
			{
				temp->next_add = head;
				size++;
			}
			head = temp;
		}
		else
		{
			Node<T>* ptr = new Node<T>;
			Node<T>* ptr2 = new Node<T>;
			ptr2 = head, ptr = head;
			// Traversing
			while (ptr2->next_add != NULL)
			{
				if (ind == index)
				{
					break;
				}
				ptr2 = ptr2->next_add;
				ind++;

			}
			
		
				temp->next_add = ptr->next_add;
				ptr->next_add = temp;
				size++;
		

		}
	}

	// Ordered Insertion
	int insert_at(int val) 
	{
		int index = 0;
		Node<T>* ptr = new Node<T>;
		Node<T>* ptr2 = new Node<T>;
		ptr2 = head, ptr = head;
		// traversing through the whole queue
		while (ptr2->next_add != NULL)
		{
			ptr = ptr2;
			index++;
			ptr2 = ptr2->next_add;
			if (ptr->data > val && ptr2->data < val) 
			{
				return index;
			}
		}
	}

	// ----------------------------------------------- ENQUE -------------------------------------
	void enque(T d)
	{
		// insert at end
		Node<T>* temp = new Node<T>;
		temp->data = d;
		temp->next_add = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			size++;
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
		Node<T>* temp = head;
		head = head->next_add;
		size--;
		delete temp;
	}
};

