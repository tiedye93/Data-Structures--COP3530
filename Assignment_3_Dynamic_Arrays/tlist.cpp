#include <iostream>
#include <fstream>
#include <string>
#include "tlist.h"



//*************************************************************************************
//Name:  TLIST
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to read from a txt file and save them to an array 
//Description:  This is the default constructor which will be called automatically when
//				the obeject is declared. it will initialize the state of the class
//
//*************************************************************************************
TLIST::TLIST()
{
	cout << "Default Constructor Invoked" << endl << endl;
	count = 0;
	capacity = 2;

	DB = new string[capacity];

	ifstream in;
	string key;

	in.open("myData.txt");

	while (!(in.eof()))
	{

		in >> key;
		//DB[count] = key;
		//count++;
		if (!in.eof())
		{
			Insert(key);
		}
	}
}

//*************************************************************************************
//Name:  TLIST
//Precondition: Takes a class of TLIST
//Postcondition: Makes a deep copy of TLIST and initialzes it to another class
//Description:  Used for a deep copy of the array TLIST
//
//
//*************************************************************************************
TLIST::TLIST(const TLIST  & copy)
{
	cout << endl << "Copy Constructor Invoked" << endl << endl;

	count = copy.count;
	capacity = copy.capacity;

	DB = new string[capacity];

	for (int i = 0; i < count; i++)
	{
		DB[i] = copy.DB[i];
		cout << DB[i] << endl;

	}

	

}
//*************************************************************************************
//Name:  IsEmpty
//Precondition: No precondition
//Postcondition: Sets count to 0
//Description:  This lets the class know that the array is empty and to reset count to 0
//
//
//*************************************************************************************
bool TLIST::IsEmpty()
{
	cout << endl << "IsEmpty Invoked" << endl << endl;

	return count == 0;
}	

//*************************************************************************************
//Name:  IsFull
//Precondition: No precondition
//Postcondition: Sets count equal to capcity
//Description:  This lets the class know that the array is full so it can not have anoy more information added to it
//
//
//*************************************************************************************
bool TLIST::IsFull()
{
	cout << endl << "IsFull Invoked" << endl << endl;

	return count == capacity;
}

//*************************************************************************************
//Name:  ~TLIST
//Precondition: Memory is allocated for TLIST 
//Postcondition: reallocated the memory back to the system
//Description:  Thi will delete the array so that the memory is given back to the system
//
//
//*************************************************************************************
TLIST::~TLIST()
{
	cout << endl << "Destructor Invoked" << endl << endl;

	delete [] DB;
}

//*************************************************************************************
//Name:  Search
//Precondition: Takes in a string
//Postcondition: Lets the user know the string has been found
//Description:  This checks to see if a string part of the array. 
//				even is its not part of the array, it will let the user know
//
//*************************************************************************************
int TLIST::Search(const string & key )
{
	cout << endl << "Search Invoked" << endl << endl;

	for (int i = 0; i < count; i++)
	{
		if(key == DB[i])
		{
			cout << "Item Found at index " << i << endl;
			return i;
		}
		if (i + 1 == count)
		{
			cout << "***Item not Found***" << endl;
			return -1;
		}
	}
}

//*************************************************************************************
//Name:  Insert
//Precondition: Takes in a string
//Postcondition: An array with an added element
//Description:  Inserts a string in the proper order into the array
//
//
//*************************************************************************************
void TLIST::Insert(const string & key)
{
	cout << endl << "Insert Invoked" << endl << endl;
	int i = 0;
	int loc;

	if(IsEmpty())
	{
		DB[count] = key;
		count++;
		return;
	}
	if (IsFull())
	{
		DoubleSize();
	}
	while (i < count && key >= DB[i])
		{
			i++;
		}

			//for (i = 0; < key; i++)
	for (loc = count; loc > i; loc--)
	{

		DB[loc] = DB[loc - 1];
	}

		
		DB[i] = key;
		count++;

}

//*************************************************************************************
//Name:  Remove
//Precondition: takes in a string
//Postcondition: An array with onne less element
//Description:  searches for a string in an array and then removes it.
//
//
//*************************************************************************************
void TLIST::Remove(const string & key)
{
	cout << endl << "Remove Invoked" << endl << endl;
	
	int inArray;

	inArray = Search(key);

	if (inArray != -1)
	{
		for (int i = inArray; i < count; i++)
		{
			DB[i] = DB[i + 1];		
		}
		count--;

		for (int i = 0; i < count; i++)
		{
			cout << DB[i] << endl;
		}
	}

}

//*************************************************************************************
//Name:  SubstringCount
//Precondition: takes in the location for the string and the substring to be counted
//Postcondition: Returns an integer that resembles the amount of occerances of the substring in the string
//Description:  looks into a string in an array and counts the amount of substrings given to the function
//
//
//*************************************************************************************
int TLIST::SubstringCount(const int loc, const string & substring)
{
	cout << endl << "SubstringCount Invoked" << endl << endl;

	string key = DB[loc];
	string sub = substring;

	if (key.find(substring) != string::npos)
	{

		SubstringRemove(loc, sub);
		DB[loc] = key;

	}
	else
	{

		cout << "Substring" " '" << substring << "' " << "is not in that particular string." << endl;

	}
	return 0;
}

//*************************************************************************************
//Name:  SubstringRemove
//Precondition: Takes in the location for the string and the substring to be removed
//Postcondition: Removes a substring from a string
//Description:  Takes in a substring to be removed from a string in an array
//
//
//*************************************************************************************
void TLIST::SubstringRemove(const int loc, const string & substring)
{
	cout << endl << "SubstringRemove Invoked" << endl<< endl;

	int sum = 0;
	string key = DB[loc];
	string::size_type n = substring.length();

	for (string::size_type i = key.find(substring); i != string::npos; i = key.find(substring))
	{
		key.erase(i, n);
		sum++;
	}
	DB[loc] = key;
	cout << "There are " << sum << " occurences of" << " '"<< substring << "' "<< "in this string." << endl;


}

//*************************************************************************************
//Name:  SubstringInsert
//Precondition: Takes in the location for the string and the substring to be inserted
//Postcondition: Has a string with an added substring
//Description:  This will add a substring to a string in an array
//
//
//*************************************************************************************
void TLIST::SubstringInsert(const int loc, const int pos , const string &substring)
{
	cout << endl << "SubstringInsert Invoked" << endl << endl;

	if (loc < 0 || loc > count)
	{
		cout << "Location does not exist in the Array." << endl;
		return;
	}

	string key = DB[loc];

	if (pos < 0 || pos > key.length())
	{
		cout << "Position does not exist in the string." << endl;
		return;
	}
	
	key.insert(pos, substring);
	DB[loc] = key;
	
}

//*************************************************************************************
//Name:  DoubleSize
//Precondition: No precondtion
//Postcondition: Doubles the size af an array
//Description:  If the array is full, this will double the size of the array so more elements can be put in the array
//
//
//*************************************************************************************
void TLIST::DoubleSize()
{
	capacity *= 2;
	string *temp = new string[capacity];
	for (int i = 0; i<count; i++)
	{
		temp[i] = DB[i];
	}

	delete[] DB;
	DB = temp;
}

//*************************************************************************************
//Name:  Overload operator : <<
//Precondition: << operator can not be overloaded
//Postcondition: alows the << operator to be overloaded
//Description:  the is the friend member fuction for : << so it can be overloaded
//
//
//*************************************************************************************
ostream & operator<<(ostream & out, const TLIST & Org)
{
	for (int i = 0; i<Org.count; i++)
	{
		out << Org.DB[i] << endl;
	}

	return out;
}