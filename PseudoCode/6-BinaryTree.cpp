//OPSTE
// DUBINA - DEPTH 
Dubina čvora v je dužina jedinstvenog puta od korena do čvora v
    -obeležimo je sa dubina(v)

depth(T,v) 
if (isRoot(T,v))
    then return(0)
else
    return(1+depth(T,parent(T,v)))

//VISINA - HEIGHT 
Visina čvora v je dužina najdužeg puta od čvora v do lista
height(T,v) 
if (jeEksterni(T,v))
    then return 0
else
    h=0
    for svako dete v iz T do
        h=1 + max(h, visinaStabla(T,dete v))
    return (h)
-Svojstvo: Visina stabla T jednaka je max dubini njegovih eksternih čvorova // Eksterni cvor == terminalni cvor 

//BINARNO STABLO 
-Binarno stablo je uređeno stablo gde svaki čvor ima najviše dvoje dece
-Ovakvo binarno stablo se takođe naziva Knutovo binarno stablo

-Striktno binarno stablo - u svakom čvoru ima 0 ili 2 podstabla

-Kompletno ili potpuno binarno stablo visine h je striktno binarno stablo čiji su svi listovi na nivou h
    -Ukupan broj čvorova u kompletnom binarnom stablu visine h je -> n = 2h + 1 - 1
    -Broj internih čvorova: 2h-1
    -Broj eksternih čvorova: 2h
    -Visina stabla od n čvorova: h=log2(n+1)-1

-Gotovo kompletno ili gotovo potpuno binarno stablo dubine d je binarno stablo čiji svi čvorovi ispunjavaju sledeća dva uslova:
    -Svaki čvor u na nivou manjem od d-1 ima dvoje dece
    -Svaki čvor u koji ima desnog potomka na nivou d mora imati levo dete i sve leve potomke kao listove na nivou d ili mora imati dvoje dece

root(k), leviPotomak ima index 2k , desni 2k+1 

//PRIMITIVNE OPERACIJE
(p pokazivač na čvor nd)
1. info(p) vraća sadržaj čvora nd
2. left(p) vraća levo dete čvora nd
3. right(p) vraća desno dete čvora nd
4. parent(p) vraća roditeljski čvor čvora nd
5. sister(p) vraća brata/sestru čvora nd
-Funkcije 2-5 vraćaju null pokazivač ukoliko ne postoji levo dete, desno dete, roditelj ili sestra/brat čvora nd
6. isleft(p) vraća vrednost true ako je nd levo dete, inače vraća vrednost false
7. isright(p) vraća vrednost true ako je nd desno dete, inače vraća vrednost false

//OBILAZAK BINARNOG STABLA
Preorder:
-Obraditi koren
-Postorder
-Obići levo podstablo korena u preorder redosledu 
-Obići desno podstablo korena u preorder redosledu
-A B C 

preOrder(v) 
    visit(v)
    preorder (left(v))
    preorder (right(v))


Postorder:
-Obići levo podstablo korena u postorder redosledu
-Obići desno podstablo korena u postorder redosledu
-Obraditi koren
-B C A

postOrder(v)
    postOrder (left(v))
    postOrder (right(v)) 
    visit(v)

Inorder:
-Obići levo podstablo korena u inorder redosledu
-Obraditi koren
-Obići desno podstablo korena u inorder redosledu
-B A C

inOrder(v)
    inOrder (left (v)) 
    visit(v)
    inOrder (right (v))

Obilazak po nivoima:
-Obilaze se čvorovi po nivoima, počev od nivoa 0 tj. korena
-A B C


//STABLA BINARNOG TRAŽENJA
-Stablo binarnog traženja (SBT) je binarno stablo koje čuva ključeve (ili parove ključ-element) u čvorovima
i za koje važi:
    -Neka su u, v, i w tri čvora, takva da je u u levom podstablu čvora v, a w je u desnom podstablu v. Tada važi da je
    key(u) < key(v) <= key(w)
-Stablo binarnog traženja (SBT) - Navedeni uslov važi za sve čvorove u stablu, odnosno za celo levo i desno podstablo:
Vrednost čvora je
    -veća od svih vrednosti levog podstabla i
    -manja ili jednaka od vrednosti desnog podstabla

