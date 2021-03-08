#define _CRT_SECURE_NO_WARNINGS

#include "SpellChecker.h"

using namespace std;

namespace sdds
{

	static int counter[6];

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
		size_t temp;
		size_t temp2;

		for (int i = 0; i < 6; i++)
		{
			temp = text.find(m_badWords[i]);

			if (temp < text.length())
			{
				text.replace(temp, m_badWords[i].length(), m_goodWords[i]);
				temp2 = text.find(m_badWords[i]);
				counter[i]++;

				if (temp2 < text.length())
				{
					text.replace(temp2, m_badWords[i].length(), m_goodWords[i]);
					counter[i]++;
				}
			}
		}
	}

	void SpellChecker::showStatistics(ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		
		for (int i = 0; i < 6; i++)
		{
			out << setw(15) << m_badWords[i] << ": " << counter[i] << "replacements" << endl;
		}
	}

}	

