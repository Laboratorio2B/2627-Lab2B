## Esercizi


### Coppie (23/10/26)

Facendo riferimento alla struct `coppia` vista nell'esempio `array_coppie.c`, scrivere un programma che richiede sulla linea di comando un numero pari *2n* di interi, crea un array di *n* puntatori a coppie, le ordina per differenza di elementi crescente e stampa e dealloca l'array ordinato. Ad esempio, scrivendo
```
coppie 2 2 3 4 7 0 2 1
```
deve creare l'array di coppie `(2 2) (3 4) (7 0) (2 1)`, che ordinato per differenza crescente risulta 
`(3 4) (2 2) (2 1) (7 0)`, essendo le differenze rispettivamente -1, 0, 1, 7. 



### Ordinamento di file (23/10/26)

Scrivere un programma che legge dalla riga di comando un elenco di nomi di file e stampa 
l'elenco di questi file ordinati per dimensione decrescente, 
i file con la stessa dimensione devono essere ordinati lessicograficamente.

*Nota:* per eseguire dei test con molti nomi di file osserviamo che la linea di comando
linux ha un meccanismo di espansione dei pattern che viene effettuato prima
di invocare i comandi. Ad esempio, se scriviamo `ordina *.c *.txt` al programma 
`ordina`, attraverso `argc` e `argv`, vengono passati tutti i file che hanno estensione `.c` e `.txt`

Questo esercizio è stato svolto in aula nel file `array_file.c` esclusa la parte di ordinamento che 
potete svolgere modificando opportunamente il mergesort visto in `array_capitali.c`


### qsort (6/11/25)

Ripetere gli esercizi **Coppie** e **Ordinamento di file** eseguendo l'ordinamento utilizzando la funzione di libreria `qsort(3)` invece di `mergesort`.



### Inserimento ordinato in lista non ricorsivo (10/11/26)

All'interno del file `capitali_lista` completare la funzione `inserisci_lat_iter`
che effettua l'inserimento ordinato in una lista utilizzando un ciclo `while`
invece della ricorsione. Per testare le vostre funzioni invocate `inserisci_lat_iter` in `crea_lista_lat`  
dal `main` al posto di `inserisci_lat_ric` e verificate di ottenere lo stesso risultato. 


### Inserimento ordinato in liste parametrico (10/11/26)


Scrivere una funzione di inserimento ordinato in una lista in cui il criterio di ordinamento 
è espreso da una funzione `int confronta_capitali(capitali *a, capitali *b)` che viene passato come parametro alla funzione di inserimento. Testare la funzione usandola opportunamento per ottenere la lista di capitali ordinata lessicograficaemnte. 



### Liste di interi (10/11/26)

Utilizzare la struct
```C
typedef struct _intero {
  int valore;
  struct _intero next;
} intero;
```
per rappresentare un elemento di una lista di interi. 

Scrivere un funzione 
```c
int confronta_lunghezza(intero *lis1, intero *lis2);
```
che date due liste di interi `lis1` e `lis2` (possibilemente anche vuote) restituisce `-1`
se `lis1` ha meno elementi di `lis2`, `1` se `lis1` ha più elementi di `lis2`, 0 se hanno lo stesso 
numero di elementi (le liste vuote si considerano avere 0 elementi).

Si scriva poi un `main` che legge dalla linea di comando un numero qualsiasi di interi e crea due liste contenenti 
rispettivamente gli interi pari e gli interi dispari passati sulla linea di comando (si noti che le liste possono essere vuote).

Successivamente il `main` deve invocare `confronta_lunghezza` e stampare la lista più lunga; se le liste hanno la stessa lughezza deve stampare quella la cui somma degli elementi è maggiore, se anche la somma degli elementi è la stessa non deve stampare nulla.

Il programma deve poi deallocare tutta la memoria utilizzata e terminare.   


 