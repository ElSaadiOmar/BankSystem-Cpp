#pragma once
#include <iostream>
#include <iomanip>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Clients\clsDepositScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Clients\clsWithdrawScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Clients\clsTotalBalancesScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Clients\clsTransferScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Clients\clsTransferLogScreen.h"
using namespace std;
class clsTransactionScreen : protected clsScreen
{

    enum enTransactionMenuOptions
    {
        eDeposit = 1,
        enWithdraw = 2,
        eShowTotalBalance = 3,
        eTransfer = 4,
        eShoeTransferLog = 5,
        eShowMainMenu = 6,
    };
    static short _ReadTransactionMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToTransactionMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menu...\n";
        system("pause>0");
        ShowTransactionScreen();
    }

    static void _ShowDepositScreen()
    {
        // cout << "Here deposit screen \n";
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen()
    {
        // cout << "Here withdraw screen\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
        // cout << "here total balance screen\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _ShowTransferScreen()
    {
        // cout << "Transfer Screen\n";
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    static void _PerformTransactionMenuOption(enTransactionMenuOptions TransactionMenuOptions)
    {
        switch (TransactionMenuOptions)
        {
        case eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenu();
            break;

        case enWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionMenu();
            break;
        case eShowTotalBalance:
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenu();
            break;
        case eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenu();
        case eShoeTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionMenu();
        case eShowMainMenu:
        {
        }
        }
    }

public:
    static void ShowTransactionScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t   Transaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransaction Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionMenuOption((enTransactionMenuOptions)_ReadTransactionMenuOption());
    }
};
