# compilatore e flag per macchine arm7
CC=gcc
CFLAGS=-std=c11 -Wall -g -O

# per il debugging con gdb e derivati meglio togliere 
# ogni ottimizzazione e usare -ggdb 
# CFLAGS=-std=c11 -Wall -ggdb -O0


# compilatore e flag per cross-compilazione
# CC=arm-linux-gnueabihf-gcc
# CFLAGS=-std=c11 -g -Wall -static 

# eseguibili da compilare se non si specifica un target
EXECS=primi strcmp tok quicksort quickarm quickarm2


# target di defualt:
all: $(EXECS)

# stampa elenco dei primi <=N
# l'eseguibile primi dipende da primi.c e primo.s
primi: primi.c primo.s
	$(CC) $(CFLAGS) primi.c primo.s -o primi


# nel seguito usiamo queste variabili automatiche 
# $^ = insieme dei prerequisiti
# $< = il primo prerequisito
# $@ = il target della regola 

# confronta le stringhe passate sulla linea di comando con strcmp e armcmp
strcmp: strcmp.c strcmp.s
	$(CC) $(CFLAGS) $^ -o $@
	
	
# implementazione di strtok in ARM
tok: tok.c tok.s
	$(CC) $(CFLAGS) $^ -o $@
	

# tre diverse versioni di quicksort su ARM
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


# regola per cancellare i file eseguibili
# e quindi forzare la ricompilazione
clean:
	rm -f $(EXECS)

