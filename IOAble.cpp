//Name: Yao Chen
//Student ID:134082197
//Date: Jul 15, 2021
//Subject: OOP244 NCC MS2 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#include "IOAble.h"
namespace sdds
{
	IOAble::~IOAble()
	{
	}


	ostream& operator<<(ostream& os, const IOAble& I)
	{
		return I.write(os); 
	}

	istream& operator>>(istream& is, IOAble& I)
	{
		return I.read(is);
	}

}