#include<iostream>

template <class T>

class SLLNode
{
    public:
        T info;
        SLLNode<T>* next; //Pokazivac na sledeci cvor

    public: 
        SLLNode()
        {
            next = NULL;
        }
        SLLNode(T i)
        {
            info = i;
            next = NULL;
        }
        SLLNode(T i,SLLNode<T>* n)
        {
            info = i;
            next = n;
        }
        ~SLLNode(){};
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

class SLList
{
    protected:
        SLLNode<T> *head,*tail; // pokazivaci na pocetak i kraj liste
    public: 
        SLList()
        {
            head = tail = NULL;
        }
        ~SLList();
        bool isEmpty()
        {
            return head == NULL;
        }
        void addToHead(T el);
        void addToTail(T el);
        T deleteFromHead();
        T deleteFromTail();
        SLLNode<T>* findNodePtr(T el);
        SLLNode<T>* getHead()
        {
            return head;
        }
        SLLNode<T>* getNext(SLLNode<T>* ptr);
        T getHeadEl();
        T getNextEl(T el);
        void printAll();
        bool isInList(T el);
        void deleteEl(T el);
};