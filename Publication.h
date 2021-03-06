/*
Name: HARMEEN KAUR
Student Number: 150228203
Student E-mail Address - harmeen-kaur1@myseneca.ca
Section Information Code- NII I have done all the coding by myself and only
copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"
namespace sdds {
	const int MAX_TITLE = 255;
	class Publication : public Streamable
	{
		char* m_title;
		char m_shelfId[5];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();
		void setEmpty();
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 
		int getMID() const;
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;

		Publication(const Publication& p);
		Publication& operator=(const Publication& p);
		~Publication();
	};
}
#endif

