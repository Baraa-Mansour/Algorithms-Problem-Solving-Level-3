#include <iostream>
#include <ctime>
#include<iomanip>
#include "Random.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// HELPER
void PrintMatrix(int Arr[100][100], int Rows, int Columns)
{
    cout << endl;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            printf("%0*d   ", 2, Arr[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

// proplem-1: Fill 2d array with random numbers
void Fill2dArrayWithRandomNumbers(int Arr[100][100], int Rows, int Columns)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            Arr[i][j] = Random::GenerateRandomNumberInRange(1, 100);
        }
    }
}
//

// proplem-2: Sum each row
int SumRowElement(int Arr[100][100], int RowNumber, int Columns)
{
    int sum = 0;

    for (int i = 0; i < Columns; i++)
        sum += Arr[RowNumber][i];

    return sum;
}
void PrintEachRowSum(int Arr[100][100], int Rows, int Columns)
{
    for (int i = 0; i < 3; i++)
    {
        int Sum = SumRowElement(Arr, i, Columns);
        printf("Sum of Row %d: %d \n", i, Sum);
    }
}
//

// proplem-3: Get Sum columns into another array
int SumColumenElement(int Arr[100][100], int Rows, int ColumnNumber)
{
    int sum = 0;

    for (int i = 0; i < Rows; i++)
        sum += Arr[i][ColumnNumber];

    return sum;
}
void GetSumColumnsElementsArray(int Arr[100][100],int arr[100], int Rows, int Columns)
{

    for (int i = 0; i < Columns; i++)
        arr[i] = SumColumenElement(Arr, Rows, i);
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element " << i << ": " << arr[i] << endl;
    }
}
//

// proplem-4: Fill 2d Array with oreder number
void Fill2dArrayWithOrderNumber(int Arr[100][100], int Rows, int Cols)
{
    for (int i = 0, k = 1; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = k++;
        }
        
    }
}
//

// proplem-5: transpose matrix
void TransposeMatrix(int Arr[100][100], int TransposeArr[100][100], int Rows, int Cols)
{
    for (int i = 0, k = 1; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            TransposeArr[j][i] = Arr[i][j];
        }
    }
}
//

// proplem-6: Multiply 2 arrays
void Mutltiply2Matrix(int Arr1[100][100], int Arr2[100][100], int Result[100][100],
    int Rows, int Cols)
{
    for (int i = 0, k = 1; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Result[i][j] = Arr1[i][j] * Arr2[i][j];
        }
    }
}
//

// proplem-7: Print middle row and column in matrix
void GetMiddleRow(int Arr[100][100], int MidArr[100], int Rows, int Cols)
{
    int MiddleRow = Rows / 2;
    for (int i = 0; i < Cols; i++)
        MidArr[i] = Arr[MiddleRow][i];
}
void GetMiddleCol(int Arr[100][100], int MidArr[100], int Rows, int Cols)
{
    int MiddleCol = Cols / 2;
    for (int i = 0; i < Rows; i++)
        MidArr[i] = Arr[i][MiddleCol];
}
//

// proplem-8: Check if two matrices are equal
int MatrixSum(int Arr[100][100], int Rows, int Cols)
{
    int Sum = 0;
    for (int i = 0, k = 1; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Sum += Arr[i][j];
        }
    }
    return Sum;
}
bool IsEqualMatrix(int Arr1[100][100], int Arr2[100][100], int Rows, int Cols)
{
    return (MatrixSum(Arr1, Rows, Cols) == MatrixSum(Arr2, Rows, Cols));
}
//

// proplem-9: Check if matrices are typical
bool IsTypicalMatrix(int Arr1[100][100], int Arr2[100][100], int Rows, int Cols)
{
    for (int i = 0, k = 1; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Arr1[i][j] != Arr2[i][j])
                return false;
        }
    }
    return true;
}
//

// proplem-10: Check if matrix is Identity
bool IsIdentityMarix(int Matrix1[100][100], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix1[i][j] != 1)
            {
                return false;
            }
            else if (i != j && Matrix1[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
//

// proplem-11: Check if scalar matrix
bool IsScalarMatrix(int Matrix[100][100], short Rows, short Cols)
{
    int FirstCeilValue = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstCeilValue)
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
//


// proplem-12: Count number in matrix
int CountNumberInMatrix(int Matrix[100][100], short Rows, short Cols, int Number)
{
    int Counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
                Counter++;
        }
    }
    return Counter;
}
//

// proplem-13: Check If Sparse Matrix
bool IsSparceMatrix(int Matrix[100][100], short Rows, short Cols)
{
    int CountOfZero = CountNumberInMatrix(Matrix, Rows, Cols, 0);
    int MatrixSize = Rows * Cols;

    return CountOfZero > (MatrixSize / 2);
}
//

