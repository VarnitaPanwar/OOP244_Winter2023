/***********************************************************************
// Workshop 1 p1: tester program
//
// File  50Best.cpp
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


#include <iostream>
#include "Movie.h"
using namespace std;
using namespace sdds;

namespace sdds
{
    void flushkeys()
    {
        while (cin.get() != '\n')
            ;
    }
    bool yes()
    {
        char ch = cin.get();
        flushkeys();
        return ch == 'y' || ch == 'Y';
    }
    int main()
    {
        bool done = false;
        char genre[128];
        loadMovies();
        cout << "Welcome to 50 top movies of all times \"genre\" search." << endl
            << endl;
        while (!done)
        {
            cout << "Enter the movie genre to start the search: ";
            cin >> genre;
            flushkeys();
            displayMoviesWithGenre(genre);
            cout << "Do another search? (Y)es: ";
            done = !yes();
            cout << endl;
        }
        cout << "Goodbye!" << endl;
        return 0;
    }
}
int main()
{
    bool done = false;
    char genre[128];
    loadMovies();
    cout << "Welcome to 50 top movies of all times \"genre\" search." << endl
        << endl;
    while (!done)
    {
        cout << "Enter the movie genre to start the search: ";
        cin >> genre;
        flushkeys();
        displayMoviesWithGenre(genre);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}