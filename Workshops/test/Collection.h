#ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace sdds
{
	template<typename T>
	class Collection
	{
		string cName;
		T* collection;
		int cSize;
		void(*observer)(const Collection<T>&, const T&);

	public:
		Collection(const string& name) :collection{},cSize(0)
		{
			cName = name;
		}

		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;

		~Collection()
		{
			delete[] collection;
		}

		const string& name() const
		{
			return cName;
		}

		size_t size()const
		{
			return cSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->observer = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			for (int i = 0; i < cSize; i++)
			{
				if (this->collection[i].title() == item.title())
				{
					return *this;
				}
			}

			T* temp = nullptr;
			temp = new T[cSize + 1];

			for (int i = 0; i < cSize; i++)
			{
				temp[i] = this->collection[i];
			}

			temp[cSize] = item;
			delete[] collection;

			collection = temp;
			cSize++;

			if (this->observer != nullptr)
			{
				observer(*this, collection[cSize - 1]);
			}

			return *this;
		}

		T& operator[](size_t idx)const
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
			return this->collection[idx];
		}

		T* operator[](string title)const
		{
			bool ok = false;
			T* temp = nullptr;

			for (int i = 0; i < cSize; i++)
			{
				if (collection[i].title() == title)
				{
					ok = true;
					temp = &collection[i];
				}
			}

			if (ok = true)
			{
				return temp;
			}
			else
			{
				return nullptr;
			}

		}

	};

	template<typename T>
	ostream& operator <<(ostream& os, const Collection<T>& src)
	{
		for (int i = 0; i < src.size(); i++)
		{
			os << src[i];
		}
		return os;
	}
}

#endif // !_SDDS_COLLECTION_H
