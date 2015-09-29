#include "word.h"


//*************************************************************************************
//Name:  WORD (Default)
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to make an empty node 
//Description:  This is the default constructor which will be called automatically when
//				the obeject is declared; it will initialize the state of the class.
//
//*************************************************************************************
WORD::WORD() 
{
	cout << "Default Constructor Invoked" << endl;
	front = new character;
	front->next = 0;
	back = 0;
}

//*************************************************************************************
//Name:  WORD (Copy)
//Precondition: Takes a class of WORD
//Postcondition: Makes a deep copy of WORD and initializes another class
//Description:  Used to make a deep copy of the class WORD
//
//*************************************************************************************
WORD::WORD(const WORD & Org)
{
	cout << "Copy Constructor Invoked"<< endl;

	character *p = Org.front;

	while (p != NULL)
	{
		if (front == NULL)
		{
			front = new character;
			front->data = p->data;
			back = front;
			back->next = NULL;
			p = p->next;
		}
		else
		{
			character *temp = new character;
			temp->data = p->data;
			temp->next = NULL;
			back->next = temp;
			back = temp;
			p = p->next;
		}
	}
}

//*************************************************************************************
//Name:  WORD (Explicit)
//Precondition: Takes a class of WORD and string
//Postcondition: Makes a singly linked list out of a string that is passe in
//Description:  This is the explicit constructor which will be called when to make a WORD out of a string passed into it
//
//*************************************************************************************
WORD::WORD(const List_Type & key)
{
	cout << "Explicit Constructor Invoked" << endl;

	for (int i = 0; i < key.length(); i++)
	{
		if (front == NULL)
		{
			front = new character;
			front->data = key[i];
			back = front;
			back->next = NULL;
		}
		else
		{
			character *p = new character;
			p->data = key[i];
			p->next = NULL;
			back->next = p;
			back = p;
		}
	}
}

//*************************************************************************************
//Name:  ~WORD (Destructor)
//Precondition: Memory is allocated for TLIST
//Postcondition: Reallocated the memory back to the system
//Description: This will delete the linked list so that the memory is given back to the system
//
//*************************************************************************************
WORD::~WORD()
{
	cout << "Destructor Invoked" << endl;
	
	while (front != NULL)
	{
		character *temp = front;
		front = front->next;
		delete (temp);
	}
}

//*************************************************************************************
//Name:  IsEmpty
//Precondition: None
//Postcondition: true if empty; false if not
//Description:  This is used to check in the class is empty or not
//
//*************************************************************************************
bool WORD::IsEmpty() 
{ 
	return front == 0; 
}

