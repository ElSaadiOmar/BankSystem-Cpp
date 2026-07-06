#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsBankClient.h"
#include <iomanip>
class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintTransferRegisterLine(const clsBankClient::stTransferLogRecord &TransferRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferRegisterRecord.Date;
        cout << "| " << setw(8) << left << TransferRegisterRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferRegisterRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferRegisterRecord.Amount;
        cout << "| " << setw(10) << left << TransferRegisterRecord.SourceBalance;
        cout << "| " << setw(10) << left << TransferRegisterRecord.DestinationBalance;
        cout << "| " << setw(8) << left << TransferRegisterRecord.UserName;
    }

public:
    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stTransferLogRecord> vTransferRecord = clsBankClient::GetTransferLogList();
        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferRecord.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________\n";
        for (const clsBankClient::stTransferLogRecord &Record : vTransferRecord)
        {
            _PrintTransferRegisterLine(Record);
            cout << endl;
        }
        cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________\n";
    }
};
