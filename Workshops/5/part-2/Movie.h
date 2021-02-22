//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       5 
// Date:           20/02/2021
//==============================================

#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "SpellChecker.h"

using namespace std;

namespace sdds 
{
	class Movie 
	{
		string mTitle;
		int mYear;
		string mDesc;

	public:

		Movie();
		const string& title() const;
		Movie(const string& strMovie);

		template<typename T>
		void fixSpelling(T& spellChecker) 
		{
			spellChecker(mTitle);
			spellChecker(mDesc);
		}

		friend ostream& operator<<(ostream& os, const Movie& src);
	};
}
#endif // !_SDDS_MOVIE_H
