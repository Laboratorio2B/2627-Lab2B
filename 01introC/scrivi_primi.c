#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe


// da compilare con:
//  gcc -std=c11 -Wall -O -g -o scrivi_primi  scrivi_primi.c
// oppure, avendo il makefile visto a lezione
//  make scrivi_primi


// Scopo del programma:
//  converte argv[1] nell'intero N
//  crea un array *dinamico* con i primi <=N
//  salva l'elenco dei primi nel file di nome argv[2]


// prototipo della funzione termina()
// il corpo della funzione può apparire dopo il main()
void termina(char *messaggio);


// dato k restituisco True se è primo, false altrimenti
// suggerito da copilot (non è bellissimo ma è corretto)
bool primo(int k) {
  // se k è pari e diverso da 2 allora non è primo
  if(k%2==0 && k!=2) return false;
  // se k è dispari e non è primo
  // allora esiste un divisore <= sqrt(k) che è dispari
  // quindi posso controllare solo i divisori dispari
  // e posso fermarmi a sqrt(k)
  for(int i=3; i*i<=k; i+=2) {
    if(k%i==0) return false;
  }
  return true;
}


int main(int argc, char *argv[])
{
  int n; // definisco variabile intera di nome n
  
  if(argc!=3) {
    printf("Uso: %s intero_pos nome_file\n",argv[0]);
    return 1;
  }
  n = atoi(argv[1]); // converto argv[1] in intero
  if(n<1) 
    termina("E' richiesto un intero *positivo*!");
  
  // crea un array dinamico inizialmente di 10 elementi
  int *a;  // dichiaro che a sarà usata come array
  int capacita = 10;   // dimensione attuale dell'array
  int messi = 0;   // numero di elementi attualmente dentro l'array 
  
  // stampa indirizzi delle variabili del main
  printf("--- Indirizzi di argc, n, a, messi: %p\n%p\n%p\n%p\n",&argc,&n,&a,&messi);

  a = malloc(capacita*sizeof(int));
  if(a==NULL) 
    termina("Malloc fallita");
  // stampa indirizzo contenuto in a  
  printf("--- contenuto di a: %p\n",a); 

  
  // riempio array
  for(int i=2; i<=n; i++) {
    if(primo(i)) {
      // se l'intero i è primo lo inserisco
      // nella tabella dei primi
      // ma prima verifico che ci sia spazio
      if(messi==capacita) {
        capacita = 2*capacita; // se la tabella è piena raddoppio la dimensione
        a = realloc(a,capacita*sizeof(int));
        if(a==NULL)
          termina("Realloc fallita");
        printf("--- a reallocato (%d): %p\n",capacita,a);
      }
      // inserisco il primo i dentro a[]
      a[messi] = i;
      messi += 1;
    }
  }
  // tabella completata
  // riduco array alla dimensione minima
  capacita = messi;
  a = realloc(a,capacita*sizeof(int));
  if(a==NULL) termina("Realloc fallita");

  // apriamo il file per scriverci gli interi
  FILE *f = fopen(argv[2],"wt");
  if(f==NULL)
    termina("Apertura del file fallita");
    
  // scrivi su f il contenuto array, un intero per riga 
  for(int i=0;i<messi;i++) {     
    fprintf(f,"%d\n",a[i]);                    
  }
  if(fclose(f)!=0)
    termina("Errore chiusura file");

  // dealloco la memoria della tabella
  free(a);
  return 0;
}


// stampa un messaggio d'errore e termina il programma
void termina(char *messaggio)
{
  perror(messaggio);
  exit(1);
}

