//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       6 
// Date:           07/03/2021
//==============================================

#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(istream& in) :Car(in)
	{
		string temp;
		temp = topSpeedString();
		m_booster = stod(temp);
		m_booster = (m_booster * Car::topSpeed());
		m_booster += Car::topSpeed();
	}

	void Racecar::display(ostream& out) const
	{
		out << "| " << right << setw(10) << Car::maker() << " | " << setw(6) << Car::condition() << " | " << setprecision(2) << m_booster << " |*";
	}

	double Racecar::topSpeed() const
	{
		return m_booster;
	}
}


