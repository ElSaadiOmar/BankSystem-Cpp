#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsBankClient.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Global.h"
class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClientCard(const clsBankClient &Client)
    {
        cout << "Client Card:\n";
        cout << "_____________________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n_____________________________\n";
    }
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }
    static double _ReadAmount(const clsBankClient &Client)
    {
        double Amount = 0;
        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate::ReadNumber<double>();
        while (Client.GetAccountBalance() < Amount)
        {

            cout << "\nAmount Exceeds the variable Balance, Enter another Amount: ";
            Amount = clsInputValidate::ReadNumber<double>();
        }
        return Amount;
    }

public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClientCard(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClientCard(DestinationClient);

        double Amount = _ReadAmount(SourceClient);
        char Answer = 'n';
        cout << "\nAre you sure you want to perform this operarion? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.GetUserName()))
            {
                cout << "\nTransfer done successfully\n";
                _PrintClientCard(SourceClient);
                _PrintClientCard(DestinationClient);
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }
    }
};
