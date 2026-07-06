#pragma once
#include <iostream>
#include <string>
using namespace std;
class clsFileManger 
{
public:
    static string GetUserFile()
    {
      return "txtFiles\\Users.txt";
    } 
    static string GetClientsFile()
    {
        return "txtFiles\\Clients.txt";
    }
    static string GetLoginRegisterFile()
    {
      return "txtFiles\\LoginsRegister.txt";
    } 
    static string GetTransferLogFile()
    {
        return "txtFiles\\TransferLog.txt";
    }
    static string GetCurrenciesFile()
    {
        return "txtFiles\\Currencies.txt";
    }

};