#include <iostream>

template<class T,class R>


class HashObject
{
    protected:
        T key;
        R* record;
    public:
        HashObject()
        {
            key = (T)0;
            record = NULL;
        }
        HashObject(T k)
        {
            key = k;
            record = NULL;
        }
        HashObject(T k,R* object)
        {
            key =  k;
            redord = object;
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
        bool isEqualKey(T key)
        {
            return this.key==key;
        }
        void print()
        {
            std::cout<<key<<"|"<<record;
        }
}