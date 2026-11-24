# il funzionamento del makefile lo vedremo prossimamente

# definizione del compilatore e dei flag di compilazione
# che vengono usati dalle regole implicite
CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm

# primo target del file eseguito se si
# invoca "make" senza argomenti
all: demo_abr demo_statiche demo_parole

	
# fino ad oggi abbiamo usato questa regola implicita
# (predefinita) che vale per qualsiasi eseguibile "xxxx"
xxxx: xxxx.c
	$(CC) xxxx.c $(CFLAGS) -o xxxx
	
# ora inizieremo a scrivere noi delel regole
# per svolgere compiti più complessi	
	
# regola per ottenere l'eseguibile demo_abr da abr_capitali.c
demo_abr: abr_capitali.c
	gcc abr_capitali.c -std=c11 -Wall -O3 -g -o demo_abr

# come sopra per demo_statiche ma usa le variabili predefinite
demo_statiche: statiche.c
	$(CC) statiche.c $(CFLAGS) -o demo_statiche

# regole per la compialzione separata di 
# parole.o e strint.o

# nella scrittura delle regole, oltre alle variabili
# definite sopra possiamo usare le variabili automatiche
# $^ = insieme dei prerequisiti
# $< = il primo prerequisito
# $@ = il target della regola 

# file eseguibile ottenuto con il linking dei due file oggetto
demo_parole: parole.o strint.o
	$(CC) $^ -o $@
	
# regole per il file oggetto	
parole.o: parole.c strint.h
	$(CC) $< $(CFLAGS) -c -o $@

strint.o: strint.c strint.h
	$(CC) strint.c $(CFLAGS) -c -o strint.o
