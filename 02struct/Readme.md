## Esercizi


### Coppie (21/10/25)

Facendo riferimento alla struct `coppia` vista nell'esempio `array_coppie.c`, scrivere un programma che richiede sulla linea di comando un numero pari *2n* di interi, crea un array di *n* puntatori a coppie, le ordina per differenza di elementi crescente e stampa e dealloca l'array ordinato. Ad esempio, scrivendo
```
coppie 2 2 3 4 7 0 2 1
```
deve creare l'array di coppie `(2 2) (3 4) (7 0) (2 1)`, che ordinato per differenza crescente risulta 
`(3 4) (2 2) (2 1) (7 0)`, essendo le differenze rispettivamente -1, 0, 1, 7. 



### Ordinamento di file (21/10/24)

Scrivere un programma che legge dalla riga di comando un elenco di nomi di file e stampa 
l'elenco di questi file ordinati per dimensione decrescente, 
i file con la stessa dimensione devono essere ordinati lessicograficamente.

*Nota:* per eseguire dei test con molti nomi di file osserviamo che la linea di comando
linux ha un meccanismo di espansione dei pattern che viene effettuato prima
di invocare i comandi. Ad esempio, se scriviamo `ordina *.c *.txt` al programma 
`ordina`, attraverso `argc` e `argv`, vengono passati tutti i file che hanno estensione `.c` e `.txt`

Questo esercizio è stato svolto in aula nel file `array_file.c` esclusa la parte di ordinamento che 
potete svolgere modificando opportunamente il mergesort visto in `array_capitali_funz.c`



### Inserimento e cancellazione da liste non ricorsivo (31/10/25)

All'interno del file `capitali_lista` completare le funzioni `cancella_nome_iter` e `inserisci_lat_iter`
che effettuano la cancellazione e l'inserimento ordinato in una lista utilizzando un ciclo `while`
invece della ricorsione. Per testare le vostre funzioni invocate `inserisci_lat_iter` in `crea_lista_lat` e 
`cancella_nome_iter` dal `main` al posto di `cancella_nome` (provate ad effettuare più di una 
cancellazione e in particolare provate a cancellare anche il primo elemento della lista). 



### Liste di interi (31/10/25)

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



### Stampa condizionale su ABR (4/11/25)


Aggiungere al programma  `abr_capitali` una funzione
```
bool pisaSE(capitale *c)

```
che prende input una capitale `c` e restituisce `true` se e solo se la città `c` si trova a Sud-Est di Pisa (che ha coordinate `43.70853`, `10.4036`). Utilizzare tale funzione insieme a `abr_stampa_cond` per stampare su `stdout` l'elenco delle capitali che si trovano a Sud-Est di Pisa. 


### Ricerca su ABR (4/11/25)

Aggiungere al programma `abr_capitali` una funzione
```
int abr_ricerca_range(capitale *r, char *smin, char *smax)
```
che date due stringhe `smin` e `smax` visualizza su stdout tutte le città contenuto nell'albero di radice `r` il cui nome è compreso lessicograficamente tra `smin` e `smax`. La funzione deve visualizzare le città in 
ordine lessicografico e deve esplorare solamente le parti dell'albero che possono contenere città nel range assegnato. La funzione deve resituire il numero di nodi esplorati (cioè quelli il cui nome di città viene confrontato con `smin` e/o `smax`); questo serve per verificare che non venga visitato tutto l'abero.

Modificare poi la funzione `main` in modo che dopo la costruzione dell'albero venga invocata la funzione 
`abr_ricerca_range` con parametri `argv[2]` e `argv[3]`.   


### ABR Città Sud America (7/11/25)

Questo esercizio richiede di creare un ABR contenente le città del Sud America predendole da file `sudAmerica.txt`. Si proceda nel seguente modo. Nel programma `abr_capitali` si cambi la definizione di `capitale` nella seguente
```c
typedef struct capit {
  char *nome;
  char *nazione;
  int kpop;
  struct capit *left, *right;
} capitale;
```
e si modifichino di conseguenza le funzioni `capitale_stampa`, `capitale_crea`, e `capitale_distruggi`. Si cancelli la funzione `capitale_leggi` e si modifichi la funzione `crea_abr` in modo che il ciclo `while` legga il file utilizzando `getline` ad ogni iterazione e per ogni linea utilizzando `strtok` crei e inserisca nell'ABR un nodo contenente i dati della città letta (si veda `legginomi.c` per un esempio). 
