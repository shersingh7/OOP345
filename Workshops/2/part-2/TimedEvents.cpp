//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       2 
// Date:           28/01/2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include "TimedEvents.h"

#include <cstring>
#include <string>
#include <iomanip>

using namespace std;
namespace sdds
{

	TimedEvents::TimedEvents() : numRecords(0)
	{
		for (int i = 0; i < 7; i++)
		{
			record[i].eventName = "";
		}
	}

	void TimedEvents::startClock()
	{
		sTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		eTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventName)
	{
		this->record[numRecords].eventName = eventName;
		this->record[numRecords].unitsOfTime = "nanoseconds";
		this->record[numRecords].durOfEvent = std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime);
		numRecords++;
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& obj)
	{
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (unsigned int i = 0; i < obj.numRecords; i++) 
		{
			os << setw(20) << std::left << obj.record[i].eventName;
			os << " " << std::setw(12) << std::right;
			os << obj.record[i].durOfEvent.count() << " ";
			os << obj.record[i].unitsOfTime << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}