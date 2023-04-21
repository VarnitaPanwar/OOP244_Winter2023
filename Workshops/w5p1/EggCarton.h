/***********************************************************************
// OOP244 Workshop 5 Part1: Operators
// File EggCarton.h
// Version 1.0
// Date	/16/2023
// Author Varnita Panwar
// Description
// Tests EggCarton module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_
#include <iostream>
using namespace std;
namespace sdds
{
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;
    class EggCarton
    {
        int Size;
        int noOfEgg;
        bool JumboSize;
        ostream& dis_Carton(int size, int noOfEggs, bool jumbo, ostream& ostr) const;
        EggCarton& set_Broken(int size, int noOfEggs);

    public:
        ostream& display(ostream& ostr = cout) const;
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
        ~EggCarton();
        istream& read(istream& istr = cin);
        operator int() const;
        operator double() const; 
        operator bool() const;
        EggCarton& operator--();
        EggCarton& operator++();
        EggCarton operator++(int);
        EggCarton& operator+=(int value);
        EggCarton operator--(int);
        EggCarton& operator=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;
    };
    int operator+(int left, const EggCarton& right);
    ostream& operator<<(ostream& ostr, const EggCarton& right);
    istream& operator>>(istream& istr, EggCarton& right);
}
#endif