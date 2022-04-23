//Name: Yao Chen
//Student ID:134082197
//Date: Jul 26, 2021
//Subject: OOP244 NCC MS4 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

namespace sdds
{
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		nextTriageTicket++;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		string temp;
		Patient::csvRead(istr);
		istr.ignore();
		getline(istr, temp, '\n');
		if (temp.length() > 0)
		{
			delete[]m_symptoms;
			m_symptoms = new char[strlen(temp.c_str()) + 1];
			strcpy(m_symptoms, temp.c_str());
		}
		nextTriageTicket = Patient::number() + 1;

		return istr;
	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << ",";
		ostr << m_symptoms;

		return ostr;// TODO: insert return statement here
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (Patient::fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: " << m_symptoms << endl;


		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		string temp;
		if (Patient::fileIO())
		{
			csvRead(istr);
		}
		else
		{
			Patient::read(istr);
			cout << "Symptoms: ";
			getline(istr, temp, '\n');
			if (temp.length() > 0)
			{
				delete[]m_symptoms;
				m_symptoms = new char[strlen(temp.c_str()) + 1];
				strcpy(m_symptoms, temp.c_str());
			}

		}

		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
	}

}