STACK - LIFO 
Dve osnovne operacije PUSH() i POP() 

// --- STACK --- 

size(s,t)
//stack s , vrh stack-a t , t = -1 kada je magacin prazan
return t + 1 

isEmpty(s,t)
if (t < 0)
    then
        return true 
else
        return false 

isFull(s,t,N)
//stack s , vrh stack-a t , velicina stack-a N 
if(t = N - 1) // if(size(s,t) = N)
    then
        return true 
else
        return

//top element bez brisanja istog 
top(s,t,e)
if(t < 0) // if(isEmpty(s,t))
    then
        stackUnderflow // podkoracenje
else
    e <- s[t] //element sa vrha stacka 
return 

//Upis 
push(s,t,N,e)
if(t = N - 1) // if(size(s,t) = N) || isFull(s,t,N)
    then
        return -1 // StackOverflow 
else
    t <- t+1
    s[t] <- e  

//Citanje i brisanje iz Stacka 
pop(s,t,e)
if(t < 0) // ili isEmpty(s,t)
    then 
        StackUnderflow 
else 
    e <- S[t]
    S[t] <- NULL 
    t <- t-1 
    return 


// --- QUEUE --- 
FIFO 
f (front):indeks prvog elementa reda
r (rear):indeks elementa koji je odmah iza poslednjeg elementa u redu
Lokacija na koju ukazuje r je prazna

Dodavanje -> provera overflow-a , dodavanje elementa u queue, promena ukazatelja r = r+1 
Brisanje -> provera underflow-a , citanje/brisanje elementa iz queue-a , promena ukazatelja f = f+1 

f = r = 0, red je prazan 
f = 0,r = N, red je pun

//queue kao cirkularno polje 
kada se kod upisa ili čitanja dođe do kraja polja, ako ima mesta/elemenata, nastavlja se dodavanje/čitanje od donje granice
Promena f kod čitanja:
    f <- (f + 1) mod N 
Promena r kod upisa:
    r <- (r + 1) mod N
Granični slučajevi
    Prazan red: f = r
    Pun red: f = (r +1) mod N

size(Q,f,r,N)
// Q – red, f – početak reda, r – kraj reda, N – veličina reda 
return (N - f + r) mod N

isEmpty(Q,f,r) 
if (f = r) 
    then
        return true // potkoračenje, red je prazan else
return false

isFull(Q,f,r,N)
if ( f = (r+1) mod N) 
    then
        return true // prekoračenje, red je pun 
else
    return false

//Upis u queue 
enqueue(Q,f,r,N,o)
if (f = (r+1) mod N) // isFull(Q,f,r,N)
    then
        Prekoracenje
else
    Q[r] <- o
r <- (r + 1) mod N

//Prvi element bez brisanja 
front(Q,f,r,N,o)
if isEmpty(Q,f,r) 
    then
        Potkoračenje
else
    o = Q[f]
    return

//Citanje elementa iz queue-a 
dequeue(Q,f,r,N,o)
if (isEmpty(Q,f,r)) 
    then
        Potokračenje
else
    o <- Q[f]
    f <- (f + 1) mod N 
    return