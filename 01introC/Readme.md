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


