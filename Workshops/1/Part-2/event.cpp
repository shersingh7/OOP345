//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       1 
// Date:           23/01/2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>

#include "event.h"

using namespace std;
using namespace sdds;

unsigned int g_sysClock = 0;

Event::Event()					// Default constructor
{
	seconds = 0;
	eventDesc = nullptr;
}

Event::Event(const Event& src)	// Constructor
{
	eventDesc = nullptr;
	*this = src;
}

Event::~Event()					// Destructor
{
	delete[] eventDesc;
	eventDesc = nullptr;
}

void Event::display()			// Displays content of an event
{
	static int counter = 1;		// Holds the no of function being called

	int hour = 0;
	int min = 0;
	int sec = 0;

	hour = seconds / 3600;
	min = (seconds - (hour * 3600)) / 60;
	sec = (seconds - (hour * 3600) - (min * 60));

	if (eventDesc != nullptr) 
	{
		cout << setw(2) << setfill(' ') << counter << ". ";
		cout << setw(2) << setfill('0') << hour << ":";
		cout << setw(2) << setfill('0') << min << ":";
		cout << setw(2) << setfill('0') << sec << " => " << eventDesc<< endl;
	}
	else 
	{
		cout << setw(2) << setfill(' ') << counter << ". | No Event |" << endl;
	}

	counter++;
}

void Event::set(const char* src)	// Receives address of an array 
{
	if (src != nullptr ) 
	{
		delete[] eventDesc;
		eventDesc = nullptr;

		int temp = strlen(src);

		eventDesc = new char[temp + 1];
		strcpy(eventDesc, src);

		seconds = g_sysClock;
	}
	else 
	{
		delete[] eventDesc;
		eventDesc = nullptr;

		seconds = 0;
	}
}

Event& Event::operator=(const Event& src) // Copy constructor
{
	if (this != &src) 
	{
		if (src.eventDesc != nullptr) 
		{
			seconds = src.seconds;

			delete[] eventDesc;
			eventDesc = nullptr;

			int temp = strlen(src.eventDesc);
			eventDesc = new char[temp + 1];

			strcpy(eventDesc, src.eventDesc);
		}
		else 
		{
			delete[] eventDesc;
			eventDesc = nullptr;

			seconds = 0;
		}
	}
	return *this;
}


	




