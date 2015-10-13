#include "stack.h"

//*************************************************************************************
//Name:  stack (Default)
//Precondition: An postfix expression
//Postcondition: An infix expression 
//Description:  This fuction will alter an postfix expression to become an infix expression
//
//*************************************************************************************
stack::stack()
{ 
	cout << "Default Constructor Invoked"<<endl; 
	s_top = 0; 
}

//*************************************************************************************
//Name:  stack (Copy)
//Precondition: An postfix expression
//Postcondition: An infix expression 
//Description:  This fuction will alter an postfix expression to become an infix expression
//
//*************************************************************************************
stack::stack(const stack & Org)
{
	cout << "Copy Constructor Invoked" << endl;
	stack_node *p = Org.s_top;

	(*this).s_top = 0;

	while (p != 0)
	{
		(*this).push(p->data);
		p = p->next;
	}
}

//*************************************************************************************
//Name:  stack (Destructor)
//Precondition: An postfix expression
//Postcondition: An infix expression 
//Description:  This fuction will alter an postfix expression to become an infix expression
//
//*************************************************************************************
stack::~stack()
{
	cout << "Destructor Invoked"<<endl;
	while (s_top != 0)
	{
		pop();
	}
}

//*************************************************************************************
//Name:  push
//Precondition: Stack with n elements
//Postcondition: Stack with n+1 elements
//Description: This function will push an item onto the top of the stack
//
//*************************************************************************************
void stack::push(const stack_element & item)
{
	cout << "Push Invoked" << endl;

	stack_node *p = new stack_node;

	p->data = item;
	p->next = s_top;
	s_top = p;
}

//*************************************************************************************
//Name:  pop
//Precondition: Stack with n elements
//Postcondition: Stack with n-1 elements
//Description:  This function will pop an item off the top of the stack
//
//*************************************************************************************
stack_element stack::pop()
{
	cout << "Pop Invoked"<<endl;
	
	stack_node *p;
	stack_element info;

	if (s_top != 0)
	{
		p = s_top;
		info = p->data;
		s_top = s_top->next;
		delete p;
		
		return info;
	}

}

//*************************************************************************************
//Name:  size
//Precondition: No precondtion
//Postcondition: Returns an integer 
//Description:  This fuction will find the size of the Stack and return the value
//
//*************************************************************************************
int stack::size()
{
	int sum = 0;
	stack_node *p = s_top;

	while (p != NULL)
	{
		sum++;
		p = p->next;
	}

	return sum;
}