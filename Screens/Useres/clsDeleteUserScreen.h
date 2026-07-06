#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsUsers.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
class clsDeleteUserScreen : protected clsScreen
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
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("Delete User Screen");
        string UserName = "";
        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName) || UserName == "Admin")
        {
            cout << "\nYou cannot Delete this User Or User Name is not Found.\nchoose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);
        cout << "\n\nAre you sure you went to delete this client y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (User.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};
