#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, int n, int Low, int High);
void Print(int** a, int n);
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}



int Search(int** a, const int n, int* iArrOfCountOfZeroValues, int& p)
{
    int iCount = 0;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n;i++)
        {
            if (a[i][j] == 0)
            {
                iCount++;
                p++;
            }

            
            
        }
        iArrOfCountOfZeroValues[j] = iCount;
        iCount = 0;
    }
    return iCount;
}
int result(int** a, int* iArrOfCountOfZeroValues, const int n)
{
    int result = 0;
    int iMaxValue = iArrOfCountOfZeroValues[0];
    for (int i = 0; i <= n; i++)
    {
        if (iMaxValue <= iArrOfCountOfZeroValues[i])
        {
            iMaxValue = iArrOfCountOfZeroValues[i];
            result++;
        }
    }

  
     return 
         result-1;
   
}


int main()
{
    srand((unsigned)time(nullptr));
    int Low = -1;
    int High = 1;
    int n;
    cout << "n = "; cin >> n;
    int* iArrOfCountOfZeroValues = new int[n];
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    Create(a, n, Low, High);
    Print(a, n);
    int max1Col = 0;
    int p = 0;
    Search(a, n, iArrOfCountOfZeroValues, p);

    if (p > 0)
        cout << "k = " << result(a, iArrOfCountOfZeroValues, n)  << endl;
    else
        cout << "Not 0s elements " << endl;


    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}