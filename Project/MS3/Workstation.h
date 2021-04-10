// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: davinderverma@myseneca.ca
// Date of completion: 05/04/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_WORKSTATION_H
#define _SDDS_WORKSTATION_H

#include  <deque>
#include"CustomerOrder.h"
#include"Station.h"
#include "Utilities.h"


using namespace std;
namespace sdds
{
	extern deque<CustomerOrder>pending;
	extern deque<CustomerOrder>completed;
	extern deque<CustomerOrder>incomplete;

	class Workstation:public Station
	{

	deque<CustomerOrder>m_orders;
	Workstation* m_pNextStation;

	public:
		Workstation(const string&);
		void fill(ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation()const;
		void display(ostream& os)const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif // !_SDDS_WORKSTATION_H
