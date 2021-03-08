//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       6 
// Date:           07/03/2021
//==============================================

#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H

#include"Vehicle.h"
#include"Car.h"
#include"Racecar.h"

#include <string>
#include <sstream>


using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif // !_SDDS_UTILITIES_H
