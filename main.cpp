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
bool IsEqual(int Arr1[100][100], int Arr2[100][100], int Rows, int Cols)
{
    return (MatrixSum(Arr1, Rows, Cols) == MatrixSum(Arr2, Rows, Cols));
}
//

// proplem-9: Check if matrices are typical
bool IsTypical(int Arr1[100][100], int Arr2[100][100], int Rows, int Cols)
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


int main()
{
    srand((unsigned)time(NULL));
    int Arr[100][100];
    int Arr2[100][100];
    int MidRow[100];
    int MidCol[100];

    Fill2dArrayWithOrderNumber(Arr, 3, 3);
    Fill2dArrayWithOrderNumber(Arr2, 3, 3);

    Print2dArray(Arr, 3, 3);
    Print2dArray(Arr2, 3, 3);

    cout << IsTypical(Arr, Arr2, 3, 3);
    return 0;
}
