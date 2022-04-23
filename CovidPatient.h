//Name: Yao Chen
//Student ID:134082197
//Date: Jul 26, 2021
//Subject: OOP244 NCC MS4 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"

using namespace std;

namespace sdds
{
	class CovidPatient :public Patient
	{
	public:
		CovidPatient();
		char type()const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);


	};
}
#endif // !SDDS_COVIDPATIENT_H_




