/*
Name: HARMEEN KAUR
Student Number: 150228203
Student E-mail Address - harmeen-kaur1@myseneca.ca
Section Information Code- NII I have done all the coding by myself and only
copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include "Book.h"

using namespace std;
namespace sdds {
	Book::Book()
	{
		m_author = nullptr;
	}
	Book::Book(const Book& b) :Publication(b)
	{
		if (b.m_author != nullptr)
		{
			m_author = new char[strlen(b.m_author) + 1];
			strcpy(m_author, b.m_author);
		}
		else
		{
			m_author = nullptr;
		}
	}
	Book& Book::operator=(const Book& b)
	{
		if (this != &b)
		{
			Publication::operator =(b);
			delete[] m_author;
			if (b.m_author != nullptr)
			{
				m_author = new char[strlen(b.m_author) + 1];
				strcpy(m_author, b.m_author);
			}
			else
			{
				m_author = nullptr;
			}
		}
		return *this;
	}
	Book::~Book()
	{
		delete[] m_author;
		m_author = nullptr;
	}
	char Book::type() const
	{
		return 'B';
	}
	std::ostream& Book::write(std::ostream& os) const
	{
		if (*this)
		{
			Publication::write(os);
			if (conIO(os))
			{
				os << ' ';


				if (strlen(m_author) > SDDS_AUTHOR_WIDTH)
				{
					char temp[SDDS_AUTHOR_WIDTH + 1];
					strncpy(temp, m_author, 15);
					temp[SDDS_AUTHOR_WIDTH] = '\0';
					os << setw(SDDS_AUTHOR_WIDTH) << temp << " |";
				}
				else
				{
					os << setw(SDDS_AUTHOR_WIDTH) << m_author << " |";
				}
			}
			else
			{
				os << '\t' << m_author << endl;
			}
		}
		return os;
	}
	std::istream& Book::read(std::istream& istr)
	{


		char author[256];
		Publication::read(istr);
		delete m_author;
		m_author = nullptr;
		if (conIO(istr))
		{
			istr.ignore();
			cout << "Author: ";
			istr.getline(author, 256, '\n');

		}
		else
		{

			istr.ignore();

			istr.get(author, 256, '\n');

		}
		if (strlen(author) > 256)
		{
			istr.setstate(ios::failbit);
		}
		if (istr)
		{

			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
		}
		return istr;
	}
	Book::operator bool() const
	{
		bool r = false;
		if (m_author != nullptr && m_author[0] != '\0' && Publication::operator bool() == true)
		{
			r = true;
		}
		return r;
	}
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}
}