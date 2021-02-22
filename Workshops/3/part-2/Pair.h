//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       3 
// Date:           06/02/2021
//==============================================

#ifndef _SDDS_PAIR_H__
#define _SDDS_PAIR_H__

#include <iostream>

using namespace std;

namespace sdds 
{
	template< typename V, typename K>
	class Pair {

		K pKey;
		V pValue;

	public:
		Pair() : pKey(), pValue() 
		{
		};

		Pair(const K& key, const V& value) 
		{
			pKey = key;
			pValue = value;
		}

		const K& key() const 
		{
			return pKey;
		}

		const V& value() const 
		{
			return pValue;
		}

		virtual void display(std::ostream& os) const 
		{
			os << pKey << " : " << pValue << '\n';
		}
	};

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& src) 
	{
		src.display(os);
		return os;
	}
}

#endif //!_SDDS_PAIR_H__