#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <cstddef>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>

namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string m_name;
		T* m_array;
		size_t m_size;
		void (*m_observer)(const Collection<T>&, const T&);
		bool exists(const T& element);
	public:
		Collection(std::string name);
		Collection(const Collection<T>&) = delete;
		Collection& operator=(const Collection<T>&) = delete;
		~Collection();
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](std::string title) const;
	};

	template<typename T>
	Collection<T>::Collection(std::string name)
	{
		m_name = name;
		m_array = nullptr;
		m_observer = nullptr;
		m_size = 0u;
	}

	template<typename T>
	Collection<T>::~Collection()
	{
		delete[] m_array;
	}

	template<typename T>
	const std::string& Collection<T>::name() const
	{
		return m_name;
	}

	template<typename T>
	size_t Collection<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	void Collection<T>::setObserver(void(*observer)(const Collection<T>&, const T&))
	{
		m_observer = observer;
	}

	template<typename T>
	Collection<T>& Collection<T>::operator+=(const T& item)
	{
		if (!exists(item)) {
			T* temporary = new T[m_size + 1];
			for (size_t i = 0u; i < m_size; i++)
			{
				temporary[i] = m_array[i];
			}
			temporary[m_size] = item;
			m_size++;
			if (m_observer) {
				m_observer(*this, item);
			}
			delete[] m_array;
			m_array = temporary;
		}
		return *this;
	}

	template<typename T>
	inline bool Collection<T>::exists(const T& element)
	{
		bool exist = false;
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_array[i].title() == element.title()) {
				exist = true;
			}
		}
		return exist;
	}

	template<typename T>
	T& Collection<T>::operator[](size_t idx) const
	{
		if (idx >= m_size) {
			std::string errorMessage = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
			throw std::out_of_range(errorMessage);
		}
		return m_array[idx];
	}

	template<typename T>
	T* Collection<T>::operator[](std::string title) const
	{
		T* found = nullptr;
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_array[i].title() == title) {
				found = &m_array[i];
			}
		}
		return found;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& collection)
	{
		for (size_t i = 0; i < collection.size(); i++)
		{
			os << collection[i];
		}
		return os;
	}
}
#endif
