//Obilazak polja
arrayTraversal(A,d,g)
k <- d // index prvog elementa
while (k <= g)
    Obrada(A[k])
    k <- k+1 
return


//Linearno trazenje
arrayLinearSearch(A,n,E)
// A je array od n elemenata
//LOC je lokacija nadjenog elementa ili NULL ako nije pronadjen element
for LOC = 1,n
    if(A[LOC] == E) then return //Trazenje uspesno
LOC = NULL //trazenje neuspesno  
return LOC


//Binarno trazenje
arrayBinarySearch(A,dg,gg,E)
d <- dg, g <- gg, s <- (d+g)/2
while(d<=g and A[s] != E)
    if(E < A[s])
        then g <- s-1
        else d <- s+1
    s <- (d+g)/2
if(A[s] == E) then LOC <- s
else LOC <- NULL 
return LOC 


//Bubble sort
arrayBubbleSort(A,n)
for k <- 1,n-1
    p <- 1
    while(p<=n-k)
    if(A[p] > A[p+1])
        then Zameni(A[p],A[p+1])
    p <- p+1
    endwhile
endfor
return 


//Insert element
arrayInsertAt(A,n,k,E)
// Ovaj algoritam umeće novi element E // u polje A od n elemenata na poziciju k
j <- n // indeks poslednjeg elementa polje
while (j >= k)
    3 A[j+1] <- A[j] // pomera udesno A[j]
    4 j <- j-1
endwhile
A[k] <- E
n <- n+1 //azurira duzinu polja
return


//Delete element
//Brise k-ti element iz polja A vraca kao E
arrayDeleteAt(A,n,k,E)
E <- A[k]
j <- k
while(j < n)
    A[j] <- A[j+1]
    j <- j+1
endwhile
n <- n-1 //azurira duzinu polja
return 