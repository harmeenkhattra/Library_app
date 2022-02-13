/*
Name: HARMEEN KAUR
Email:harmeen-kaur1@myseneca.ca
Student ID:150228203
Data:nov 16 2021
Section: NII

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
***********************************************************************/
//Student id : 150228203
//Section NII

#define _CRT_SECURE_NO_WARNINGS 
#include "Streamable.h"
using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Streamable& s)
	{

		return s.write(os);
	}
	std::istream& operator>>(std::istream& is, Streamable& s)
	{

		return s.read(is);
	}
}