#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsCurrency.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include <iomanip>
#include <iostream>
class clsCurrenciesListScreen : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(const clsCurrency &Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCountryName();
        cout << "| " << setw(10) << left << Currency.GetCurrencyCode();
        cout << "| " << setw(40) << left << Currency.GetCurrencyName();
        cout << "| " << setw(12) << left << Currency.GetRate();
    }

public:
    static void ShowCurrenciesListScreen()
    {
        vector<clsCurrency> vCurrenciesList = clsCurrency::GetCurrenciesList();
        string Title = "\t Currencies List Screen";
        string SubTitle = "\t   (" + to_string(vCurrenciesList.size()) + ") Currency";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
        cout << "| " << setw(10) << left << "Code";
        cout << "| " << setw(40) << left << "Name";
        cout << "| " << setw(10) << left << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________\n\n";
        if (vCurrenciesList.size() == 0)
        {
            cout<<"\t\t\t\t\n\nNo Currencies Available In the System!\n\n";
        }
        else
        {
            for (const clsCurrency &Currency : vCurrenciesList)
            {
                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________\n";
    }
};
