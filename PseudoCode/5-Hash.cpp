Najčešće metode za izračunavanje hash funkcija su sledeće:
    metoda deljenja -> h(k) = k mod M 
    metod sredine kvadrata -> h(k) = M/W (k^2 mod W) 
    itd... 

-Kolizija: Ako dva ključa imaju istu vrednost hash funkcije (različiti ključevi preslikavaju se u istu adresu), kažemo da je došlo do kolizije.
-Ključevi koji izazivaju koliziju nazivaju se sinonimi.

Faktor popunjenosti tablice (engl.load factor), FP
    -predstavlja odnos broja elemenata u tablici i broja rezervisanih lokacija za elemente tablice (veličine tablice):
        FP = broj elemenata u tablici / velicina tablice 


//Opsti postupak kod dodavanja podatka sa kljucem K 
Algoritam:
1. Izračunavanje hash funkcije h(K) na osnovu vrednosti ključa;
2. Ako je pozicija h(K) slobodna, podatak se upisuje na to mesto.
3. Inače, lokacija je zauzeta i došlo je do kolizije:
1. vrši se rešavanje kolizije nekom od metoda
2. Menja se vrednost primarne adrese u sekundarne adrese i pokušava upis sve dok se ne nađe slobodna lokacija
3. Ako slobodna lokacija postoji, vrši se upis podatka,
4. Inače, tablica je puna.

//OPŠTI POSTUPAK KOD BRISANJA PODATKA SA KLJUČEM K 
Algoritam:
1. Izračunavanje hash funkcije h(K) na osnovu vrednosti ključa;
2. Ako je pozicija h(K) zauzeta,
    1.Ako je to podatak sa ključem K, obrisati ga.
    2.Inače, nastavi pretragu po sinonimima
        1. Menja se vrednost primarne adrese u sekundarne adrese i pokušava traženje sve dok se ne nađe traženi podatak
        2. Ako podatak postoji, vrši se brisanje podatka,
        3. Inače, podatak koji se traži ne postoji, nemoguće brisanje
3. Inače, podatak sa ključem K ne postoji

-Ne može se jednostavno samo obrisati element iz tablice na koji ukazuje h(k). Zašto?
-Koristi se specijalna vrednost DELETED za markiranje ćelije koja je sadržala obrisani element.
-Traženje tretira vrednost DELETED kao da ćelija sadrži element sa ključem koji se ne poklapa sa traženim.
-Dodavanje tretira vrednost DELETED kao da je ćelija prazna tako da se može koristiti za smeštanje novog podatka.

//Resavanje kolizije 
-Otvoreno adresiranje - kad dođe do kolizije, polje se pretražuje na izabrani sistematski način sve dok se ne nađe prazna ćelija za upis podatka.
-Ulančavanje sinonima
    - spoljašnje ulančavanje sinonima - kreira se lančana lista tako da se kod kolizije u nju dodaju sinonimi
    - unutrašnje ulančavanje sinonima - ulančavanje se vrši unutar tablice (praktično odgovara definiciji otvorenog adresiranja, s tim da se elementima tablice dodaje još jedno polje - link na sinonime).

Kod kolizije traženje se nastavlja traženjem slobodne lokacije korišćenjem sekundarne transformacije:
Najčešće korišćene sekundarne transformacije su:
    - Linearno traženje
    - Modifikovano linearno traženje  Kvadratno traženje
    - Sekundarna hash funkcija

//Linearno trazenje 
Traženje slobodne ćelije se vrši sekvencijalno (sekvencijalna promena indeksa u tablici) dok se ne dođe do prve slobodne lokacije
- c(i) = a⋅s, gde je a uzajamno prost broj sa M , k+1, trazi redom slobodno mesto 

//TRAŽENJE ELEMENTA SA LINEARNIM TRAŽENJEM MESTA ZA SINONIME
find(T,N,k) 
i <- h(k) 
p <- 0
repeat
    c <- T[i] 
    if c = NULL
        return NULL  
    else if c.key = k
        return T[i]
    else 
        i <- (i + 1) % N 
        p <- p + 1 
until p = N 
return NULL 

/* 
Traženje u tablici T počinje od lokacije h(k)
-Vrši se sukcesivni obilazak lokacija sve dok se ne desi:
    - Našli smo element sa ključem k,
    ILI
    - Našli smo praznu ćeliju, 
    ILI
    - N ćelija je neuspešno obiđeno (N je veličina T)
*/

