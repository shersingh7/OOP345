//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       2 
// Date:           28/01/2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include "StringSet.h"

using namespace sdds;

StringSet::StringSet() : str{ nullptr }, noOfRec(0) {};


StringSet::StringSet(const string& file)
{
    size_t temp = 0;

    std::ifstream f(file);

        while (!f.eof()) 
        {
            std::string string;
            getline(f, string, ' ');

            ++temp;
        }

    noOfRec = temp;  
    f.close();

    str = new string[noOfRec];
    size_t index = 0;

    f.open(file);

    while (!f.eof()) 
    {
        getline(f, str[index++], ' ');
    }

    f.close();
}

StringSet::StringSet(const StringSet& obj)
{
    *this = obj;
}

StringSet& StringSet::operator=(const StringSet& source) 
{
    if (this != &source)
    {
        if (source.noOfRec > 0)
        {
            str = new string[source.noOfRec];
            noOfRec = source.noOfRec;

            for (unsigned int i = 0; i < source.noOfRec; i++)
            {
                str[i] = source.str[i];
            }
        }
    }
    return *this;
}

StringSet::~StringSet() 
{
    delete[] str;
}

size_t StringSet::size() 
{
    return noOfRec;
}

std::string StringSet::operator[](size_t index) 
{
    if (index < 0 || index > noOfRec || str == nullptr) 
    {
        return "";
    }
    else 
    {
        return str[index];
    }      
}

StringSet& StringSet::operator=(StringSet&& obj) noexcept 
{
    if (this != &obj)
    {
        noOfRec = obj.noOfRec;
        str = obj.str;
        obj.noOfRec = 0u;
        obj.str = nullptr;
    }
    return *this;
}

StringSet::StringSet(StringSet&& obj) noexcept 
{
    *this = std::move(obj);
}
