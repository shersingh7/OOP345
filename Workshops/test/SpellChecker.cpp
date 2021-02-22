#include <fstream>
#include <iostream>
#include <utility>
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
	static int m_badCounter[6] = { 0,0,0,0,0,0 };
	SpellChecker::SpellChecker(char const* file)
	{
		if (!file || file[0] == '\0')
			throw  "Bad file name!";

		ifstream wordsFile(file);
		if (!wordsFile.good())
			throw  "Bad file name!";
		string line;
		for (auto i = 0u; i < 6; i++)
		{
			if (!wordsFile.good())
				break;
			getline(wordsFile, line);
			auto position = line.find(' ');
			m_badWords[i] = line.substr(0, position);
			m_goodWords[i] = line.substr(line.find_first_not_of(' ', position));
		}
	}


	void SpellChecker::operator()(string& text)
	{
		for (auto i = 0u; i < 6u; i++)
		{
			auto bSize = m_badWords[i].length();
			auto gSize = m_goodWords[i].length();
			if (bSize == 0)
				break;

			for (auto pos = text.find(m_badWords[i]); pos < string::npos; pos = text.find(m_badWords[i], pos + gSize))
			{
				text.replace(pos, bSize, m_goodWords[i]);
				m_badCounter[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(ostream& out) const {
		cout << "Spellchecker Statistics\n";
		for (auto i = 0u; i < 6u; i++) {
			cout.width(15);
			cout << m_badWords[i] << ": " << m_badCounter[i] << " replacements\n";
		}
	}
}
