#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H

#include "Vehicle.h"
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;
namespace sdds
{
	class Car : public Vehicle
	{
		string cMaker;
		string cCondition;
		double cTopSpeed=0.0;
		string topSpeedStr;

	public:
		Car();
		Car(istream&);
		string condition()const;
		double topSpeed()const;
		void display(ostream& out) const;

	};
}
#endif // !_SDDS_CAR_H
