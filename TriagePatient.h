//Name: Yao Chen
//Student ID:134082197
//Date: Jul 26, 2021
//Subject: OOP244 NCC MS4 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include"Patient.h"
using namespace std;

namespace sdds
{
	class TriagePatient :public Patient
	{
		char* m_symptoms{};
	public:
		TriagePatient();
		char type()const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		~TriagePatient();

	};
}
#endif // !SDDS_TRIAGEPATIENT_H



