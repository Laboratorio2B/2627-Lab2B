#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno

void termina(const char *messaggio);


// Scopo del programma:
//   mostrare il funzionamento di getline() e strtok() 
//   eseguire passando come argomento il file sudAmerica.txt


// main che legge le linee e le spezza al ;
int main(int argc, char *argv[])
{
  if(argc!=2) {
    printf("Uso: %s nomefile\n",argv[0]);
    exit(1);
  }
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) termina("Errore apertura file");

  // ciclo di lettura dal file f
  char *buffer=NULL;    // usate da getline()
  size_t n=0;           // vengono riutilizzate ad ogni iterazione
  // legge una linea del file alla volta 
  while(true) {
    //legge linea dal file salvando contenuto in buffer
    ssize_t e = getline(&buffer,&n,f);
    if(e<0) {        // segnala la fine del file
      if(buffer!=NULL) 
        free(buffer);  // dealloco il buffer usato per contenere le linee 
      break;           // esci dal ciclo di lettura 
    }
    // scommentare per vedere cosa ha letto getline()
    // fprintf(stderr,"e=%ld n=%zd, buffer=%s",e, n,buffer);
    // Legge i primi tre token di buffer
    char *s = strtok(buffer,";\n");
    printf("token 1: %s\n",s);
    s = strtok(NULL,";\n");       // per leggere i token dopo il primo
    printf("token 2: %s\n",s);  // si passa NULL a strtok 
    s = strtok(NULL,";\n");
    printf("token 3: %s\n",s);
  } // end while del getline
  fclose(f);
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



