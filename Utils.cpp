/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date 08/11/2021
// Author harmeen kaur
// Description
//
// Revision History
// -----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
// -----------------------------------------------------------

***********************************************************************/
//Student id : 150228203
//Section NII

#include "Utils.h"
#include <iostream>
using namespace std;
namespace sdds {
   
    void read(int& i, int min, int max, const char* error)
    {
        bool valid = false;
        char newline;
        do
        {
            cin >> i;
            newline = cin.get();
            if (cin.fail() || newline != '\n')
            {
                valid = false;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                if (i <= max && i >= min)
                    valid = true;
            }
        } while (!valid && cout << error);
    }
}