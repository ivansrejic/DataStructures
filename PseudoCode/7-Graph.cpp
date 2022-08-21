Graf se sastoji od niza čvorova i niza potega.
Svaki poteg u grafu je određen parom čvorova.

Graf je uređeni par (V, E), gde je
 - V skup temena v, koji se zovu i
 - E je kolekcija parova čvorova e=[u,v], koji čine potege ili čvorovi 
Čvorovi i grane čuvaju odgovarajuće vrednosti (graf je obeležen)
Svakom potegu u grafu može biti pridružen broj i takav graf se naziva tezinski graf ili mreza.
Nenegativan broj pridružen potegu naziva se tezina

//Orijentisani poteg 
-Uređeni par čvorova (u,v) 
-Prvi čvor u je početni
Poteg iz njega izvire
-drugi čvor v je odredišni 
Poteg u njega uvire

//Orijentisani graph
-Svi potezi su orijentisani 

//Neorijentisani poteg
Neuređeni par (u,v)

//Neorijetisani graf
Svi potezi su neorijentisani

//Završni čvorovi nekog potega 
-Krajnje tačke potega
-U i V su završni čvorovi za a //sa slike, poteg a spaja U i V 

//Incidentnost potega i čvorova
-Grana e je incidentna (vezana) za čvor v ukoliko je v jedna od krajnjih tačaka potega
-Čvor v je incidentan potegu x ako je v jedan od čvorova u uređenom paru čvorova koji čine poteg x.
-a,d,i b su incidentni za V //Slika Graph2.png

//Susedni čvorovi
-Čvor u je susedan čvoru v ako postoji poteg od u do v.
-Ako je čvor u susedan čvoru v onda se v naziva sledbenik čvora u, a čvor u je prethodnik čvora v.

//Stepen čvora
-broj potega incidentnih njemu 
-X ima stepen deg(X)=5 //slika 

//Izolovan čvor
-Ako je deg(u)=0

//Paralelni potezi
-Potezi između dva čvora

//Petlja (Self-loop)
-Poteg koji počinje i završava se u istom čvoru.

//Put u grafu
-Sekvenca čvorova i potega
-Počinje čvorom
-Završava se čvorom
-Za svaki poteg su poznati završni čvorovi

Put dužine n od čvora u do čvora v se definiše kao sekvenca od n+1 čvorova (v0,v1,v2,...,vn) tako da je v0=u, vn=v.

Prost put (Simple path)
-Put kod koga su svi čvorovi i potezi različiti

//Zatvoreni put 
-Kružni put
-v0=vn
-Prost zatvoren put

Put od čvora do njega samog se naziva ciklus

//Aciklični graf
-Graf koji nema cikluse

//Povezani graf
-ako postoji prost put imeđu bilo koja dva njegova čvora

//Strogo povezani graf
-ako postoji samo po jedan put iz svakog čvora do svih ostalih čvorova

// SEKVENCIJALNA REPREZENTACIJA - MATRICA SUSEDSTVA

//Matrica susedstva
-Dimenzije: nxn, gde je n broj čvorova
-Elementi mij matrice definišu broj potega koji spajaju čvorove i i j:

-neorijentisani graf matrica susedstva je simetrična u odnosu na glavnu dijagonalu

//Matrica incidencije
-zasniva se na incidenciji čvorova i potega
Vrednosti elementa mij:
0 - nisu incidentni,
1 - incidentni
2 - čvor vi spaja sam sebe (petlja) potegom ej.

Ako je graf usmeren, broj može biti +1 (ulazak u čvor) ili -1 (izlazak iz čvora).
Dimenzije su N x G //N broj cvorova, N broj potega !!!



////////////////// LANČANA REPREZENTACIJA GRAFA //////////////////

Lančane liste
    -Jedna lančana lista za čvorove
    -Po jedna lančana lista za potege nekog čvora

Element za čvor:
    -node - vrenost čvora
    -next - pokazivač na sledeći el. u listi
    -adj - pokazivač na listu potega za taj čvor

Element za poteg:
    -dest - pointer na odredište potega
    -link - sledeći u listi potega
    -Opciono: vrednost potega (napr weight)
// POGLEDAJ SLIKU ./LancanaPrezentacijaGrafa


//Trazenje puta u grafu - Sekvencijalna prezentacija grafa 

