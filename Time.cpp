//Name: Yao Chen
//Student ID:134082197
//Date: Jul 09, 2021
//Subject: OOP244 NCC MS1 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	Time& Time::setToNow()
	{
		m_min = sdds::getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr.setf(ios::right);
		ostr.width(2);
		ostr.fill('0');
		ostr << (int)m_min / 60 << ':';
		ostr.width(2);
		ostr.fill('0');
		ostr << m_min % 60;
		return ostr;
	}
	std::istream& Time::read(std::istream& istr)
	{
		int H = 0, M = 0;
		char str{};
		istr >> H;
		istr >> str;
		istr >> M;
		if (H < 0 || str != ':' || M < 0)
		{
			istr.setstate(ios::failbit);
		}
		m_min = H * 60 + M;
		return istr;// TODO: insert return statement here
	}
	Time& Time::operator-=(const Time& D)
	{
		int temp;
		temp = m_min -= D.m_min;
		while (temp < 0)
		{
			temp += 1440;
		}

		m_min = temp;
		return *this;// TODO: insert return statement here
	}
	Time Time::operator-(const Time& D) const
	{
		Time temp;
		int t_min = 0;
		t_min = m_min - D.m_min;
		while (t_min < 0)
		{
			t_min += 1440;
		}

		temp.m_min = t_min;
		return temp;
	}
	Time& Time::operator+=(const Time& D)
	{
		int temp;
		temp = m_min += D.m_min;
		m_min = temp;
		return *this;// TODO: insert return statement here
	}
	Time Time::operator+(const Time& D) const
	{
		Time temp;
		temp.m_min = m_min + D.m_min;
		return temp;
	}
	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;// TODO: insert return statement here
	}
	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;// TODO: insert return statement here
	}
	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;
		return *this;// TODO: insert return statement here
	}
	Time Time::operator*(unsigned int val) const
	{
		Time temp;
		temp.m_min = m_min * val;
		return temp;
	}
	Time Time::operator/(unsigned int val) const
	{
		Time temp;
		if (val != 0)
			temp.m_min = m_min / val;
		return temp.m_min;
	}
	Time::operator unsigned int() const
	{
		return m_min;
	}
	Time::operator int() const
	{
		return m_min;
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);// TODO: insert return statement here
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);// TODO: insert return statement here
	}
}
