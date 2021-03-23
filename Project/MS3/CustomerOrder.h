// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: davinderverma@myseneca.ca
// Date of completion: 30/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_CUSTOMERORDER_H
#define _SDDS_CUSTOMERORDER_H

#include "Utilities.h"
#include "Station.h"

#include<algorithm>
#include<iostream>
#include<iomanip>

using namespace std;
namespace sdds
{
	struct Item
	{
		string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		string m_name;
		string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const string&);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&)noexcept;
		CustomerOrder& operator=(CustomerOrder&&)noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

	};
}
#endif // !_SDDS_CUSTOMERORDER_H
