#include<iostream>

template <class T>
class BinaryMaxHeap
{
    protected: 
        T* array;
        long lenght;
        long numOfElements;
    public:
        BinaryMaxHeap(long len)
        {
            lenght = len;
            array = new T[lenght+1]; //lenght + 1 zato sto se 0 ne koristi,vec krece numeracija od 1
            numOfElements = 0;
        }
        ~BinaryMaxHeap()
        {
            delete []array;
        }
        bool isEmpty()
        {
            return numOfElements == 0;
        }
        void insert(T el);
        T deleteRoot();
        static void HeapSort(T* a, long n);
};