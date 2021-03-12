#define _CRT_SECURE_NO_WARNINGS

#include "Station.h"

namespace sdds
{
	unsigned Station::m_widthField = 0;
	unsigned Station::id_genereator = 0;

	Station::Station(const string& str)
	{
		Utilities temp;
		size_t a = 0;
		bool ok = false;
		this->id = ++id_genereator;

		size_t start = 0;
		size_t end = str.find(Utilities::getDelimiter());
		this->itemName = str.substr(start, end);

		start = end + 1;
		end = str.find(Utilities::getDelimiter(), start);
		this->serialNum = std::stoi(temp.extractToken(str, start, ok));

		start = end + 1;
		end = str.find(Utilities::getDelimiter(), start);
		this->inStock = std::stoi(temp.extractToken(str, start, ok));

		start = end + 1;
		this->desc = temp.extractToken(str, start, ok);


		if (m_widthField < itemName.length())
		{
			m_widthField = itemName.length();
		}
	}

	const std::string& Station::getItemName() const
	{
		return this->itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		return this->serialNum++;
	}

	size_t Station::getQuantity() const
	{
		return this->inStock;
	}

	void Station::updateQuantity()
	{
		if (this->inStock > 0) inStock--;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		if (full == false)
		{
			os << right << "[" << setw(3) << this->id << "] Item: " << left << setfill(' ') << setw(m_widthField) << this->getItemName() << " [" << setw(6) << setfill('0') << right << this->serialNum << "]" << endl;
		}
		else
		{
			os << right << "[" << setw(3) << this->id << "] Item " << left << setfill(' ') << setw(m_widthField) << this->getItemName() << " [" << setw(6) << setfill('0') << right << this->serialNum << "] Quantity: " << left << setw(m_widthField) << setfill(' ') << this->getQuantity() << right << " Description: " << this->desc << endl;
		}
	}
}


