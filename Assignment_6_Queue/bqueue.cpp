#include "bqueue.h"

//*************************************************************************************
//Name:  BQUEUE (Default)
//Precondition: No precondition
//Postcondition: A circular queue with the data being NULL 
//Description:  This will allocate memory and set the data members of a circular queue
//
//*************************************************************************************
BQUEUE::BQUEUE()
{
	cout << "Default Constructor Invoked" << endl;

	back = new bqnode;

	back->next = back;
	back->prev = back;
	back->time = NULL;

}

//*************************************************************************************
//Name:  ~BQUEUE (Destructor)
//Precondition: A circular queue
//Postcondition: Deleted circular queue  
//Description:  This will give the memory given to the circular queue back to the system 
//
//*************************************************************************************
BQUEUE::~BQUEUE()
{
	cout << "Destructor Invoked" << endl;

	if (back == NULL)
	{
		Dequeue();
	}
}

//*************************************************************************************
//Name:  BQUEUE (Copy)
//Precondition: A circular queue
//Postcondition: A copy of that circular queue 
//Description:  This will make a deep copy of a circular queue
//
//*************************************************************************************
BQUEUE::BQUEUE(const BQUEUE & Obj)
{
	cout << "Copy Constructor Invoked" << endl;

	back = new bqnode;

	back->next = back;
	back->prev = back;
	back->time = NULL;

	bqnode *temp = Obj.back->next;

	while (temp != Obj.back)
	{
		if (back->time == NULL)
		{
			back->time = temp->time;
		}
	
		else
		{
			bqnode *p = new bqnode;
			bqnode *front = back->next;

			p->prev = back;
			p->prev->next = p;
			p->next = front;
			p->next->prev = p;
			p->time = temp->time;
			back = p;
		}

		temp = temp->next;
	}
	
	if (temp = Obj.back)
	{
		bqnode *p = new bqnode;
		bqnode *front = back->next;

		p->prev = back;
		p->prev->next = p;
		p->next = front;
		p->next->prev = p;
		p->time = temp->time;
		back = p;
	}
}

//*************************************************************************************
//Name: Enqueue
//Precondition: A circular queue with n elements
//Postcondition: A circular queue with n+1 elements
//Description:  This function add an element to the back of a cirular queue
//
//*************************************************************************************
void BQUEUE::Enqueue(int key)
{
	cout << "Enqueue Invoked" << endl;

	if (back->time == NULL)
	{
		back->time = key;
	}
	
	else
	{
		bqnode *p = new bqnode;
		bqnode *front = back->next;

		p->prev = back;
		p->prev->next = p;
		p->next = front;
		p->next->prev = p;
		p->time = key;
		back = p;
	}
}

//*************************************************************************************
//Name:  Dequeue
//Precondition: A circular queue with n elements
//Postcondition: A circulare queue with n-1 elelments
//Description:  This function will remove an element from the front of the queue
//
//*************************************************************************************
void BQUEUE::Dequeue()
{
	cout << "Dequeue Invoked" << endl;

	if (back->time == NULL)
	{
		delete back;
	}
	
	else if (back->next == back)
	{
		back->time = NULL;
	}
	
	else
	{
		bqnode *front = back->next;
		bqnode *p = front->next;

		back->next = p;
		back->next->prev = back;

		delete front;
	}
}

//*************************************************************************************
//Name:  Print
//Precondition: No precondition
//Postcondition:  No post condition
//Description:  This function print the elements in a circular queue
//
//*************************************************************************************
void BQUEUE::Print()
{
	cout << "Print Invoked" << endl;
	
	bqnode *temp = new bqnode;
	temp = back->next;
	
	while (temp != back)
		{
			cout << temp->time << endl;
			
			temp = temp->next;
		}
	
	cout << back->time << endl;
}
