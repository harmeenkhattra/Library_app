/*
Name: HARMEEN KAUR
Student Number: 150228203
Student E-mail Address - harmeen-kaur1@myseneca.ca
Section Information Code- NII I have done all the coding by myself and only
copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
namespace sdds {
	class Book : public Publication
	{
		char* m_author;
	public:
		Book();
		Book(const Book& b);
		Book& operator=(const Book& b);
		~Book();
		char type() const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		void set(int member_id);
	};
}
#endif
