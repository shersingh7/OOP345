//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       5 
// Date:           20/02/2021
//==============================================

#include "SpellChecker.h"

using namespace std;

namespace sdds 
{
	static int replaceCounter[6];

	SpellChecker::SpellChecker(const char* filename) 
	{
		ifstream file(filename);
		int count = 0;

		if (!file) 
		{
			throw "Bad file name!";
		}
		else
		{
			do
			{
				string temp = "";
				getline(file, temp);

				if (file)
				{
					string::size_type possible = temp.find(' ');
					
					m_badWords[count] = temp.substr(0, possible);
					temp.erase(0, possible + 1);
					auto possible2 = temp.find_first_not_of(' ');
					temp.erase(0, possible2);
					m_goodWords[count] = temp;
					++count;
				}
			} while (file);
			file.close();
		}
	}

	void SpellChecker::operator()(string& text) const
	{
		size_t found;
		size_t found2;

			for (int i = 0; i < 6; i++)
			{
				found = text.find(m_badWords[i]);

				if (found < text.length()) 
				{
					text.replace(found, m_badWords[i].length(), m_goodWords[i]);
					found2 = text.find(m_badWords[i]);
					replaceCounter[i]++;

					if (found2 < text.length()) 
					{
						text.replace(found2, m_badWords[i].length(), m_goodWords[i]);
						replaceCounter[i]++;
					}
				}
			}	
			
	}

	void SpellChecker::showStatistics(ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		for (int i = 0; i < 6; i++)
		{
			out << setw(15) << m_badWords[i] << ": " << replaceCounter[i] << " replacements" << endl;
		}
	}
}


