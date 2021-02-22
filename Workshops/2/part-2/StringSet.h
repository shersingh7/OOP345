//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       2 
// Date:           28/01/2021
//==============================================

#ifndef _SDDS_RECORDSET_H
#define _SDDS_RECORDSET_H

#include <string>
#include <fstream> 
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds 
{
	class StringSet 
	{
		string* str = nullptr;
		size_t noOfRec = 0;

		public:
			StringSet();	//Default Constructor
			StringSet(const string& file);	// Constructor that recieves the name of the file
			StringSet(const StringSet& obj);	//Constructor that sets the source object to current object
			~StringSet();	//Destructor

			size_t size();	//Returns the number of strings stored in the current object
			std::string operator[](size_t);		//Returns a copy of the string at the index received as the function parameter
			StringSet& operator=(const StringSet& obj);	
			StringSet(StringSet&& ) noexcept;
			StringSet& operator=( StringSet&& obj) noexcept;
	};
}



#endif // !_SDDS_RECORDSET_H
