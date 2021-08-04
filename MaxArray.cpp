#include<iostream>
using namespace std;
int arrayMax (int A[], int n)
{

    int tekMax = A[0];
    for(int i=1;i<n;i++)
    {
        if (A[i] > tekMax)
        {
        tekMax = A[i];
        return tekMax;
        }
    }
}

    int main()
    {
        int n;
        cout <<" Unesi broj elemenata";
        cin >> n;
        int *A = new int[n];
        cout << "Unesite elemente";
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }
        cout << arrayMax(A,n);
        return 0;
    }