//AŽURIRANJE SA LINEARNIM TRAŽENJEM
Kod operacija dodavanja i brisanja, uveden je specijalni objekat, nazvan DELETED, koji zamenjuje obrisane elemente

removeElement(T,N,k)
1. Traženje elementa sa ključem k (kao kod find) 
2. Ako je element (k, o) nađen,
    Tada zamenjujemo njegovu vrednost specijalnom vrednošću DELETED i vraćamo poziciju tog elementa
1. Inače, vraća se null pozicija

insertItem(T, N, k, o)
1. Ako je tabela puna 
    Tada Prekoračenje Kraj
2. Početna ćelija za obradu je h(k)
3. Obilazimo konsekventne ćelije sve dok se ne desi nešto od sledećeg (petlja)
    - Ćelija i je prazna ili sadrži DELETED, ili
    - N ćelija je neuspešno obiđeno
4. Ako je nađena prazna ćelija tada Smestimo element (k, o) u ćeliju i

// Za operacije find ili removeElement - Pretraživanje se zaustavlja jedino ako je detektovana prazna ćelija (ne i za obrisanu!!)

//KVADRATNO TRAŽENJE
Slobodna lokacija se traži:
- c(i) = a⋅i^2
Ako je indeks x, sledeće ćelije koje se obilaze su x+1, x+4, x+9, x+16 ...

//SEKUNDARNA HASH FUNKCIJA
//Dvostruko heširanje
Vrši se transformacija ključa novom hash funkcijom, tzv. Sekundarna hash funkcija, koja se koristi i u svakom narednom koraku za dobijeni ključ:
- c(i) = i⋅h'(k), gde je h'(k) hash funkcija različita od primarne transformacije.
- N mora da bude prost broj 
Pomeramo za vrednost sekundarne hash funkcije 
Npr -> h(k) = 5, koje je zauzeto. d(k) = 5, koje pokazuje na istu adresu, sledeca adresa koju proveravamo da li je slobodna je 10, 15,20 ... 

//ULANČAVANJE SINONIMA
Ulančavanje sinonima
    -Spoljno ulančavanje
        - Svaki element tablice sadrži element, ukazatelj na početak l.liste koja sadrži sinonime
    -Unutrašnje ulančavanje
        - implementirano po ugledu na statičku implementaciju lančanih listi
        - 2D polje, gde je jedna kolona za podatke a druga kolona za „link“ unutar tablice

//SPOLJAŠNJE ULANČAVANJE SINONIMA
Hash tablica je organizovana kao vektor lančanih listi.
- Hash funkcija određuje u kojoj od lančanih listi se nalazi traženi podatak
- Lista obilazi standardnim metodom praćenja linkova.
- Broj elemenata liste je broj sinonima M
- Taj broj može da utiče na brzinu pristupa
- Redukuje se broj poređenja za faktor M, ali se koristi dodatni memorijski prostor za M linkova
- Brisanje elemenata iz tablice ne predstavlja problem
- Veličina tablice ne mora biti prost broj
- Mogu se koristiti i polja tzv buckets na svakoj lokaciji u hash tablici umesto ulančavanja.

//UNUTRAŠNJE ULANČAVANJE SINONIMA
Svaka vrsta u tablici mora sadržati bar dva polja: 
    - ključ
    - pokazivač na sledeći sinonim.
- Hash funkcijom određuje se pozicija prvog sinonima, a ukoliko traženi podatak nije na toj poziciji, traženje se nastavlja sleđenjem “linkova”
- Sinonimi mogu biti postavljeni bilo gde u okviru tablice
- Upis se vrši u dva prolaza
    - Sinonimi se smeju postavljati tek nakon zauzimanja svih lokacija dobijenih transformacijama ključa
    - Smeštanje se najčešće obavlja linearnim traženjem slobodne lokacije, počev od pozicije koju generiše hash funkcija. Kasnije dodavanje novih podataka u tablicu zahteva restrukturiranj tablice.
- Za sinonime se može rezervisati poseban prostor
//LINEARNO SE TRAZI MESTO ZA SKLADISTENJE,PA NAKON TOGA MOZEMO DA ULANCAVAMO NA TU LinkedListu 

