//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       2 
// Date:           28/01/2021
//==============================================

#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H

#include <chrono>
#include <string>
#include <iostream>


namespace sdds 
{
	constexpr int MAX_NO_OBJ = 10;	//Max no. of event objects

	class TimedEvents	//Manages statically allocated array of Event Object
	{		
		unsigned int numRecords;	//No. of records currently stored
		std::chrono::steady_clock::time_point sTime;	//Start time for the current event
		std::chrono::steady_clock::time_point eTime;	//End time for the current event

		struct 
		{
			std::string eventName;		//Event Name
			std::string unitsOfTime;	//Predefined units of time
			std::chrono::steady_clock::duration durOfEvent;		//Duration of the event
		} record[MAX_NO_OBJ];

	public:

		TimedEvents();		//Deault Constructor
		void startClock();	//Modifier that starts the timer for an event
		void stopClock();	//Modifier that stops the timer for an event
		void addEvent(const char* eventName);	//updates the next time-record
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& obj);	//Displays the execution times
	};
	
}

#endif // !_SDDS_TIMEDEVENTS_H
