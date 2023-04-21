/***********************************************************************
// OOP244 Workshop 5 Part1: Operators
// File EggCarton.cpp
// Version 1.0
// Date	02/16/2023
// Author Varnita Panwar
// Description
// Tests EggCarton module
// Update the code.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds
{
    EggCarton& EggCarton::set_Broken(int size, int noOfEggs)
    {
        Size = size;
        noOfEgg = noOfEggs;
        return *this;
    }
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        if ((size < 6 || size > 36) || (noOfEggs < 0 || noOfEggs > size) || (size % 6) != 0)
        {
            set_Broken(-1, -1);
        }
        else
        {
            Size = size;
            noOfEgg = noOfEggs;
            JumboSize = jumboSize;
        }
    }
    ostream& EggCarton::display(ostream& ostr) const
    {
        if (bool(*this))
        {
            dis_Carton(Size, noOfEgg, JumboSize, ostr);
        }
        else
        {
            ostr << "Broken Egg Carton!" << endl;
        }
        return ostr;
    }
    ostream& EggCarton::dis_Carton(int size, int noOfEggs, bool jumbo, ostream& ostr) const
    {
        int cartonWidth = size == 6 ? 3 : 6;
        for (int i = 0; i < size; i++)
        {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        return ostr;
    }
    istream& EggCarton::read(istream& istr)
    {
        JumboSize = false;
        char jumbo;
        istr >> jumbo;
        if (jumbo == 'j')
        {
            JumboSize = true;
        }
        istr.ignore();
        istr >> Size;
        istr.ignore();
        istr >> noOfEgg;

        if ((Size < 6 || Size > 36) || (noOfEgg < 0 || noOfEgg > Size) || (Size % 6) != 0)
        {
            set_Broken(-1, -1);
        }
        return istr;
    }
    EggCarton::operator bool() const
    {
        return Size > 0;
    }
    EggCarton::operator int() const
    {
        if (bool(*this))
        {
            return noOfEgg;
        }
        else
        {
            return -1;
        }
    }
    EggCarton::operator double() const
    {
        double totalWeight = 0.0;
        if (bool(*this))
        {
            totalWeight = (noOfEgg * (JumboSize ? JumboEggWieght : RegularEggWieght)) / 1000.0;
        }
        else
        {
            totalWeight = -1.0;
        }
        return totalWeight;
    }
    EggCarton& EggCarton::operator--()
    {
        if (bool(*this) && noOfEgg > 0)
        {
            noOfEgg -= 1;
        }
        return *this;
    }
    EggCarton& EggCarton::operator++()
    {
        if (bool(*this))
        {
            noOfEgg += 1;
            if (noOfEgg > Size)
            {
                set_Broken(-1, -1);
            }
        }
        return *this;
    }
    EggCarton EggCarton::operator--(int)
    {
        EggCarton old(*this);
        --(*this);
        return old;
    }
    EggCarton EggCarton::operator++(int)
    {
        EggCarton old(*this);
        ++(*this);
        return old;
    }
    EggCarton& EggCarton::operator=(int value)
    {
        noOfEgg = value;
        if (noOfEgg > Size)
        {
            set_Broken(-1, -1);
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(int value)
    {
        if (bool(*this))
        {
            noOfEgg += value;
            if (noOfEgg > Size)
            {
                set_Broken(-1, -1);
            }
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(EggCarton& right)
    {
        if (bool(*this))
        {
            int spaceLeft = Size - noOfEgg;
            noOfEgg += right.noOfEgg;
            noOfEgg = Size;
            right.noOfEgg -= spaceLeft;
        }
        return *this;
    }
    bool EggCarton::operator==(const EggCarton& right) const
    {

        return (double(JumboSize) - double(right.JumboSize) >= -0.001) &&
            (double(JumboSize) - double(right.JumboSize) >= 0.001);
    }
    int operator+(int left, const EggCarton& right)
    {
        int sum = 0;
        if (bool(right))
        {
            sum = left;
        }
        else
        {
            sum = left + right;
        }
        return sum;
    }
    ostream& operator<<(ostream& ostr, const EggCarton& right)
    {
        right.display(ostr);
        return ostr;
    }
    istream& operator>>(istream& istr, EggCarton& right)
    {
        right.read(istr);
        return istr;
    }
    EggCarton::~EggCarton()
    {
    }
}