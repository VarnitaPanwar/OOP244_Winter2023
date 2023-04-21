/***********************************************************************
// OOP244 Workshop 4 Part2
// File NameTag.cpp
// Version 1.0
// Date	Feb 15 2023
// Author Varnita Panwar
// Description
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NameTag.h"

using namespace std;
namespace sdds
{
    NameTag::NameTag()
    {
        Name = nullptr;
        Extn = 0;
    }
    NameTag::NameTag(const char* name)
    {
        *this = NameTag();
        if (name)
        {
            Name = new char[strlen(name) + 1];
            strcpy(Name, name);
        }
    }
    NameTag::NameTag(const char* name, int extension)
    {
        *this = NameTag();
        if (name)
        {
            Name = new char[strlen(name) + 1];
            strcpy(Name, name);
        }
        Extn = extension;
    }
    NameTag::~NameTag()
    {
        delete[] Name;
        Name = nullptr;
    }
    NameTag& NameTag::read()
    {
        char temp_Name[41];
        char option;
        int ex = 0;
        bool isError = false;
        cout << "Please enter the name: ";
        cin.get(temp_Name, 41, '\n');
        cin.clear();
        cin.ignore(1000, '\n');
        if (Name)
        {
            delete[] Name;
        }
        Name = nullptr;
        Name = new char[strlen(temp_Name) + 1];
        strcpy(Name, temp_Name);

        if (strlen(Name) == 0 || strcmp(Name, " ") == 0)
        {
            cout << "EMPTY NAMETAG!" << endl;
        }
        else
        {
            cout << "Would you like to enter an extension? (Y)es/(N)o: ";
            do
            {
                cin >> option;
                cin.clear();
                cin.ignore(1000, '\n');
                if (toupper(option) != 'Y' && toupper(option) != 'N')
                {
                    cout << "Only (Y) or (N) are acceptable, try agin: ";
                    isError = true;
                }
                else
                {
                    isError = false;
                }
            } while (isError);
            if (toupper(option) == 'Y')
            {
                cout << "Please enter a 5 digit phone extension: ";
                do
                {
                    isError = false;
                    cin >> ex;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    if (cin.fail() || !ex)
                    {
                        cout << "Bad integer value, try again: ";
                        isError = true;
                    }
                    else if (ex > 99999 || ex < 10000)
                    {
                        cout << "Invalid value [10000<=value<=99999]: ";
                        isError = true;
                    }
                } while (isError);
            }
        }
        Extn = ex;
        return *this;
    }
    void NameTag::print() const
    {
        if (Name == nullptr || (Extn != 0 && (Extn < 10000 || Extn > 99999)))
        {
            cout << "EMPTY NAMETAG!" << endl;
        }
        else
        {
            int len = strlen(Name);
            int width;
            if (len < 20)
            {
                width = 22;
            }
            else if (len >= 40)
            {
                width = 42;
            }
            else
            {
                width = len + 2;
            }
            // Line: 1
            cout << "+";
            for (int i = 0; i < width; i++)
            {
                cout << "-";
            }
            cout << "+" << endl;
            // Line: 2
            cout << "|";
            for (int i = 0; i < width; i++)
            {
                cout << " ";
            }
            cout << "|" << endl;
            // Line: 3
            cout << "| ";
            for (int i = 0; i < len && i < 40; i++)
            {
                cout << Name[i];
            }
            if (len < 20)
            {
                cout.width(width - len - 1);
                cout << ' ' << '|' << endl;
            }
            else
            {
                cout << " |" << endl;
            }
            // Line: 4
            cout << "|";
            for (int i = 0; i < width; i++)
            {
                cout << " ";
            }
            cout << "|" << endl;
            // Line: 5
            if (Extn == 0)
            {
                cout << "| Extension:"
                    << " N/A";
                cout.width(width - 14);
                cout.fill(' ');
            }
            else
            {
                cout << "| Extension: " << Extn;
                cout.width(width - 5 - 11);
                cout.fill(' ');
            }
            cout << "|" << endl;
            // Line: 5
            cout << "|";
            for (int i = 0; i < width; i++)
            {
                cout << " ";
            }
            cout << "|" << endl;
            // Line: 6
            cout << "+";
            for (int i = 0; i < width; i++)
            {
                cout << "-";
            }
            cout << "+" << endl;
        }
    }
}
