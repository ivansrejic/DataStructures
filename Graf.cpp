#include<iostream>

template<class T,class W>
class Edge; // da mozemo da koristimo Edge direktno u cpp
class LinkedNode // Node -> cvor
{    public:
        T node;
        Edge<T,W>* adj;
        LinkedNode<T,W>* next;
        int status; // 1 - neobradjen , 2 - smesten u red cekanja, 3 - obradjen

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
class LinkedNode; // da mozemo da koristimo LinkedNode direktno dole
class Edge // poteg
{
    public:
        LinkedNode<T,W>* dest;
        Edge<T,W> link;
        W weight;
        inline Edge()
        { 
            dest=NULL; 
            link=NULL; 
        }
        inline Edge(LinkedNode<T,W>* destN,Edge<T,W>* linkN)
        { 
            dest=destN; 
            link=linkN;
        }
};

template<class T,class W>
class GraphAsList 
{
    protected:
        LinkedNode<T,W> *start; // head,odakle krecemo da radimo 
        long nodeNum; // broj cvorova
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
        long topologicalOrderTrav();
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
            std::cout<<ptr->node<<"->"; // ili visit(), nije deklarisana f-ja ali moze da se napise
            Edge<T,W>*pa = ptr->adj;
            while(pa != NULL)
                {
                    std::cout<<pa->dest->node;
                    pa = pa->next;
                }
        }
};

template<class T,class W>
LinkedNode<T,W>* GraphAsList<T,W>::findNode(T pod)
{
    LinkedNode<T,W>* ptr = start;
    while(ptr != NULL && ptr->node != pod) // uvek se vrsi sleva u desno, levo uvek proveravamo da li je ptr != NUll 
        ptr = ptr->next;
    return ptr;
};

template<class T,class W>
Edge<T,W>* GraphAsList<T,W>::findEdge(T a, T b)
{
    LinkedNode<T,W>* pa,pb;
    pa = findNode(a);
    pb = findNode(b); // Nadjemo poinere na node sa vrednoscu a i b
    if(pa == NULL || pb == NULL)
        return NULL; // ne postoji ili cvor sa vrednoscu a ili b
    Edge<T,W>* ptr = pa->adj;
    while(ptr != NULL && ptr->dest != pb)
        ptr = ptr->link;
    return ptr;
};

template<class T, class W>
bool GraphAsList<T,W>::insertNode(T pod)
{
    LinkedNode<T,W> newNode = new LinkedNode<T,W>(pod,start,NULL,0);
    if(newNode == NULL)
        return false;
    start = newNode;
    nodeNum++;
    return true;
};

template<class T,class W>
bool GraphAsList<T,W>::insertEdge(T a,T b)
{
    LinkedNode<T,W>* pa = findNode(a);
    LinkedNode<T,W>* pb = findNode(b);
    if(pa == NULL || pb == NULL)
        return false;
    Edge<T,W>* ptr = new Edge<T,W>(pb,pa->adj); //pb nam je destination , dodajemo edge u listu pa->adj preko link dela edge-a
    if(ptr == NULL)
        return false;
    pa->adj = ptr; //stavljamo ptr poteg(edge) u listu potega nodea pa
    return true;
};

template<class T,class W>
bool GraphAsList<T,W>::deleteEdge(T a,T b)
{
    Edge<T,W>* ptr = findEdge(a,b);
    if(ptr == NULL)
        return false;
    LinkedNode<T,W>* pa = findNode(a);
    if(ptr == pa->adj) // ako je prvi u listi potega nodea pa
    {
        pa->adj = ptr->link; //Stavljamo da je prvi poteg u listi link od ptr,odnosno preskacemo prvi poteg
        delete ptr; //brisemo pointer na poteg ptr
        return true;
    }
    Edge<T,W>* tptr = pa->adj;
    while(tptr != ptr)
        tptr = tptr->link; // prolazimo kroz listu potega i ispitujemo da li je neki poteg == potegu ptr
    tptr->link = ptr->link; // preskacemo ptr
    delete ptr;
    return true;
};

