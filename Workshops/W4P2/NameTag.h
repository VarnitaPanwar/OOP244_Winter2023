/***********************************************************************
// OOP244 Workshop 4 Part2
// File NameTag.h
// Version 1.0
// Date	Feb 15 2023
// Author Varnita Panwar
// Description
// Header files
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
namespace sdds
{
    class NameTag
    {
        char* Name;
        int Extn;

    public:
        NameTag();
        NameTag(const char* name);
        NameTag(const char* name, int extension);
        ~NameTag();
        void print() const;
        NameTag& read();
    };
}
#endif
