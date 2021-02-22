//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       4 
// Date:           12/02/2021
//==============================================

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include"Reservation.h"

namespace sdds 
{
	class Restaurant 
	{
		Reservation* reservation;
		size_t numOfRes;
	
	public:

		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant(Restaurant&& src)noexcept;

		Restaurant& operator=(const Restaurant& src);
		Restaurant& operator=(Restaurant&& src)noexcept;

		size_t size() const;

		~Restaurant();

		friend ostream& operator<<(ostream& os, const Restaurant& src);
	};
}



#endif //!_SDDS_RESTAURANT_H
