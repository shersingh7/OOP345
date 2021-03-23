// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: davinderverma@myseneca.ca
// Date of completion: 22/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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

		static unsigned m_widthField;
		static unsigned id_genereator;

	public:
		Station(const string&);
		const string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(ostream& os, bool full) const;


	};
}
#endif // !_SDDS_STATION_H
