#ifndef _SDDS_LINEMANAGER_H
#define _SDDS_LINEMANAGER_H

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<fstream>

#include"Workstation.h"
#include"Station.h"

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
		void display() const;

	};
}

#endif // !_SDDS_LINEMANAGER_H
