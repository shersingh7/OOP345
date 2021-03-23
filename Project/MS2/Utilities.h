// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: davinderverma@myseneca.ca
// Date of completion: 22/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H

#include<iostream>
#include<string>


using namespace std;
namespace sdds
{
	class Utilities
	{
		size_t m_widthField = 1;
		static char m_delimiter;

	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		string extractToken(const string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}

#endif // !_SDDS_UTILITIES_H
