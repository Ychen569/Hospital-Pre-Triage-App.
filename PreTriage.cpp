//Name: Yao Chen
//Student ID:134082197
//Date: Jul 28, 2021
//Subject: OOP244 NCC MS5 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "Patient.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename):m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit",2),m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage",2)
	{
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		if (strlen(dataFilename) != 0)
		{
			m_dataFilename = new char[strlen(dataFilename) + 1];
			strcpy(m_dataFilename, dataFilename);
		}
		load();

	}
	PreTriage::~PreTriage()
	{
		
		ofstream fileout(m_dataFilename);//
		fileout << m_averCovidWait << "," << m_averTriageWait << endl;
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait << endl;
		cout << "   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++)
		{
			m_lineup[i]->fileIO(true);
			fileout << *m_lineup[i] << endl;
			cout << i+1<<"- "<<*m_lineup[i] << endl;
		}
		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
		}

		delete[] m_dataFilename;
		fileout.close();
		cout << "done!" << endl;

	}
	void PreTriage::run(void)
	{
		int selection;
		while (m_appMenu >> selection)
		{
			switch (selection)
			{
			case 1: reg();
				break;
			case 2: admit();
				break;
			case 0:
				exit(0);
			}
		}

	}
	void PreTriage::reg()
	{
		if (m_lineupSize == maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			int selection;
			m_pMenu >> selection;
			
			switch (selection)
			{
			case 1: m_lineup[m_lineupSize] = new CovidPatient;
				break;
			case 2: m_lineup[m_lineupSize] = new TriagePatient;
				break;
			case 0: 
				exit(0);
			}
			
			m_lineup[m_lineupSize]->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			m_lineup[m_lineupSize]->fileIO(false);
			cin >> *m_lineup[m_lineupSize];
			cout << endl << "******************************************" << endl;
			cout << *m_lineup[m_lineupSize];
			cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
			cout << "******************************************" << endl << endl;
			m_lineupSize++;
		}
	}
	void PreTriage::admit()
	{

		int selection; char ch;
		m_pMenu >> selection;
		switch (selection)
		{
		case 1: ch = 'C';
			break;
		case 2: ch = 'T';
			break;
		case 0:
			break;
		}
		
		int index = indexOfFirstInLine(ch);
		if (index != -1)
		{
			cout << endl << "******************************************" << endl;
			m_lineup[index]->fileIO(false);
			cout << "Calling for " << *m_lineup[index];
			cout << "******************************************" << endl  <<endl;
			setAverageWaitTime(*m_lineup[index]);
			removePatientFromLineup(index);

		}

	}
	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		unsigned int count = 0;
		Time time;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type()) count++;
		}
		if (p.type() == 'C') time = m_averCovidWait * count;
		if (p.type() == 'T') time = m_averCovidWait * count;
		return time;
	}
	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == 'C')
		{
			m_averCovidWait = ((m_averCovidWait.setToNow() - Time(p)) + (m_averCovidWait * (unsigned int)(p.number() - 1))) / (unsigned int)p.number();
		}
		if (p.type() == 'T')
		{
			m_averTriageWait = ((m_averTriageWait.setToNow() - Time(p)) + (m_averTriageWait * (unsigned int)(p.number() - 1))) / (unsigned int)p.number();
		}
	}
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int p = 0;
		int index = -1;
		for (int i = 0; i < m_lineupSize && p==0; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				index = i;
				p = 1;
			}
		}
		return index;
	}

	void PreTriage::load()
	{
		Time temp1, temp2;
		cout << "Loading data..." << endl;
		ifstream filein(m_dataFilename);
		filein >> temp1;
		filein.ignore();
		filein >> temp2;
		filein.ignore(1000,'\n');
		if ((!(int)temp1) || filein.fail())
		{
			cout << "No data or bad data file!" << endl << endl;
		}
		else
		{
			m_averCovidWait = (int)temp1;
			m_averTriageWait = (int)temp2;
			
			for (int i = 0; i < maxNoOfPatients && (!filein.fail()); i++)
			{
				Patient* p{};
				char ch{};
				filein >> ch;
				filein.ignore();
				if (ch == 'C' || ch == 'T')
				{
					if (ch == 'C')
					{
						p = new CovidPatient;
					}
					if (ch == 'T')
					{
						p = new TriagePatient;
					}
					p->fileIO(true);
					filein >> *p;
					p->fileIO(false);
					m_lineup[m_lineupSize] = p;
					m_lineupSize++;

				}

			}
			filein.clear();
			filein.ignore(1000, '\n');

			if ((m_lineupSize == 100) && (!filein.fail()))
			{
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
				cout << m_lineupSize << " Records imported..." << endl << endl;
			}
			else
			{
				cout << m_lineupSize << " Records imported..." << endl<< endl;
			}
			filein.close();

		}


	}


}