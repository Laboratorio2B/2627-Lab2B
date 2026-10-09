## Esercizi per casa


### Pari e dispari (18/9/26)

Scrivere un programma `paridispari` che legge gli interi passati dalla linea di comando e scrive quelli pari in un file di nome `pari.txt` e quelli dispari in un file di nome `dispari.txt`. Prima di terminare il programma deva visualizzare sul terminale la somma degli interi pari e dispari letti. Ad esempio se il programma viene invocato scrivendo
```
paridispari 10 70 17 36 -23
```
al termine dell'esecuzione il file `pari.txt` deve contenere
```
10
70
36
```
e il file `dispari.txt`
```
17
-23
```
Il programma deve poi visualizzare sul terminale:
```
Somma interi pari: 116
Somma interi dispari: -6
```

### Costruzione array dinamici (25/9/26)

Scrivere un programma C che legge un intero N e costruisce i seguenti due array di interi:

* l'array `a[]` contente i numeri tra 1 e N che sono multipli 3 ma non di 5: ``3, 6, 9, 12, 18, 21, 24, 27, 33, ...``

* l'array `b[]` contente i numeri tra 1 e N che sono multipli 5 ma non di 3:  ``5, 10, 20, 25, 35, 40, 50, ...``

Al termine della costruzione deve stampare lunghezza e la somma gli elementi degli array `a` e `b`, deve poi deallocarli e terminare. 

Ad esempio per N=100 i due array risultano

```
a = [3, 6, 9, 12, 18, 21, 24, 27, 33, 36, 39, 42, 48, 51, 54, 57, 63, 66, 69, 72, 78, 81, 84, 87, 93, 96, 99]

b = [5, 10, 20, 25, 35, 40, 50, 55, 65, 70, 80, 85, 95, 100]
```

e di conseguenza l'output dovrebbe essere 
```
lunghezza a[] = 27,  somma a[] = 1368
lunghezza b[] = 14,  somma b[] = 735
```

Per N=99999 l'output dovrebbe essere
```
lunghezza a[] = 26667,  somma a[] = 1333366668
lunghezza b[] = 13333,  somma b[] = 666633335
```
Eseguire il programma anche utilizzando `valgrind` verificando che non stampi nessun messaggio d'errore e al termine visualizzi il messaggio 
```
HEAP SUMMARY:
 in use at exit: 0 bytes in 0 blocks
```


### Reverse di stringhe (2/10/26)

Scrivere un programma `reverse` che stampa sullo schermo gli argomenti passati sulla linea di comando (escluso il nome del programma) con i caratteri in ordine inverso. Ad esempio, scrivendo
```
reverse sole azzurro 123
```
l'output dovrebbe essere
```
elos
orruzza
321
```
Si noti che per stampare i caratteri in ordine inverso potete 1. creare la stringa ribaltata e poi stamparla con `printf` con modificatore `%s`, oppure  2.  stampare i caratteri da destra a sinistra uno alla volta con il modificatore `%c`. 



### Concatena stringhe (2/10/26)

Scrivere un programma `concatena` che costruisce la stringa ottenuta concatenando tra loro le stringhe passate sulla linea di comando. Ad esempio, scrivendo
```
concatena sole azzurro 123
```
l'output dovrebbe essere
```
Stringa concatenata: soleazzurro123
```
In dettaglio il vostro programma deve 

1. calcolare la lunghezza `lun` della stringa risultato, come somma delle lunghezze delle stringhe `argv[1]` ... `argv[argc-1]`
2. allocare con `malloc` un blocco di `lun+1` byte (il `+1` serve per il byte 0 finale)
3. copiare i singoli caratteri dalle stringhe `argv[i]`  nella stringa appena allocata, seguiti dal terminatore 0
4. stampare la stringa ottenuta e deallocarla con `free`

Eseguire il programma anche utilizzando `valgrind` verificando che non stampi nessun messaggio d'errore e al termine visualizzi il messaggio 
```
HEAP SUMMARY:
 in use at exit: 0 bytes in 0 blocks
```



### Boomer (9/10/26)

Scrivere una funzione `void maiuscole(char *s)` che riceve in input una stringa e la modifica convertendo ogni carattere in maiuscolo. 
Per convertire un singolo carattere in maiuscolo è necessario invocare la funzione `toupper()`, consultate la pagina `man` per l'uso. 

Scrivere un programma `boomer` che invoca la funzione `maiuscole` sui parametri `argv[1]`, `argv[2]`, ... e stampa le stringhe così ottenute.


### Confronta stringhe (9/10/26)

Scrivere una funzione `int confrontas(const char *s, const char *q)` che prende in input due stringhe e resituisce:

* -1 se la prima è lessicograficamente minore della seconda (ad esempio `s`=camino, `q`=cane)
*  1 se la prima è è lessicograficamente maggiore della seconda (ad esempio `s`=gatto, `q`=cane)
* 0 se le due stringhe sono uguali

Si ricordi che per convenzione se una stringa è un prefisso proprio dell'altra allora quella lessicograficamente minore è quell più corta (quindi `porta` è minore di `portale`).

Si scriva poi un un programma `minimo` che calcola e la stmpa la stringa più piccola tra `argv[1]`, `argv[2]`, ...

