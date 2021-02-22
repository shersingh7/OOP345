#include <iomanip>
#include "Movie.h"
#include "Util.h"

namespace sdds
{
	std::ostream& operator<<(std::ostream& os, Movie const& movie)
	{
		os << std::setw(40) << movie.m_title << " | "
			<< std::setw(4) << movie.m_year << " | "
			<< movie.m_description << '\n';
		return os;
	}

	Movie::Movie() : m_year{ 0 }
	{ }


	Movie::Movie(std::string const& strMovie)
	{
		std::string::size_type position = 0;

		m_title = readToken(strMovie, position);
		trimToken(m_title);
		m_year = std::stoi(readToken(strMovie, position));

		m_description = strMovie.substr(position);
		trimToken(m_description);
	}


	std::string const& Movie::title() const
	{
		return m_title;
	}
}
