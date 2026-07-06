#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsCurrency.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include <iostream>

class clsCurrencyCalculator : protected clsScreen
{
private:
    static double _ReadAmount()
    {
        double Amount = 0;
        cout << "\nEnter Amount to Exchange: ";
        Amount = clsInputValidate::ReadNumber<double>();
        return Amount;
    }
    static void _PrintCurrencyCard(const clsCurrency &Currency, string Title = "Currency Card")
    {
        cout << "\n" << Title;
        cout << "\n____________________________________\n";
        cout << "\nCountry    :" << Currency.GetCountryName();
        cout << "\nCode       :" << Currency.GetCurrencyCode();
        cout << "\nName       :" << Currency.GetCurrencyName();
        cout << "\nRate(1$)   :" << Currency.GetRate();
        cout << "\n____________________________________\n\n";
    }
    static clsCurrency _GetCurrency(string Message)
    {
        string Code = "";
        cout << Message << endl;
        Code = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCurrency NOT found, try another Currency: ";
            Code = clsInputValidate::ReadString();
        }
        return clsCurrency::FindByCode(Code);
    }
    static void _PrintCalculationResults(const double Amount, const clsCurrency &Currency1, const clsCurrency &Currency2)
    {
        _PrintCurrencyCard(Currency1,"Convert From:");
        cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << Currency1.ConvertToUSD(Amount) << " USD\n";

        if (!(Currency2.GetCurrencyCode() == "USD"))
        {
            cout << "\nConverting from USD to:\n";
            _PrintCurrencyCard(Currency2,"To:");
            cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << Currency1.ConvertToOtherCurrency(Amount, Currency2) << " " << Currency2.GetCurrencyCode();
        }
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        while (true)
        {
            system("cls");
            _DrawScreenHeader("  Currency Calculator");

            clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");
            double Amount = _ReadAmount();
            _PrintCalculationResults(Amount, Currency1, Currency2);
            char Answer = 'n';
            cout << "\n\nDo you want to perform another calculation? y/n ?";
            cin >> Answer;
            if (!(tolower(Answer) == 'y'))
            {
                break;
            }
        }
    }
};