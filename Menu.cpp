//Name: Yao Chen
//Student ID:134082197
//Date: Jul 15, 2021
//Subject: OOP244 NCC MS2 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Menu.h"
#include "utils.h"
using namespace std;

namespace sdds
{
	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;

	}
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		bool valid = MenuContent != nullptr && NoOfSelections != 0;
		if (valid)
		{
			m_text = new char[strlen(MenuContent) + 1];
			strcpy(m_text, MenuContent);
			m_noOfSel = NoOfSelections;
		}
	}
	Menu::~Menu()
	{
		delete[] m_text;
	}
	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");

		return Selection;
	}
	Menu::Menu(const Menu& M)
	{
		*this = M;

	}
	Menu& Menu::operator=(const Menu& M)
	{
		if (this != &M)
		{
			delete[] m_text;
			m_text = new char[strlen(M.m_text) + 1];
			strcpy(m_text, M.m_text);
			m_noOfSel = M.m_noOfSel;

		}
		return *this;
	}
}
