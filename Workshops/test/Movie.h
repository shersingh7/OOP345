#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <ostream>
#include <string>

namespace sdds
{
	class Movie;
	std::ostream& operator<<(std::ostream& os, Movie const& movie);

	class Movie
	{
	private:
		std::string m_title;
		int m_year;
		std::string m_description;

	public:
		Movie();
		Movie(std::string const& strMovie);
		std::string const& title() const;
		friend std::ostream& operator<<(std::ostream& os, Movie const& movie);

		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};
}
#endif