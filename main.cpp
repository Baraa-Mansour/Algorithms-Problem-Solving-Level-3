#include <iostream>
#include <ctime>
#include<iomanip>
#include "Random.h"

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

int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[100][100] = { {1,2,1},{5,5,5},{7,2,7} };
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    if (IsPalindromeMatrix(Matrix1, 3, 3))
    {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else
        cout << "\nNo: Matrix is NOT Palindrome\n";
    system("pause>0");
}
