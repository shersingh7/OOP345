#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds
{
	class SpellChecker
	{
	private:
		std::string m_badWords[6];
		std::string m_goodWords[6];
	public:
		SpellChecker(char const* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif

