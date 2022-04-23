//Name: Yao Chen
//Student ID:134082197
//Date: Jul 09, 2021
//Subject: OOP244 NCC MS1 
//I have done all the coding by myself and only copied the code that my professor 
//provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
    bool debug = false;  // made global in utils.h
    int getTime()
    {
        int mins = -1;
        if (debug)
        {
            Time t(0);
            cout << "Enter current time: ";
            do
            {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin)
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    int getInt(const char* prompt)
    {
        if (prompt)
        {
            cout << prompt;
        }

        int input;
        char str[81];
        bool valid = false;
        while (!valid)
        {
            cin >> input;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                cin.get(str, 81, '\n');
                if (!cin.fail())
                {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                {
                    valid = true;
                }

            }

        }
        cin.clear();
        cin.ignore(1000, '\n');

        return input;
    }
    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
    {
        if (prompt)
        {
            cout << prompt;
        }

        int input;
        char str[81];
        bool valid = false;
        while (!valid)
        {
            cin >> input;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                cin.get(str, 81, '\n');
                if (!cin.fail())
                {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                {
                    if (input > max || input < min)
                    {
                        if (errorMessage)
                        {
                            if (showRangeAtError)
                            {
                                cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            else
                            {
                                cout << errorMessage;
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                        }
                    }
                    else
                    {
                        valid = true;
                    }

                }

            }
        }

        cin.clear();
        cin.ignore(1000, '\n');

        return input;
    }
    char* getcstr(const char* prompt, std::istream& istr, char delimiter)
    {
        char* m_str = nullptr;
        string temp;
        if (prompt)
        {
            cout << prompt;
        }
        getline(istr, temp, '\n');
        if (temp.length() != 0)
        {
            m_str = new char[strlen(temp.c_str()) + 1];
            strcpy(m_str, temp.c_str());
        }

        return m_str;
    }
}