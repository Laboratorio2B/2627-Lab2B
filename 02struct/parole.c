#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno
#include <math.h>
#include "strint.h"

// Scopo del programma:
//   mostrare un altro esempio di ABR
//   mostrare l'uso della compilazione separata 


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);

// inserisce le stringhe passate sulla linea di comando
// nell'abr associando gli interi 0,1,2,....
int main(int argc, char *argv[])
{
  if(argc<2) {
    printf("Uso: %s [s1 s2 ...]\n",argv[0]);
    exit(1);
  } 

  strint *root = NULL;
  for(int i=1;i<argc;i++) {
    strint *si = strint_crea(argv[i],i-1);
    root = abr_inserisci(root,si);
  }
  puts("--- inizio visita pre-order (lista ordinata)---");
  abr_strint_stampa(root,stdout);
  puts("--- fine visita ---");

  puts("--- inizio visita in-order---");
  abr_strint_stampa_preorder(root,stdout,0);
  puts("--- fine visita e programma ---");

  abr_strint_distruggi(root);

  return 0;
}



// stampa su stderr il  messaggio che gli passo
// se errno!=0 stampa anche il messaggio d'errore associato 
// a errno. dopo queste stampe termina il programma
void termina(const char *messaggio)
{
  if(errno==0) 
     fprintf(stderr,"%s\n",messaggio);
  else 
    perror(messaggio);
  exit(1);
}

