//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       3 
// Date:           06/02/2021
//==============================================

#ifndef _SDDS_PAIRSUMMABLE_H__
#define _SDDS_PAIRSUMMABLE_H__

#include "Pair.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace sdds 
{
    template<typename V, typename K>
    class PairSummable : public Pair<V, K> 
    {
        static const V initial;
        static size_t minWidth;
    public:

        PairSummable()
        {  
        }

        PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) 
        {
            if (minWidth < key.size()) 
            {
                minWidth = key.size();
            }
        }
        
        bool isCompatibleWith(const PairSummable<V, K>& b)
        {
            return this->key() == b.key();
        }


        void display(std::ostream& os) const 
        {
            os << left;
            os.width(minWidth);
            Pair<V, K>::display(os);
            os << right;
        }
        
        PairSummable<V, K>& operator+=(const PairSummable<V, K>& source) {

            if (this->isCompatibleWith(source.key())) {
                PairSummable<V,K> temp(this->key(), source.value() + this->value());
                *this = temp;
            }
            return *this;
        }
    };

    template<>
    const string PairSummable <string, string> ::initial ="";

    template<>
    const int PairSummable <int, string> ::initial = 0;

    template <typename V, typename K>
    size_t PairSummable<V, K>::minWidth = 0;

    template<>
    PairSummable<string, string>& PairSummable<string, string>::operator += (const PairSummable<string, string>& src)
    {

        if (this->isCompatibleWith(src.key()))
        {
            string source;

            if (this->value() == "") 
            {
                source = src.value();
            }
            else 
            {
                source = this->value() + ", " + src.value();
            }

            PairSummable<string, string> temp(this->key(), source);
            *this = temp;
        }

        return *this;
    }

}
#endif //!_SDDS_PAIRSUMMABLE_H__


