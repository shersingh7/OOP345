#include <iomanip>
#include "Book.h"
#include "Util.h"

using namespace std;

namespace sdds
{
	ostream& operator<<(ostream& os, Book const& book)
	{
		os << setprecision(2) << fixed
			<< setw(20) << book.m_author << " | "
			<< setw(22) << book.m_title << " | "
			<< setw(5) << book.m_country << " | "
			<< setw(4) << book.m_year << " | "
			<< setw(6) << book.m_price << " | "
			<< book.m_description << '\n'
			<< setprecision(6) << defaultfloat;
		return os;
	}

	Book::Book() : m_year{ 0 }, m_price{ 0.0 }{}


	Book::Book(string const& strBook)
	{
		string::size_type position = 0;

		m_author = readToken(strBook, position);
		trimToken(m_author);
		m_title = readToken(strBook, position);
		trimToken(m_title);
		m_country = readToken(strBook, position);
		trimToken(m_country);
		m_price = stod(readToken(strBook, position));
		m_year = stoi(readToken(strBook, position));
		m_description = strBook.substr(position);
		trimToken(m_description);
	}

	const string& Book::title() const
	{
		return m_title;
	}

	const string& Book::country() const
	{
		return m_country;
	}


	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}
}
