#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;
namespace sdds
{
	class Book
	{
		string bAuthor;
		string bTitle;
		string bCountry;
		unsigned bYear;
		double bPrice;
		string bDesc;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend ostream& operator<<(ostream& os, const Book& src);

		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(bDesc);
		}
	};
}

#endif // !_SDDS_BOOK_H