// proplem-14: Check If Palindrome Matrix
bool IsPalindromeMatrix(int Matrix[100][100], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
                return false;
        }
    }
    return true;
}
//

// proplem-15: Fibonacci using loop
void PrintFibonacciUsingLoop(short Number)
{
    int FibNumber = 1;
    int Prev1 = 1, Prev2 = 0;
    cout << "1" << " ";
    for (int i = 2; i <= Number; i++)
    {
        FibNumber = Prev1 + Prev2;
        cout << FibNumber << " ";

        Prev2 = Prev1;
        Prev1 = FibNumber;
    }
}
//

// proplem-16: Fibonacci using recurssion
void PrintFibonacciUsingRecurssion(short Number, short Prev1, short Prev2)
{
    if (Number > 0)
    {
        int FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << " ";
        PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
    }
}
//

// proplem-17: Print first letter from each word
void PrintFirstLetterOfEachWord(string Line)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < Line.size(); i++)
    {
        if (Line[i] != ' ' && IsFirstLetter)
        {
            cout << Line[i] << endl;
            IsFirstLetter = false;
        }
        
        IsFirstLetter = Line[i] == ' ' ? true : false;
    }
}
//

// proplem-18: Uppercase From each first letter
string UpperEachFirstLetter(string Line)
{
    string UpperLine = "";
    bool IsFirstLetter = true;

    for (int i = 0; i < Line.size(); i++)
    {
        if (Line[i] != ' ' && IsFirstLetter)
        {
            UpperLine += toupper(Line[i]);
        }
        else
        {
            UpperLine += Line[i];
        }

        IsFirstLetter = Line[i] == ' ' ? true : false;
    }

    return UpperLine;
}
//

// proplem-19: Upper/Lower String
string ToUpperString(string Line)
{
    string UpperLine = "";

    for (const char& Letter : Line)
        UpperLine += toupper(Letter);

    return UpperLine;
}
string ToLowerString(string Line)
{
    string LowerLine = "";

    for (const char& Letter : Line)
        LowerLine += tolower(Letter);

    return LowerLine;
}
void PrintUpperLowerString(string Line)
{
    cout << Line << endl;
    printf("Uppercase: %s\n", ToUpperString(Line).c_str());
    printf("Lowercase: %s\n", ToLowerString(Line).c_str());
}
//

// proplem-20: Invert char case
char InvertCharCase(char C)
{
    return isupper(C) ? tolower(C) : toupper(C);
}
//

// proplem-21: Invert all string char case
string InvertStringCase(string Line)
{
    for (char& c : Line)
        c = InvertCharCase(c);

    return Line;
}
//

// proplem-22: Print Count of Capital/Small letters and length of string
struct stStringCountInfo
{
    short Length = 0;
    short CapitalCount = 0;
    short SmallCount = 0;
    short WhiteSpace = 0;
};
stStringCountInfo CountString(const string& Line)
{
    stStringCountInfo StringInfo;

    StringInfo.Length = Line.size();

    for (const char& c : Line)
    {
        c == ' ' ? StringInfo.WhiteSpace++
            : (isupper(c) ? StringInfo.CapitalCount++ 
                : StringInfo.SmallCount++);
    }

    return StringInfo;
}
void PrintStringCountInfo(stStringCountInfo StringInfo)
{
    printf("Length: %d \n", StringInfo.Length);
    printf("Capital : %d \n", StringInfo.CapitalCount);
    printf("Small: %d \n", StringInfo.SmallCount);
    printf("White space: %d \n", StringInfo.WhiteSpace);
}
//

// proplem-23: Check if chr is vowel
bool IsVowel(char Char)
{
    Char = tolower(Char);

    return (Char == 'a') || (Char == 'e') || (Char == 'i')
        || (Char == 'o') || (Char == 'u');
}
//

// proplem-24: Print each word in string
bool IsEmpty(string& Line)
{
    return Line == "" || Line == " ";
}
//void PrintStringWords(string& Line)
//{
//    if (IsEmpty(Line))
//        return;
//
//    string Word = "";
//    for (int i = 0; i < Line.length(); i++)
//    {
//        if (Line[i] != ' ')
//            Word += Line[i];
//        else if(!IsEmpty(Word))
//        {
//            cout << Word << endl;
//            Word = "";
//        }
//    }
//}
void PrintStringWords(string& Line)
{
    string Word = "";
    short Pos = 0;
    const string Dilim = " ";

    while ((Pos = Line.find(Dilim)) != std::string::npos)
    {
        Word = Line.substr(0, Pos);

        if(!IsEmpty(Word))
            cout << Word << endl;

        Line.erase(0, Pos + Dilim.length());
    }

    // Print last word cause find method wont find it if Line dont end with white space
    if (!IsEmpty(Line)) 
        cout << Line << endl;
}
//

