/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.cpp
// Version 1.0
// Date	02/20/2023
// Author Varnita Panwar
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>
using namespace std;
namespace sdds {
    const double Bus_Tickets = 125.34;
    class Bus {
        int m_NumSeats;
        int m_NoOfPass;
        void Draw_Bus(int seats, int noOfPassengers, ostream& ostr) const;

    public:
        ostream& display(ostream& ostr = cout) const;
        Bus(int numSeats = 20, int numPass = 0);
        ~Bus();
        istream& read(istream& istr = cin);
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator--();
        bool operator++();
        bool operator--(int);
        bool operator++(int);
        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);
        bool operator==(const Bus& right) const;
    };
    int operator+(int left, const Bus& right);
    ostream& operator<<(ostream& ostr, const Bus& right);
    istream& operator>>(istream& istr, Bus& right);
}
#endif
