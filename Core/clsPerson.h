#pragma once
#include <iostream>
using namespace std;
class clsPerson
{

private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    void SetEmail(string Email)
    {
        _Email = Email;
    }
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string GetFirstName() const
    {
        return _FirstName;
    }
    string GetLastName() const
    {
        return _LastName;
    }
    string GetEmail() const
    {
        return _Email;
    }
    string GetPhone() const
    {
        return _Phone;
    }
    string FullName() const
    {
        return _FirstName + " " + _LastName;
    }
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n_________________________";
        cout << "\nFirstName : " << _FirstName;
        cout << "\nLastName  : " << _LastName;
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << _Email;
        cout << "\nFhone     : " << _Phone;
        cout << "\n_________________________\n";
    }
    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl;
    }
    void SendSMS(string Body)
    {
        cout << "\nThe following SMS sent successfully to phone number" << _Phone << " \n";
        cout << "Body: " << Body;
    }
};
