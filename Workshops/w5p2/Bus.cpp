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

#include <iostream>
#include "Bus.h"
using namespace std;
namespace sdds
{
    Bus::~Bus() {
    }
    Bus::Bus(int numSeats, int numPass) {
        if (numSeats % 2 != 0 || (numSeats < 10 || numSeats > 40) ||
            (numPass < 0 || numPass > numSeats)) {
            m_NumSeats = -1;
        }
        else {
            m_NumSeats = numSeats;
            m_NoOfPass = numPass;
        }
    }
    ostream &Bus::display(ostream &ostr) const {
        if (m_NumSeats <= 0){
            ostr << "Out of service!" << endl;
        }
        else {
            Draw_Bus(m_NumSeats, m_NoOfPass, ostr);
            ostr << "Total Fare Price: ";
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << double(*this) << endl;
        }
        return ostr;
    }
    void Bus::Draw_Bus(int seats, int noOfPassengers, ostream &ostr) const {
        int i, p;
        ostr.fill('_');
        ostr.width((seats / 2) * 3 + 4);
        ostr << "_";
        ostr << endl
             << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]")
            ;
        ostr << "|_\\_" << endl;
        ostr << "| ";
        ostr.fill(' ');
        ostr.width(((seats / 2) * 3 - 14) / 2);
        ostr << " "
             << "Seneca College";
        ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
        ostr << " "
             << "    )" << endl;
        ostr << "`---OO";
        ostr.fill('-');
        ostr.width((seats / 2) * 3 - 5);
        ostr << "-"
             << "O---'" << endl;
    }
    istream &Bus::read(istream &istr) {
        istr >> m_NumSeats;
        istr.ignore();
        istr >> m_NoOfPass;
        istr.ignore();

        if (m_NumSeats % 2 != 0 || (m_NumSeats < 10 || m_NumSeats > 40) ||
            (m_NoOfPass < 0 || m_NoOfPass > m_NumSeats)) {
            m_NumSeats = -1;
        }
        return istr;
    }
    Bus::operator bool() const {
        return m_NumSeats > 0;
    }
    Bus::operator int() const {
        return (bool(*this) ? m_NoOfPass : -1);
    }
    Bus::operator double() const {
        return (bool(*this) ? m_NoOfPass *Bus_Tickets : -1);
    }
    bool Bus::operator--() {
        bool result = true;
        if (!bool(*this) || m_NoOfPass == 0) {
            result = false;
        }
        else {
            m_NoOfPass -= 1;
            result = true;
        }
        return result;
    }
    bool Bus::operator++() {
        bool result = true;
        if (!bool(*this) || m_NoOfPass >= m_NumSeats) {
            result = false;
        }
        else {
            m_NoOfPass += 1;
            result = true;
        }
        return result;
    }
    bool Bus::operator--(int) {
        bool result = true;
        if (!bool(*this) || m_NoOfPass == 0) {
            result = false;
        }
        else {
            m_NoOfPass -= 1;
            result = true;
        }
        return result;
    }
    bool Bus::operator++(int) {
        bool result = true;
        if (!bool(*this) || m_NoOfPass >= m_NumSeats) {
            result = false;
        }
        else {
            m_NoOfPass += 1;
            result = true;
        }
        return result;
    }
    Bus &Bus::operator=(int value) {
        m_NoOfPass = value;
        if (m_NoOfPass > m_NumSeats) {
            m_NumSeats = -1;
        }
        return *this;
    }
    Bus &Bus::operator+=(int value) {
        if (bool(*this) && m_NoOfPass < m_NumSeats) {
            m_NoOfPass += value;
        }
        else {
            m_NumSeats = -1;
        }
        return *this;
    }
    Bus &Bus::operator+=(Bus &right) {
        int empty = m_NumSeats - m_NoOfPass;
        if (bool(*this) && bool(right))
        {
            if (empty < right.m_NoOfPass) {
                right.m_NoOfPass -= empty;
                m_NoOfPass = m_NumSeats;
            }
            else {
                right.m_NoOfPass = 0;
                m_NoOfPass += right.m_NoOfPass;
            }
        }
        return *this;
    }
    bool Bus::operator==(const Bus &right) const {
        bool result = true;
        if (bool(*this) && bool(right)) {
            if (m_NoOfPass == right.m_NoOfPass) {
                result = true;
            }
            else {
                result = false;
            }
        }
        return result;
    }
    int operator+(int left, const Bus &right) {
        int sum = 0;
        if (bool(right)) {
            sum = left + int(right);
        }
        else {
            sum = left;
        }
        return sum;
    }
    ostream &operator<<(ostream &ostr, const Bus &right) {
        right.display(ostr);
        return ostr;
    }
    istream &operator>>(istream &istr, Bus &right) {
        right.read(istr);
        return istr;
    }
}