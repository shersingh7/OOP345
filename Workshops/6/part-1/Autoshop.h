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

	};
}

#endif