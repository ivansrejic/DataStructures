#include<iostream>

template<class T,class W>
class LinkedNode
{
    public:
        T node;
        Edge<T,W>* adj;
        LinkedNode<T,W>* next;
        int status;

        inline LinkedNode()
        {
            adj = NULL;
            next = NULL;
            status = 0;
        }
        inline LinkedNode(T nodeN)
        {
            node = nodeN;
            adj = next = NULL;
            status = 0;
        }
        inline LinkedNode(T nodeN,Edge<T,W>* ajdN,LinkedNode<T,W>*nextN,int statusN)
        {
            node = nodeN;
            adj = adjN;
            next = nextN;
            status = statusN;
        }
        inline void Visit()
        {
            std::cout<<node<<std::endl;
        }
        
};

template<class T,class W>
class Edge
{
    public:
        LinkedNode<T,W>* dest;
        Edge<T,W> link;
        W weight;
        inline
};

template<class T,class W>
class GraphAsList
{
    protected:
        LinkedNode<T,W> *start;
        long nodeNum;
    public:
        inline GraphAsList()
        {
            start = NULL;
            nodeNum = 0;
        }
        ~GraphAsList();
        LinkedNode<T,W>* findNode(T pod);
        Edge<T,W>* findEdge(T a,T b);
        bool insertNode(T pod);
        bool deleteNode(T pod);
        bool insertEdge(T a,T b);
        bool deleteEdge(T a,T b);
        long breathtrav(T a);
        long depthTrav(T a);
        void print();
    protected:
        void deleteEdgeToNode(LinkedNode<T,W>*ptr);

};

template<class T,class W>
void GraphAsList<T,W>::print()
{
    LinkedNode<T,W> *ptr = start;
    while(ptr != NULL)
        {
            std::cout<<ptr->node<<"->";
            Edge<T,W>*pa = ptr->adj;
            while(pa != NULL)
                {
                    std::cout<<pa->dest->node
                }
        }
};