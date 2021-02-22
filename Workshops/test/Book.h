#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <cstddef>
#include <ostream>
#include <string>

namespace sdds
{
	class Book;
	std::ostream& operator<<(std::ostream& os, Book const& book);

	class Book
	{
	private:
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::size_t m_year;
		double m_price;
		std::string m_description;

	public:
		Book();
		Book(const std::string& string);
		const std::string& title() const;
		const std::string& country() const;
		const std::size_t& year() const;
		double& price();
		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& os, const Book& book);

	};
}
#endif