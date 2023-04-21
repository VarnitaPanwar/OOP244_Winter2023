/***********************************************************************
// Workshop 1 p1: tester program
//
// File  movie.h
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

#ifndef SDDS_MOVIE_H 
#define SDDS_MOVIE_H


namespace sdds
{
    struct Movie
    {
        char m_title[128];
        int m_year;
        char m_rating[6];
        int m_duration;
        char m_genres[10][11];
        float m_consumerRating;
    };
    bool loadMovies();
    bool hasGenre(const Movie* mvp, const char genre[]);
    void displayMovie(const Movie* mvp);
    void displayMoviesWithGenre(const char genre[]);
}
#endif