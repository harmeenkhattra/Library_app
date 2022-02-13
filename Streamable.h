/***********************************************************************
// OOP244 Streamable Module
// File	Streamable.h
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
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
namespace sdds {
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		bool conIO(std::ios& i) const;
		virtual operator bool() const = 0;
		virtual ~Streamable() {};
	};
	std::ostream& operator<<(std::ostream& os, const Streamable& s);
	std::istream& operator>>(std::istream& is, Streamable& s);
}
#endif

