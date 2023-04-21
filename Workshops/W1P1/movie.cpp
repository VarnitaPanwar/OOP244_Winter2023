/***********************************************************************
// Workshop 1 p1: tester program
//
// File  movie.cpp
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
#include "Movie.h"
#include "File.h"
using namespace std;
using namespace sdds;
namespace sdds
{
    Movie movies[50];
    bool loadMovies()
    {
        Movie mv;
        int mnum = 0; // number of movies read
        bool ok = true;
        if (openFile("movies.dat"))
        {
            while (ok && mnum < 50)
            {
                ok = readTitle(mv.m_title) &&
                    readYear(&mv.m_year) &&
                    readMovieRating(mv.m_rating) &&
                    readDuration(&mv.m_duration) &&
                    readGenres(mv.m_genres) &&
                    readConsumerRating(&mv.m_consumerRating);
                if (ok)
                    movies[mnum++] = mv;
            }
            closeFile();
        }
        return mnum == 50;
    }
    bool hasGenre(const Movie* mvp, const char genre[])
    {
        int i = 0;
        bool found = false;
        while (!found && mvp->m_genres[i][0])
        {
            if (strstr(mvp->m_genres[i++], genre))
            {
                found = true;
            }
        }
        return found;
    }
    void displayMovie(const Movie* mvp)
    {
        int i = 1;
        cout << mvp->m_title << " [" << mvp->m_year << "], "
            << mvp->m_rating << ", duration: " << mvp->m_duration << " minutes, Rating: " << mvp->m_consumerRating << "/10" << endl
            << "    (" << mvp->m_genres[0];
        while (mvp->m_genres[i][0])
        {
            cout << ", " << mvp->m_genres[i++];
        }
        cout << ")" << endl;
    }
    void displayMoviesWithGenre(const char genre[])
    {
        int i, j;
        for (i = 0, j = 1; i < 50; i++)
        {
            if (hasGenre(&movies[i], genre))
            {
                cout << j++ << "- ";
                displayMovie(&movies[i]);
            }
        }
        if (j == 1)
        {
            cout << "No match found for: " << genre << endl;
        }
    }
}