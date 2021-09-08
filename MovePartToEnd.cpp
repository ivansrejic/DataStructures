#include<iostream>
#include<DLL.h>

template<class T>
void MovePartToEnd(int val1,int val2)
{
    bool border = true;
    DLLNode<T>* ptr1 = nullptr;
    DLLNode<T>* ptr2 = nullptr;
    DLLNode<T>* ptr = head;

    while((ptr1 == nullptr || ptr2 == nullptr) && ptr != nullptr) // dok head ne dodje do kraja ili dok ne nadjemo i ptr1 i ptr2
    {
        if(ptr->info == val1) // ako je head trazeni element VAL1
        {
            ptr1 = ptr;
            if(ptr2 != nullptr)
            {
                border = false; // ako smo nasli prvo ptr2 pa ptr1, redosled je izokrenut
            }
        }
        if(ptr->info == val2)
        {
            ptr2 = ptr;
        }
        ptr = ptr->next;
    }
    if(ptr1 == nullptr || ptr2 == nullptr) // nismo nasli neki element
        return;
    if(!border) // proveravamo da li je redosled ptr1 pa ptr2 , ako nije swapujemo ptr1 i ptr2
        {
            DLLNode<T>* ptrSwap = ptr1;
            ptr1 = ptr2;
            ptr2 = ptrSwap;
        }
    if(ptr2 == tail)
        return;
    if(ptr->prev == nullptr) // ptr1 je head liste
        head = ptr2->next;
    else
        {
            ptr1->prev->next = ptr2->next;
        }
    ptr2->next->prev = ptr1->prev;

    tail->next = ptr1;
    ptr1->prev = tail;
    ptr2->next = nullptr;
    tail = ptr2;
}