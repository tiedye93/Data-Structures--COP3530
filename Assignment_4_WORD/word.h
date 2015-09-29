
#include <iostream>
#include <string>

using namespace std;

#ifndef SLIST_H
#define SLIST_H

typedef string List_Type;										//List_Type is equal to strings

					
class character													//***Declaration for a node in the list***
{
public:
		List_Type data;											//Data element

		character *next;										//Pointer element
};


class WORD														//***Declaration of a list class***
{
public:
	WORD();														//Default constructor

	WORD(const WORD & Org);										//Copy constructor

	WORD(const List_Type & key);								//Explicit Value Constructor

	~WORD();													//Destructor

	bool IsEmpty();												//Returns true if empty; Otherwise false

	bool IsEqual(const WORD & Obj);								//Returns true if lists are equal; Otherwise false

	int Length() const;												//Returns the length of a list

	void Insert(const WORD & key, const int & pos);				//Inserts a list into another list at position pos

	void Remove(const WORD & Obj);								//Removes one iteration of a list from the current list

	void RemoveALL(const WORD & Obj);							//Removes all iterations of a llist from the current list

	friend WORD & operator+( WORD & Obj1, const WORD & Obj2);	//Overload + to concatenate two lists
	
	WORD & operator=(const List_Type & key);					//Overload = to set a list equal to a string

	WORD & operator=(const WORD & Obj );						//Overload = to set a list equal to a list

	friend ostream & operator<<(ostream &, const WORD &);		//Ovrload << to allow insertion of a list


private:

	character *front;									//Pointer for the front of a list
	character *back;									//Pointer for the back of a list

};
#endif