/***********************************************************************
// Workshop 1 p1: tester program
//
// File  file.h
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

#ifndef SDDS_FILE_H

#define SDDS_FILE_H


namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);
}
#endif