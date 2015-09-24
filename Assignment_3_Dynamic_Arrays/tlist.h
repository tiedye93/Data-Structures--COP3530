
using  namespace std;

#ifndef TLIST_H
#define TLIST_H

class TLIST

{

public:

	TLIST();															//default constructor sets the following: count = 0, capacity = //2, and allocates memory the size of string[capacity]

	TLIST(const TLIST  &);												//copy constructor

	~TLIST();															//destructor

	bool IsEmpty();														//return true if empty; otherwise false

	bool IsFull();														//return true if full; otherwise false

	int Search(const string &);											//returns the location of the string in the dynamic array

	void Insert(const string & key);									//add key to dynamic array if not full; otherwise prints a message stating dynamic array is full

	void Remove(const string & key);									//removes key from dynamic array if it is there; //otherwise prints a message stating it was not in dynamic array

	int SubstringCount(const int loc, const string & substring);		//loc is the location of //the string in the array and substring is the string you are counting

	void SubstringRemove(const int loc, const string & substring);		//loc is the location of //the string in the array and substring is the to be removed

	void SubstringInsert(const int loc ,const int pos, const string &substring);		//loc is the index/subscript of the string in DB.  This is the string to be modified; pos is the

																						//starting location of where the substring should be placed. If loc is 0 or 1, the

																						//substring is inserted just before the first character in the string; if loc is 2 or

																						//greater but less than or equal to the length of string minus 1, then the substring is

																						//inserted just before the character occupying loc; substring is the string to be

																						//inserted.

	void DoubleSize();													//doubles the capacity of the array, copies the contains of the old //arrry, and de-allocates the old array's memory

	friend ostream & operator<<(ostream & out, const TLIST & Org);		// print the contents of //the dynamic array

																  

private:

	string *DB;															//dynamic array

	int count;															//number of strings stored in the dynamic array

	int capacity;														//total number of cells in the dynamic array

};

#endif

