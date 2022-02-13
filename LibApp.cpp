/***********************************************************************
// OOP244 LibApp Module
// File	LibApp.cpp
// Version
// Date 14/11/2021
// Author harmeen kaur
// Description
//
// Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//Student id : 150228203
//Section NII
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "LibApp.h"
#include <iomanip>
using namespace std;
namespace sdds {
    void LibApp::prnPub(Publication* p[], int size, int ref) {
        int i;
        for (i = 0; i < size; i++) {
            if (ref == p[i]->getRef()) {
                cout << *p[i] << endl;
                i = size; // Exit the loop.
            }
        }
    }
    LibApp::LibApp(const char* file) :m_changed(), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_publicationmenu("Choose the type of publication:")
    {
        m_changed = false;
        strcpy(m_filename, file);
        m_numpub = 0;
        m_librefapp = -1;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
       
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_publicationmenu << "Book" << "Publication";
        load();


    }
    bool LibApp::confirm(const char* message)
    {
        bool r = false;
        Menu temp(message);
        temp << "Yes";

        int i = temp.run();
        if (i == 1)
        {
            r = true;
        }
        return r;
    }
    void LibApp::load()
    {
        cout << "Loading Data" << endl;
        ifstream infile(m_filename);
       char type{}; 
       
      for(int i = 0; infile; i++)
        {
            infile >> type;
            
           
           if(infile) {
                if (type == 'P')
                    m_publication[i] = new Publication;
                else if (type == 'B')
                   m_publication[i] = new Book;
               if (m_publication[i])
                {
                    infile >> *m_publication[i];
                  
                    m_numpub++;
                }
           }
        }
        m_librefapp = m_publication[m_numpub - 1]->getRef();
    }
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
        ofstream onfile(m_filename);
        if (onfile.is_open())
        {
            for (int i = 0; i < m_numpub; i++) {
              
                if (m_publication[i]->getRef() != 0)
                {
                     onfile << *m_publication[i];
                }
            }
        }
    }
   int LibApp::search(int type)//(bool all, bool onloan, bool notloan)
    {
        int res = 0;
        char filename[256];
      
        int selection = -1;
        ifstream infile(m_filename);
       
        PublicationSelector ps("Select one of the following found matches:", 15);
        if (type == 1)
        {
            selection = m_publicationmenu.run();
            switch (selection)
            {
            case 1:
            {
                cout << "Publication Title: ";
                cin.getline(filename, '\n');
                char type{};
                int i;
                for (i = 0; i < m_numpub; i++) {
                    infile >> type;
                    infile.ignore();
                    if (infile) {
                        if (m_publication[i]->type() == 'B' && strstr(*m_publication[i], filename) && m_publication[i]->getRef() != 0)
                            ps << m_publication[i];
                       
                    }
                }
                if (ps) {
                    ps.sort(); // sort them based on date and title
                    int ref = ps.run(); // display the publications and select one
                    if (ref) {
                        
                        cout << *getPub(ref) << endl;
                        res = ref;
                    }
                    else {
                        cout << "Aborted!" << endl;
                    }
                }
                else {
                    cout << "No matches found!" << endl;
                }
               
                break;
            }
            case 2:
            {
                cout << "Publication Title: ";
                cin.getline(filename, '\n');
                char type{};
                int i;
                for (i = 0; i < m_numpub; i++) {
                    infile >> type;
                    infile.ignore();
                    if (infile) {

                        if (m_publication[i]->type() == 'P' && strstr(*m_publication[i], filename) && m_publication[i]->getRef() != 0)
                            ps << m_publication[i];
                       
                    }
                }
                if (ps) {
                    ps.sort(); // sort them based on date and title
                    int ref = ps.run(); // display the publications and select one
                    if (ref) {
                      
                        cout << *getPub(ref) << endl;
                        res = ref;
                    }
                    else {
                        cout << "Aborted!" << endl;
                    }
                }
                else {
                    cout << "No matches found!" << endl;
                }
                
                break;
            }
            case 0:
            {
                cout << "Aborted!" << endl;
                break;
            }
            }
        }
        if (type == 2)
        {
            selection = m_publicationmenu.run();
            switch (selection)
            {
            case 1:
            {
                cout << "Publication Title: ";
                cin.getline(filename, '\n');
                char type{};
                int i;
                for (i = 0; i < m_numpub; i++) {
                    infile >> type;
                    infile.ignore();
                    if (infile) {

                        if (m_publication[i]->type() == 'B' && strstr(*m_publication[i], filename) && m_publication[i]->onLoan())
                            ps << m_publication[i];
                        
                    }
                }
                if (ps) {
                    ps.sort(); // sort them based on date and title
                    int ref = ps.run(); // display the publications and select one
                    if (ref) {
                       
                        cout << *getPub(ref) << endl;
                        res = ref;
                    }
                    else {
                        cout << "Aborted!" << endl;
                    }
                }
                else {
                    cout << "No matches found!" << endl;
                }
                
                break;
            }
            case 2:
            {
                cout << "Publication Title: ";
                cin.getline(filename, '\n');
                char type{};
                int i;
                for (i = 0; i < m_numpub; i++) {
                    infile >> type;
                    infile.ignore();
                    if (infile) {

                        if (m_publication[i]->type() == 'P' && strstr(*m_publication[i], filename) && m_publication[i]->onLoan())
                            ps << m_publication[i];
                        
                    }
                }
                if (ps) {
                    ps.sort(); // sort them based on date and title
                    int ref = ps.run(); // display the publications and select one
                    if (ref) {
                      
                        cout << *getPub(ref) << endl;
                        res = ref;
                    }
                    else {
                        cout << "Aborted!" << endl;
                    }
                }
                else {
                    cout << "No matches found!" << endl;
                }
                
                break;
            }
            case 0:
            {
                cout << "Aborted!" << endl;
                break;
            }
            }
        }
        if (type == 3)
        {
            selection = m_publicationmenu.run();
            switch (selection)
            {
            case 1:
            {
                cout << "Publication Title: ";
                cin.getline(filename, '\n');
                char type{};
                int i;
                for (i = 0; i < m_numpub; i++) {
                    infile >> type;
                    infile.ignore();
                    if (infile) {

                        if (m_publication[i]->type() == 'B' && strstr(*m_publication[i], filename) && !m_publication[i]->onLoan())
                            ps << m_publication[i];
                      
                    }
                }
                if (ps) {
                    ps.sort(); // sort them based on date and title
                    int ref = ps.run(); // display the publications and select one
                    if (ref) {
                       
                        cout << *getPub(ref) << endl;
                        res = ref;
                    }
                    else {
                        cout << "Aborted!" << endl;
                    }
                }
                else {
                    cout << "No matches found!" << endl;
                }
                
                break;
            }
            case 2:
            {
                cout << "Publication Title: ";
                cin.getline(filename, '\n');
                char type{};
                int i;
                for (i = 0; i < m_numpub; i++) {
                    infile >> type;
                    infile.ignore();
                    if (infile) {

                        if (m_publication[i]->type() == 'P' && strstr(*m_publication[i], filename) && !m_publication[i]->onLoan())
                            ps << m_publication[i];
                       
                    }
                }
                if (ps) {
                    ps.sort(); // sort them based on date and title
                    int ref = ps.run(); // display the publications and select one
                    if (ref) {
                        
                        cout << *getPub(ref) << endl;
                        res = ref;
                    }
                    else {
                        cout << "Aborted!" << endl;
                    }
                }
                else {
                    cout << "No matches found!" << endl;
                }
               
                break;
            }
            case 0:
            {
                cout << "Aborted!" << endl;
                break;
            }
            }
        }
        return res;
    }
    Publication* LibApp::getPub(int libRef)
    {
        Publication* temp = nullptr;
        for (int i = 0; i < m_numpub; i++)
        {
            if (m_publication[i]->getRef() == libRef)
            {
                temp = m_publication[i];
            }
        }
        return temp;
    }
    void LibApp::returnPub()
    {
        cout << "Return publication to the library" << endl;
        int ref = 0;
        bool r = false;
        ref = search(2);
        if (ref > 0)
        {
            r = confirm("Return Publication?");
            if (r)
            {
                Date temp = getPub(ref)->checkoutDate();
                Date today;
                if (today - temp > 15)
                {
                    int penalty = (today - temp) - 15;
                    double price = penalty * 0.5;
                   // Please pay $4.00 penalty for being 8 days late!
                    cout << "Please pay " << "$";
                    cout.setf(ios::fixed);
                    cout.width(3);
                    cout.precision(2);
                    cout << price << " penalty for being " << penalty << " days late!" << endl;
                }
                getPub(ref)->set(0);

                cout << "Publication returned" << endl;
                m_changed = true;
            }
        }
    }
    void LibApp::newPublication()
    {
        if (m_numpub == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl;
        }
        else
        {
            cout << "Adding new publication to the library" << endl;
            int selection = -1;
            
            selection = m_publicationmenu.run();
            switch (selection)
            {
            case 0:
            {
                cout << "Aborted!" << endl;
                break;
            }
            case 1:
            {
                Publication* temp = new Book;
                temp->read(cin);
               
                if (cin)
                {
                    bool r = confirm("Add this publication to the library?");
                    if (r == true)
                    {
                        if (temp)
                        {
                           
                            m_publication[m_numpub] = temp;
                            m_publication[m_numpub]->setRef(m_librefapp+1);
                            m_librefapp++;
                            m_numpub++;
                            m_changed = true;
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl;
                            delete temp;
                        }
                    }
                }
                else
                {
                    cout.clear();
                    cout << "Aborted" << endl;
                }
                break;
            }
            case 2:
            {
                Publication* temp = new Publication;
                temp->read(cin);
             
                if (cin)
                {
                    bool r = confirm("Add this publication to the library?");
                    if (r == true)
                    {
                        if (temp)
                        {
                            m_publication[m_numpub] = temp;
                            m_publication[m_numpub]->setRef(m_librefapp + 1);
                            m_librefapp++;
                          
                            m_numpub++;
                            m_changed = true;
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl;
                            delete temp;
                        }
                    }
                }
                else
                {
                    cout.clear();
                    cout << "Aborted" << endl;
                }
                break;
            }
            }
           
            
        }
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from the library" << endl;
        int ref = 0;
        Publication* temp;
        ref = search(1);
        if (ref > 0)
        {
            bool r = confirm("Remove this publication from the library?");
            if (r == true)
            {
                temp = getPub(ref);
                temp->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
    }
    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;
        int ref = 0;
        int mem = 0;
       
       ref = search(3);
       if (ref > 0)
       {
           bool r = confirm("Check out publication?");
           if (r == true)
           {
               cout << "Enter Membership number: ";
               //cin.getline(mem, 5, '\n');
               cin >> mem;
               while (!(mem >= 10000 && mem <= 99999))
               {
                   
                   {
                       cout << "Invalid membership number, try again: ";
                       
                       cin >> mem;
                   }
               }
               if (cin)
               {
                   int mid = int(mem);
                   getPub(ref)->set(mid);
                   m_changed = true;
                   cout << "Publication checked out" << endl;
               }

           }
       }
    }


    LibApp::~LibApp()
    {
        for (int i = 0; i < m_numpub; i++)
        {
            delete m_publication[i];
        }
    }
    void LibApp::run()
    {
        bool done = true;
        int selection = -1;
        do
        {

            selection = m_mainMenu.run();

            {
                if (selection == 1)
                {
                    newPublication();
                    cout << endl;

                }
                else if (selection == 2)
                {
                    removePublication();
                    cout << endl;

                }
                else if (selection == 3)
                {
                    checkOutPub();
                    cout << endl;
                }
                else if (selection == 4)
                {
                    returnPub();
                    cout << endl;
                }
                else
                {
                    if (m_changed == true)
                    {
                        int i = -1;
                        i = m_exitMenu.run();
                        switch (i)
                        {
                        case 1:
                        {
                            save();
                            done = false;
                        }
                        case 2:
                        {
                            continue;
                        }
                        case 0:
                        {
                            bool exit = confirm("This will discard all the changes are you sure?");
                            if (exit == true)
                            {

                                done = false;
                            }
                        }
                        }
                    }

                    break;

                }
            };
        } while (done);
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

}
