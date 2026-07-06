#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
#include <limits>
using namespace std;
class clsInputValidate
{
public:
    template <typename T>
    static bool IsNumberBetween(T Number, T from, T to)
    {
        if (from > to)
            clsUtil::Swap<T>(from, to);
        return (Number <= to && Number >= from);
    }

    template <typename T>
    static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        T Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }
    template <typename T>
    static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number = ReadNumber<T>();

        while (!IsNumberBetween<T>(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadNumber<T>();
        }
        return Number;
    }

    static bool IsValidDate(clsDate Date)
    {
        /*if (Date.GetYear() == 0)
            return false;
        return IsNumberBetween(Date.GetDay(), 1, clsDate::NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear())) && IsNumberBetween(Date.GetMonth(), 1, 12);*/
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string S1 = "";
        // Usage of std::ws will extract all the whitespace character
        getline(cin >> ws, S1);
        return S1;
    }
};