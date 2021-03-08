#define _CRT_SECURE_NO_WARNINGS

#include "Station.h"
#include "Utilities.h"

using namespace sdds;

	unsigned int Station::m_widthField = 0;
	unsigned int Station::id_generator = 0;
	Station::Station(const std::string& str) {
		Utilities util;
		size_t pos = 0;
		bool more = false;
		this->station_id = ++Station::id_generator;
		if (str.empty()) {
			this->nameOfItem = "";
			serialNumb = 0;
			itemLeft = 0;
		}
		else {
			nameOfItem = util.extractToken(str, pos, more);
			if (more) {
				string tmp = util.extractToken(str, pos, more);
				serialNumb = atoi(tmp.c_str());
			}
			if (more) {
				string tmp2 = util.extractToken(str, pos, more);
				itemLeft = atoi(tmp2.c_str());
			}

			if (m_widthField < util.getFieldWidth()) {
				m_widthField = util.getFieldWidth();
			}

			if (more) {
				desOfStation = util.extractToken(str, pos, more);
			}
		}
	}

	const std::string& Station::getItemName() const {
		return this->nameOfItem;
	}

	size_t Station::getNextSerialNumber() {
		return this->serialNumb++;
	}
	
	size_t Station::getQuantity() const {
		return this->itemLeft;
	}

	void Station::updateQuantity() {
		if (this->itemLeft > 0) { 
			itemLeft--;
		}
	}

	void Station::display(std::ostream& os, bool full) const {
		if (full == false) {
			os << right << "[" << setw(3) << std::setfill('0')  << this->station_id << "] Item: " << left << std::setfill(' ') << setw(m_widthField) << this->getItemName() << " [" << setw(6) << std::setfill('0') << right << this->serialNumb << "]";
		}
		else {
			os << "[" << setw(3) << std::setfill('0') << right << this->station_id << "] Item: " << left << std::setfill(' ') << setw(m_widthField) << this->getItemName() << " [" << setw(6) << std::setfill('0') << right << this->serialNumb << "]" << " Quantity: " << std::left << std::setw(m_widthField) << setfill(' ') << this->getQuantity() << right << " Description: " << this->desOfStation ;
		}
		os << endl;
	}
