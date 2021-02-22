//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       3 
// Date:           06/02/2021
//==============================================

#ifndef _SDDS_SET_H__
#define _SDDS_SET_H__

#include <cstring>
#include <iostream>

using namespace std;

namespace sdds 
{
	template<size_t  N, typename T>
	class Set {
		T arr[N];
		size_t currentNum;

	public:

		Set() 
		{
			currentNum = 0;
		}

		size_t size() const
		{
			return currentNum;
		}
		
		const T& get(size_t idx) const
		{
			return arr[idx];
		}

		void operator+=(const T& item) {
			if (currentNum < N) 
			{
				arr[currentNum] = item;
				currentNum++;
			}
		}
	};
}

#endif //!_SDDS_SET_H__