#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H

#include<sstream>
#include<string>

#include "Vehicle.h"
#include "Car.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif // !_SDDS_UTILITIES_H
