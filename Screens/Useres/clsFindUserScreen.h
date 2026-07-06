#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsUsers.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include <iomanip>
class clsFindUserScreen : protected clsScreen
{
private:
    static void _PrintUser(const clsUser &User)
    {

        cout << "\nUser Card:";
        cout << "\n_________________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUserName    : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermission();
        cout << "\n_________________________\n";
    }

public:
    static void ShowFindUserScreen()
    {
        clsScreen::_DrawScreenHeader("\tFind User Screen");
        string UserName = "";
        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser Client1 = clsUser::Find(UserName);

        if (!Client1.IsEmpty())
            cout << "\nUser Found :-)";
        else
            cout << "\nUser not Found :-()";
        _PrintUser(Client1);
    }
};