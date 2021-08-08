#include<iostream>

using namespace std;

template <class T>

class Stack
{
    public:
        virtual T getTop()
        {
            throw new SBPException("Virtual function call!");
        }
        virtual void push(T object)
        {
            throw new SBPException("Virtual function call!");
        }
        virtual T pop()
        {
            throw new SBPException("Virtual function call!");
        }
        virtual bool isEmpty()
        {
            return true;
        }
        virtual long numberOfElements()
        {
            return 0;
        }
};
