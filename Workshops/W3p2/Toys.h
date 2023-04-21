/***********************************************************************
// OOP244 Workshop 3 p2:  Toys header file
//
// File Toys.h
// Version 1.0
// Date  02/05/2023
// Author Varnita Panwar
// Section OOP244-NDD
// Seneca ID   : 166484212
// Seneca email: vpanwar1@myseneca.ca
//
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SDDS_TOYS_H
#define SDDS_TOYS_H
#define MAX_TNAME 31 

namespace sdds
{
	class Toys
	{
		char m_Toyname[MAX_TNAME] = { 0 };
		int m_sku = 0; 
		double m_Price = 0.0;
		int m_Age = 0;
		bool m_Sale = false;

	public:
		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display()const;
		int getSku()const;
		bool isOnSale()const;
	};
}
#endif // !SDDS_TOYS_H
