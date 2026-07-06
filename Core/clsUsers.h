#pragma once
#include <iostream>
#include <string>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsPerson.h"
#include <vector>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsString.h"
#include <fstream>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsDate.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsUtil.h"
using namespace std;
class clsUser : public clsPerson
{
 private:
public:
    struct stLoginRegisterRecord
    {
        string Date;
        string UserName;
        string Password;
        int Permission;
    };

private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
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
        return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtil::DecryptText(vUser[5]), stoi(vUser[6]));
    }
    static string _ConvertUserObjectToLine(const clsUser &User, string Separator = "#//#")
    {
        string Line = "";
        Line += User.GetFirstName() + Separator;
        Line += User.GetLastName() + Separator;
        Line += User.GetEmail() + Separator;
        Line += User.GetPhone() + Separator;
        Line += User.GetUserName() + Separator;
        Line += clsUtil::EncryptText(User.GetPassword()) + Separator;
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

    string _PrepareLogInRecord(string Separator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetDateWithTime() + Separator;
        LoginRecord += GetUserName() + Separator;
        LoginRecord += clsUtil::EncryptText(GetPassword()) + Separator;
        LoginRecord += to_string(GetPermission());
        return LoginRecord;
    }
    static stLoginRegisterRecord _PraseLoginRecord(string Line, string Separator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector<string> LoginRegisterDatLine = clsString::Split(Line, Separator);
        LoginRegisterRecord.Date = LoginRegisterDatLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDatLine[1];
        LoginRegisterRecord.Password =clsUtil::DecryptText( LoginRegisterDatLine[2]);
        LoginRegisterRecord.Permission = stoi(LoginRegisterDatLine[3]);
        return LoginRegisterRecord;
    }

public:
    enum enPermissions
    {
        pAllPermission = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClient = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64,
        pLoginRegister = 128,
        pCurrencyExchange=256,

    };
    clsUser(enMode Mode, string FirstName, string LastName, string Email,
            string Phone, string UserName, string Password, int Permission) : clsPerson(FirstName, LastName, Email, Phone)
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
        svFaildUserExist = 2,

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
                return enSaveResults::svFaildUserExist;
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
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->_Permission == enPermissions::pAllPermission)
            return true;
        if ((this->_Permission & Permission) == Permission)
            return true;
        else
            return false;
    }

    void RegisterLogin()
    {
        fstream MyFile;
        MyFile.open("LoginsRegister.txt", ios::out | ios ::app);
        if (MyFile.is_open())
        {
            MyFile << _PrepareLogInRecord() << endl;
            MyFile.close();
        }
    }
    static vector<stLoginRegisterRecord> GetLoginRecord()
    {
        vector<stLoginRegisterRecord> vUserLogin;
        fstream MyFile;
        MyFile.open("LoginsRegister.txt", ios::in);
        if (MyFile.is_open())
        {
            string DataLine;
            while (getline(MyFile, DataLine))
            {
                vUserLogin.push_back(_PraseLoginRecord(DataLine));
            }
            MyFile.close();
        }
        return vUserLogin;
    }
};
