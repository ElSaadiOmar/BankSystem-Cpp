#pragma once
#include <iostream>
#include <iomanip>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsBankClient.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
using namespace std;
class clsDepositScreen : protected clsScreen
{
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
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:
    static void ShowDepositScreen()
    {
        clsScreen::_DrawScreenHeader("\tDeposit Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With [" << AccountNumber << "] does not exist.";
            cout << "Pleas enter Account Number? ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "Please enter deposit amount? ";
        Amount = clsInputValidate::ReadNumber<double>();
        cout << "Are you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAccount Deposited Successfully.";
            cout << "\nNew Balance Is: " << Client1.GetAccountBalance();
        }
        else
        {

            cout << "\nOperation was cancelled.\n";
        }
    }
};