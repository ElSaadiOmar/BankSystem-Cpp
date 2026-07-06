#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsCurrency.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include <iomanip>
#include <iostream>
class clsFindCurrencyScreen : protected clsScreen
{
private:
    enum enChoice
    {
        eCode = 1,
        eCountry = 2,
    };
    static void _ShowResult(const clsCurrency &Currency)
    {
        if (Currency.IsEmpty())
        {
            cout << "\nCurrency Was not Found :-(\n";
            return;
        }
        else
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
    }
    static void _PrintCurrency(const clsCurrency &Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n____________________________________\n";
        cout << "\nCountry    :" << Currency.GetCountryName();
        cout << "\nCode       :" << Currency.GetCurrencyCode();
        cout << "\nName       :" << Currency.GetCurrencyName();
        cout << "\nRate(1$)   :" << Currency.GetRate();
        cout << "\n____________________________________\n";
    }
    static void _FindByCode()
    {
        string CurrencyCode = "";
        cout << "\nPlease Enter CurrencyCode: ";
        CurrencyCode = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _ShowResult(Currency);
    }
    static void _FindByName()
    {
        string Country = "";
        cout << "\nPlease Enter Country Name: ";
        Country = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCountry(Country);
        _ShowResult(Currency);
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("  Find Currency Screen");
        cout << "Find By: [1] Code or [2] Country ? ";
        enChoice Choice = (enChoice) clsInputValidate::ReadNumberBetween<short>(1, 2, "Please Enter [1] for Code or [2] for Country ? ");
        switch (Choice)
        {
        case eCode:
        {
            _FindByCode();
            break;
        }
        case eCountry:
        {
            _FindByName();
            break;
        }
        }
    }
};
