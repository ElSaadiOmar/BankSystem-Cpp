#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsBankClient.h"
#include <iomanip>
using namespace std;
class clsClientListScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient &Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetPhone();
        cout << "| " << setw(20) << left << Client.GetEmail();
        cout << "| " << setw(10) << left << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
    }

public:
    static void ShowClientList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n";
        if (vClients.size() == 0)
        {
            cout << clsUtil::Tabs(4) << "No Client Available In the System!";
        }
        else
        {
            for (clsBankClient &Client : vClients)
            {
                _PrintClientRecordLine(Client);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n";
    }
};