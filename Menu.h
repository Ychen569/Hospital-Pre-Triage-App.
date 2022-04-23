//Name: Yao Chen
//Student ID:134082197
//Date: Jul 15, 2021
//Subject: OOP244 NCC MS2 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	class Menu
	{
		char* m_text{};
		int m_noOfSel{};
		void display()const;
	public:
		Menu(const char* MenuContent, int NoOfSelections);
		virtual ~Menu();
		int& operator>>(int& Selection);
		Menu(const Menu& M);
		Menu& operator=(const Menu& M);

	};
}
#endif // !SDDS_MENU_H


