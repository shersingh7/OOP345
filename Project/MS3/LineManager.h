// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: davinderverma@myseneca.ca
// Date of completion: 05/04/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_LINEMANAGER_H
#define _SDDS_LINEMANAGER_H

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<fstream>

#include "Utilities.h"
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Station.h"
using namespace std;
namespace sdds
{
	class LineManager
	{

		vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(ostream& os) const;

	};
}

#endif // !_SDDS_LINEMANAGER_H
