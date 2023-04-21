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


#ifndef SDDS_PACKAGE_H_
#define SDDS_PACKAGE_H_
#define filename_r "Filtered_Dataset.csv"

namespace sdds {

    struct Customers {
        char* Packagename;
        double time_hrs;
        int Id;
        int Fwifi_time;
        int Fc_Time;
        int day_Year;
        char day_Week;
    };

    int loadTraces(); 
    void grouptTraces();
    void display();
    int loadTraces(Customers& user);
    void  deallocateMemory();

}
#endif