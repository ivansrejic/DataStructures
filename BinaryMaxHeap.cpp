#include<iostream>
#include<BinaryMaxHeap.h>

template<class T>

void BinaryMaxHeap<T>::insert(T el)
{
    if(numOfElements == lenght)
        throw new SBPException("The heap is full");
    numOfElements++;
    int i = numOfElements;
    while(i > 1 && array[i/2] < el)
        {
            array [i] = array[i/2];
            i = i/2;
        }
        array[i] = el;
}
