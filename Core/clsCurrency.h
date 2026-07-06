#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "clsFileManger.h"
#include <fstream>
#include "C:\Users\elssa\Desktop\Problem\BankFile\Library\clsString.h"
using namespace std;
class clsCurrency
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,

    };
    enMode _Mode;
    string _CountryName;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static string _ConvertCurrencyObjectToLine(const clsCurrency &Currency, const string &Separator = "#//#")
    {
        string DatLine = "";
        DatLine += Currency.GetCountryName() + Separator;
        DatLine += Currency.GetCurrencyCode() + Separator;
        DatLine += Currency.GetCurrencyName() + Separator;
        DatLine += to_string(Currency.GetRate());
        return DatLine;
    }
    static clsCurrency _ConvertLineToCurrencyObject(const string &Line, const string &Separator = "#//#")
    {
        vector<string> vCurrencyData = clsString::Split(Line, Separator);
        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
    }
    static vector<clsCurrency> _LoadCurrencyDataFromFile()
    {
        vector<clsCurrency> vCurrencyData;
        fstream MyFile;
        MyFile.open(clsFileManger::GetCurrenciesFile(), ios::in);
        if (MyFile.is_open())
        {
            string DataLine;
            while (getline(MyFile, DataLine))
            {
                vCurrencyData.push_back(_ConvertLineToCurrencyObject(DataLine));
            }
            MyFile.close();
        }
        return vCurrencyData;
    }
    static void _SaveDataInFile(const vector<clsCurrency> &vCurrencyData)
    {

        fstream MyFile;
        MyFile.open(clsFileManger::GetCurrenciesFile(), ios::out);
        if (MyFile.is_open())
        {
            for (const clsCurrency &C : vCurrencyData)
            {
                MyFile << _ConvertCurrencyObjectToLine(C) << endl;
            }
            MyFile.close();
        }
    }
    void _Update()
    {

        vector<clsCurrency> vCurrencyData = _LoadCurrencyDataFromFile();

        for (clsCurrency &C : vCurrencyData)
        {
            if (C.GetCurrencyCode() == GetCurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveDataInFile(vCurrencyData);
    }

    static clsCurrency _GetEmptyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:
    clsCurrency(enMode Mode, string CountryName, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _CountryName = CountryName;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }
    bool IsEmpty() const
    {
        return (_Mode == enMode::EmptyMode);
    }
    string GetCountryName() const
    {
        return _CountryName;
    }
    string GetCurrencyCode() const
    {
        return _CurrencyCode;
    }
    string GetCurrencyName() const
    {
        return _CurrencyName;
    }

    void UpdateRate(float Rate)
    {
        _Rate = Rate;
        _Update();
    }
    float GetRate() const
    {
        return _Rate;
    }

    static clsCurrency FindByCountry(string CountryName)
    {
        CountryName = clsString::UpperAllLetter(CountryName);
        fstream MyFile;
        MyFile.open(clsFileManger::GetCurrenciesFile(), ios::in);
        if (MyFile.is_open())
        {
            string DataLine;
            while (getline(MyFile, DataLine))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(DataLine);
                if (clsString::UpperAllLetter(Currency.GetCountryName()) == CountryName)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyObject();
    }
    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllLetter(CurrencyCode);
        fstream MyFile;
        MyFile.open(clsFileManger::GetCurrenciesFile(), ios::in);
        if (MyFile.is_open())
        {
            string DataLine;
            while (getline(MyFile, DataLine))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(DataLine);
                if (Currency.GetCurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyObject();
    }
    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency Currency = FindByCode(CurrencyCode);
        //  clsCurrency CurrencyContry = FindByCountry(CurrencyCode);
        return !(Currency.IsEmpty()); // && CurrencyContry.IsEmpty());
    }
    static vector<clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencyDataFromFile();
    }
    double ConvertToUSD(const double Amount) const
    {
        return Amount / GetRate();
    }
    // double ConvertFromDollar(double Amount)
    // {
    //     return Amount * GetRate();
    // }
    double ConvertToOtherCurrency(const double Amount, const clsCurrency &Currency2) const
    {
        double AmountInUSD = ConvertToUSD(Amount);
        if (Currency2.GetCurrencyCode() == "USD")
        {
            return AmountInUSD;
        }
        // return Currency2.ConvertFromDollar(ConvertToUSD(Amount));
        return AmountInUSD * Currency2.GetRate();
    }
};
