#include "Date.h"



//This stub (for now) should be implemented in date.cpp
//*************************************************************************************
//Name:  Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:  This is the default constructor which will be called automatically when 
//an object is declared.  It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{

	myMonth = 01;
	myDay = 01;
	myYear = 0001;
	
	cout << myMonth << " / " << myDay << " / " << myYear << endl;

}


//*************************************************************************************
//Name:  Date
//Precondition: Takes in 3 arguments: month, day, year, repectively.  
//Postcondition: checks intial values
//Description:  Checks to make sure that all the months, days, and years are correct in the format xx/xx/xxxx
//
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	if (m > 0 && m <= 12)
	{
		myMonth = m;
		
	}
	else
	{
		cout << m << " is an invalid month." << endl;
	}

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if ( d > 0 && d <= 31)
		{
			myDay = d;
			
		}
		else
		{
			cout << d << " is an invalid day." << endl;
		}

	}

	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d > 0 && d <= 30)
		{
			myDay = d;

		}
		else
		{
			cout << d << " is an invalid day." << endl;
		}
	}

	if( m == 2)
	{
		if (y % 4 == 0)
		{
			if (d > 0 && d <= 29)
			{
				myDay = d;
			}
			else
			{
				cout << d << " is an invalid day." << endl;
			}
		}
		else
		{
			if (d > 0 && d <= 28)
			{
				myDay = d;
			}
			else
			{
				cout << d << " is an invalid day." << endl;
			}
		}
	}
	else
	{
		if (d == 0 || d > 31)
		{
			cout << d << " is an invalid day." << endl;
		}
	}
	
	if( y > 0000 && y <= 9999 )
	{
		myYear = y;
		if (y % 4 == 0)
		{
			cout << "Ths year is a leap year." << endl;
		}
	}
	else
	{
		cout << y << " is an invalid year." << endl;

	}

	cout << endl;

}

//*************************************************************************************
//Name:  Display
//Precondition: none
//Postcondition: prints the date
//Description:  prints the date so that the user can see it
//
//
//*************************************************************************************
void Date::display()
{

	cout << myMonth << "/" << myDay << "/" << myYear << endl << endl;

}

//*************************************************************************************
//Name:  getMonth
//Precondition: none
//Postcondition: returns an integer for the month
//Description: gets the month from the month typed in
//
//
//*************************************************************************************	
int Date::getMonth()
{

	return myMonth;

}

//*************************************************************************************
//Name:  getDay
//Precondition: none
//Postcondition: returns an integer for the day
//Description:  gets the day from the day typed in
//
//
//*************************************************************************************
int Date::getDay()
{

	return myDay;

}

//*************************************************************************************
//Name:  getYear
//Precondition: none 
//Postcondition: returns an integer for the year
//Description:  gets the year from the year typed in
//
//
//*************************************************************************************
int Date::getYear()
{

	return myYear;

}

//*************************************************************************************
//Name: setMonth
//Precondition: 
//Postcondition: 
//Description:  
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{

	myMonth = m;

}

//*************************************************************************************
//Name:  setDay
//Precondition: 
//Postcondition: 
//Description:  
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{

	myDay = d;
}

//*************************************************************************************
//Name:  getYear
//Precondition: 
//Postcondition: 
//Description:  
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{

	myYear = y; 


}

ostream & operator<<(ostream & out, const Date & dateObj)
{

	 
	out << dateObj.myMonth << "/" << dateObj.myDay << "/" << dateObj.myYear << endl;

	return out;

}
