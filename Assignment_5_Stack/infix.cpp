#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

stack_element infix(stack_element exp);

int main()
{
	stack_element post;

	cout << "Hello there!" << endl;
	cout << "This program will convert any POSTFIX expression to an INFIX expression." << endl;
	cout << "Please add spaces in between each operand and operator." << endl;
	cout << "Type in '#' to end the program." << endl << endl;

	while(1)
	{
		cout << "Please type in an expression to be converted:" << endl;
		cout << "> ";
		getline(cin, post);

		if (post == "#")
		{
			break;
		}

		cout << endl<<"The new expression is "<< infix(post) << endl<<endl;
		

	}

	cout << "Goodbye!" << endl << endl;

	return 0;
}


stack_element infix(stack_element exp)
{
	cout << "INFIX Invoked" << endl<<endl;

	stack numStack;
	stack_element result;
	stack_element token;
	stack_element x;
	stack_element y;

	for (int i = 0; i < exp.length(); i++)
	{
		token = exp[i];

		if (exp.length() == 1)
		{
			return exp;
		}


		if (token == " ")
		{

		}
		else if (token == "+")
		{
			if (numStack.size() < 2)
			{
				result = "ERROR: Not enough operands\n\n";
				break;
			}
			else
			{
				x = numStack.pop();
				y = numStack.pop();
				result = "(" + y + "+" + x + ")";
				numStack.push(result);
			}

		}
		else if (token == "-")
		{
			if (numStack.size() < 2)
			{
				result = "ERROR: Not enough operands\n\n";
				break;
			}
			else
			{
				x = numStack.pop();
				y = numStack.pop();
				result = "(" + y + "-" + x + ")";
				numStack.push(result);
			}
		}
		else if (token == "*")
		{
			if (numStack.size() < 2)
			{
				result = "ERROR: Not enough operands\n\n";
				break;
			}
			else
			{
				x = numStack.pop();
				y = numStack.pop();
				result = "(" + y + "*" + x + ")";
				numStack.push(result);
			}
		}
		else if (token == "/")
		{
			if (numStack.size() < 2)
			{
				result = "ERROR: Not enough operands\n\n";
				break;
			}
			else
			{
				x = numStack.pop();
				y = numStack.pop();
				result = "(" + y + "/" + x + ")";
				numStack.push(result);
			}
		}
		else
		{
			numStack.push(token);
		}
	}

	if (numStack.size() == 1)
	{
		return result;
	}
	else
	{
		return "ERROR: Not enough operators\n\n";
	}
}