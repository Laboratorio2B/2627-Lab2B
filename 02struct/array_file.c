#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno

/**  
Esercizio:

Scrivere un programma che legge dalla riga 
di comando un elenco di file e stampa 
questi file ordinati per dimensione decrescente, 
i file con la stessa dimensione devono essere 
ordinati lessicograficamente.

Esercizio svolto tranne parte sull'ordinamento

**/ 


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);


// definizione struct che rappresenta
// una file con nome e lunghezza
typedef struct {
  char *nome;
  long lung; 
} miofile;

// crea oggetto miofile a partire dal suo nome
miofile *miofile_crea(char *s)
{
  assert(s!=NULL);
  // apro file in lettura
  FILE *f = fopen(s,"r");
  if(f==NULL) {
    fprintf(stderr,"Non è stato possibile aprire il file %s\n",s);
    return NULL;
  }
  if(fseek(f,0,SEEK_END)!=0) {
    fprintf(stderr,"Non è stato possibile fare seek sul file %s\n",s);
    fclose(f);
    return NULL;
  }
  // ora il puntatore è alla fine del file
  long pos = ftell(f);
  if(pos<0) {
    fprintf(stderr,"Non è stato possibile fare ftell sul file %s\n",s);
    fclose(f);
    return NULL;
  }  
  fclose(f);
  // se siamo arrivati qui pos contiene
  // la lunghezza del file in byte 
  miofile *a = malloc(sizeof(*a));
  if(a==NULL) termina("Memoria insufficiente");
  a->nome = strdup(s);
  a->lung = pos;
  return a;
}


// distrugge (dealloca) un oggetto capitale 
void miofile_distruggi(miofile *a)
{
  free(a->nome);
  free(a);
}

// stampa sul file *f i campi del file *a
void miofile_stampa(const miofile *a, FILE *f) {
  fprintf(f,"%20ld %s\n",a->lung,a->nome);
}


int main(int argc, char *argv[])
{
  if(argc<2) {
    printf("Uso: %s nome1 [nome2 nome3 ...]\n",argv[0]);
    exit(1);
  }
  miofile **arr;
  arr = malloc((argc-1)*sizeof(*arr));
  if(arr==NULL) termina("Memoria esaurita");
  int n=0; // numero di elementi in arr[]
  for(int i=1;i<argc;i++) {
    // provo a inserire argv[i]
    miofile *tmp = miofile_crea(argv[i]);
    if(tmp!=NULL)
      arr[n++] = tmp;
  }
  // stampa array
  for(int i=0;i<n;i++)
    miofile_stampa(arr[i],stdout);

  puts("-------------");

  // dealloca i singoli file e l'array
  for(int i=0;i<n;i++)
    miofile_distruggi(arr [i]);
  free(arr);
  
  return 0;
}


void termina(const char *messaggio)
{
  // se errno!=0 oltre al mio messaggio stampa il messaggio
  // associato alla variabile globale errno 
  // utilizzando la funzione di libreria perror()
  if(errno!=0) perror(messaggio);
  // altrimenti stampa solo il mio messaggio
  else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}

