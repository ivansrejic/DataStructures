#include<iostream>
using namespace std;

void bubblesort(int* data,int dim)
{
    int i,j;
    for(i=0; i<dim-1;i++)
    {
        for(j<dim-1;j>i;j--)
        {
            if(data[j]<data[j-1])
                swap(data[j],data[j-1]);
        }
    }
}

void slectionsort(int* data,int dim)
{
    int i,j,least;
    for(i=0;i<dim-1;i++)
    {
        for(j=i+1;least = i,j<dim; j++)
        {
            if(data[j] < data[least])
            {
                least = j;
            }
            swap(data[least],data[i]);
        }
    }
}
void print(int* data,int dim)
{
    for(int i=0;i<dim;i++)
    {
        cout<<data[i]<<endl;
    }
}
int main()
{
        int n;
        cout <<" Unesi broj elemenata";
        cin >> n;
        int *A = new int[n];
        cout << "Unesite elemente" << endl;;
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
            cout<<endl;
        }
        slectionsort(A,n);
        print(A,n);
        
        return 0;
}