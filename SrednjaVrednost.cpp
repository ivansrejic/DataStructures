#include<iostream>



int SrednjaVrednost(int* A,int N)
{
    int s=0;
    for(int i=0;i<N;i++)
        s=s+A[i];
    int srednja = s/N;
    return srednja;
}
int binarySearch(int* A,int N,int element)
{
    int d=0;
    int g=N-1;
    int mid = (d+g)/2;
    while(d<=g && A[mid]!=element)
        {
            if(element < A[mid])
                {
                    g = mid -1;
                }
            else
                d = mid + 1;
            mid = (d+g)/2;
        }
    if(A[mid] == element)
        return mid;
    else
        return -1;
}
int main()
{
    int* A;
    int N;
    std::cout<<"Unesite velicinu niza A"<<std::endl;
    std::cin>>N;
    A = new int[N];
    std::cout<<"Unesite elemente niza"<<std::endl;
    for(int i=0;i<N;i++)
        std::cin>>A[i];
    int srednja = SrednjaVrednost(A,N);
    int pronadjeno = binarySearch(A,N,srednja);
    if(pronadjeno != -1)
        std::cout<<"Postoji element sa indexom"<<pronadjeno<<std::endl;
    else
        std::cout<<"Ne postoji takav element"<<std::endl;
    return 0;
}