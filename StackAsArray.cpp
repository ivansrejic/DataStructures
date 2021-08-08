#include<iostream>
using namespace std;

template <class T>
class StackAsArray : public Stack<T>
{
    protected:
        T* array; //polje elemenata
        long size;
        long top;

    public:
        StackAsArray(long nsize)
        {
            size = nsize;
            array = new T[size];
            top = -1;
        }
        bool isEmpty()
        {
            return top == -1;
        }
        long numberOfElements()
        {
            return top+1;
        }
        ~StackAsArray()
        {
            delete []array;
        }
        void push(T object)
        {
            if(top == size-1)
                throw new SBPException("Stack overflow");
            array[++top] = object;
        }
        T pop()
        {
            if(top == -1)
                throw new SBPException("Stack underflow");
            T result = array[top--];
            return result;
        }
        T getTop()
        {
            if(top == -1)
                throw new SBPException("Stack underflow");
            return array[top];
        }
};