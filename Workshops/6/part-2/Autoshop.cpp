//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       6 
// Date:           07/03/2021
//==============================================

#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		if (theVehicle != nullptr)
		{
			m_vehicles.push_back(theVehicle);
		}
		return *this;
	}

	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (unsigned i = 0; i < m_vehicles.size(); i++)
		{
			m_vehicles[i]->display(out);
			cout << endl;
		}

		out << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop()
	{
		for (int i = 0; i < m_vehicles.size(); i++) delete[] m_vehicles[i];
	}
}


