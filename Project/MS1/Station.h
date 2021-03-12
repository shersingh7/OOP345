#ifndef _SDDS_STATION_H
#define _SDDS_STATION_H

#include"Utilities.h"

#include<iostream>
#include<iomanip>
#include<string>


using namespace std;
namespace sdds
{
	class Station
	{
		int id;
		string itemName;
		string desc;
		unsigned serialNum;
		unsigned inStock;

		//Class Variables
		static unsigned m_widthField;
		static unsigned id_genereator;

	public:
		Station(const string&);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;


	};
}
#endif // !_SDDS_STATION_H
