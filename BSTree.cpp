#include<iostream>
#include<BSTree.h>
#include<queue>

template<class T>

void BSTree<T>::insert(T el)
{
    BSTNode<T> *p = root,*prev = NULL;
    while(p != NULL) //trazenje mesta za umetanje novog cvora
    {
        prev = p;
        if(p->isLT(el))
            p = p->right;
        else
            p = p->left;
    }
    if (root == NULL)
        root = new BSTNode<T>(el);
    else if(prev->isLT(el))
        prev->right = new BSTNode<T>(el);
    else
        prev->left = new BSTNode<T>(el);
    numOfElements++;
}

template<class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T> *p,T el)
{
    while(p != NULL)
    {
        if(p->isEQ(el))
            return p;
        else if(p->isLT(el))
            p = p->right;
        else if(p->isGT(el))
            p = p->left;
        return NULL;
    }
}

template <class T>
void BSTree<T>::deleteTree(BSTNode<T>* p) // uglavnom p = root pointer na pocetak stabla
{
    if(p != NULL)
    {
        deleteTree(p->left);
        deleteTree(p->right);
        delete p;
    }
}

template<class T>

void BSTree<T>::preorder(BSTNode<T>* p)
{
    p->visit();
    preorder(p->left);
    preorder(p->right);
}

template <class T>

void BSTree<T>::inorder(BSTNode<T>* p)
{
    inorder(p->left);
    p->visit();
    inorder(p->right);
}

template <class T>

void BSTree<T>::postorder(BSTNode<T>* p)
{
    postorder(p->left);
    postorder(p->right);
    p->visit();
}

template<class T>
void BSTree<T>::breadthFirst()
{
    BSTNode<T>* p = root;
    QueueAsArray <BSTNode<T>*> queue(numOfElements);
    if(p != NULL)
    {
        queue.enque(p);
        while(!queue.isEmpty())
            {
                p = queue.dequeue();
                p->visit();
                if(p->left != NULL)
                    queue.enqueue(p->left);
                if(p->right != NULL)
                    queue.enqueue(p->right);
            }
    }



}