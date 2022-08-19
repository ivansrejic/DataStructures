//Izdvajanje podniza
PS <- SUBSTRING(S,i,n) 
    S - niz koji obrađujemo
    PS - izdvojeni podniz
    i - pozicija gde počinje podniz n - dužina podniza


//Indexiranje
i <- INDEX(T,P)
i - pozicija prve pojave P u T
    ili nula (indeksi 1,2,...), 
    odnosno -1 (indeksi 0,1,...) //ako pocinje od 0 i nema pattern, onda -1 , ako krece od 1 onda je 0
T - tekst koji se pretražuje
P - uzorak (pattern) koji se traži


//Konkatenacija
S3 <- CONCAT(S1,S2)
Funkcija:
    -Vraća niz S3 dobijen konkatenacijom nizova S1 i S2
    -Niz S3 sadrži sve znake niza S1 iza kojih slede znaci niza S2


//Duzina niza
n <- LENGHT(S)


//Umetanje
INSERT(T,k,S)
T - tekst koji se obrađuje
k - pozicija od koje se vrši umetanje
    k=0,1,... ili k=1,2,... 
S - niz koji se umeće

-- ALGORITAM ZA INSERT
Insert (T,k,S)
S1 <- substring(T,d,k-d)
S2 <- substring(T,k,length(T)-k+d) S3  concat(S1,S)
T <- concat(S3,S2)
return // d = donja granica indexa, d = 0 || d = 1

Insert (T,k,S)
T <- concat(concat(substring(T,d,k- d), S), substring(T,k,length(T)-k+d))
return


//Brisanje
DELETE(T,k,n)
T - tekst koji se obrađuje
k - indeks niza koji se briše 
n - dužina niza koji se briše

delete (T,k,n)
S1 <- substring(T,d,k-d) // d=o ili 1
S2 <- substring(T,k+n,length(T)-k-n+d) 
T <- concat(S1,S2)
return

delete (T,k,n)
// d = 0 ili 1
T <- concat(substring(T,d,k-d), substring(T,k+n,length(T)-k-n+d))
return

//Brisanje svih pojava uzorka P iz T
deleteALL(T,P)
// Ovaj algoritam briše sve pojave uzorka P u tekstu T
k <- index(T,P) // nalazi indeks prve pojave uzorka 
repeat while(k≠0)
    T <- delete(T,index(T,P),length(P))
    k <- index(T,P) 
endrepeat 
return


//Zamena
REPLACE(T,P,Q)
T - tekst koji se obrađuje
P - uzorak koji se menja
Q - uzorak kojim se vrši izmena

replace (T,P,Q) 
k <- index(T,P)
T <- delete(T,k,length(P)) 
insert(T,k,Q)
return

//Zamena svih pojava P u T
replaceAll(T,P,Q)
// Ovaj algoritam vrši zamenu svih pojava uzorka P // uzorkom Q u tekstu T
k <- index(T,P) // nalazi indeks prve pojave uzorka 
repeat while(k≠0)
    T <- replace(T,P,Q)
    k <- index(T,P) 
endrepeat 
return


//Trazenje u textu 
BruteForceMatching(T,P,INDEX)
// Tekst T i uzorak P su nizovi dužine lt i lp, respektivno, a memorisani su kao 1D polja // Svaki znak je element polja
// Ovaj algoritam nalazi indeks INDEX uzorka P u tekstu T, ako se P nalazi u T,
// ili je INDEX=0, što pokazuje da se P ne nalazi u T
lp <- length(P) // određuje dužinu uzorka
lt <- length(T)  // određuje dužinu teksta
max <- lt-lp+1 // nalazi maksimalnu vrednost indeksa k
k<-1
repeat while (k <= max) 
    repeat for j = 1,lp
        if(P[j] != T[k+j-1]) then goto 11// k <- k+1 je 11. linija 
    endrepeat
    INDEX=k // traženje uspešno
    exit
    k <- k+1
endrepeat
INDEX <- 0 // traženje neuspešno exit
return

PatternMatching(T,P,F,INDEX)
// Tekst T, uzorak P i tablica F(Q,T) su u memoriji
// Tekst T je memorisan kao 1D polje, svaki znak je element polja // Ovaj algoritam nalazi indeks INDEX uzorka P u tekstu T, ako se // P nalazi u T, ili je INDEX=0, što pokazuje da se P ne nalazi u T
lt <- length(T)
k <- 1 
Q <- ""//prazan niz Q0 
repeat while(Q != P and k <= lt)
    Q <- F(Q,T[k]) // nalazi sledece stanje 
    k <- k+1
endrepeat 
if(Q = P)
    then INDEX  k-length(P) // traženje uspešno
    else INDEX  0 // traženje neuspešno 
exit

