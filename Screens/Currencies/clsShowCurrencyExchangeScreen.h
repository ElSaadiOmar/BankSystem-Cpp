#pragma once
#include <iomanip>
#include <iostream>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Currencies\clsCurrenciesListScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Currencies\clsFindCurrencyScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Currencies\clsUpdateRateScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Currencies\clsCurrencyCalculate.h"
class clsShowCurrencyExchangeMenu : protected clsScreen
{
private:
    enum enCurrencyMenuOptions
    {
        cListCurrencies = 1,
        cFindCurrency = 2,
        cUpdateRate = 3,
        cCurrencyCalculator = 4,
        cMainMenu = 5,
    };
    static short _ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMenu()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Currency Exchange Menu...\n";
        system("pause>0");
        ShowCurrencyExchangeMenu();
    }
    static void _ShowCurrenciesListScreen()
    {
        // cout << "Here is Currencies List\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }
    static void _ShowFindCurrencyScreen()
    {
        // cout << "Here is Find Currency\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        // cout << "Here is Update Rate\n";
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        // cout << "Here is Currency Calculator\n";
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
    }
    static void _PerformCurrencyExchangeMenuOption(enCurrencyMenuOptions CurrencyMenuOption)
    {
        switch (CurrencyMenuOption)
        {
        case cListCurrencies:
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        case cFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();

            break;
        case cUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        case cCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        case cMainMenu:
        {
        }
        }
    }

public:
    static void ShowCurrencyExchangeMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Menu Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenuOption((enCurrencyMenuOptions)_ReadCurrencyExchangeMenuOption());
    }
};
