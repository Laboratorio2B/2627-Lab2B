#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe
#include <errno.h>


// stampa un messaggio d'errore e termina il programma
void termina(const char *messaggio);

// strcmp implementato in arm
int armcmp(char *,char *);


// confronta argomenti passati sulla linea di comando
int main(int argc, char *argv[])
{
  if(argc<=2) {
    printf("Uso:\t %s s1 s2 [s3 s4 ...]\n",argv[0]);
    return 1;
  }
  for(int i=1;i<argc-1;i++) {
    int ris;
    ris = strcmp(argv[i],argv[i+1]);
    printf("%s vs %s --> strcmp: %d\n",argv[i],argv[i+1],ris);
    ris = armcmp(argv[i],argv[i+1]);
    printf("%s vs %s --> armcmp: %d\n",argv[i],argv[i+1],ris);
  }
  return 0;
}

// funzione C di confronto stringhe usata come modello 
// per la versione ARM
int modello(char *s, char *t)
{
  for(int i=0; ;i++) 
    if(s[i]!=t[i]) 
      return s[i]-t[i];
    else if(s[i]==0)
      return 0;
}



void termina(const char *messaggio){
  if(errno!=0) perror(messaggio);
    else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}


