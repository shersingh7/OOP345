//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       4 
// Date:           12/02/2021
//==============================================

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds 
{
	class Reservation 
	{
		string id;
		string name;
		string email;
		size_t noOfPeople;
		unsigned int day;
		unsigned int hour;

	public:

		Reservation();
		Reservation(const std::string& res);

		friend ostream& operator<<(ostream& os,const Reservation& res);
	};

}

#endif // !SDDS_RESERVATION_H
