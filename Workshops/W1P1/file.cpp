/***********************************************************************
// Workshop 1 p1: tester program
//
// File  file.cpp
// Version 1.0
// Date JAN 20 winter 2023
// Author Varnita Panwar
// ID: 166484212
// Email: vpanwar1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name Varnita Panwar    Date Jan 20 2023   Reason update files
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "File.h"
using namespace std;
namespace sdds
{
    FILE* fptr;
    
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile()
    {
        if (fptr)
            fclose(fptr);
    }

    
    bool readTitle(char title[])
    {
        return fscanf(fptr, "%[^(](", title) == 1;
    }

    bool readYear(int* year)
    {
        return fscanf(fptr, "%d)", year) == 1;
    }

  
    bool readMovieRating(char rating[])
    {
        return fscanf(fptr, " %[^|]|", rating) == 1;
    }

    bool readDuration(int* duration)
    {
        return fscanf(fptr, "%d|", duration) == 1;
    }

    bool readGenres(char genre[][11])
    {
        char genres[256];
        int gi = 0; // genres index;
        int i = 0;  // genre[i] index
        int j = 0;  // genre[i][j] index
        bool res = fscanf(fptr, " %[^|]|", genres);
        if (res)
        { 
            res = false;
            while (genres[gi])
            {
                if (genres[gi] != ',')
                {
                    genre[i][j++] = genres[gi++];
                    res = true;
                }
                else
                {
                    genre[i][j] = '\0';
                    i++;
                    gi++;
                    j = 0;
                }
            }
        }
        genre[i++][j] = '\0';
        genre[i][0] = '\0'; // NULL terminating the array of strings
        return res;
    }

   
    bool readConsumerRating(float* rating)
    {
        return fscanf(fptr, "%f\n", rating) == 1;
    }
}