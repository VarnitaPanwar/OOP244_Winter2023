/***********************************************************************
// OOP244 Workshop 2 p1
//
// Version 1.0
// Date Jan 27 Winter 2023
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
#include <cstring>
#include "Package.h"
#include "Tools.h"

using namespace std;
namespace sdds {
    int no_of_traces;
    Customers* users;

   
    int loadTraces() { 
        bool check = true;
        int i = 0;
        if (openFile_r(filename_r))
        {
            
            no_of_traces = NoOfTraces();
            
            users = new Customers[no_of_traces];

            
            for (i = 0; i < no_of_traces; i++) {
                loadTraces(users[i]);
            }
            
            if (i != no_of_traces) {
                cout << "Error reading the records, Check the data file " << endl;
            }
            else {
                
                check = true;
            }

            
            closefile();
        }
        else {
            cout << "Could not open the" << filename_r << " data file" << endl;
        }
        return check;
    }

   

    int loadTraces(Customers& user_info) { 
        bool check = false;
        char read_Package_name[50];

        if (read(user_info.day_Week) && read(user_info.Id) && read(user_info.time_hrs) && read(user_info.day_Year) &&
            read(user_info.Fwifi_time) && read(user_info.Fc_Time) &&
            read(read_Package_name)) { 
            user_info.Packagename = new char[strlen(read_Package_name) + 1];
            
            strCpy(user_info.Packagename, read_Package_name);
            
            check = true;
        }
        return check;
    }

    void grouptTraces() { 
        int i, j;
        Customers temp_record;
        for (i = no_of_traces - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (users[j].Id > users[j + 1].Id) {
                    temp_record = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp_record;
                }
            }
        }
    }

    void display(){
        for (int i = 0; i < no_of_traces; i++){
            if (users[i].time_hrs > 1.0 && users[i].day_Week == 'F'){
                cout << users[i].Id << "," << users[i].time_hrs << ","
                    << users[i].Fc_Time << "," << users[i].Fwifi_time << "," << users[i].Packagename << endl;
            }
        }
    }
    
    void deallocateMemory() {
        for (int i = 0; i < no_of_traces; i++) {
            delete[] users[i].Packagename;
            users[i].Packagename = nullptr;
        }
        delete[] users;
        users = nullptr;
    }

}