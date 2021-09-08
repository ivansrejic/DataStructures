#include<iostream>

template <class T>

class BSTNode
{
    public:
        T key;
        BSTNode<T> *left,*right;
    public:
        BSTNode()
        {
            left = right = NULL;
        }
        BSTNode(T el)
        {
            key = el;
            left = right = NULL;
        }
        BSTNode(T el,BSTNode<T> *lt,BSTNode<T> *rt)
        {
            key = el;
            right = rt;
            left = lt;
        }
        bool isLT(T el) // is lower than
        {
            if(key > el)
                return true;
            else
                return false;
        }
        bool isGT(T el)
        {
            if(key < el)
                return true;
            else
                return false;
        }
        bool isEQ(T el)
        {
            return key == el;
        }
        void setKey(T el)
        {
            key = el;
        }
        T getKey()
        {
            return key;
        }
        void visit()
        {
            std::cout<<key<<" ";
        }
};