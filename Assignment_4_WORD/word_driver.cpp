/********************************************************************************************

Name: Tyler Bourque               Z#: 23200873
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: September 29th, 2015
Total Points: 100
Assignment 4: Singly Linked Lists

Description: This program will show the fuctionality of a singly linked list. You will be able to test insert, length, and remove lnked lists in this program.

*********************************************************************************************/
#include "word.h"


int main()
{
	
	cout<<"Testing the default constructor and printing empty word\n";
	cout << "**********************************************************" << endl;
	WORD you;
	cout<<you<<endl<<endl;
	
	
	cout<<"Testing the explicit-value constructor\n";
	cout << "**********************************************************" << endl;
	WORD me("123abc345abc129012");
	cout<<me<<endl << endl;
	
	
	cout<<"Testing the copy constructor\n";
	cout << "**********************************************************" << endl;
	WORD them = me;
	cout<< them <<" = "<< me << endl << endl;
	
	
	cout<<"Testing length\n";
	cout << "**********************************************************" << endl;
	cout<<"The length of me is "<<me.Length()<<endl;
	cout<<"The length of them is "<<them.Length()<<endl;
	cout<<"The length of you is "<<you.Length()<<endl << endl;


	cout << "Testing Insert by inserting them2 into you2 at position 0\n";
	cout << "**********************************************************" << endl;
	WORD you2("12345");
	WORD them2("XXXXXXXXX");
	cout << you2 << endl;
	cout << them2 << endl;
	you2.Insert(them2,1);
	cout << "The length of you2 is " << you2.Length() << endl;
	cout << you2 << endl;
	cout<<"The word you2 is "<<you2<<endl;
	you2.Insert(me,5);
	cout<<you2<<endl << endl << endl;
	
	
	cout<<"Testing operator= by assignment the value of \"abc\" to use\n";
	cout << "**********************************************************" << endl;
	WORD us;
	us = "abc";
	cout<<us<<endl << endl;

	
	cout<<"Testing overloaded operator= with chaining by assignment\nthe value of \"ABC123XYZ\" to use.\n";
	cout << "**********************************************************" << endl;
	WORD word1, word2, word3;
	word1 = "ABC123XYZ";
	word3=word2=word1;
	cout<<"word3 is "<<word3<<", word2 is "<<word2<<" and word1 is "<<word1<<endl << endl;


	cout<<"Testing overloaded operator= with chaining by assignment\nthe value of word1, \"ABC123XYZ\", into itself \n";
	cout << "**********************************************************" << endl;
	word1 = word1 = word1;
	cout<<"word1 is "<<word1<<endl<<endl;

	
	cout<<"Testing operator+ without chaining"<<endl;
	cout << "**********************************************************" << endl;
	word3 + word2;
	cout<<word3<<endl<<endl;
	
	us = "";
	us = "12";
	cout<<us<<endl<<endl;

	
	cout<<"Testing Remove by removing us from them \n";
	cout << "**********************************************************" << endl;
	cout << them << endl << endl;
	them.Remove(us);
	you.Remove(us);
	cout<<you<<endl;
	cout<<"The word them is "<<them<<endl << endl;
	
	
	cout<<"Testing RemoveAll by removing all occurrences of us in me \n";
	cout << "**********************************************************" << endl;
	me.RemoveALL(us);
	cout<<"The word me is "<<me<<endl << endl;
	

	cout<<"Testing IsEqual by testing to see if us is equal to our \n";
	cout << "**********************************************************" << endl;
	WORD our, him;
	our = "XXXCCCYYY";
	us = "XXXX";

	if (our.IsEqual(us))
	{
		cout << "The 2 words are equal\n";
	}
	else
	{
		cout << "The 2 words are not equal\n";
	}

	cout << endl << endl << "Destructing all objects" << endl;
	cout << "**********************************************************" << endl;

	return 0;
}