/***********************************************************************
// OOP244 Workshop 2 p2
//
// Version 1.0
// Date 01/27/2023
// Author Varnita panwar
// Description
// MyId: 166484212
// Email: vpanwar1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include "Tools.h"

namespace sdds
{
    void strCpy(char* str1, const char* str2)
    {
        while (*str2)
        {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
}