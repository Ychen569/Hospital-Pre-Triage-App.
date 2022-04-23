//Name: Yao Chen
//Student ID:134082197
//Date: Jul 18, 2021
//Subject: OOP244 NCC MS3 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "Ticket.h"
#include "utils.h"
#include <cstring>

namespace sdds
{

	Patient::Patient(int ticketNo, bool flag) :ticket(ticketNo)
	{
		fileIOFlag = flag;
	}

	Patient::~Patient()
	{
		delete[] m_name;

	}
	bool Patient::fileIO() const
	{
		return fileIOFlag;
	}
	bool Patient::fileIO(bool flag)
	{

		return fileIOFlag = flag;
	}
	bool Patient::operator==(char ObjectType) const
	{
		return type() == ObjectType;
	}
	bool Patient::operator==(const Patient& p) const
	{
		return type() == p.type();
	}
	void Patient::setArrivalTime()
	{
		ticket.resetTime();
	}

	Patient::operator Time() const
	{
		return Time(ticket);
	}

	int Patient::number() const
	{
		return ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << "," << m_name << "," << m_OHIP << ",";
		ticket.csvWrite(ostr);
		return ostr; 
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{
		char str[81]{};
		istr.getline(str, 81, ',');
		if (strlen(str) != 0)
		{
			delete[] m_name;
			m_name = new char[strlen(str) + 1];
			strcpy(m_name, str);

			istr >> m_OHIP;
			istr.ignore();
			ticket.csvRead(istr);
		};

		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{

		ticket.write(ostr);
		ostr << endl;
		char w_name[26];
		strncpy(w_name, m_name, 25);
		w_name[25] = '\0';
		ostr << w_name;
		ostr << ", OHIP: ";
		ostr << m_OHIP;

		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{

		delete[] m_name;
		m_name = getcstr("Name: ", istr);
		m_OHIP = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ");


		return istr;
	}

}