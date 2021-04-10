// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: davinderverma@myseneca.ca
// Date of completion: 30/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

namespace sdds
{
	size_t CustomerOrder::m_widthField=0;

	CustomerOrder::CustomerOrder()
	{
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const string& str)
	{
		if (str != "") 
		{
			m_cntItem = 0;
			m_lstItem = nullptr;
			Utilities temp;
			size_t a = 0;
			bool ok = true;
			Item* tempItem[20] = {};
			m_name = temp.extractToken(str, a, ok);
			m_product = temp.extractToken(str, a, ok);

			while (ok)
			{
				string tempStr = temp.extractToken(str, a, ok);
				tempItem[m_cntItem] = new Item(tempStr);
				m_cntItem++;
			}

			m_lstItem = new Item * [m_cntItem];

			for(size_t i = 0; i < m_cntItem; i++) 
			{
				m_lstItem[i] = tempItem[i];
			}

			if (m_widthField < temp.getFieldWidth()) 
			{
				m_widthField = temp.getFieldWidth();
			}
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder&)
	{
		throw "Error";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		m_lstItem = nullptr;
		m_cntItem = 0;
		*this = move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			for(size_t i=0;i<m_cntItem;i++) delete m_lstItem[i];
			m_name = src.m_name;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			m_product = src.m_product;

			src.m_lstItem = nullptr;
			src.m_cntItem = 0;
			src.m_product = "";
			src.m_name = "";

		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (unsigned int i = 0; i < m_cntItem; i++) delete m_lstItem[i];

		delete[] m_lstItem;
	}

	bool CustomerOrder::isFilled() const
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if ((m_lstItem[i]->m_isFilled) == false) return false;
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (itemName.compare(m_lstItem[i]->m_itemName) == 0) return m_lstItem[i]->m_isFilled;
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				if (station.getQuantity() > 0)
				{
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();

					os << setw(11) << right << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
				}
				else if(station.getQuantity() == 0)
				{
					os << setw(11) << right << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << endl;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName;
			if (m_lstItem[i]->m_isFilled) os << " - FILLED\n";
			else os << " - TO BE FILLED\n";
		}
	}
}


