#include<iostream>

template <class T>
class DLLNode
{
    public:
    T info;
    DLLNode<T> *prev,*next; //Pokazivaci na sledeci i prethodni cvor

    DLLNode()
    {
        prev = next = NULL;
    }
    DLLNode(T el)
    {
        info = el;
        prev = next = NULL;
    }
    DLLNode(T el,DLLNode<T>*p,DLLNode<T>*n)
    {
        info = el;
        prev = p;
        next = n;
    }
    ~DLLNode(){};
    T print()
    {
        return info;
    }
    bool isEqual(T el)
    {
        return el == info;
    }
};

template <class T>
class DLList
{
    protected:
        DLLNode<T> *head,*tail;
    public:
        DLList()
        {
            head = tail = NULL;
        }
        ~DLList();

        bool isEmpty()
        {
            return head == NULL;
        }
        void printAll();
        DLLNode<T>* findNodePtr(T el);
        DLLNode<T>* geHead()
        {
            return head;
        }
        DLLNode<T>* getNext(DLLNode<T>* ptr);
        T getHeadEl();
        T getNextEl();
        bool isInList(T el);
        void deleteEl(T el);
        void addToHead(T el);
        void addToTail(T el);
        T deleteFromHead();
        T deleteFromTail();
};