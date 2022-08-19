-p je pokazivač
-node(p) je čvor na koji ukazuje pokazivač p 
-info(p) je info polje čvora node(p)
-link(p) je link polje čvora node(p)


//Obilazak SLL 
Traversal(start)
POK <- START /* POK se postavlja na prvi element liste*/ 
while(POK != NULL)
    OBRADA(info(POK))
    POK <- link(POK) 
endwhile
exit


//Trazenje u nesortiranoj SLL
searchNonSorted(START,E,LOC)
POK <- START
while (POK != NULL AND info(POK) != E)
    POK <- link(POK) 
endwhile
if info(POK) = E 
then
    LOC <- POK
else
    LOC <- NULL
exit


//Trazenje u sortiranoj SLL
searchSorted(START,E,LOC)
POK <- START
while(POK != NULL)
    if(info(POK) = E)
        then
            LOC <- POK 
            exit //trazenje uspesno
    else if(E < info(POK))
        then
            LOC <- NULL
            exit
    else
        POK <- link(POK)
    endif
endwhile
LOC <- NULL 
exit 


//Insert na pocetak SLL
insertAtStart(START,E)
novi <- getnode()
info(novi) <- E 
link(novi) <- START 
START <- novi 
exit 


//Insert posle odredjenog node-a SLL
insertAfterLoc(START,LOC,E)
novi <- getnode()
info(novi) <- E 
if(LOC = NULL)
    then
        link(novi) <- START
        START <- novi 
else
    link(novi) <- link(LOC)
    link(LOC) <- novi
exit 


//Brisanje node-a sa pocetka SLL
deleteFromStart(START,E)
POK <- START 
START <- link(POK)
E <- info(POK)
freenode(POK)
exit 


//Brisanje za zadate LOC SLL
deleteFromLOC(ISTART,LOC,LOCP)
//LOCP je lokacija cvora koji prethodi cvoru loc koji se brise 
if(LOCP = NULL)
    then
        START <- link(START)
else
    link(LOCP) <- link(LOC)
freenode(LOC)
exit 


//Brisanje node-a zadate vrednosti SLL
deleteE(START,E,STATUS)
call findB(START,E,LOC,LOCP)
//Nalazi lokaciju LOC node-a koji sadrzi E i njegovog prethodog node-a LOCP 
//Definicija funkcije je ispod 
if(LOC = NULL)
    then 
        STATUS <- 1 
        exit 
call DeleteFromLOC(START,LOC,LOCP)
STATUS <- 0 //Uspesno
exit 


//Trazenje u SLL
findB(START,E,LOC,LOCP)
if(START = NULL)
    then
        LOC <- NULL 
        LOCP <- NULL 
        return //prazna lista
if(info(START) = E)
    then 
        LOC <- START 
        LOCP <- NULL 
        return 
spok <- START 
npok <- link(START)
repeat while(npok != NULL)
    if(info(npok) = E)
        then
            LOC <- npok
            LOCP <- spok 
            return 
    spok <- npok 
    npok <- link(npok)
endrepeat
LOC <- NULL 
return 

//DLL ima head i tail kao i node |llink|info|dlink|

//Umetanje DLL
insertAfter(p,E)
getnode(q)
info(q) = E
dlink(q) <- dlink(p)
llink(q) <- p 
llink(dlink(p)) <- q 
dlink(p) <- q 

insertBefore(p,E)
getnode(q)
info(q) = E 
dlink(q) <- p 
llink(q) <- llink(p) 
dlink(llink(p)) <- q 
llink(p) <- q 


//Brisanje zadnjeg elementa DLL 
remove(p)
E <- info(p)
rep <- llink(q)
dlink(llink(p)) <- dlink(p) //dlink(p) je u ovom slucaju NULL posto je p bio tail 
freenode(p) 


//Brisanje DLL 
remove(p)
E <- info(p)
llink(dlink(p)) <- llink(p)
dlink(llink(p)) <- dlink(p)
freenode(p) 