#include "Workstation.h"

namespace sdds
{
	Workstation::Workstation(const string& str) : Station(str)
	{

	}

	void Workstation::fill(ostream& os)
	{
		if (m_orders.empty()) return;

		m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		if (m_orders.empty()) return false;

		if (m_pNextStation && m_orders.front().isItemFilled(this->getItemName()))
		{
			*m_pNextStation += move(m_orders.front());
			m_orders.pop_front();
			return true;
		}
		else return false;
	}

	void Workstation::setNextStation(Workstation* station = nullptr)
	{
		m_pNextStation = (Workstation*)&station;
	}

	const Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(ostream& os) const
	{
		os << getItemName() << " --> ";
		if (m_pNextStation != nullptr) os << m_pNextStation->getItemName() << endl;
		else os << "END OF LINE\n";
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}

}
