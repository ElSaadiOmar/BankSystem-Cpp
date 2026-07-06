#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsUsers.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsUtil.h"
#include <iomanip>
using namespace std;
class clsListUserScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(const clsUser &User)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.GetPhone();
        cout << "| " << setw(20) << left << User.GetEmail();
        cout << "| " << setw(10) << left << User.GetPassword();
        cout << "| " << setw(12) << left << User.GetPermission();
    }

public:
    static void ShowUsersList()
    {
        vector<clsUser> vUserList = clsUser::GetUsersList();
        string Title = "\t User List Screen";
        string SubTitle = "\t  (" + to_string(vUserList.size()) + ") User(s)";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permission";
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________\n";
        if (vUserList.size() == 0)
        {
            cout << clsUtil::Tabs(4) << "No User Available In the System!";
        }
        else
        {
            for (const clsUser &User : vUserList)
            {
                _PrintUserRecordLine(User);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________\n";
    }
};