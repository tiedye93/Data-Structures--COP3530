#include <iostream>

using namespace std;

class bqnode
{
public:
	int time;					// Data type of the node

	bqnode *prev, *next;		// Pointers for the node
};

class BQUEUE
{

public:
	BQUEUE();					// Default Constructor

	~BQUEUE();					// Destructor

	BQUEUE(const BQUEUE &);		// Copy Constructor

	void Enqueue(int);			// Enqueue function; adds an item to the back of the queue

	void Dequeue();				// Dequeue function; removes an item from the front of the queue

	void Print();				// Print funtcion; prints the items of the queue

private:
	bqnode *back;				// Pointer to the back of the queue

};
