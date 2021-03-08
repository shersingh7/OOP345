//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       6 
// Date:           07/03/2021
//==============================================

#ifndef _SDDS_RACECAR_H
#define _SDDS_RACECAR_H

#include"Car.h"

#include<iostream>
#include<string>
#include<sstream>

using namespace std;
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;

	public:
		Racecar(istream& in);
		void display(ostream& out)const;
		double topSpeed() const;

	};
}

#endif // !_SDDS_RACECAR_H
