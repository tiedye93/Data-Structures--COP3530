/********************************************************************************************

Name: Tyler Bourque               Z#: 23200873
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:                      Due Time: September 1st, 2015
Total Points: 100
Assignment 3: Dynamic Arrays

Description: This program will show the fuctionality of a dynamic array. you will be able to add, remove, print, and alter strings with this program

*********************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "tlist.h"

using namespace std;

int main()
{
	TLIST T;		// Checks Default Constuctor
	TLIST R(T);		//Checks copy Constuctor
	
	
	cout << "--------------------------------------------------" << endl;
	T.Search("ac");			// Checks Search Function (Error Testing)
	
	cout << "--------------------------------------------------" << endl;
	T.Search("cveevcyxq");	// Checks Search Function
	
	cout << "--------------------------------------------------" << endl;
	cout << T << endl << endl;
	T.Remove("cveevcyxq");	// Checks Remove Function

	cout << "--------------------------------------------------" << endl;
	T.Remove("ac");			// Checks Remove Function
	
	cout << "--------------------------------------------------" << endl;
	cout << T << endl << endl;
	T.Insert("hello World");	// Checks Insert Function
	cout << T << endl << endl;
	
	cout << "--------------------------------------------------" << endl;
	T.SubstringCount(1, "ab");	// Checks SubstringCount Function
	
	cout << "--------------------------------------------------" << endl;
	T.SubstringCount(1, "z");	// Checks SubstringCount Function (Error Testing)
	
	cout << "--------------------------------------------------" << endl;
	cout << T << endl << endl;
	T.SubstringRemove(1, "ab");	// Checks SubstringRemove Function
	cout << T << endl << endl;
	
	cout << "--------------------------------------------------" << endl;
	cout << T << endl << endl;
	T.SubstringInsert(1, 6, "Hi Mom");	// Checks SubstringInsert Function
	cout << T << endl << endl;

	cout << "--------------------------------------------------" << endl;
	cout << T << endl << endl;
	T.SubstringInsert(4, 5, "Please send money!"); // Checks SubstringInsert Function
	cout << T << endl << endl;

	cout << "--------------------------------------------------" << endl;
	T.SubstringInsert(12, 5, "Please send money!");	// Checks SubstringInsert Function (Error Testing)
	
	cout << "--------------------------------------------------" << endl;
	T.SubstringInsert(9, 12 , "Please send money!");	// Checks SubstringInsert Function (Error Testing)

	return 0;
}