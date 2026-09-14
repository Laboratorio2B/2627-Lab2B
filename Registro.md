##  Introduzione ad array, puntatori e file (01introC)


**Lezione 1** (15/9/26)

Introduzione al corso: obiettivi e modalità d'esame. Introduzione al linguaggio C. La funzione `main`. Lettura e scrittura di interi dal terminale. Compilazione: linea di comando, errori e warning. Permessi di lettura/scrittura/esecuzione `rwx`. Esecuzione di programmi. Array "statici" (tipo `int a[n]` in `somma.c`). 

-----------------------

**Lezione 2** (18/9/26)


Concetto di PATH, uso di `.` per indicare la directory corrente. File `.bashrc` e sua modifica. 
Allocazione dinamica di array in C: funzioni malloc e free, programma `sommad.c`.
Lettura di input dalla linea di comando con argc/argv. 
Scrittura di file in formato testo, funzioni fopen/fprintf/fclose. Programma `scrivi_primi.c`.
Terminazione in caso di errori: funzione perror().




[//]: # (INIZIO SEZIONE COMMENTATA)

-------

**Lezione 3** (23/9/25)

Allocazione dinamica di array in C: funzioni malloc/free/realloc, programma `scrivi_primi.c`
Scrittura in un file di testo: fopen(), fprintf(), fclose(). Modalità append.
Introduzione ai puntatori; uso di puntatori negli array.
Significato e uso di `*` e `&`. Uso di `%p` per la stampa di un puntatore. 
Prototipi di funzione; significato istruzioni `#include`

-------

**Lezione 4** (26/9/25)

Utilizzo di *valgrind* per verificare il corretto utilizzo e deallocazione degli array.
Esempio passaggio parametri per riferimento attraverso un puntatore: `sommadprod.c`
Rappresentazione di stringhe in C (inizio): i tipi `char` e `char *`: sorgente `charstr.c`.


------------

**Lezione 5** (30/9/25)

Rappresentazione di stringhe in C (fine).
Stampa di stringhe con `printf`, calcolo lunghezza con `strlen`. 
Struttura dei parametri argc/argv di main().
Copia del puntatore vs copia degli elementi di un array: la funzione strdup()
Comandi `less` e `od` per visualizzare il contenuto di un file.


------------

**Lezione 6** (7/10/25)

Passaggio di array dalle/alle funzioni.
Lettura da un file di testo: comando fscanf().  
Terminazione in caso di errori: funzione perror(). Significato del tipo `const char *`
`stdout` e `stderr` e loro ridirezione.
Uso di `assert`.
Introduzione al *makefile*; compilazione con il comando *make*.
Equivalenza fra `*a` e `a[0]`.
Equivalenza fra `a` e `&a[0]`.
Aritmetica dei puntatori: definizione di `a+i` come `&a[i]`


------------

**Lezione 7** (14/10/25)

Esempio di uso della notazione `&a[i]` nel *mergesort*
Esercitazione in aula su array e stringhe: [testo esercizio](https://elearning.di.unipi.it/mod/page/view.php?id=24746)


----

**Lezione 8** (17/10/25)


Lettura di stringhe con `scanf`: evitare il buffer overflow: modificatori `%Ns` (con N massimo numero di caratteri) e `%ms`
Costruzione/concatenazione di stringhe mediante `asprintf` 



---

## Definizione di struct: liste e alberi binari di ricerca (02struct)



**Lezione 8** (17/10/25)

Definizione di tipi composti con `struct`; definizione di nuovi tipi con `typedef` e uso combinato con `struct`
Operazioni sui tipi composti, notazioni `.` e  `->`; passaggio per valore e per riferimento di struct. 
Ordinamento di un array di struct mediante mergesort
Array di puntatori a struct vs array di struct. Esempio: array di capitali.

----


**Lezione 9** (21/10/25)

Ordinamento array di puntatori a struct mediante mergesort (`array_capitali.c`)
Terminazione in caso di errori: funzione perror() e variabile globale `errno`
Confronto lessicografico di stringhe: funzione `strcmp`.
Introduzione all'uso delle funzioni come parametri di altre funzioni.
Funzioni `fseek` e `ftell`. Uso del tipo `long`.
Esercizio: ordinamento di file per dimensione e nome (`array_file.c`). 


---

**Lezione 10** (24/10/25)

Puntatori generici (`void *`). La funzione di ordinamento di libreria `qsort`: tipo della funzione di confronto, casting.


---

**Lezione 11** (28/10/25)

Prova in itinere sui contenuti delle lezioni 1-9. 


----

**Lezione 12** (31/10/25)

Introduzione alle *linked list*: creazione, stampa, distruzione di liste. Inserimento in testa e in coda. 
Linked list: procedure ricorsive per la cancellazione e l'inserimento ordinato. 



----

**Lezione 13** (4/11/25)

Alberi binari di ricerca: procedure ricorsive per costruzione, visita e deallocazione.
Alberi binari di ricerca: visita in preorder, ricerca di un elemento, calcolo altezza (file `abr_capitali.c`)
Makefile: concetto di target, prerequisiti e comandi.


----


**Lezione 14** (7/11/25)

Lettura da file con getline(). Parsing di stringhe mediante strtok() (esempi `leggicitta.c` e `legginomi.c`).
Funzionamento interno di strtok(). Varabili statiche (esempio `statiche.c`)
Makefile: target di default, meccanismo di risoluzione dei prerequisiti, regole implicite


---


## Assembler ARM (03assembler)


**Lezione 15** (11/11/25)

Test di primalità in assembler ARM (`primo.s`). 
Uso di un debugger: esecuzione passo/passo, breakpoint, visualizzazione variabili locali o registri, espressioni, breakpoint condizionali.
Accesso a sistemi remoti via ssh con X11 forwarding. Uso di gdbgui per debugging su sistemi remoti attraverso un browser, visualizzazione di strutture con puntatori all'interno del debugger. 

---

**Lezione 16** (14/11/25)

File oggetto (`.o`) e compilazione separata (programma `parole`) 
Realizzazione della compilazione separata nel makefile. Utilizzo delel variabili 
`$<`, `$^`, e `$@` nel makefile.
Implementazione `strtok` in assembler ARM (`tok.s`)


---

**Lezione 17** (18/11/25)

Implementazione quicksort in C e in assembler (`quicksort.c`, `quicksort.s` e `quicksort2.s`)
e misura dei tempi di esecuzione con `times(3)` .
Concetto di compilazione condizionale con `#ifdef` e suo controllo attraverso il makefile.
Operazioni bitwise in C: `&`, `|`, `^`, `~`, `<<`, `>>`. 
Uso di variabili intere come array di bit. Esempi in `bitops.c` (non commentati a lezione).


---

## Java (04ava)


**Lezione 18** (21/11/25)


Definizione e uso di matrici bidimensionali definite in modo statico (ad esempio `int a[3][5]`) e in modo dinamico come array di righe.
Introduzione a Java: la classe `Coppia`, la classe `ArrayList<>`, metodi `sort` e `contains`.


-----

**Lezione 19** (25/11/25)


Java: overloading vs overriding. Overriding dei metodi `toString` e  `equals`. Uso dell'annotazione `@Override`
La classe `TreeSet` e l'interfaccia `Comparable`. Lettura da file con `BufferedReader` e `FileReader`.
Uso di eccezioni. Java: la classe `HashSet` e il metodo `hashCode` (sorgente `Citta.java`).

-----

**Lezione 20** (28/11/25)

Cenni sulla gerarchia delle collezioni: `Set` vs `HashSet` vs 'LinkedHashSet', `List` vs `ArrayList` vs `LinkedList`.
Java: classi (astratte) e interfacce; differenza di uso fra `extends` e `implements`.
Classe `Grafo`, cammini minimi con algoritmo di Dijkstra. Classe `LogGrafo` 
e implementazione di un grafo di città mediante l'interfaccia `Nodo` 

-----


**Lezione 21** (2/12/25)

Esercitazione su lettura/scrittura di file e uso di collezioni e mappe in Java.


-----

**Lezione 22** (5/12/25)

Prova in itinere sul contenuto delle lezioni 10-21



---


## Uso di Python per interagire con il file system (05python)


**Lezione 23** (3/2/26)


Introduzione a Python, differenze e similarità con il C. 
Sintassi, interprete, istruzioni `if`, `else`, `elif`, `for`, `while`. 
Definizione di funzioni e Docstring. Liste e tuple.
Interprete ed esecuzione dalla linea di programma. 


-----


**Lezione 24** (5/2/26)

Esecuzione dalla linea di comando: uso di `import` e `sys.argv`. 
Uso di `#!/usr/bin/env python3` e permesso di execuzione. 
Dizionari e insiemi: funzionamento interno e vincoli sulle chiavi.  
Esempio: costruzione classifica leggendo risultati da file. Apertura di file con `with` e `open`. 
Istruzione `raise` per segnalare gli errori. Sorting di liste utilizzando una key function. 
Esercizi per casa: *Ribalta file* e *Ordina file*


---

**Lezione 25** (10/2/26)

Definizione e uso di classi in python. I metodi speciali `__init__`,  ` __str__`, `__repr__`.
Esplorazione del filesystem in Python: metodi dei moduli `os` e `os.path`.  
Esempio di ricerca ricorsiva del file piu grande.


---

**Lezione 26** (12/2/26)

Uso di classi in python: i metodi speciali `is`, `__eq__`, `__hash__` e ,  `__lt__`.
Uso del decorator `@functools.total_ordering`.
Sottoclassi in python; funzioni `type` e `isinstance`. 
Esplorazione del filesystem in Python. Permessi e comando `chmod`.
[Permessi](https://linuxcommand.org/lc3_lts0090.php) associati alle directory.
Concetto di [link symbolici](https://linuxize.com/post/how-to-create-symbolic-links-in-linux-using-the-ln-command/)
e loro gestione. 



---

**Lezione 27** (17/2/26)


Metodi speciali per operatori aritmetici (`__add__`, `__mul__`, etc.). 
Metodi `__getitem__` e `__setitem__`
Esplorazione del filesystem in Python. Path relativi e assoluti. 
Creazione di elenco dei file ordinato per dimensione decrescente.
Ricerca di file duplicati in python: soluzione basata sulla dimensione dei file.



---

**Lezione 28** (19/2/26)

Invocazione comandi della shell da python con `subprocess.run`.
Ricerca di file duplicati in python utilizzando il comando della shell  `cmp`. 
Ricerca di file basata sul tempo di ultima modifica e uso di espressioni regolari:
utilizzo della classe `Miofile` per memorizzare le informazioni relative a un singolo file.
Parametri posizionali e keyword. Uso di `*` e `**` per funzioni con numero arbitrario di parametri.


---


## Introduzione ai thread in C (06threads)



**Lezione 29** (24/2/26)

Introduzione ai thread in C.  Uso di mutex.  



---

**Lezione 30** (26/2/26)

Uso delle funzioni in `xerrori.c` per la gestione degli errori, compresa la relativa impostazione del `makefile`.
Esercitazione in aula su Python



---
**Lezione 31** (3/3/26)


Semafori e loro uso per implementare la tecnica produttori e consumatori.
Esempio: `primi_file.c`.


---

**Lezione 32** (5/3/26)

Prova in itinere sul linguaggio Python. [Testo della prova](https://elearning.di.unipi.it/mod/page/view.php?id=26142). 


---

**Lezione 33** (10/3/26)


Altro esempio di tecnica produttori e consumatori: `primi_files.c`. 
Esempio di sorting parallelo: `threadSort.c` e `pmergesort.c`.



---

**Lezione 34** (12/3/26)

Paradigma produttori-consumatori con produttori e consumatori multipli: `multip_primi_files.c`


---


## Condition Variables e uso di file binari (07condVars)



**Lezione 34** (12/3/26)


Introduzione alle Condition Variables. Esempi per la gestione della memoria condivisa (`heap.c`).



---

**Lezione 35** (17/3/26)


Gestione di readers e writers con condition variables (`rw0.c` e `rw.c`).
Uso di condition variables per schemi produttori consumatori (`multipcv_primi_files.c`)
Uso di condition variables per emulazione dei semafori (`zem.c`).
Cenni all'uso della threads library (`thrd_create`, `thrd_join`, etc) in alternativa ai POSIX threads (pthread);
fare riferimento alle [dispense su moodle](https://elearning.di.unipi.it/mod/resource/view.php?id=24147). 



---

**Lezione 36** (19/3/26)


Confronto tra condition variables e semafori (`pctest.c` con relative istruzioni nel `makefile`), 
e confronto con le versioni basate sulla threads library di C11 (`pctestC11.c`).

Lettura e scrittura di file binari in C: funzioni `fread` e `fwrite`; comando `od`.
System calls vs library functions.
Sezioni del system manual (comando man).
Esempi: open/read/write vs fopen/fread/fwrite/fprintf
Esempio prestazioni di `write(2)` vs `fwrite(3)`.



---

**Lezione 37** (24/3/26)


Flags e loro uso in `open`.
Permessi dei file e notazione ottale in `open`. 
Significato e uso di `umask(1)` e `chmod(1)`
Lettura di file binari con `fread()`; richiamo uso di `fseek` e `ftell` per determinare la dimensione di un file.  



---

## Introduzione ai processi (08processi)



**Lezione 37** (24/3/26)


Creazione di processi in C: comando `fork`.
Comandi `wait` e `sleep`, processi zombie. 
Comandi del terminale per monitare i processi: `ps`, `htop`, e `kill`


----


**Lezione 38** (26/3/26)


Esecuzione di processi in background con `&` con eventuale ridirezione dell'output. 
Concetto di pipe anonima per la comunicazione fra processi, esempio `contaprimi.c` 
Documentazione sulle pipe, pagine: `pipe(2)` e `pipe(7)`.


[Esercitazione in aula](https://elearning.di.unipi.it/mod/page/view.php?id=26289) su uso thread e file binari.



----


**Lezione 39** (31/3/26)

Comandi `mkfifo(1)` e `mkfifo(3)`.  
Comunicazione tra processi mediante named pipe (anche con Python) con riferimento a `pipe(7)`, `fifo(7)`. 
Lancio di un nuovo eseguibile mediante `fork` seguito da `execl`.
Introduzione all'uso della memoria condivisa con riferimento a `shm_overview(7)`.
Uso e significato di `shm_open`, `ftruncate`, `mmap`, `munmap`, `shm_unlink`.
Esempio creazione shared memory: `shm0.c`



----


**Lezione 40** (9/4/26)


Utilizzo dei named semaphore per la sincronizzazione di processi, con riferimento a `sem_overview(7)`. 
Esempio utilizzo shared memory: `sommaprimi.c` e `sommaprimi_aux.c`.
Esempio schema produttori consumatori tra processi, sorgenti `shm_prod.c` e `shm_cons.c`.


---


## Segnali e variabili atomic (09segnali)

----


**Lezione 41** (14/4/26)



Introduzione ai segnali con riferimento a `signal(7)`. Segnali da tastiera e comando `kill(1)`. 
Gestione asincrona dei segnali con `sigaction`, esempio: `segnali.c`. 
Uso modificatore `volatile sig_atomic_t`. Comandi `sleep(3)` e `pause(2)` per evitare il busy waiting. 
Concetti di multithread safety: MT-safe e async-signal-safe.


----


**Lezione 42** (16/4/26)

Gestione sincrona dei segnali: blocco dei segnali  con `pthread_sigblock`, attesa con `sigwait` e `sigwait_info`.
Invio di informazioni aggiuntive con `kill -q` e `sigqueue`; differenza fra `union` e `struct` 
Inviare segnali ad uno specifico thread: `pthread_kill` e `pthread_sigqueue`. 
Introduzione ai segnali real-time: `man 7 signal`.


---

**Lezione 43** (21/4/26)

Esempio gestione di segnali real time: `segnaliRT.c`.

Variabili `atomic` e [Atomic operations library](https://en.cppreference.com/w/c/atomic), vdere anche il 
Esempio di uso di una variable atomic: `atcontaprimi.c`
[Operazioni atomiche e lock](https://elearning.di.unipi.it/mod/resource/view.php?id=24147): 
uso di `atomic_flag_test_and_set` per realizzare uno spinlock. 
Confronto fra spinlock, mutex e variabili atomiche: `spinlock.c`.
Uso di `atomic_compare_exchange_weak` per la realizzazione di uno stack lock-free; confronto fra stack lock-free e mutex: `stack.c`.


---


## Introduzione ai thread in Python (10pythreads)


**Lezione 43** (21/4/26)

Threads in Python: [Creazione e join di thread](https://realpython.com/intro-to-python-threading/) : `threads.py`


---


**Lezione 44** (23/4/26)

Il [Global Interpreter Lock](https://realpython.com/python-gil/) e i suoi effetti.
Modulo [argparse](https://docs.python.org/3/howto/argparse.html) e il suo uso. 
Modulo [logging](https://realpython.com/python-logging/) e il suo uso.
Uso di `ThreadPoolExecutor` e `ProcessPoolExecutor`, i metodi [`map` e `submit`](https://superfastpython.com/threadpoolexecutor-in-python/), esempio: `contaprimi.py`.  


----


**Lezione 45** (28/4/26)


Altri esempi di Thread Pool: `esempiPool.py`.
Mutex in Python (classe Lock), esempio: `sommaprimi.py`. 
[semafori e condition variables in python](https://superfastpython.com/threading-in-python/):
`somma_primi_files.py` e `rw.py`.
Ripasso del programma con esempi di domande della prova orale. 



----

**Lezione 46** (30/4/26)

Prova in itinere sul contenuto delle lezioni da 29 a 43 (testo su moodle).


----

**Lezione 47** (5/5/26)

Discussione del progetto finale. 


----

**Lezione 48** (7/5/26)

Prova di recupero riservata agli studenti che hanno superato 2 prove in itinere su 4. 



[//]: # (FINE SEZIONE COMMENTATA)