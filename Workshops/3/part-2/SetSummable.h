//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       3 
// Date:           06/02/2021
//==============================================

#ifndef _SDDS_SETSUMMABLE_H__
#define _SDDS_SETSUMMABLE_H__

#include <iostream>

#include "Set.h"

using namespace std;

namespace sdds 
{
	template<size_t N, typename T>
	class SetSummable : public Set<N, T> 
	{

	public:

		T accumulate(const string& filter) const 
		{
			T accum(filter);
			for (size_t i = 0; i < this->size(); i++)
			{
				if (accum.isCompatibleWith(filter))
					accum += this->get(i);
			}
			return accum;
		}
	};
}
#endif //!_SDDS_SETSUMMABLE_H__