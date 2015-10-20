/********************************************************************************************
Name: Tyler Bourque               Z#: 23200873
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: October 21st, 2015
Total Points: 100
Assignment 4: Circular Queue
Description: This program will show the fuctionality of a circular queue. You will be able to test enqueue, dequeue, and print to alter circular queues in this program.
*********************************************************************************************/

#include "bqueue.h"


int main()
{
	BQUEUE  k;

	k.Enqueue(60);
	k.Enqueue(100);
	k.Print();
	k.Enqueue(20);
	k.Enqueue(30);
	k.Print();
	k.Enqueue(10);
	k.Print();
	k.Enqueue(50);
	k.Enqueue(40);
	k.Print();

	BQUEUE j = k;

	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	
	return 0;
}