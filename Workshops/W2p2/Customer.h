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


#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds
{

    struct Customers
    {
        char username[21];
        int retweets;
        int likes;
        int replies;
        char share_videos;
    };

    struct CustomersRecord
    {
        Customers* ptr_rec;  
        int noOfRecords;
    };


    void EmptyRecord(Customers& c_rec);
    void EmptyRecord(CustomersRecord& t_rec);
    bool read(Customers& rec);
    void read(char* str, int len);
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
    void display(const Customers& c_rec);
    void display(const CustomersRecord& t_rec);

}

#endif