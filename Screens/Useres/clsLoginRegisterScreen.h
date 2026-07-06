#pragma once
#include <iostream>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsUsers.h"
#include <iomanip>
class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _PrintLoginRegisterLine(const clsUser::stLoginRegisterRecord &LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << LoginRegisterRecord.Date;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permission;
    }

public:
    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }
        vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRecord();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s)";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permission";
        cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________\n";
        for (const clsUser::stLoginRegisterRecord &Record : vLoginRegisterRecord)
        {
            _PrintLoginRegisterLine(Record);
            cout << endl;
        }
        cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________\n";
    }
};
