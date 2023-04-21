/***********************************************************************
// OOP244 Workshop 2 p1
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
#include <cstdio>
#include <iostream>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds
{
    int openFile_r(const char filename[]) { 
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int NoOfTraces(){ 
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }

    

    int read(char packName[])  {
        return fscanf(fp, "%60[^\n]\n", packName);
    }

    int read(int& cusTimeUsing) {
        return fscanf(fp, "%d,", &cusTimeUsing);
    }

    int read(double& timeInHours)  {
        return fscanf(fp, "%lf,", &timeInHours); 
    }

    int read(char& dayOfWeek) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &dayOfWeek);
    }

    void closefile()  { 
        if (fp)
            fclose(fp);
    }

    void strCpy(char* str1, const char* str2) { 
        while (*str2)
        {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) { 
        int i = -1;
        while (str[++i])
            ;
        return i;
    }
}