template<class T,class W>
bool GraphAsList<T,W>::deleteNode(T pod)
{
    LinkedNode<T,W>* ptr;
    if(start == NULL)
        return false; // prazan graf
    if(start->node == pod)//ako je startni cvor jedan pod
    {
        Edge<T,W>* pot = start->adj;
        while(pot != NULL)
        {
            Edge<T,W>* tpot = pot->link; // ovo moramo da uradimo zato sto ako obrisemo prvi, ostali ce da se izgube, fakticki imamo pointer na sledeci a brisemo trenutni, ako ti to ima smisla
            delete pot;
            pot = tpot;
        }
        deleteEdgeToNode(start); // obrisemo sve potege do Nodea start. Nema ovde implementacija, mozda negde gore,dole ima implementacija ove funkcije
        ptr = start; // uzimamo ptr od starta da bi mogli u sledecem koraku da promenimo start na start->next i da obrisemo pointer
        start = start->next;
        delete ptr;
        nodeNum--;
        return true;
    }
    else
    {
        ptr = start->next;
        LinkedNode<T,W>* parent = start; //prethodni u listi,moramo da ga zapamtimo
        while(ptr != NULL && ptr->node != pod)
        {
            parent = ptr->next;
            ptr = ptr->next;
        }
        if(ptr == NULL)
            return false;
        parent->next = ptr->next; //preskacemo ptr
        Edge<T,W>* pot = ptr->adj;
        while(pot != NULL) //prolazimo kroz listu potega i brisemo je na nacin kao gore. pomocni ptr na sledeci pa brisemo tekuci pointer
            {
                Edge<T,W>* tpot = pot->next;
                delete pot;
                pot=tpot;
            }
        deleteEdgeToNode(ptr);
        delete ptr;
        nodeNum--;
        return true;
    }
};

template<class T,class W>
long GraphAsList<T,W>::breathtrav(T a)
{
    long retVal = 0;
    LinkedNode<T,W>* ptr = start;
    QueueAsArray<LinkedNode<T,W>*> que(nodeNum);
    while(ptr != NULL) // prolazimo kroz listu da postavimo status na 1
    {
        status = 1; // neobradjen
        ptr = ptr->next;
    }
    ptr = findNode(a);
    if(ptr == NULL)
        return 0;
    que.enqueue(ptr);
    ptr->status = 2; // smesten u red cekanja
    while(!que.isEmpty())
    {
        ptr = que.dequeue();
        ptr->status = 3; //obradjen
        ptr->visit();
        retVal+=1;
        Edge<T,W>* pot = ptr->adj;
        while(pot != NULL)
        {
            if(pot->dest->status = 1)
            {
                pot->dest->status = 2;
                que.enqueue(pot->dest);
            }
            pot = pot->link;
        }
    }
    return retVal;
};

template<class T,class W>
long GraphAsList<T,W>::topologicalOrderTrav()
{
    long retVal = 0l; // broj obidjenih cvorova
    //odredjivanje ulaznog stepena za svaki cvor
    LinkedNode<T,W>* ptr = start;
    while(ptr != NULL)
    {
        ptr->status = 0; // postavljamo na 0 jer zelimo da nam status pokazuje broj potega koji dolaze do datog cvora
        ptr = ptr->next;
    }
    ptr = start;
    while(ptr != NULL)
    {
        Edge<T,W>* pot = ptr->adj;
        while(pot != NULL)
        {
            pot->dest->status += 1; //svakom dest nodeu povecavamo status za 1
            pot = pot->link;
        }
        ptr = ptr->next;
    }
    QueueAsArray<LinkedNode<T,W>*> que(nodeNum);
    //sve izvorne potege smestiti u red
    ptr = start;
    while(ptr != NULL)
    {
        if(ptr->status == 0)
            que.enqueue(ptr);
        ptr = ptr->next;
    }
    while(!que.isEmpty())
    {
        ptr = que.dequeue();
        ptr->visit();
        retVal+=1;
        Edge<T,W>* pot = prt->adj;
        while(pot != NULL)
        {
            pot->dest->status -= 1;
            if(pot->dest->status == 0)
                que.enqueue(pot->dest);
            pot = pot->link
        }
    }
    return retVal;
};