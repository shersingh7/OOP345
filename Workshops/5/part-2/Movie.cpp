//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       5 
// Date:           20/02/2021
//==============================================

#include "Movie.h"

namespace sdds 
{
	Movie::Movie() 
	{
		mTitle = "";
		mYear = 0;
		mDesc = "";
	}

	const string& Movie::title() const 
	{
		return mTitle;
	}

	Movie::Movie(const string& strMovie) 
	{
		string temp = strMovie;
		auto pos = temp.find(',');

		mTitle = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');

		mYear = stoi(temp.substr(0, pos));
		temp.erase(0, pos + 1);

		mDesc = temp;
		auto pos1 = mDesc.find_first_not_of(' ');
		auto pos2 = mDesc.find_last_not_of(' ');
		mDesc = mDesc.substr(pos1, (pos2 - pos1) + 1);

		pos1 = mTitle.find_first_not_of(' ');
		pos2 = mTitle.find_last_not_of(' ');
		mTitle = mTitle.substr(pos1, (pos2 - pos1) + 1);
	}

	ostream& operator<<(ostream& os, const Movie& src) 
	{
		os << setw(40) <<src.mTitle << " | " << setw(4) <<src.mYear << " | " << src.mDesc << endl;
		return os;
	}
}