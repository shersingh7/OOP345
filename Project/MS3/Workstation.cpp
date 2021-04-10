// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: dverma22@myseneca.ca
// Date of completion: 05/04/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

namespace sdds
{
	deque<CustomerOrder>pending;
	deque<CustomerOrder>completed;
	deque<CustomerOrder>incomplete;


	Workstation::Workstation(const string& str) : Station(str)
	{
		m_pNextStation = nullptr;
	}

	void Workstation::fill(ostream& os)
	{
		if (m_orders.empty()) return;
		else
		{
			if(!m_orders.front().isFilled())
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{

		if (m_orders.empty()) return false;
		else
		{
			if (m_orders.front().isItemFilled(this->getItemName()))
			{
				if (m_pNextStation != nullptr)
				{
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
					return true;
				}			
				else
				{
					completed.push_back(move(m_orders.front()));
					m_orders.pop_front();
					return true;
				}

			}

			if (this->getQuantity() <= 0)
			{
				if (m_pNextStation != nullptr)
				{
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
					return true;
				}
				else
				{
					incomplete.push_back(move(m_orders.front()));
					m_orders.pop_front();
					return true;

				}
			}return false;
		}
		
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(ostream& os) const
	{
		os << getItemName() << " --> ";
		if (m_pNextStation != nullptr) os << m_pNextStation->getItemName() << endl;
		else os << "End of Line\n";
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}

}