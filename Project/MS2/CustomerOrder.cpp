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
		Utilities temp;
		bool ok = false;
		size_t a = 0;

		if (str.empty())
		{
			m_name = "";
			m_product = "";
			m_cntItem = 0;
			m_lstItem = nullptr;
		}
		else
		{
			m_name = temp.extractToken(str, a, ok);

			if (ok) m_product = temp.extractToken(str, a, ok);

			string tempItems = str.substr(a, str.length() - a);
			m_cntItem = count(tempItems.begin(), tempItems.end(), temp.getDelimiter()) + 1;

			m_lstItem = new Item * [m_cntItem];

			for (size_t i = 0; (i < m_cntItem) && ok; i++) m_lstItem[i] = new Item(temp.extractToken(str, a, ok));

			if (m_widthField < temp.getFieldWidth()) m_widthField = temp.getFieldWidth();
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
			for(unsigned int i=0;i<m_cntItem;i++) delete m_lstItem[i];
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
		for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
		delete[] m_lstItem;
	}
	bool CustomerOrder::isFilled() const
	{
		bool ok = false;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled) ok = true;
			else ok = false;
		}
		return ok;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool ok = false;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (itemName.compare(m_lstItem[i]->m_itemName) == 0) ok = true;
		}
		return ok;
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
				else
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