Matrica puta ili matrica dostupnosti P=[pij] definiše se kao:
        {-1, ako postoji put iz vi u vj 
pij =   {
        {-0, u ostalim slučajevima

Matrica P strogo povezanog grafa nema nultih elemenata
pij=1 ako i samo ako matrica Bm= A+A2+A3+...+Am ima nenulti element bij
//Racunamo matricu A1 , putevi duzine 1, pa onda A2 ... , i na kraju saberemo. Gde je 0,tu ne mozemo da stignemo, ako npr Y ima sve nule u kolini,onda nikako ne mozemo da stignemo do Y preko b ilo kog cvora

//Algoitam za ovo gore , matrica puta P 
1. Naći matricu susedstva A
2. Naći redom matrice A2, A3, ..., Am
3. Naći matricu B = [bij] = A+A2+A3+ ...+Am 
Generisati matricu P korišćenjem matrice B
    pij=1, ako je bij != 0 
    pij=0, ako je bij = 0

//WARSHALL-OV ALGORITAM 
Warshall(A,m)
    {
        // data je matrica susedstva A i broj čvorova m 
        // algoritam generiše matricu P
        repeat for (i=1,m) //inicijalizacija matrice P0
            {
                repeat for (j=1,m)
                {
                    if (A[i,j]=0)
                        then P[i,j ]=0
                        else P[i,j ]=1
                }
            }
        repeat for k=1,m //Azuriranje P
        {
            repeat for i=1,m
            {
                repeat for j=1,m
                P[i,j ]=P[i,j] OR (P[i,k] AND P[k,j])
            }
        }
        return 
    }
    //Pogledaj na YT 

    //TRAZENJE CVORA I TRAZENJE POTEGA 

    //trazenje cvora
    findoNode(start,A,LOC)
    {
        pok <- start 
        repeat while(pok != NULL)
        {
            if(pok.info = A)
            {
                LOC <- pok 
                return 
            }
            else
                pok  <- pok.link 
        }
        loc = NULL 
        return 
    }

    //trazenje potega 
    findEdge(start,A,B,LOC)
    {
        call findNode(start,A,locA)
        call findNode(start,B,locB)
        if(locA = NULL OR locB = NULL)
            then LOC = NULL 
        else
        {
            pok = locA.adj
            repeat while(pok != NULL)
            {
                if(pok.dest = locB)
                then {
                    LOC = pok 
                    return
                }
                else
                    pok = pok.link 
            }
        }
        LOC = NULL 
        return 
    }
    //Jednostavan algoritam, nadjemo cvor A i B, i ondaa u listi potega A, gledamo da li je negde dest poteg B 


    //DODAVANJE I BRISANJE ČVORA ILI GRANE(POTEGA)

    //Dodavanje čvora
    -Čvor se dodaje na početak liste čvorova
    -Odogovara operaciji dodavanja elementa na početak liste
    -U adj se upisuje null

    //Dodavanje potega
    -Podrazmeva se da čvorovi A i B postoje
    -Zadati su svojom vrednošću, pa se najpre pozivom findNode određuju lokacije u listi čvorova
    -Novi poteg se dodaje kao prvi element u listu potega prvog čvora
    -U dest se upisuje lokacija drugog čvora

    //Brisanje potega 
    -Brišemo poteg između dva zadata čvora A i B
    -Nalazimo lokacije oba čvora
    -U listi potega prvog čvora brišemo element koji ukazuje na drugi čvor
    -Ovaj deo odgovara operaciji brisanja zadatog elementa liste

    //Brisanje cvora
    -Nalazimo lokaciju čvora N
    -Obrisati sve potege koji se završavaju na čvoru N
        -Zahteva obilazak celog grafa, tj liste čvorova, i za svaki čvor obilazak njegove liste potega
        -Obrisati poteg prema N iz listi potega svih čvorova
    -Obrisati listu potega čvora N 
        -Odogovara brisanju cele liste
    -Obrisati čvor N iz liste čvorova


    //OBILAZAK GRAFA 
    Obilazak po širini - BFS - QUEUE kao pomoćna struktura (red) //BreadthFirstSearch
    Obilazak po dubini - DFS - Stack kao pomoćna struktura (magaci) //DepthFirstSearch
    Status čvorova
        - 1 (spreman): inicijalno stanje
        - 2 (čekanje): čvor čeka na obradu 
        - 3 (obrađen): čvor je obrađen
    Ako neki od čvorova nisu obiđeni, ponoviti postupak počev od prvog čvora kome je status ostao 1.

    BFS/DFS - razlika je u pomoćnoj strukturi !!
    //Obilazak po širini / dubini
        -Postaviti sve čvorove u STATUS=1
        -Upisati prvi čvor u RED / MAGACIN i promeniti mu status na STATUS=2
        -Sve dok RED / MAGACIN ne bude prazan 
            -Uzeti čvor sa početka REDa / MAGACINa. Obraditi N u promeniti mu STATUS=3
            -Dodati u RED / MAGACIN sve susede čvora N čiji je STATUS=1. , Promeniti im STATUS=2
        KRAJ
    
    
