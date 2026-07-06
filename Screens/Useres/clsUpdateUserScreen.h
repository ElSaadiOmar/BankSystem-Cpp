#pragma once
#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\clsScreen.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Core\clsUsers.h"
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsInputValidate.h"
class clsUpdateUserScreen : protected clsScreen
{
private:
    static int _ReadPermissionToSet()
    {
        int Permissions = 0;
        char Answer = 'n';
        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pAllPermission))
            {
                return -1;
            }
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pListClients))
            {
                Permissions |= clsUser::enPermissions::pListClients;
            }
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pAddNewClient))
            {
                Permissions |= clsUser::enPermissions::pAddNewClient;
            }
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pDeleteClient))
            {
                Permissions |= clsUser::enPermissions::pDeleteClient;
            }
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pUpdateClient))
            {
                Permissions |= clsUser::enPermissions::pUpdateClient;
            }
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pFindClient))
            {
                Permissions |= clsUser::enPermissions::pFindClient;
            }
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pTransactions))
            {
                Permissions |= clsUser::enPermissions::pTransactions;
            }
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pManageUsers))
            {
                Permissions |= clsUser::enPermissions::pManageUsers;
            }
        }
        cout << "\nShow Login Register? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pLoginRegister))
            {
                Permissions |= clsUser::enPermissions::pLoginRegister;
            }
        }
        cout << "\nCurrency Exchange? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            if (CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
            {
                Permissions |= clsUser::enPermissions::pCurrencyExchange;
            }
        }

        return Permissions;
    }
    static void _ReadUserInfo(clsUser &User)
    {
        cout << "\nEnter First Name: ";
        User.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter Last Name: ";
        User.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        User.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        User.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permission: ";
        User.SetPermission(_ReadPermissionToSet());
    }
    static void _PrintUser(const clsUser &User)
    {

        cout << "\nUser Card:";
        cout << "\n_________________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUserName    : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermission();
        cout << "\n_________________________\n";
    }

public:
    static void ShowUpdateClientScreen()
    {
        clsScreen::_DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName) || UserName == "Admin")
        {
            cout << "\nAccount Number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\n\nAre you sure you went to Update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n_________________________\n";

            _ReadUserInfo(User);

            clsUser::enSaveResults SaveResult;
            SaveResult = User.Save();

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Update Successfully :-)\n";
                _PrintUser(User);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }
            }
        }
    }
};