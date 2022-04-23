//Name: Yao Chen
//Student ID:134082197
//Date: Jul 15, 2021
//Subject: OOP244 NCC MS2 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
using namespace std;

namespace sdds
{
	class IOAble
	{
	public:
		virtual ostream& csvWrite(ostream& os) const = 0;
		virtual istream& csvRead(istream& is) = 0;
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual ~IOAble();
	};
	ostream& operator<<(ostream& os, const IOAble& I);
	istream& operator>>(istream& is, IOAble& I);

}

#endif

