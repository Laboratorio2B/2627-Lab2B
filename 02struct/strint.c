#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno
#include <math.h>
#include "strint.h"

// funzioni per la gestione di nodi contenenti una coppia (stringa,intero) 
// rappresentata dal tipo strint definito dentro strint.h


void strint_stampa(const strint *a, FILE *f) {
  fprintf(f,"%-8s (%d)\n",a->s,a->n);
}

strint *strint_crea(char *w, int v)
{
  strint *a  = malloc(sizeof(*a));
  a->n = v;
  a->s = strdup(w); // creo una copia di s
  a->left = a->right = NULL;
  return a;
}

void strint_distruggi(strint *a)
{
  free(a->s);
  free(a);
}

// stampa tutti gli elementi dell'albero
// che ha come radice root
void abr_strint_stampa(const strint *root, FILE *f)
{
  if(root!=NULL) {
    abr_strint_stampa(root->left,f);
    strint_stampa(root,f);
    abr_strint_stampa(root->right,f);
  }
}

// conta il numero di nodi dell'albero
int abr_strint_totnodi(const strint *root)
{ 
  int tot=0;
  if(root!=NULL) {
    tot += abr_strint_totnodi(root->left);
    tot +=1; // contributo di root
    tot += abr_strint_totnodi(root->right);
  }
  return tot;
}

// calcola la somma dei valori nei nodi dell'albero
int abr_strint_sommanodi(const strint *root)
{ 
  int tot=0;
  if(root!=NULL) {
    tot += abr_strint_sommanodi(root->left);
    tot +=root->n; // contributo di root
    tot += abr_strint_sommanodi(root->right);
  }
  return tot;
}


// stampa tutti gli elementi dell'albero
// che ha come radice root
// facendo una visita in preorder
// il parametro depth è la profondita di root
void abr_strint_stampa_preorder(const strint *root, FILE *f, int depth)
{
  // stampa depth spazi per mostrare la profondità del nodo
  for(int i=0;i<depth;i++) fprintf(f,". ");
  if(root!=NULL) {
    strint_stampa(root,f);
    abr_strint_stampa_preorder(root->left,f,depth+1);
    abr_strint_stampa_preorder(root->right,f,depth+1);
  }
  else fprintf(f,"X\n");
}



// distrugge tutti gli elementi dell'ABR con radice root
void abr_strint_distruggi(strint *root)
{
  if(root!=NULL) {
    abr_strint_distruggi(root->left);
    abr_strint_distruggi(root->right);
    strint_distruggi(root);
  }
}


// inserisci il nuovo nodo "c" dentro l'albero 
// con radice "root", non inserisce se c
// è già presente, restituisce la root
// del nuovo albero contenente anche "c"
strint *abr_inserisci(strint *root, strint *c)
{
  c->left=c->right=NULL;
  // caso base albero vuoto
  if(root==NULL) 
    return c;
  int ris = strcmp(c->s,root->s);
  if(ris==0) {// i nomi sono uguali
    fprintf(stderr, "Nodo duplicato: ");
    strint_stampa(c,stderr);
    strint_distruggi(c);
  }
  else if(ris<0) // c->s < root->s
    root->left = abr_inserisci(root->left,c);
  else // c->s > root->s
    root->right = abr_inserisci(root->right,c);
  return root;
}    
    

// cerca la stringa w dentro l'abr con radice root
// restituisce il puntatore al nodo se trovata
// altrimenti NULL
strint *abr_ricerca(strint *root, char *w)
{
  if(root==NULL) return NULL;
  int cfr = strcmp(w,root->s);
  if(cfr==0) return root;
  else if(cfr<0) // ricerco a sinistra
    return abr_ricerca(root->left,w);
  else // ricerca a destra
    return abr_ricerca(root->right,w);
}

// dato un abr di radice root restituisce
// la sua altezza = numero di livelli =
// profondità massima di una foglia
int abr_altezza(strint *root)
{
  if(root==NULL) return 0;
  int hl = abr_altezza(root->left);
  int hr = abr_altezza(root->right);
  return (hl>hr) ? hl+1 : hr+1;
}

