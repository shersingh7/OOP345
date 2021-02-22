//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       1 
// Date:           23/01/2021
//==============================================

#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H

extern unsigned int g_sysClock;	// Stores the event start time

namespace sdds
{
	class Event
	{
		char* eventDesc;			// eventDesc of the event
		unsigned int seconds;			// seconds after midnight

	public:
		Event();				 // Default constructor
		Event(const Event& src); // Constructor
		~Event();				 // Destructor

		void display();							// Displays content of an event
		void set(const char* src = nullptr);	// Receives address of an array 
		Event& operator=(const Event& src);		// Copy constructor

	};
}
#endif // !_SDDS_EVENT_H