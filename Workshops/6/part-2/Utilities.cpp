//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       6 
// Date:           07/03/2021
//==============================================

#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		string temp;
		stringstream str;
		string name;

		getline(in, temp);

		string::size_type a = temp.find(',');
		name = temp.substr(0, a);
		temp.erase(0, a + 1);

		auto a1 = name.find_first_not_of(' ');
		auto a2 = name.find_last_not_of(' ');
		name = name.substr(a1, (a2 - a1) + 1);
		
		str << temp;

		if (in.peek() == EOF + 1)
		{
			return nullptr;
		}
		else if (name == "c" || name == "C")
		{
			Vehicle* car;
			car = new Car(str);
			return car;
		}
		else if (name == "r" || name == "R")
		{
			Vehicle* racecar;
			racecar = new Racecar(str);
			return racecar;
		}
		else
		{
			throw "Unrecognized record type: [t]";
		}
	}
}

