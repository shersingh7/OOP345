//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       4 
// Date:           12/02/2021
//==============================================

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds 
{
    class ConfirmationSender
    {
       const Reservation** confirmReservation;
        size_t confirmNum;

    public:

        ConfirmationSender();
        ~ConfirmationSender();

        size_t size() const ;

        ConfirmationSender(const ConfirmationSender&);
        ConfirmationSender(ConfirmationSender&&) noexcept;

        ConfirmationSender& operator+=( const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        ConfirmationSender& operator=(const ConfirmationSender& res);
        ConfirmationSender& operator=(ConfirmationSender&& res)noexcept;

        friend ostream& operator<<(ostream& os, const ConfirmationSender& src);
    };
}

#endif //!_SDDS_CONFIRMATIONSENDER_H
