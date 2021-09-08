#include<iostream>
#include<math.h>  
#include<SLL.h> 

unsigned int hashCode(double d) //
{
    if(d == 0)
        return 0U;
    else
        {
            int exponent;
            double mantissa = frexp(d,&mantissa);
            return (unsigned int)(2* fabs(mantissa) - 1)* ~0U;
        }
}

unsigned int hashCode(char* s)
{
    unsigned int res = 0;
    unsigned int a = 7;
    for(int i=0; s[i] != 0; i++)
        res = res << a^s[i];
    return res;
}

template<class T,class R>
class HashObject
{
    protected:
        T key;
        R* record;
    public:
        HashObject()
        {
            T key = (T)0;
            record = NULL;
        }
        HashObject(T k)
        {
            key = k;
            record = NULL;
        }
        HashObject(T k,R* object)
        {
            key = k;
            record = object;
        }
        ~HashObject()
        {
            deleteRecord();
        }
        HashObject& operator = (HashObject const& obj)
        {
            key = obj.key;
            record = obj.record;
            return *this;
        }
        bool operator == (HashObject const& obj)
        {
            return record == obj.record;
        }
        void deleteRecord()
        {
            if(record)
                {
                    delete record;
                    record = NULL;
                }
        }
        T getKey()
        {
            return key;
        }
        R* getRecord()
        {
            return record;
        }
        bool isEqualKey(T k)
        {
            return key == k;
        }
        void print()
        {
            std::cout<<key<<"|"<<record;
        }
}

template<class T,class R>
class HashTable
{
    protected:
        unsigned int lenght; //velicina tablice
        unsigned int count; //broj elemenata u tablici
    protected:
        unsigned int h(HashObject<T,R> obj)
        {
            return (f(obj.getKey())%lenght);
        }
      //primarna transformacija
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
                double mantissa = frexp(d,&exponent)
                return (unsigned int)((2*fabs(mantissa)-1) * ~0U);
            }
       }
       virtual unsigned int f(char* s)
       {
          unsigned int res = 0;
          unsigned int a = 7;
          for(int i = 0; s[i] != 0; i++)
          {
              res = res << a^s[i];
          }
          return res;
       }
       //sekundarna transformacija
       virtual unsigned int g(unsigned int i)
       {
          return (i+1) % lenght;
       }

    public:
        unsigned int getLenght()
        {
            return lenght;
        }
        virtual double getLoadFactor()
        {
            return (double)count/(double)lenght;
        }   
}

template<class T,class R>
class ChainedHashTable : public HashTable<T,R>
{
    protected:
        SLList < HashObject<T,R> >* array; //polje lancanih listi
    public:
        ChainedHashTable(unsigned int len)
        {
            lenght = len;
            count = 0;
            array = new SLList<HashObject<T,R> >[len];
        }
        ~ChainedHashTable()
        {
            HashObject<T,R> obj;
            for(unsigned int i=0;i<lenght;i++)
            {
                try
                {
                    obj = array[i].getHeadEl();
                    while(true)
                    {
                            obj.deleteRecord;
                            obj = array[i].getNextEl(obj); //Lancana lista sa sinonimima,idemo redom i brisemo sve
                    }
                }
                catch(SBPException* e){}
            }
            delete []array;
        }
        void insert(HashObject<T,R> obj)
        {
            array[h[obj]].addToHead(obj);
            count++;
        }
        void withdraw(HashObject<T,R> obj)
        {
            array[h(obj)].deleteEl(obj);
            count--;
        }
        void withdraw(T key)
        {
            HashObject<T,R> obj = find(key);
            withdraw(obj);
        }
        HashObject<T,R> find(T key)
        {
            HashObject<T,R> obj;
            unsigned int i = f(key)%lenght;
            obj = array[i],getHeadEl();
            while(!(obj.isEqualKey(key)))
                obj = array[i].getNextEl(obj);
            return obj;
        }
}
template<class T,class R>
class ScatterObject : public HashObject<T,R>
{
    public:
        int status; //0-slobodan , 1-obrisan, 2-zauzet
    public:
        ScatterObject() : HashObject<T,R> 
        {
            status = 0;
        }
        ScatterObject(T k) : HashObject<T,R>(k)
        {
            status = 0;
        }
        ScatterObject(T k,R* object) : HashObject<T,R>(k,object)
        {
            status = 0;
        }
}

template<class T,class R>
class ChainedScatterObject : public ScatterObject<T,R>
{
    public:
        long next;
    public:
        ChainedScatterObject() : ScatterObject<T,R>()
        {
            next = -1;
        }
        ChainedScatterObject(T k) : ScatterObject<T,R>(k)
        {
            next = -1;
        }
        ChainedScatterObject(T k,R* object) : ScatterObject(k,object)
        {
            next = -1;
        }
        ChainedScatterObject(T k,R* object,unsigned int n) : ScatterObject(k,object)
        {
            next = n;
        }

}

template<class T,class R>
class ChainedScatterTable : public HashTable<T,R>
{
    protected:
        ChainedScatterObject<T,R>* array;
    public:
        ChainedScatterTable(unsigned int len)
        {
            lenght = len;
            count = 0;
            array = new ChainedScatterObject<T,R>[len];
        }
        ~ChainedScatterTable()
        {
            delete []array;
        }
}
