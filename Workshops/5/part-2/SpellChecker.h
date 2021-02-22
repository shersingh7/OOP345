//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       5 
// Date:           20/02/2021
//==============================================

#ifndef _SDDS_SPELLCHECKER_H
#define _SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

namespace sdds 
{
	class SpellChecker 
	{
		string m_badWords[6];
		string m_goodWords[6];
	public:
		SpellChecker(const char* filename);
		void operator()(string& text) const;
		void showStatistics(ostream& out) const;
	};
}

#endif // !_SDDS_SPELLCHECKER_H
