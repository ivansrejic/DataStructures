#include<iostream>
#include<BSTNode.cpp>

template <class T>

class BSTree
{
    protected:
        BSTNode<T> *root;
        long numOfElements;
    public:
        BSTree()
        {
            root = NULL;
            numOfElements = 0;
        }
        ~BSTree()
        {
            deleteTree(root);
        }
        void deleteTree(BSTNode<T>* p);
        void insert(T el);
        bool isInTree(T el){return search(el)!=NULL;};
        BSTNode<T>*search(T el){return search(root,el);};
        BSTNode<T>*search(BSTNode<T> *p,T el);
        void balance(int data[],int first,int last);
        void deleteByCopying(T el);
        void deleteByMerging(T el);
        void preorder(){preorder(root);};
        void inorder(){inorder(root);};
        void postorder(){postorder(root);};
        void inorder(BSTNode<T> *p);
        void preorder(BSTNode<T> *p);
        void postorder(BSTNode<T> *p);
        void breadthFirst();
        void iterativePreorder();
        void iterativeInorder();
        void iterativePostorder();
};