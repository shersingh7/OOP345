#ifndef _SDDS_WORKSTATION_H
#define _SDDS_WORKSTATION_H

#include  <deque>
#include"CustomerOrder.h"
#include"Station.h"
#include "Utilities.h"


using namespace std;
namespace sdds
{

	class Workstation:public Station
	{

		deque<CustomerOrder>pending;
		deque<CustomerOrder>completed;
		deque<CustomerOrder>incomplete;

		deque<CustomerOrder>m_orders;
		Workstation* m_pNextStation;

		

	public:
		Workstation(const string&);
		void fill(ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		const Workstation* getNextStation()const;
		void display(ostream& os)const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif // !_SDDS_WORKSTATION_H
