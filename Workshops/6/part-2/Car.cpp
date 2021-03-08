//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       6 
// Date:           07/03/2021
//==============================================

#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car()
	{
		cMaker = "";
		cCondition = "";
		cTopSpeed = 0.0;
	}

	Car::Car(istream& src)
	{
		
		string temp = "";
		getline(src, temp);

		string::size_type a = temp.find(',');
		cMaker = temp.substr(0, a);
		temp.erase(0, a + 1);

		a = temp.find(',');
		cCondition = temp.substr(0, a);
		if (cCondition.length() == 0 || cCondition == " ")
		{
			cCondition = "n";
		}

		temp.erase(0, a + 1);

		a = temp.find(',');
		if (a > 0)
		{
			topSpeedStr = temp.substr(0, a);
		}
		temp.erase(0, a + 1);

		//Remove spaces
		auto a1 = cMaker.find_first_not_of(' '); // Find spaces before the string
		auto a2 = cMaker.find_last_not_of(' '); //Find spaces after the string

		cMaker = cMaker.substr(a1, (a2 - a1) + 1);

		a1 = cCondition.find_first_not_of(' '); // Find spaces before the string
		a2 = cCondition.find_last_not_of(' '); //Find spaces after the string

		cCondition = cCondition.substr(a1, (a2 - a1) + 1);

		a1 = topSpeedStr.find_first_not_of(' '); // Find spaces before the string
		a2 = topSpeedStr.find_last_not_of(' '); //Find spaces after the string

		topSpeedStr = topSpeedStr.substr(a1, (a2 - a1) + 1);

		a1 = temp.find_first_not_of(' '); // Find spaces before the string
		a2 = temp.find_last_not_of(' '); //Find spaces after the string
		temp = temp.substr(a1, (a2 - a1) + 1);

		//if (cCondition == "n" && cCondition == "N" && cCondition == "u" && cCondition == "U" && cCondition == "b" && cCondition == "B")
		if (cCondition != "n" && cCondition != "N" && cCondition != "u" && cCondition != "U" && cCondition != "b" && cCondition != "B")
		{
			throw "Invalid record!";
		}
		else
		{
			bool ok = (topSpeedStr.find_first_not_of("0123456789") == std::string::npos);
			
			if (ok) 
			{
				cTopSpeed = stod(topSpeedStr);
			}
			else
			{
				throw "Invalid record!";
			}

			topSpeedStr = temp;
		}
		

	}

	string Car::condition() const
	{
		if (cCondition == "n" || cCondition == "N")
		{
			return "new";
		}
		else if (cCondition == "u" || cCondition == "U")
		{
			return "used";
		}
		else
		{
			return "broken";
		}
	}

	double Car::topSpeed() const
	{
		return cTopSpeed;
	}
	

	void Car::display(ostream& out) const
	{
		out << "| " << right <<setw(10) << cMaker << " | " << left << setw(6) << condition() << " | " << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
	}
	string Car::maker() const
	{
		return cMaker;
	}
	string& Car::topSpeedString()
	{
		return topSpeedStr;
	}
}


