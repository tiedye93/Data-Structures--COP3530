#include <iostream>
#include <string>

using namespace std;

typedef string stack_element;

class stack_node
{
public:
	stack_element data;							// Data located in the node

	stack_node *next;							// Pointer to link nodes
};

class stack
{
public:
	stack();									// Default Constructor

	stack(const stack & Org);					// Copy Constructor

	~stack();									// Destructor

	void push(const stack_element & item);		// Push function; pushes information onto the stack

	stack_element pop();						// Pop fuction; pops information off of the stack

	int size();									// Size fuction; returns the size of the stack

private:

	stack_node *s_top;							// Pointer to the top of the stack
};
