//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       5 
// Date:           20/02/2021
//==============================================

#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H

#include <string>
#include <iostream>
#include <iomanip> 

#include "SpellChecker.h"

using namespace std;

namespace sdds 
{
	class Book 
	{
		string author;
		string bTitle;
		string bCountry;
		size_t bYear;
		double bPrice;
		string bDesc;

	public:

		Book();
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const string& strBook);
		friend ostream& operator<<(ostream& os, const Book& src);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(bDesc);
		}
	};
}

#endif // !_SDDS_BOOK_H
