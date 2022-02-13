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
#include "Publication.h"

using namespace std;
namespace sdds {
	Publication::Publication()
	{

		setEmpty();
	}
	void Publication::setEmpty()
	{
		//m_title[0] = '\0';
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;

	}
	void Publication::set(int member_id)
	{

		m_membership = member_id;

	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date.resetDate1();
	}

	char Publication::type()const
	{
		return 'P';
	}

	bool Publication::onLoan()const
	{
		bool r = false;
		if (m_membership != 0)
		{
			r = true;
		}
		return r;
	}

	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title)const
	{
		bool r = false;
		if (strstr(m_title, title) != nullptr)
		{
			r = true;
		}
		return r;
	}

	Publication::operator const char* ()const
	{
		return m_title;
	}

	int Publication::getRef()const
	{
		return m_libRef;
	}
	int Publication::getMID() const
	{
		return m_membership;
	}
	bool Publication::conIO(ios& io)const
	{
		bool r = false;
		if (&io == &cin || &io == &cout)
		{
			r = true;
		}
		return r;
	}

	ostream& Publication::write(ostream& os) const
	{
		if (*this)
		{
			if (conIO(os))
			{

				os << "| " << setw(4) << m_shelfId;

				os << " | ";
				if (strlen(m_title) > SDDS_TITLE_WIDTH)
				{
					char temp[SDDS_TITLE_WIDTH + 1];
					strncpy(temp, m_title, 30);
					temp[SDDS_TITLE_WIDTH] = '\0';
					os << setfill('.') << setw(30) << left << temp;
				}
				else
				{
					os << setfill('.') << setw(30) << left << m_title;
				}
				os << " | " << setfill(' ');
				if (onLoan())
				{
					os << setw(5) << m_membership << " | ";
				}
				else
				{
					os << setw(5) << " N/A " << " | ";
				}

				os << m_date;
				cout << " |";
			}
			else
			{
				os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t';

				os << m_date;
				if (type() == 'P')
				{
					os << endl;
				}
			}
		}
		return os;
	}
	istream& Publication::read(istream& istr)
	{
		delete m_title;
		setEmpty();

		string ShelfId;
		string Title;
		int LibRef = -1;
		int Membership = 0;
		Date D;

		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> ShelfId;

			if (ShelfId.length() != 4)
			{
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.ignore();
			getline(istr, Title, '\n');
			cout << "Date: ";
			istr >> D;

			if (D.errCode() != 0)
			{
				istr.setstate(ios::failbit);
			}
		}
		else
		{
			istr >> LibRef;
			istr.ignore();
			getline(istr, ShelfId, '\t');

			getline(istr, Title, '\t');


			istr >> Membership;
			istr >> D;
			if (D.errCode() != 0)
			{
				istr.setstate(ios::failbit);
			}
		}

		if (istr)
		{
			m_libRef = LibRef;
			strcpy(m_shelfId, ShelfId.c_str());

			m_title = new char[Title.length() + 1];
			strcpy(m_title, Title.c_str());

			m_membership = Membership;
			
			m_date = D;
		}
		else
		{
			setEmpty();
		}

		return istr;
	}

	Publication::operator bool() const
	{
		bool r = false;
		if (m_shelfId[0] != '\0' && m_title != nullptr)
		{
			r = true;
		}
		return r;
	}

	Publication::Publication(const Publication& source) : Streamable(source)
	{
		m_libRef = source.m_libRef;
		m_membership = source.m_membership;
		if (source.m_shelfId[0] != '\0')
		{
			strcpy(m_shelfId, source.m_shelfId);
			m_shelfId[4] = '\0';
		}
		else
		{
			m_shelfId[0] = '\0';
		}
		if (source.m_title != nullptr)
		{

			m_title = new char[strlen(source.m_title) + 1];
			strcpy(m_title, source.m_title);

		}
		else
		{
			m_title = nullptr;
		}


	}

	Publication& Publication::operator=(const Publication& source)
	{
		if (this != &source)
		{
			Streamable::operator =(source);
			
			
				delete[] m_title;
			
			m_libRef = source.m_libRef;
			m_membership = source.m_membership;
			if (source.m_shelfId[0] != '\0')
			{
				strcpy(m_shelfId, source.m_shelfId);
				m_shelfId[4] = '\0';

			}
			else
			{
				m_shelfId[0] = '\0';
			}
			if (source.m_title != nullptr)
			{
				m_title = new char[strlen(source.m_title) + 1];
				strcpy(m_title, source.m_title);

			}
			else
			{
				m_title = nullptr;
			}
			m_date = source.m_date;
		}
		return *this;
	}
	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}
}