//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       6 
// Date:           07/03/2021
//==============================================

#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H

#include<iostream>
#include<vector>
#include<list>

#include"Vehicle.h"
#include"Car.h"

using namespace std;
namespace sdds
{
	class Autoshop
	{
		vector<Vehicle*> m_vehicles;
		
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto i = m_vehicles.begin(); i!=m_vehicles.end(); i++)
			{
				if (test(*i)) vehicles.push_back(*i);
			}
		}

	};
}

#endif