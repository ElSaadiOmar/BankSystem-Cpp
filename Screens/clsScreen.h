#pragma once
#include <iostream>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Global.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsUsers.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsDate.h"
using namespace std;
class clsScreen
{

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {

        cout << "\t\t\t\t     ___________________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t     ___________________________________________\n";
        cout << "\n\t\t\t\t     User: " << CurrentUser.GetUserName();
        cout << "\n\t\t\t\t     Date: " << clsDate::DateToString(clsDate()) << endl
             << endl;
    }
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!(CurrentUser.CheckAccessPermission(Permission)))
        {
            cout << "\t\t\t\t     ___________________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin";
            cout << "\n\t\t\t\t     ___________________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};