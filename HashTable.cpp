#include<iostream>
#include<HashObject>


template<class T,class R>

class HashTable
{
    protected:
        unsigned int lenght; //velicina tablice
        unsigned int count;  //broj elemenata u matrici
    protected:
        unsigned int h(HashObject<T,R> obj)
        {
            return(f(obj.getKey())%lenght);
        }

    virtual unsigned int f(int i)
    {
        return abs(i);
    }
    virtual unsigned int f(double d)
    {
        if(d == 0)
            return 0;
        else
        {
            int exponent;
            double mantissa = frexp(d,&mantissa);
            return (unsigned int)((2*fabs(mantissa)*~0U);
        }
    }
}