//*************************************************************************************
//Name:  IsEqual
//Precondition: None
//Postcondition: true if two lists are equal; false if not 
//Description:  This is used to check if two linked lists are identical
//
//*************************************************************************************
bool WORD::IsEqual(const WORD & Obj)
{
	cout << "IsEqual Invoked" << endl;

	character *r = Obj.front;
	int currentObj = Length();
	int passingObj = Obj.Length();
	
	/*while (r != NULL)
	{
		passingObj++;
		r = r->next;
	}*/
	
	if (currentObj != passingObj)
	{
		return false;
	}
	else
	{
		character *p = front;
		character *t = Obj.front;

		while (p != NULL)
		{
			if (p->data == t->data)
			{
				p = p->next;
				t = t->next;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

//*************************************************************************************
//Name:  Length
//Precondition: None
//Postcondition: Returns the length of a linked list
//Description:  This is used to find the length of a linked list
//
//*************************************************************************************
int WORD::Length() const
{
	character *temp = front;
	int count = 0;

	if (front->next == NULL)
	{
		return 0;
	}

	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	return count;
}

//*************************************************************************************
//Name:  Insert
//Precondition: Takes in a WORD and a postion
//Postcondition: Inserts a WORD at the postion given
//Description:  This is used to add a linked list to a nother linked list at any postion in the current list
//
//*************************************************************************************
void WORD::Insert(const WORD & Obj , const int & pos )
{
	cout << "Insert Invoked" << endl;

	int currentLength = Length();
	int counter;

	if (pos < 1)
	{
		cout << "Error: position needs to be at least one.\n";
	}
	else if (pos == 1)
	{
		character *t = Obj.back;

		while (t != Obj.front)
		{
			character * p = new character;
			p->data = t->data;
			p->next = front;
			front = p;

			character *t2 = Obj.front;
			while (t2->next != t)
			{
				t2 = t2->next;
			}

			t = t2;
		}

		character * p = new character;
		p->data = t->data;
		p->next = front;
		front = p;
	}
	else if (pos > currentLength)
	{
		character *t = Obj.front;
		while (t != NULL)
		{
			back->next = new character;
			back = back->next;
			back->data = t->data;
			t = t->next;
		}
	}
	else
	{
		character *p = front;
		counter = 1;

		while (p != NULL)
		{
			if (counter == pos)
			{
				character *q = front;
				while (q->next != p)
				{
					q = q->next;
				}

				character *t = Obj.front;
				while (t != NULL)
				{
					q->next = new character;
					q = q->next;
					q->data = t->data;
					q->next = p;
					t = t->next;

				}

				break;
			}
			else
			{
				counter++;
				p = p->next;
			}
		}
	}
}

//*************************************************************************************
//Name:  Remove
//Precondition: Tkaes a WORD
//Postcondition: removes a WORD from the Current WORD 
//Description:  This is used to remove one iteration of a list inside the current list
//
//*************************************************************************************
void WORD::Remove(const WORD & Obj)
{
	cout << "Remove Invoked" << endl;

	character *org = this->front;
	character *key = Obj.front;
	character *pp = org;
	int len = Obj.Length();
	int count = 0, num = 0;

	while (org != NULL)
	{
		if (org->data == key->data)
		{
			character *temp = org;
			character *temp2 = key;
			for (int i = 0; i < len; i++)
			{
				if (org->data == key->data)
				{
					key = key->next;
					org = org->next;
					count++;
				}
				else
				{
					count = 0;
					key = temp2;
					pp = pp->next;
					num++;
					break;
				}
			}

			if (count == len)
			{
				if (num == 0)
				{
					pp = org;
					front = org;
				}
				else {
					pp->next = org;
				}

				for (int i = 0; i < count; i++)
				{
					character *p = temp;
					temp = temp->next;
					delete p;
					if (i == 0)
					{
						key = temp2;
					}
				}
				count = 0;
				break;
			}

		}

		else
		{
			num++;
			pp = org;
			org = org->next;
		}
	}
}

//*************************************************************************************
//Name:  RemoveALL
//Precondition: Takes a WORD
//Postcondition: removes all WORDs from the current WORD
//Description:  This is used to remove all iterations of a list inside the current list
//
//*************************************************************************************
void WORD::RemoveALL(const WORD & Obj)
{
	cout << "RemoveALL Invoked"<<endl;

	character *org = this->front;
	character *key = Obj.front;
	character *pp = org;
	int len = Obj.Length();
	int count = 0, num = 0;

	while (org != NULL)
	{
		if (org->data == key->data)
		{
			character *temp = org;
			character *temp2 = key;
			for (int i = 0; i < len; i++)
			{
				if (org->data == key->data)
				{
					key = key->next;
					org = org->next;
					count++;
				}
				else
				{
					count = 0;
					key = temp2;
					pp = pp->next;
					num++;
					break;
				}
			}

			if (count == len)
			{
				if (num == 0)
				{
					pp = org;
					front = org;
				}
				else {
					pp->next = org;
				}

				for (int i = 0; i < count; i++)
				{
					character *p = temp;
					temp = temp->next;
					delete p;
					if (i == 0)
					{
						key = temp2;
					}
				}
				count = 0;
				//break;
			}

		}

		else
		{
			num++;
			pp = org;
			org = org->next;
		}
	}
}

//*************************************************************************************
//Name:  Opeartor +
//Precondition: Tkaes two WORDs
//Postcondition: concatenates two WORDs 
//Description:  This overload is used to combine two lists
//
//*************************************************************************************
WORD & operator+(WORD & Obj1, const WORD & Obj2)
{
	cout << "Overloading Operator +" << endl;

	character *t = Obj2.front;
	while (t != NULL)
	{
		Obj1.back->next = new character;
		Obj1.back = Obj1.back->next;
		Obj1.back->data = t->data;
		t = t->next;
	}

	return Obj1;
}

//*************************************************************************************
//Name:  Operator = (WORD = string)
//Precondition: Takes a string
//Postcondition: Sets a list equal to a string
//Description:  This overload is used to replace an old list with a string
//
//*************************************************************************************
WORD & WORD::operator=(const List_Type & key)
{
	cout << "Overloading operator = " << endl;

	while (this->front != NULL)
	{
		character *temp = this->front;
		front = this->front->next;
		delete (temp);
	}

	for (int i = 0; i < key.length(); i++)
	{
		if (front == NULL)
		{
			this->front = new character;
			this->front->data = key[i];
			this->back = front;
			this->back->next = NULL;
		}
		else
		{
			character *p = new character;
			p->data = key[i];
			p->next = NULL;
			this->back->next = p;
			this->back = p;
		}
	}

	return (*this);
}

//*************************************************************************************
//Name:  Operator = (WORD = WORD)
//Precondition: Takes in a WORD
//Postcondition: Sets a WORD equal to a WORD 
//Description:  This overload is used to set an onld list equal to another list
//
//*************************************************************************************
WORD & WORD::operator=(const WORD & Obj)
{
	cout << "Overloading operator = with chaining" << endl;

	character *p = Obj.front;

	if (IsEqual(Obj))
	{
		return (*this);
	}

	while (this->front != NULL)
	{
		character *temp = this->front;
		front = this->front->next;
		delete (temp);
	}
	
	while (p != NULL)
	{
		if (this->front == NULL)
		{
			this->front = new character;
			this ->front->data = p->data;
			this->back = this->front;
			this->back->next = NULL;
			p = p->next;
		}
		else
		{
			character *temp = new character;
			temp->data = p->data;
			temp->next = NULL;
			this->back->next = temp;
			back = temp; 
			p = p->next;
		}
	}

	return (*this);
}

//*************************************************************************************
//Name:  Opperator <<
//Precondition: Takes in a WORD and an ostream
//Postcondition: allows a WORD to be inserted 
//Description:  This overload is use to all a list to be written the the insertion operator
//
//*************************************************************************************
ostream & operator<<(ostream & out, const WORD & Obj)
{
	character *temp = Obj.front;
	while (temp != 0)
	{
		out << temp->data << "";
		temp = temp->next;
	}
	return out;

}