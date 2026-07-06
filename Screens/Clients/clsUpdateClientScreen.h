#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsBankClient.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "\nEnter First Name: ";
        Client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter Last Name: ";
        Client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadNumber<float>());
    }
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
    static void ShowUpdateClientScreen()
    {
         if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("\tUpdate Client Screen");
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

            cout << "\n\nUpdate Client Info:";
            cout << "\n_________________________\n";

            _ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Update Successfully :-)\n";
                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }
            }
        }
    }
};