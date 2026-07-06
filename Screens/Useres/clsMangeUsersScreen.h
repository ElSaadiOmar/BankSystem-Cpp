#pragma once
#include <iostream>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include <iomanip>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Useres\clsUsersListScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Useres\clsAddNewUserScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Useres\clsDeleteUserScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Useres\clsUpdateUserScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Useres\clsFindUserScreen.h"
using namespace std;
class clsMangeUsersScreen : protected clsScreen
{
private:
    enum enMangeUsersMenuOptions
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6,

    };
    static short _ReadMangeUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowListUsersScreen()
    {
        clsListUserScreen::ShowUsersList();
    }
    static void _ShowAddNewUserScreen()
    {
        // cout << "Here is Add new user screen\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUserScreen()
    {
        // cout << "Here is Delete user screen \n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }
    static void _ShowUpdateUserScreen()
    {
        // cout << "Here is update user screen \n";
        clsUpdateUserScreen::ShowUpdateClientScreen();
    }
    static void _ShowFindUserScreen()
    {
        // cout << "Here is find user screen\n";
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void _GoBackToMangeUsersMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Mange User Menu...\n";
        system("pause>0");
        ShowMangeUsersMenu();
    }
    static void _PerformMangeUsersMenuOption(enMangeUsersMenuOptions MangeUsersMenuOption)
    {
        switch (MangeUsersMenuOption)
        {
        case enMangeUsersMenuOptions::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToMangeUsersMenu();
            break;

        case enMangeUsersMenuOptions::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToMangeUsersMenu();
            break;

        case enMangeUsersMenuOptions::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToMangeUsersMenu();
            break;

        case enMangeUsersMenuOptions::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToMangeUsersMenu();
            break;

        case enMangeUsersMenuOptions::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToMangeUsersMenu();
            break;

        case enMangeUsersMenuOptions::eMainMenu:
        {
        }
        }
    }

public:
    static void ShowMangeUsersMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t Mange Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Mange User Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformMangeUsersMenuOption((enMangeUsersMenuOptions)_ReadMangeUsersMenuOption());
    }
};