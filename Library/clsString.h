#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{

private:
    string _Value;

public:
    clsString()
    {
        _Value = "";
    }
    clsString(string Value)
    {
        _Value = Value;
    }

    void SetValue(string Value)
    {
        _Value = Value;
    }
    string GetValue()
    {
        return _Value;
    }

    static string UpperFirstLetter(string S1)
    {
        bool IsFirstLetter = true;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && IsFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }
            IsFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }
    void UpperFirstLetter()
    {
        _Value = UpperFirstLetter(_Value);
    }

    static void printFirstLetter(string S1)
    {
        bool IsFirstLetter = true;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && IsFirstLetter)
            {
                cout << S1[i] << endl;
            }
            IsFirstLetter = (S1[i] == ' ' ? true : false);
        }
    }
    void printFirstLetter()
    {
        printFirstLetter(_Value);
    }

    static short CountWord(string S1)
    {
        string delim = " "; // delimiter
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable
        // use find() function to get the position of the delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "")
            {
                Counter++;
            }
            // erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }
        return Counter;
    }
    short CountWord()
    {
        return CountWord(_Value);
    }

    static string LowerFirstLetter(string S1)
    {
        bool IsFirstLetter = true;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && IsFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }
            IsFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }
    void LowerFirstLetter()
    {
        _Value = LowerFirstLetter(_Value);
    }

    static string UpperAllLetter(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }
    void UpperAllLetter()
    {
        _Value = UpperAllLetter(_Value);
    }

    static string LowerAllLetter(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }
    void LowerAllLetter()
    {
        _Value = LowerAllLetter(_Value);
    }

    static char IvertLetter(char Lett)
    {
        return isupper(Lett) ? tolower(Lett) : toupper(Lett);
    }

    static string IvertAllLetter(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = IvertLetter(S1[i]);
        }
        return S1;
    }
    void IvertAllLetter()
    {
        _Value = IvertAllLetter(_Value);
    }

    enum enWhatToCount
    {
        SmallLetters = 0,
        CapitalLetters = 1,
        All = 2,
    };

    static short CountLetters(string S1, enWhatToCount WhatToCount)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;
            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }
        return Counter;
    }
    short CountLetters(enWhatToCount WhatToCount)
    {
        return CountLetters(_Value, WhatToCount);
    }

    static int CountCapitalLetter(string S1)
    {
        int Counter = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Counter++;
        }
        return Counter;
    }
    int CountCapitalLetter()
    {
        return CountCapitalLetter(_Value);
    }

    static int CountSmallLetter(string S1)
    {
        int Counter = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Counter++;
        }
        return Counter;
    }
    int CountSmallLetter()
    {
        return CountSmallLetter(_Value);
    }

    static short CountNumOfChar(string S1, char Charactare)
    {
        short count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == Charactare)
                count++;
        }
        return count;
    }
    short CountNumOfChar(char Charactare)
    {
        return CountNumOfChar(_Value, Charactare);
    }

    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }
        }
        return Counter;
    }
    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowelLetter(char Char)
    {
        Char = tolower(Char);
        return ((Char == 'a') || (Char == 'o') || (Char == 'i') || (Char == 'u') || (Char == 'e'));
    }
    static short CountVowel(string S1)
    {
        short count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (IsVowelLetter(S1[i]))
                count++;
        }
        return count;
    }
    short CountVowel()
    {
        return CountVowel(_Value);
    }

    static void PrintVowel(string S1)
    {
        cout << "\nVowels in string are: ";
        for (int i = 0; i < S1.length(); i++)
        {
            if (IsVowelLetter(S1[i]))
                cout << S1[i] << "      ";
        }
    }
    void PrintVowel()
    {
        PrintVowel(_Value);
    }
    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            //if (sWord != "")
            //{
                vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length()); /* erase() until position and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;
    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static string TrimLeft(string S1)
    {

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {

        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector<string> vString, string Delim)
    {

        string S1 = "";

        for (string &s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string JoinString(string arrString[], short Length, string Delim)
    {

        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string ReverseWordsInString(string S1)
    {

        vector<string> vString;
        string S2 = "";

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            S2 += *iter + " ";
        }

        S2 = S2.substr(0, S2.length() - 1); // remove last space.

        return S2;
    }

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
    {

        vector<string> vString = Split(S1, " ");

        for (string &s : vString)
        {

            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = ReplaceTo;
                }
            }
            else
            {
                if (LowerAllLetter(s) == LowerAllLetter(StringToReplace))
                {
                    s = ReplaceTo;
                }
            }
        }

        return JoinString(vString, " ");
    }

    string ReplaceWord(string StringToReplace, string sReplaceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sReplaceTo);
    }

    static string RemovePunctuations(string S1)
    {

        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }
};
