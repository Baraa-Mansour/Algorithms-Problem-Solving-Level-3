#include <iostream>
#include <ctime>
#include<iomanip>
#include "Random.h"

using namespace std;

// HELPER
void Print2dArray(int Arr[100][100], int Rows, int Columns)
{
    cout << endl;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            cout << setw(3) << Arr[i][j] << "   ";
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

int main()
{
    srand((unsigned)time(NULL));
    int Arr[100][100];
    int Transpose[100][100];

    Fill2dArrayWithOrderNumber(Arr, 3, 3);
    TransposeMatrix(Arr, Transpose, 3, 3);

    Print2dArray(Transpose, 3, 3);
    return 0;
}
