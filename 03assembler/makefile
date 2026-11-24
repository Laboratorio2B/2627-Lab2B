# compilatore e flag per macchine arm7
CC=gcc
CFLAGS=-std=c11 -Wall -g 

# compilatore e flag per cross-compilazione
# CC=arm-linux-gnueabihf-gcc
# CFLAGS=-std=c11 -g -Wall -static 

EXECS=primi strcmp tok quicksort quickarm quickarm2

all: $(EXECS)

# stampa elenco dei primi <=N
# l'eseguibile primi dipende da primi.c e primo.s
primi: primi.c primo.s
	$(CC) $(CFLAGS) primi.c primo.s -o primi
	
# confronta le stringhe passate sulla linea di comando con strcmp e armcmp
# $^ = insieme dei prerequisiti
# $< = il primo prerequisito
# $@ = il target della regola 
strcmp: strcmp.c strcmp.s
	$(CC) $(CFLAGS) $^ -o $@
	
# implementazione di strtok in ARM
tok: tok.c tok.s
	$(CC) $(CFLAGS) $^ -o $@
	

# si noti come lo stesso sorgente quicksort.c è usato per 3 diversi eseguibili	
	
# quicksort solo con -O3 per massima velocità	
quicksort: quicksort.c 
	$(CC) $(CFLAGS) -O3 $^ -o $@
	
# quicksort con funzione qs_arm del file quicksort.s		
quickarm: quicksort.c quicksort.s
	$(CC) $(CFLAGS) $^ -o $@ -DUSA_ARM

# quicksort con funzione qs_arm del file quicksort2.s		
quickarm2: quicksort.c quicksort2.s
	$(CC) $(CFLAGS) $^ -o $@ -DUSA_ARM


clean:
	rm =f $(EXECS)