// proplem-25: Split string -> Return vector contain string word based on delimiter
vector<string> SplitString(string Line, string Delimiter = " ")
{
    vector<string> vWords;
    string Word = "";
    short Pos = 0;

    while ((Pos = Line.find(Delimiter)) != std::string::npos)
    {
        Word = Line.substr(0, Pos);

        if (!IsEmpty(Word))
            vWords.push_back(Word);

        Line.erase(0, Pos + Delimiter.length());
    }

    // Print last word cause find method wont find it if Line dont end with white space
    if (!IsEmpty(Line))
        vWords.push_back(Line);

    return vWords;
}
void PrintVector(vector<string> vStrings)
{
    for (const string& str : vStrings)
        cout << str << endl;
}
//

// proplem-26: Trim left/right/all
string TrimLeft(string Line)
{
    for (int i = 0; i < Line.length(); i++)
    {
        if (Line[i] != ' ')
            return Line.substr(i, Line.length() - i);
    }
    return Line;
}
string TrimRight(string Line)
{
    for (int i = Line.length() - 1; i >= 0; i--)
    {
        if (Line[i] != ' ')
            return Line.substr(0, i + 1);
    }
    return Line;
}
string Trim(string Line)
{
    return TrimRight(TrimLeft(Line));
}
//

// proplem-27: Join String
string Join(vector<string> vStrings, string Delimiter = " ")
{
    string Line = "";

    for (const string& Word : vStrings)
        Line += Word + Delimiter;
    
    return Line.substr(0, Line.length() - Delimiter.length());
}
//

// proplem-28(extend 27): Join string using array (overloading)
string Join(string Strings[], short ArrLength, string Delimiter = " ")
{
    string Line = "";

    for (int i = 0 ; i < ArrLength ; i++)
        Line += Strings[i] + Delimiter;
        
    return Line.substr(0, Line.length() - Delimiter.length());
}
//

// proplem-29: Reverse sting word
string ReverseWords(string Line, string Delimiter = " ")
{
    string ReversedLine = "";
    
    vector<string> vWords = SplitString(Line, Delimiter);
    vector<string>::iterator strIter = vWords.end();

    while (strIter != vWords.begin())
    {
        strIter--;
        ReversedLine += *strIter + Delimiter;
    }

    return ReversedLine.substr(0, ReversedLine.length() - Delimiter.length());
}
//

// proplem-30: Replace word in string
string ReplaceWord(string Line, string OldWord, string NewWord)
{
    short Pos = 0;

    while ((Pos = Line.find(OldWord)) != string::npos)
    {
        Line = Line.replace(Pos, OldWord.length(), NewWord);
    }

    return Line;
}
//

// proplem-31: Replace word in string with custom with match case
string ReplaceWord(string Line, string OldWord, string NewWord, bool MatchCase)
{
    vector<string> vWords = SplitString(Line);

    for (string& Word : vWords)
    {
        if (MatchCase)
        {
            if (Word == OldWord)
                Word = NewWord;
        }
        else
        {
            if (ToLowerString(Word) == ToLowerString(OldWord))
            {
                Word = NewWord;
            }
        }
    }

    return Join(vWords);
}
//

// proplem-32: Delete Punctuations From String
string DeletePunctuationsFromString(string Line)
{
    string NewLine = "";

    for (const char& Char : Line)
        if (!ispunct(Char))
            NewLine += Char;

    return NewLine;
}
//

// proplem-33: Read client data and save if as record in file
struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;
};
stClient ReadClientInfo()
{
    stClient Client;

    cout << "Account number: ";
    getline(cin, Client.AccountNumber);

    cout << "Pin Code: ";
    getline(cin, Client.PinCode);

    cout << "Name: ";
    getline(cin, Client.Name);

    cout << "Phone: ";
    getline(cin, Client.Phone);

    cout << "Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}
string ClientToString(stClient Client)
{
    string Record = "";
    string Delimiter = "#//#";

    Record += Client.AccountNumber + Delimiter;
    Record += Client.PinCode + Delimiter;
    Record += Client.Name + Delimiter;
    Record += Client.Phone + Delimiter;
    Record += to_string(Client.AccountBalance);

    return Record;
}
bool SaveClient(stClient Client)
{
    fstream File;
    File.open("Clients.txt", ios::out | ios::app);

    if (File.is_open())
    {
        string Record = ClientToString(Client);
        File << Record << endl;

        File.close();

        return true;
    }


    return false;
}
//

int main()
{
    srand((unsigned)time(NULL));

    stClient Client = ReadClientInfo();

    cout << ClientToString(Client);

    SaveClient(Client);
}
