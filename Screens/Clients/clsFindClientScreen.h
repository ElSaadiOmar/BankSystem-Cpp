#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsBankClient.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include <iomanip>
class clsFindClientScreen : protected clsScreen
{
private:
    static void _PrintClient(const clsBankClient &Client)
    {
        cout << "\nClient Card:";
        cout << "\n_________________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n_________________________\n";
    }

public:
    static void ShowFindClientScreen()
    {
         if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("\tFind Client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
            cout << "\nClient Found :-)";
        else
            cout << "\nClient not Found :-()";
        _PrintClient(Client1);
    }
};