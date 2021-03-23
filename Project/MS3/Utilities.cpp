// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: davinderverma@myseneca.ca
// Date of completion: 22/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delimiter;

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return this->m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
	{
		string tmp = "";
		size_t first_pos = next_pos;
		next_pos = str.find(m_delimiter, first_pos);
		size_t wField;

		if (next_pos == string::npos)
		{
			tmp = str.substr(first_pos);
			wField = max(tmp.length(), m_widthField);
			setFieldWidth(wField);
			more = false;
		}
		else if (first_pos == next_pos)
		{
			more = false;
			throw "Delimiter found";
		}
		else 
		{
			tmp = str.substr(first_pos, next_pos - first_pos);
			wField = max(tmp.length(), m_widthField);
			setFieldWidth(wField);
			more = true;
		}
		next_pos++;
		return tmp;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}

