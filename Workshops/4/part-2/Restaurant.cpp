//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       4 
// Date:           12/02/2021
//==============================================

#include"Restaurant.h"

using namespace std;

namespace sdds 
{
	Restaurant::Restaurant() 
	{
		reservation = nullptr;
		numOfRes = 0;
	}

	Restaurant::~Restaurant() 
	{
		delete[] reservation;
		reservation = nullptr;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) 
	{
		reservation = nullptr;
		numOfRes = cnt;

		if (reservations != nullptr) 
		{
			reservation = new Reservation[cnt + 1];

			for (size_t i = 0; i < cnt; i++) 
			{
				reservation[i] = *reservations[i];
			}
		}
	}

	Restaurant::Restaurant(const Restaurant& src) 
	{
		if (this != &src) 
		{
			if (src.reservation != nullptr) 
			{
				reservation = nullptr;

				reservation = new Reservation[src.size() + 1];

				for (size_t i = 0; i < src.size(); i++)
				{
					reservation[i] = src.reservation[i];
				}
				numOfRes = src.numOfRes;
			}
		}
	}

	size_t Restaurant::size() const 
	{
		return numOfRes;
	}

	ostream& operator<<(ostream& os, const Restaurant& src) 
	{
		static int temp = 1;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant" << " (" << temp++ << ")" << endl;
		os << "--------------------------" << endl;

		if (src.size() == 0) 
		{
			os << "This restaurant is empty!" << endl;
		}
		else 
		{
			for (size_t i = 0; i < src.size(); i++) 
			{
				os << src.reservation[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept 
	{
		/*if (src.reservation != nullptr) 
		{ 
			swap(reservation, src.reservation);
			numOfRes = src.numOfRes;
			src.numOfRes = 0;
			src.reservation = nullptr;
		}*/
		*this = move(src);
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) 
	{
		if (this != &src) 
		{
			delete[] reservation;
			numOfRes = src.numOfRes;
			reservation = new Reservation[numOfRes];

			for (size_t i = 0; i < numOfRes; i++) 
			{
				reservation[i] = src.reservation[i];
			}
		}
		return *this;
	}
	

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept 
	{
		if (this != &src)
		{
			delete[] reservation;
			reservation = nullptr;
			reservation = src.reservation;
			src.reservation = nullptr;
			numOfRes = src.numOfRes;
			src.numOfRes = 0;
		}
		return *this;
	}

}





