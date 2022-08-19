Najčešće metode za izračunavanje hash funkcija su sledeće:
    metoda deljenja -> h(k) = k mod M 
    metod sredine kvadrata -> h(k) = M/W (k^2 mod W) 
    itd... 

-Kolizija: Ako dva ključa imaju istu vrednost hash funkcije (različiti ključevi preslikavaju se u istu adresu), kažemo da je došlo do kolizije.
-Ključevi koji izazivaju koliziju nazivaju se sinonimi.

Faktor popunjenosti tablice (engl.load factor), FP
    -predstavlja odnos broja elemenata u tablici i broja rezervisanih lokacija za elemente tablice (veličine tablice):
        FP = broj elemenata u tablici / velicina tablice 

