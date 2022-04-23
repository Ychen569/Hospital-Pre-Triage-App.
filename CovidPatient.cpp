//Name: Yao Chen
//Student ID:134082197
//Date: Jul 26, 2021
//Subject: OOP244 NCC MS4 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#include "CovidPatient.h"
namespace sdds
{
	int nextCovidTicket = 1;
	CovidPatient::CovidPatient() :Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}
	char CovidPatient::type() const
	{
		return 'C';
	}
	std::istream& CovidPatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;
		istr.ignore(1000, '\n');

		return istr;
	}
	std::ostream& CovidPatient::write(std::ostream& ostr) const
	{
		if (Patient::fileIO())
		{
			Patient::csvWrite(ostr);
		}
		else
		{
			cout << "COVID TEST" << endl;
			Patient::write(ostr);
			cout << endl;
		}


		return ostr;
	}
	std::istream& CovidPatient::read(std::istream& istr)
	{
		if (Patient::fileIO())
		{
			csvRead(istr);
		}
		else
		{
			Patient::read(istr);
		}
		return istr;
	}
}