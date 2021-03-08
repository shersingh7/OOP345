#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

using namespace sdds;

char Utilities::m_delimiter;

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return this->m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token;
		if (next_pos <= str.length()) {
			size_t loc = str.find_first_of(m_delimiter, next_pos);
			if (loc != std::string::npos) {
				token = str.substr(next_pos, loc - next_pos);
				next_pos = loc + 1;
			}
			else {
				token = str.substr(next_pos);
				next_pos = str.length() + 1;
			}
			if ((token.empty()) && (next_pos != str.length() + 1)) {
				more = false;
				throw str + "<-- ERROR:  Token Failure";
			}
			if (m_widthField < token.length()) {
				m_widthField = token.length();
			}
			more = next_pos <= str.length();
		}
		return token;
	}

	 void Utilities::setDelimiter(char newDelimiter) {
		 m_delimiter = newDelimiter;
	}

	 char Utilities::getDelimiter() {
		 return m_delimiter;
	}
