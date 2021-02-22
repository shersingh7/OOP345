#ifndef SDDS_UTIL_H
#define SDDS_UTIL_H

#include <string>

namespace sdds
{
	inline std::string readToken(const std::string& str, std::string::size_type& pos, char delim = ',')
	{
		const auto next = str.find(delim, pos);
		const auto token = str.substr(pos, next - pos);
		pos = next;
		if (pos < std::string::npos) {
			pos++;
		}
		return token;
	}


	inline void trimToken(std::string& token, const char* chars = " \t")
	{
		token.erase(0, token.find_first_not_of(chars));

		auto position = token.find_last_not_of(chars);
		if (position < std::string::npos)
			token.erase(position + 1);
	}
}
#endif
