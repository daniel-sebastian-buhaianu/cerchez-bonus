# cerchez-bonus
Gigel este programator amator, dar web designer profesionist. Acum proiecteaza un magazin virtual si se confrunta cu o problema de programare. Pe site sunt prezentate n produse, numerotate de la 1 la n. In cosul de cumparaturi virtual, un client poate alege orice submultime de produse dintre cele n. In functie de componenta cosului de cumparaturi, Gigel trebuie sa ofere un bonus.

Gigel a observat ca se pot forma din cele n produse 2<sup>n</sup>-1 submultimi distincte nevide. A ordonat submultimile lexicografic si a asociat apoi fiecarei submultimi un numar de ordine de la 1 la 2<sup>n</sup>-1.

De exemplu, pentru n=3 submultimile nevide in ordine lexicografica sunt:
| Numar de ordine | Submultime  |
| --------------- | ----------- |
| 1               | {1}         |
| 2               | {1, 2}      |
| 3               | {1, 2, 3}   |
| 4               | {1, 3}      |
| 5               | {2}         |
| 6               | {2, 3}      |
| 7               | {3}         |

Pentru a acorda corect si eficient bonusul, trebuie sa fie implementate operatiile:
- data fiind o submultime, sa determine numarul ei de ordine;
- dat fiind un numar de ordine, sa determine submultimea corespunzatoare.

Fisierul de intrare *bonus.in* contine pe prima linie numarul natural n (1 ≤ n ≤ 30), iar pe a doua linie, un numar natural m, reprezentand numarul de operatii ce trebuie executate (1 ≤ m ≤ 1000). Pentru fiecare operatie urmeaza in fisier cate doua linii; pe prima linie este scris tipul operatiei (1 sau 2); daca tipul operatiei este 1, atunci pe cea de-a doua linie este scris numarul de elemente din submultime, urmat de elementele submultimii, separate prin spatii; daca tipul operatiei este 2, pe cea de-a doua linie va fi scris un numar de ordine (adica un numar natural cuprins intre 1 si 2<sup>n</sup>-1).

Fisierul de iesire *bonus.out* va contine m linii, cate una pentru fiecare operatie din fisierul de intrare. Pe fiecare linie va fi scris rezultatul unei operatii, in ordinea in care operatiile apar in fisierul de intrare. Daca operatia este de tip 1, in fisierul de iesire va fi afisat numarul de ordine al submultimii specificate in operatie. Daca operatia este de tip 2, in fisierul de iesire vor fi afisate elementele submultimii cu numarul de ordine specificat, separate prin spatii, in ordine crescatoare.

*Exemplu*
| bonus.in                  | bonus.out |
|---------------------------|-----------|
| 3                         | 1 2 3     |
| 3                         | 6         |
| 2                         | 3         |
| 3<br>1<br>2 2 3<br>2<br>7 |           |

OMI Iasi 2004
