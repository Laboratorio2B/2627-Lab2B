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


