/***********************************************************************
// OOP244 Workshop w3p1:  Department cpp file
//
// File Department.cpp
// Version 1.0
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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds
{

    void Department::updateName(const char* newname)
    {
        if (newname != NULL && newname[0] != '\0')
        {
            if (m_Name)
            {
                delete[] m_Name;
            }
            m_Name = new char[strlen(newname) + 1];
            strcpy(m_Name, newname);
        }
    }

    void Department::updateBudget(double change)
    {
        m_budget += change;
    }

    bool Department::addProject(Project& newproject)
    {
        bool success;

        if ((totalexpenses() + newproject.cost) <= m_budget)
        {
            if (m_numOfProject == 0)
            {
                m_project = new Project[1];                     
                *m_project = newproject;
            }
            else
            {
                Project* temp = nullptr;                        
                temp = new Project[m_numOfProject + 1];
                for (int i = 0; i < m_numOfProject; i++)
                {
                    temp[i] = m_project[i];
                }
                temp[m_numOfProject] = newproject;

                delete[] m_project;
                m_project = nullptr;
                m_project = temp;   
            }
            m_numOfProject += 1;
            success = true;
        }
        else
        {
            success = false;
        }
        return success;
    }

    void Department::createDepartment(const char* newname,
        Project& newproject,
        double change)
    {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }
    Project* Department::fetchProjects() const
    {
        return m_project;
    }
    int Department::fetchNumProjects() const
    {
        return m_numOfProject;
    }
    double Department::fetchBudget() const
    {
        return m_budget;
    }
    char* Department::fetchName() const
    {
        return m_Name;
    }
    double Department::totalexpenses()
    {
        double totalCost = 0;
        for (int i = 0; i < m_numOfProject; i++)
        {
            totalCost += m_project[i].cost;
        }
        return totalCost;
    }
    double Department::remainingBudget()
    {
        return m_budget - Department::totalexpenses();
    }
    void Department::clearDepartment()
    {
        delete[] m_Name;   
        m_Name = nullptr;
        delete[] m_project;  
        m_project = nullptr;
        m_numOfProject = 0;
        m_budget = 0;
    }

    
    void display(const Project& project) {
        cout << "Project " << project.topic
            << " will cost a total of " << project.cost << " C$." << endl;
    }

    
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }

}