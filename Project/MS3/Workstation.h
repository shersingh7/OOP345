#ifndef _SDDS_WORKSTATION_H
#define _SDDS_WORKSTATION_H

#include"CustomerOrder.h"
#include"Station.h"

#include<deque>

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
		const Workstation* getNextStation()const;
		void display(ostream& os)const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif // !_SDDS_WORKSTATION_H
