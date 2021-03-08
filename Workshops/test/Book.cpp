#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"


using namespace std;

namespace sdds
{	
	Book::Book()
	{
		bAuthor = "";
		bTitle = "";
		bCountry = "";
		bYear = 0;
		bPrice = 0.0;
		bDesc = "";
	}

	const std::string& sdds::Book::title() const
	{
		return bTitle;
	}

	const std::string& sdds::Book::country() const
	{
		return bCountry;
	}

	const size_t& sdds::Book::year() const
	{
		return bYear;
	}

	double& sdds::Book::price()
	{
		return bPrice;
	}

	sdds::Book::Book(const std::string& strBook)
	{
		bAuthor = "";
		bTitle = "";
		bCountry = "";
		bYear = 0;
		bPrice = 0;
		bDesc = "";

		string temp = strBook;
		string::size_type pos = temp.find(',');

		bAuthor = temp.substr(0, pos);
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

		pos1 = bAuthor.find_first_not_of(' ');
		pos2 = bAuthor.find_last_not_of(' ');
		bAuthor = bAuthor.substr(pos1, (pos2 - pos1) + 1);

	}

	ostream& operator<<(ostream& os, const Book& src)
	{
		os << setw(20) << src.bAuthor << " | "
			<< setw(22) << src.bTitle << " | " 
			<< setw(5) << src.bCountry << " | " 
			<< setw(4) << src.bYear << " | " 
			<< setw(6) << setprecision(2) << src.bPrice << " | " 
			<< src.bDesc << endl;

		return os;
	}


}

