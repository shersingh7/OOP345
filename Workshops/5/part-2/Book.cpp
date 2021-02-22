//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       5 
// Date:           20/02/2021
//==============================================

#include "Book.h"

namespace sdds 
{
	Book::Book() 
	{
		author = "";
		bTitle = "";
		bCountry = "";
		bYear = 0;
		bPrice = 0;
		bDesc = "";
	}

	const string& Book::title() const 
	{
		return bTitle;
	}

	const string& Book::country() const 
	{
		return bCountry;
	}

	const size_t& Book::year() const 
	{
		return bYear;
	}

	double& Book::price() 
	{
		return bPrice;
	}

	Book::Book(const string& strBook) 
	{
		author = "";
		bTitle = "";
		bCountry = "";
		bYear = 0;
		bPrice = 0;
		bDesc = "";

		string temp = strBook;
		string::size_type pos = temp.find(',');

		author = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');

		bTitle = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');

		bCountry = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');

		bPrice = stod(temp.substr(0, pos));
		temp.erase(0, pos + 1);
		pos = temp.find(',');

		bYear = stoi(temp.substr(0, pos));
		temp.erase(0, pos + 1);
		pos = temp.find(',');

		bDesc = temp;

		auto pos1 = bTitle.find_first_not_of(' '); 
		auto pos2 = bTitle.find_last_not_of(' '); 
		bTitle = bTitle.substr(pos1, (pos2 - pos1) + 1); 

		pos1 = bCountry.find_first_not_of(' ');
		pos2 = bCountry.find_last_not_of(' ');
		bCountry = bCountry.substr(pos1, (pos2 - pos1) + 1);

		pos1 = bDesc.find_first_not_of(' ');
		bDesc.erase(0, pos1);

		pos1 = author.find_first_not_of(' ');
		pos2 = author.find_last_not_of(' ');
		author = author.substr(pos1, (pos2 - pos1) + 1);
	}

	ostream& operator<<(ostream& os, const Book& src) 
	{
		os << setw(20) << src.author << " | " << setw(22) << src.title() << " | " << setw(5) << src.country() << " | " << setw(4) << src.year()  << " | " << fixed << setprecision(2)  << setw(6) << src.bPrice << " | " << src.bDesc << endl;
		return os;
	}

}