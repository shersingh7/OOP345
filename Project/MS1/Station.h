#ifndef _SDDS_STATION_H
#define _SDDS_STATION_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

namespace sdds
{
	class Station {
		private:
			unsigned int station_id;
			std::string nameOfItem;
			std::string desOfStation;
			unsigned int serialNumb;
			unsigned int itemLeft;
			//static data
			static unsigned int m_widthField;
			static unsigned int id_generator;
		public:
			Station(const std::string&);
			const std::string& getItemName() const;
			size_t getNextSerialNumber();
			size_t getQuantity() const;
			void updateQuantity();
			void display(std::ostream& os, bool full) const;
		};
}

	
	


#endif // !_SDDS_STATION_H
