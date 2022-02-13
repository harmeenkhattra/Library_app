/***********************************************************************
// OOP244 LibApp Module
// File	LibApp.h
// Version
// Date 14/11/2021
// Author harmeen kaur
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//Student id : 150228203
//Section NII
#ifndef SDDS_LIBAPP_H
/***********************************************************************
// OOP244 LibApp Module
// File	LibApp.h
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
#define SDDS_LIBAPP_H
#include"Utils.h"
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"
namespace sdds {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        Menu m_publicationmenu;
        char m_filename[256];
        Publication* m_publication[SDDS_LIBRARY_CAPACITY]{};
        int m_numpub;
        int m_librefapp;

        bool confirm(const char* message);
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        int search(int type);//(bool all = false, bool onloan = false, bool notloan = false);  // prints: "Searching for publication"<NEWLINE>

        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
        Publication* getPub(int libRef);
        void prnPub(Publication* p[], int size, int ref);
    public:
        LibApp( const char* file);
        ~LibApp();
        void run();





    };
}
#endif // !SDDS_LIBAPP_H




//#ifndef SDDS_LIBAPP_H__
//#define SDDS_LIBAPP_H__
//#include <iostream>
//#include "Publication.h"
//namespace sdds {
//
//	class LibApp : public Publication
//	{
//		char m_filename[256];
//		Publication* m_publication[SDDS_LIBRARY_CAPACITY];
//		int m_numpub;
//		int m_libref;
//	};
//
//
//
//}
//#endif