//dodavanje
Tree-Insert(T, z)
y <- null
x <- root(T) 
while (x != null)
    y <- x
    if (key(z) < key(x))
        then x <- left(x)
    else x <- right(x) 
end while
p(z) <- y //p-roditeljski čvor 
if (y = null)
    then root(T) <- z 
else if key(z) < key(y)
    then left(y) <- z 
    else right(y) <- z

//trazenje rekurzivno
Tree-Search(x, k)
if (x = null or k = key(x))
    then return x
if (k < key(x))
    then return Tree-Search(left(x), k)
    else return Tree-Search(right(x), k)

//trazenje iterativno
Iterative-Tree-Search(x, k)
while (x != null and k != key(x))
    if (k < key(x))
        then x <- left(x) 
        else x <- right(x)
return x

//Brisanje
-Naći čvor N i čvor ROD
-Obrisati čvor N na sledeći način:
Slučaj 1 ( Brisanje iz lista): 
null -> ROD.link(N)
// link na N roditelja se postavlja na null
Slučaj 2 (brisanje čvora koji ima 1 dete): 
N.link(D) -> ROD.link(N)
// u roditeljski čvor čvora N se postavlja
// link na dete čvora N
Slučaj 3 (brisanje čvora sa 2 deteta):
Naći čvor S (inorder sledbenik čvora N) Obrisati čvor S korišćenjem slučaja 1 ili 2 S→ROD.link(N)
// u roditeljski čvor čvora N se postavlja
// link na inorder sledbenika čvora N


//HEAP 
Heap je gotovo kompletno binarno stablo koje čuva vednosti u čvorovima i koje zadovoljava osobine tzv Heap-order:
    Minheap:
        key(v)  key(parent(v)) // LIST IMA NAJVECU VREDNOST 
    Maxheap:
        key(v)  key(parent(v)) // KOREN IMA NAJVECU VREDNOST

// NE KORISTI SE INDEX 0, novi element se dodaje na poziciju n+1 , parent sa indexom i ima decu , levo sa indexom 2i , desno 2i + 1 

//Dodavanje elementa min-gomili
InsertHeap(h,n,e)
//h – gomila (heap), n – broj elemenata gomile, e – novi element
n <- n+1, ptr <- n // lokacija novog elementa
repeat while (ptr>1) {
    //nalaženje lokacije elementa e
    rod <- [ptr/2]//donja granica ptr/2 
    if(e <= h(rod)) 
        then h(ptr) <- e
        return
    h(ptr) <- h(rod) // pomeranje čvora naniže
    ptr <- rod // ažuriranje ptr
    end repreat
    h(1) <- e
    return 
}

//Brisanje 
DeleteHeap(h,n,e)
/* h – heap, n – broj el. gomile, e – obrisani el., posl - vrednost iz poslednjeg elem. Gomile, ptr - lokacija poslednjeg elementa, levo i desno – deca posl. elementa gomile */
e <- h[1] // uklanjanje korena gomile
posl <- h[n]; n ← n-1 // brisanje posl. elementa
if (n=0) then return //brisanje jedinog elem. gomile 
ptr ← 1; levo ← 2; desno ← 3 // inicijalizacija 
repeat while (desno<=n)
//nalazenje prave lokacije elementa
if (posl>h[levo] and posl>= h[desno]) 
    then {h[ptr] ← posl; return}
if (h[desno]<=h[levo])
    then {h[ptr] ← h[levo]; ptr ← levo} 
    else {h[ptr] ← h[desno]; ptr ← desno }
levo ← 2*ptr; desno ← levo + 1
end repeat
if (levo = n) and if(posl < h[levo]) then ptr ← levo 
h[ptr] ← posl
return
//NEMAM POJMA KAKO RADI OVAJ ALGORITAM , PROUCI GA 


//HEAP SORT 
heapSort(a,n)
// sortira polje a od n elemenata
// formiranje min ili max gomile od elemenata polja a
repeat for j=1,n-1
    call insertHeap(a,j,a[j+1])
// sortiranje brisanjem korena gomile dok se gomila ne isprazni
repeat while n>1
    call deleteHeap(a,n,e) 
    a[n+1] = e
exit



