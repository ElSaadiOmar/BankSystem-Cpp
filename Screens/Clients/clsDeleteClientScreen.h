#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsBankClient.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
class clsDeleteClientScreen : protected clsScreen
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
        cout << "\nPin Code    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n_________________________\n";
    }

public:
    static void ShowDeleteClientScreen()
    {
         if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        _DrawScreenHeader("\tDelete client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\n\nAre you sure you went to delete this client y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};
