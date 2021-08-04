#include<iostream>
#include<DLL.h>

template<class T>
DLList<T>::~DLList()
{
    while(!isEmpty())
    {
        T tmp = deleteFromHead();
    }
}
template <class T>
void DLList<T>::addToHead(T el)
{
    if(!isEmpty())
    {
        head = new DLLNode<T>(el,NULL,head);
        head -> next -> prev = head;
    }
    else
    {
        head = tail = new DLLNode<T>(el);
    }
}
template <class T>
void DLList<T>::addToTail(T el)
{
    if(!isEmpty())
    {
        tail = new DLLNode<T>(el,tail,NULL);
        tail -> prev -> next = tail;
    }
    else
    {
        head = tail = new DLLNode<T>(el);
    }
}
template<class T>
void DLList<T>::deleteEl(T el)
{
    if(isEmpty())
        throw new SBPException("Lista je prazna");
    if(head == tail && head->info.isEqaul(el))
    {
        delete head;
        head = tail = NULL;
    }
    else if(el == head->info)
    {
        DLLNode<T>* tmp = head;
        head = head->next; head->prev = NULL;
        delete tmp;
    }
    else
    {
        DLLNode<T> *tmp;
        for(tmp=head->next;tmp!=NULL && !(tmp->info.isEqaul(el));tmp = tmp->next);
        if(tmp != NULL)
        {
            tmp->prev->next = tmp->next;
            if(tmp->next) // tmp != tail ... Moramo da dodelimo i pokazivacu prev i next... Zato ovaj gore i ovaj ispod uslova
                tmp->next->prev = tmp->next;
            if(tmp == tail)
                tail = tmp -> prev;
            delete tmp;
        }
    }
}