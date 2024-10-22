#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Input(int** a, const int k, const int n);
void Print(int** a, const int k, const int n);
int SUM(int** a, const int k, const int n);
void MinDiagonalSum(int** a, const int k, const int n);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int Low = -99;
    int High = 99;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    //Create(a, k, n, Low, High);
    Input(a, k, n);

    Print(a, k, n);

    int sum = SUM(a, k, n);
    cout << "Сума елементів у тих стовпцях, які не містять від'ємних елементів  " << sum << endl;

    MinDiagonalSum(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int k, const int n)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}
void Print(int** a, const int k, const int n)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SUM(int** a, const int k, const int n)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        bool hasNegative = false;
        for (int i = 0; i < k; i++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative)
        {
            for (int i = 0; i < k; i++)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

void MinDiagonalSum(int** a, const int k, const int n)
{
    int minSum = INT_MAX;

    for (int first = 1; first < n; first++)
    {
        int sum = 0;
        for (int i = 0, j = first; i < k && j >= 0; i++, j--)
        {
            sum += abs(a[i][j]);
        }
        if (sum < minSum)
            minSum = sum;
    }

    for (int first = 1; first < k; first++)
    {
        int sum = 0;
        for (int i = first, j = n - 1; i < k && j >= 0; i++, j--)
        {
            sum += abs(a[i][j]);
        }
        if (sum < minSum)
            minSum = sum;
    }

    cout << "Мінімум серед сум модулів елементів діагоналей, паралельних до побічної діагоналі матриці " << minSum << endl;
}
