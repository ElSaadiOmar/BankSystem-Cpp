#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsMainScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsUsers.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Global.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        short Trail = 0;
        while (true)
        {
            if (Trail == 3)
            {
                cout << "\n\n\n You are Locked after 3 Felid trails\n";
                return false;
            }
            string UserName = "";
            cout << "Enter UserName? ";
            UserName = clsInputValidate::ReadString();

            string Password = "";
            cout << "Enter Password? ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);
            if (!CurrentUser.IsEmpty())
            {
                break;
            }
            else
            {
                cout << "\nInvalid Username/Password!";
                Trail++;
                cout << "\nYou have " << to_string(3 - Trail) << " trails to login\n\n";
            }
        }
        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};
