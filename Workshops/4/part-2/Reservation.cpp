//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       4 
// Date:           12/02/2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include"Reservation.h"

#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

namespace sdds 
{
	Reservation::Reservation()
	{
		id = "";
		name = "";
		email = "";
		noOfPeople =0;
		day=0;
		hour=0;
	}

	Reservation::Reservation(const std::string& res) 
	{
		string tempString = res;
		string tempID, tempName, tempEmail, tempNoOfPeople, tempDay, tempHour;

		tempID = tempString.substr(0, tempString.find(':'));
		tempID.erase(0, tempID.find_first_not_of(' '));
		tempID.erase(tempID.find_last_not_of(' ') + 1);

		tempString.erase(0, tempString.find(':')+1);

		tempName=tempString.substr(0, tempString.find(','));
		tempName.erase(0, tempName.find_first_not_of(' '));
		tempName.erase(tempName.find_last_not_of(' ') + 1);
		tempString.erase(0, tempString.find(',') + 1);
		tempEmail = tempString.substr(0, tempString.find(','));
		tempEmail.erase(0, tempEmail.find_first_not_of(' '));
		tempEmail.erase(tempEmail.find_last_not_of(' ') + 1);
		tempString.erase(0, tempString.find(',') + 1);
		tempNoOfPeople = tempString.substr(0, tempString.find(','));
		tempNoOfPeople.erase(0, tempNoOfPeople.find_first_not_of(' '));
		tempNoOfPeople.erase(tempNoOfPeople.find_last_not_of(' ') + 1);
		tempString.erase(0, tempString.find(',') + 1);
		tempDay = tempString.substr(0, tempString.find(','));
		tempDay.erase(0, tempDay.find_first_not_of(' '));
		tempDay.erase(tempDay.find_last_not_of(' ') + 1);
		tempString.erase(0, tempString.find(',') + 1);
		tempHour = tempString.substr(0, tempString.find(','));
		tempHour.erase(0, tempHour.find_first_not_of(' '));
		tempHour.erase(tempHour.find_last_not_of(' ') + 1);

		id = tempID;
		name = tempName;
		email = "<" + tempEmail + ">";

		noOfPeople = stoi(tempNoOfPeople);
		day = stoi(tempDay);
		hour = stoi(tempHour);
	}


	ostream& operator<<(ostream& os, const  Reservation& res) 
	{
		string display = "";

		if (res.hour >=6 && res.hour <= 9) 
		{
			display = "Breakfast on day ";
		}
		else if (res.hour >= 11 && res.hour <= 15) 
		{
			display = "Lunch on day ";
		}
		else if (res.hour >= 17 && res.hour <= 21) 
		{
			display = "Dinner on day ";
		}
		else 
		{
			display = "Drinks on day ";
		}

		os << "Reservation " << setw(10) << right << res.id << ": "
			<< setw(20) << right << res.name << "  "
			<< setw(20) << left << res.email << "    " << display << res.day
			<< " " << "@ " << res.hour << ":00 " << "for " << res.noOfPeople;

			if (res.noOfPeople == 1)
			{
				os << " person." << endl;
			}
			else
			{
				os << " people." << endl;
			}
		return os;
	}
}