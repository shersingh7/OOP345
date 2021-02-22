//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       4 
// Date:           12/02/2021
//==============================================

#include"ConfirmationSender.h"

using namespace std;

namespace sdds 
{
	ConfirmationSender::ConfirmationSender() 
	{
		confirmReservation = nullptr;
		confirmNum = 0;
	}

	ConfirmationSender::~ConfirmationSender() 
	{
		delete[] confirmReservation;
		confirmReservation = nullptr;
	} 

	size_t ConfirmationSender::size() const 
	{
		return confirmNum;  
	} 

	ConfirmationSender::ConfirmationSender( const ConfirmationSender& src) 
	{
		if (this != &src) 
		{
			*this = src;
		}
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept 
	{    
		if (src.confirmReservation != nullptr) 
		{  
			swap(confirmReservation, src.confirmReservation); 
			confirmNum = src.confirmNum; 
			src.confirmNum = 0;  
			src.confirmReservation = nullptr; 
		}
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& src) 
	{
        bool ok = false;  

        for (size_t i = 0; i < confirmNum; i++) 
		{
            if (confirmReservation[i] == &src) 
			{
                ok = true;
            } 
        }

        if (ok == false)
		{   
            const Reservation** temp = nullptr;  
            temp = new  const Reservation * [confirmNum + 1]; 

			for (size_t i = 0; i < confirmNum; ++i)
			{
				temp[i] = confirmReservation[i];
			}

             temp[confirmNum] = &src; 
			++confirmNum;

            delete[] confirmReservation;
            confirmReservation = temp; 
        }
        return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& src)
	{  
        for (size_t i = 0; i < confirmNum; i++)
		{
            if (confirmReservation[i] == &src) 
			{ 
                confirmReservation[i] = nullptr; 
            }
        }
        return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& src) 
	{  
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;

		if (src.confirmNum == 0) 
		{
			os << "The object is empty!" << endl;
		}
		else 
		{
			for (size_t i = 0; i < src.size(); i++) 
			{
				if (src.confirmReservation[i] != nullptr)
				{
					os << *src.confirmReservation[i];
				}
			}
		}
		os << "--------------------------" << endl;

		return os;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& res)
	{
		if (this != &res) 
		{
			delete[] confirmReservation;
			confirmReservation = nullptr;

			confirmNum = res.confirmNum;
			confirmReservation = new const Reservation * [res.confirmNum + 1];

			for (size_t i = 0; i < confirmNum; i++) 
			{
				confirmReservation[i] = res.confirmReservation[i];
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& res)noexcept 
	{
		if (this != &res) 
		{
			delete[] confirmReservation;
			confirmReservation = res.confirmReservation;
			res.confirmReservation = nullptr;

			confirmNum = res.confirmNum;
			res.confirmNum = 0;
		}
		return *this;
	}
}




