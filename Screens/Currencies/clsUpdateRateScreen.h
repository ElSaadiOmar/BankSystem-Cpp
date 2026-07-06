#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsCurrency.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include <iomanip>
#include <iostream>
class clsUpdateRateScreen : protected clsScreen
{
private:
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
    static void _UpdateRate(clsCurrency &Currency)
    {
        float NewRate = 0;
        cout << "\n\nUpdate Currency Rate:";
        cout << "\n____________________\n";
        cout << "\nEnter New Rate: ";
        NewRate = clsInputValidate::ReadNumber<float>();
        Currency.UpdateRate(NewRate);
        cout << "\nCurrency Rate Update Successfully :-)\n";
        _PrintCurrency(Currency);
    }

public:
    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader(" Update Currency Screen");
        string CurrencyCode = "";
        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        if (Currency.IsEmpty())
        {
            cout << "\nCurrency Was not Found :-(\n";
            return;
        }
        else
        {
            _PrintCurrency(Currency);
            char Answer = 'n';
            cout << "\nAre you sure you want to update thr rate of this Currency y/n? ";
            cin >> Answer;
            if (tolower(Answer) == 'y')
            {
                _UpdateRate(Currency);
                return;
            }
        }
    }
};
