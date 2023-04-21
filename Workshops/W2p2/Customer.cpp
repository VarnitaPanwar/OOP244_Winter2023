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

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds 
{
    void EmptyRecord(Customers& c_rec)
    {
        c_rec = { 0 };
    }
    void EmptyRecord(CustomersRecord& t_rec)
    {
        t_rec.ptr_rec = nullptr;
        t_rec.noOfRecords = 0;
    }

    bool read(Customers& rec)
    {
        bool validValue;

        cout << " Enter User name: ";
        read(rec.username, 21);
        if (rec.username[0] != '\0')
        {
            validValue = true;
            cout << " Enter likes_count: ";
            cin >> rec.likes;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets;
            cout << " Enter replies_count: ";
            cin >> rec.replies;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
        }
        else
        {
            validValue = false;
        }

        return validValue;
    }
    void read(char* str, int len)
    {  
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
    {
        if (t_rec.noOfRecords == 0)
        {
            t_rec.ptr_rec = new Customers[t_rec.noOfRecords + 1];
            *t_rec.ptr_rec = c_rec;
        }
        else
        {
            int i;
            Customers* newCustomer = nullptr;
            newCustomer = new Customers[t_rec.noOfRecords + 1];

            for (i = 0; i < t_rec.noOfRecords; i++)
            {
                newCustomer[i] = t_rec.ptr_rec[i];
            }
            newCustomer[t_rec.noOfRecords] = c_rec;

            delete[] t_rec.ptr_rec;
            t_rec.ptr_rec = nullptr;
            t_rec.ptr_rec = newCustomer;
        }
        t_rec.noOfRecords += 1;
    }

    void display(const Customers& c_rec)
    {
        cout << c_rec.username << ", "
            << c_rec.likes<< ", "
            << c_rec.retweets << ", "
            << c_rec.replies << ", "
            << c_rec.share_videos << endl;
    }
    void display(const CustomersRecord& t_rec)
    {
        int i;
        for (i = 1; i < t_rec.noOfRecords + 1; i++)
        {
            cout << i << ". ";
            display(t_rec.ptr_rec[i - 1]);
            cout << endl;
        }
    }
  
}