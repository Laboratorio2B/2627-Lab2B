#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno
#include <math.h>


// definizione struct che rappresenta un
// nodo contenente una stringa e un intero 
// + campi left/right per costruire l'albero 
typedef struct strint {
  char *s;
  int n;
  struct strint *left, *right;
} strint;


// prototipi delle funzioni 
void strint_stampa(const strint *a, FILE *f);
strint *strint_crea(char *w, int v);
void strint_distruggi(strint *a);
// stampa tutti gli elementi dell'albero
// che ha come radice root
void abr_strint_stampa(const strint *root, FILE *f);
// stampa tutti gli elementi dell'albero
// che ha come radice root
// facendo una visita in preorder
// il parametro depth è la profondita di root
void abr_strint_stampa_preorder(const strint *root, FILE *f, int depth);

// distrugge tutti gli elementi dell'ABR con radice root
void abr_strint_distruggi(strint *root);


// inserisci il nuovo nodo "c" dentro l'albero 
// con radice "root", non inserisce se c
// è già presente, restituisce la root
// del nuovo albero contenente anche "c"
strint *abr_inserisci(strint *root, strint *c);

// cerca la stringa w dentro l'abr con radice root
// restituisce il puntatore al nodo se trovata
// altrimenti NULL
strint *abr_ricerca(strint *root, char *w);

// dato un abr di radice root restituisce
// la sua altezza = numero di livelli =
// profondità massima di una foglia
int abr_altezza(strint *root);

// conta il numero di nodi dell'albero
int abr_strint_totnodi(const strint *root);

// calcola la somma dei valori nei nodi dell'albero
int abr_strint_sommanodi(const strint *root);


