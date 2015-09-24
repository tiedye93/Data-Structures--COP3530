/********************************************************************************************

Name: Tyler Bourque               Z#: 23200873
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:                      Due Time: September 1st, 2015
Total Points: 100
Assignment 2: Date program

Description: This program will allow the user to type in a date of any time and have it display it for the user.

*********************************************************************************************/

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{

	Date myDate;
	Date yourDate(12,31, 1957);
	Date test1Date(15, 1, 1962); //should generate error message that bad month
	Date test2Date(2, 29, 1956); //ok, should say leep year
	Date test3Date(2, 30, 1956); //should generate error message that bad day
	Date test4Date(12,31,0000); //should generate error message that bad year
	Date test5Date(80,40,0000); //should generate error message that bad month, day and year

	test4Date.display();
	
	yourDate.display();

	cout<<yourDate.getMonth()<<endl;
	cout<<yourDate.getDay()<<endl;
	cout<<yourDate.getYear()<<endl;
	cout << endl;
	cout<<"myDate: "<<myDate<<"test2Date: "<<test2Date<<"yourDate: "<<yourDate<<endl;

	return 0;

}
