//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       5 
// Date:           20/02/2021
//==============================================

#ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds 
{
	template<typename T>
	class Collection 
	{
		string cName;
		T* cItem;
		size_t cSize;
		void (*observer)(const Collection<T>&, const T&) = nullptr;

	public:

		Collection(const string& name) :cItem{}, cSize(0) 
		{
			cName = name;
		}

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

		~Collection() 
		{
			delete[] cItem;
		}

		const string& name() const 
		{
			return cName;
		}

		size_t size() const 
		{
			return cSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->observer = observer;
		}

		Collection<T>& operator+=(const T& item) 
		{
			for (auto i = 0u; i < cSize; i++) 
			{
				if (this->cItem[i].title() == item.title())
				{
					return *this;
				}
			}

			T* temp = nullptr;
			temp = new T[cSize + 1];

			for (auto i = 0u; i < cSize; i++) 
			{
				temp[i] = this->cItem[i];		
			}

			temp[cSize] = item;
			delete[] cItem;

			cItem = temp;

			++cSize;

			if (this->observer != nullptr) 
			{
				observer(*this, cItem[cSize - 1]);
			}
			return *this;
		}

		T& operator[](size_t idx) const 
		{
			if (idx >= cSize) 
			{
				string msg = "Bad index [";
				msg += to_string(idx);
				msg += "]. Collection has [";
				msg += to_string(cSize);
				msg += "] items.";
				throw out_of_range(msg);
			}
			return this->cItem[idx];
		}

		T* operator[](string title) const 
		{
			bool ok = false;
			T* temp = nullptr;

			for (size_t i = 0; i < cSize; i++) 
			{
				if (cItem[i].title() == title) 
				{
					ok = true;
					temp =  &cItem[i];
				}
			}

			if (ok == false) 
			{
				return nullptr;
			}
			else 
			{
				return temp;
			}
		}
	};

	template<typename T>
	ostream& operator<<(ostream& os, const Collection<T>& value) 
	{
		for (size_t i = 0; i < value.size(); i++)
		{
			os << value[i];
		}
		return os;
	}
}
#endif // !_SDDS_COLLECTION_H
