

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

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		string temp;

		if (next_pos <= str.length())
		{
			size_t a = str.find_first_of(m_delimiter, next_pos);
			
			if (a != std::string::npos)
			{
				temp = str.substr(next_pos, a - next_pos);
				next_pos = a + 1;
			}
			else
			{
				temp = str.substr(next_pos);
				next_pos = str.length() + 1;
			}

			if (temp.empty() && (next_pos != str.length() + 1))
			{
				more = false;
			}

			if (m_widthField < temp.length()) m_widthField = temp.length();

			more = next_pos <= str.length();
		}

		return temp;
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

