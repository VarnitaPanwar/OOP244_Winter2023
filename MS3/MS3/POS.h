/***********************************************************************
// OOP244 Project MS3:  POS h file
//
// File POS.h 
// Version 1.0
// Date  04/01/2023
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

#define TAX 0.13
#define MAX_SKU_LEN 7

#define MIN_YEAR 2000
#define MAX_YEAR 2030

#define MAX_STOCK_NUMBER 99
#define MAX_NO_ITEMS 2000

#define MAX_NAME_LEN 40

#define POS_LIST 1
#define POS_FORM 2

#define ERROR_POS_SKU "SKU too long"
#define ERROR_POS_NAME "Item name too long"
#define ERROR_POS_PRICE "Invalid price value"
#define ERROR_POS_TAX "Invalid tax status"
#define ERROR_POS_QTY "Invalid quantity value"
#define ERROR_POS_STOCK "Item out of stock"
#define ERROR_POS_EMPTY "Invalid Empty Item"