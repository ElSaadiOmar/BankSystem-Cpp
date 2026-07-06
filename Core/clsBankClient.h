#pragma once
#include <iostream>
#include "clsFileManger.h"
#include <string>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsPerson.h"
#include <vector>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsString.h"
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
public:
    struct stTransferLogRecord
    {
        string Date;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        double Amount;
        double SourceBalance;
        double DestinationBalance;
        string UserName;
    };

private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2,

    };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    string _PrepareTransferRecord(const double &Amount, const clsBankClient &DestinationClient, const string &UserName, const string &Separator = "#//#")
    {
        string Line = "";
        Line += clsDate::GetDateWithTime() + Separator;

        Line += GetAccountNumber() + Separator;
        Line += DestinationClient.GetAccountNumber() + Separator;

        Line += to_string(Amount) + Separator;

        Line += to_string(GetAccountBalance()) + Separator;
        Line += to_string(DestinationClient.GetAccountBalance()) + Separator;

        Line += UserName;
        return Line;
    }

    static stTransferLogRecord _PraseTransferRecord(string Line, string Separator = "#//#")
    {
        stTransferLogRecord TransferRegisterRecord;
        vector<string> vRecord = clsString::Split(Line, Separator);
        TransferRegisterRecord.Date = vRecord[0];
        TransferRegisterRecord.SourceAccountNumber = vRecord[1];
        TransferRegisterRecord.DestinationAccountNumber = vRecord[2];
        TransferRegisterRecord.Amount = stod(vRecord[3]);
        TransferRegisterRecord.SourceBalance = stod(vRecord[4]);
        TransferRegisterRecord.DestinationBalance = stod(vRecord[5]);
        TransferRegisterRecord.UserName = vRecord[6];
        return TransferRegisterRecord;
    }
    static clsBankClient
    _ConvertLinetoClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData = clsString::Split(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                             vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static string _ConvertClientObjecttoLine(clsBankClient Client, string Separator = "#//#")
    {
        return Client.GetFirstName() + Separator + Client.GetLastName() + Separator + Client.GetEmail() + Separator + Client.GetPhone() +
               Separator + Client.GetAccountNumber() + Separator +
               Client.GetPinCode() + Separator + to_string(Client.GetAccountBalance());
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> _vClient;

        fstream MyFile;
        MyFile.open(clsFileManger::GetClientsFile(), ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                _vClient.push_back(Client);
            }
            MyFile.close();
        }
        return _vClient;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> vClient)
    {
        fstream MyFile;
        MyFile.open(clsFileManger::GetClientsFile(), ios::out);
        if (MyFile.is_open())
        {
            for (clsBankClient &C : vClient)
            {
                if (C.GetMarkForDelete() == false)
                {
                    MyFile << _ConvertClientObjecttoLine(C) << endl;
                }
            }
            MyFile.close();
        }
    }
    void _Update()
    {
        vector<clsBankClient> _vClient;
        _vClient = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClient)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(_vClient);
    }
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjecttoLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open(clsFileManger::GetClientsFile(), ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    void _RegisterTransferLog(const double &Amount, const clsBankClient &DestinationClient, const string &UserName)
    {
        fstream MyFile;
        string DataLine = _PrepareTransferRecord(Amount, DestinationClient, UserName);
        MyFile.open(clsFileManger::GetTransferLogFile(), ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
                  string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    string GetAccountNumber() const
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode() const
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance() const
    {
        return _AccountBalance;
    }

    void SetMarkForDelete(bool MarkForDelete)
    {
        _MarkForDelete = MarkForDelete;
    }
    bool GetMarkForDelete() const
    {
        return _MarkForDelete;
    }

    static clsBankClient Find(string AccountNum)
    {
        fstream MyFile;
        MyFile.open(clsFileManger::GetClientsFile(), ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.GetAccountNumber() == AccountNum)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }
    static clsBankClient Find(string AccountNum, string PinCode)
    {
        fstream MyFile;
        MyFile.open(clsFileManger::GetClientsFile(), ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.GetAccountNumber() == AccountNum &&
                    Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }
    enum enSaveResults
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildAccountNumberExists = 2,
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
        }
        return enSaveResults::svFaildEmptyObject;
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
    bool Delete()
    {
        vector<clsBankClient> vClientData;
        vClientData = _LoadClientsDataFromFile();
        for (clsBankClient &C : vClientData)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }
        _SaveClientsDataToFile(vClientData);
        *this = _GetEmptyClientObject();
        return true;
    }
    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }
    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients = GetClientsList();
        double TotalBalance = 0;
        for (clsBankClient const &Client : vClients)
        {
            TotalBalance += Client.GetAccountBalance();
        }
        return TotalBalance;
    }
    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }
    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
            return false;
        else
        {
            _AccountBalance -= Amount;
            Save();
        }
        return true;
    }
    bool Transfer(const double &Amount, clsBankClient &DestinationClient, const string &UserName)
    {
        if (Amount > GetAccountBalance())
        {
            return false;
        }
        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }
    static vector<stTransferLogRecord> GetTransferLogList()
    {
        vector<stTransferLogRecord> vTransferLog;
        fstream MyFile;
        MyFile.open(clsFileManger::GetTransferLogFile(), ios::in);
        
        if (MyFile.is_open())
        {string DataLine;
            while (getline(MyFile, DataLine))
            {
                vTransferLog.push_back(_PraseTransferRecord(DataLine));
            }
            MyFile.close();
        }
        return vTransferLog;
    }
};
/*
#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include <vector>
#include "clsString.h"
#include <fstream>
using namespace std;
class clsUser : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode=1,
        AddNewMode = 2
    };
    enMode _Mode;
    string _UserName;
    string _Password;
    short _Permission;
    bool _MarkForDelete = false;

    static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector<string> vUser = clsString::Split(Line, Separator);
        return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stoi(vUser[6]));
    }
    static string _ConvertUserObjectToLine(const clsUser &User, string Separator = "#//#")
    {
        string Line = "";
        Line += User.GetFirstName() + Separator;
        Line += User.GetLastName() + Separator;
        Line += User.GetEmail() + Separator;
        Line += User.GetPhone() + Separator;
        Line += User.GetUserName() + Separator;
        Line += User.GetPassword() + Separator;
        Line += to_string(User.GetPermission());
        return Line;
    }
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUser;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                vUser.push_back(_ConvertLineToUserObject(Line));
            }
            MyFile.close();
        }
        return vUser;
    }

    static void _SaveDataUserToFile(const vector<clsUser> &vUser)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);
        if (MyFile.is_open())
        {
            string Line;
            for (const clsUser &User : vUser)
            {
                if (User.GetMarkForDeleted() == false)
                {
                    Line = _ConvertUserObjectToLine(User);
                    MyFile << Line << endl;
                }
            }
            MyFile.close();
        }
    }

    void _MarkedForDelete()
    {
        _MarkForDelete = true;
    }
    void _Update()
    {
        vector<clsUser> vUser = _LoadUsersDataFromFile();
        for (clsUser &User : vUser)
        {
            if (User.GetUserName() == _UserName)
            {
                User = *this;
                break;
            }
        }
        _SaveDataUserToFile(vUser);
    }
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }
    void _AddDataLineToFile(string stDataLine)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

public:
    clsUser(enMode Mode, string FirstName, string LastName, string Email,
            string Phone, string UserName, string Password, short Permission) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permission = Permission;
    }
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    static bool IsUserExist(string UserName)
    {
        clsUser User = Find(UserName);
        return !(User.IsEmpty());
    }
    bool GetMarkForDeleted() const
    {
        return _MarkForDelete;
    }

    string GetUserName() const
    {
        return _UserName;
    }
    void SetUsername(const string &UserName)
    {
        _UserName = UserName;
    }

    string GetPassword() const
    {
        return _Password;
    }
    void SetPassword(const string &Password)
    {
        _Password = Password;
    }

    short GetPermission() const
    {
        return _Permission;
    }
    void SetPermission(const short &Permission)
    {
        _Permission = Permission;
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.GetUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }
    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if ((User.GetUserName() == UserName) && (User.GetPassword() == Password))
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildeUserExist = 2,

    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildeUserExist;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
        }
        return enSaveResults::svFaildEmptyObject;
    }

    bool Delete()
    {
        bool Found = false;
        vector<clsUser> vUser = _LoadUsersDataFromFile();
        for (clsUser &User : vUser)
        {
            if (User.GetUserName() == _UserName)
            {
                User._MarkedForDelete();
                Found = true;
                break;
            }
        }
        _SaveDataUserToFile(vUser);
        if (Found)
        {
            *this = _GetEmptyUserObject();
        }
        return Found;
    }
    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }
    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
};


*/