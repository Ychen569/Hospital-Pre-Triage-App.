//Name: Yao Chen
//Student ID:134082197
//Date: Jul 18, 2021
//Subject: OOP244 NCC MS3 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h" 
#include "Ticket.h"

namespace sdds
{
	class Patient :public IOAble
	{
	private:
		char* m_name{};
		int m_OHIP{};
		Ticket ticket;
		bool fileIOFlag;
	public:
		Patient(int ticketNo = 0, bool flag = false);
		Patient& operator=(const Patient& P) = delete;
		Patient(const Patient& p) = delete;
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		bool fileIO(bool flag);
		bool operator==(char ObjectType) const;
		bool operator==(const Patient& p) const;
		void setArrivalTime();
		operator Time()const;
		int number() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);


	};

}

#endif // !SDDS_PATIENT_H



