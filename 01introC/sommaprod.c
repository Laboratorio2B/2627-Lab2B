#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe


// esempio di funzione che restituisce 2 valori
// scrive il prodotto a*b nella variabile
// a cui punta p  e restituisce la somma a+b
int sommaprod(int a, int b, int *p)
{
  *p = a*b;
  return a+b;
}

int main(int argc, char *argv[])
{
  // calcolo di somma e prodotto di 6 e 11
  int n=6;
  int m=11;
  int somma, prodotto;
  // per ottenere il prodotto passo il suo indirizzo 
  somma = sommaprod(n,m,&prodotto);
  printf("Somma: %d, prodotto: %d\n",somma,prodotto);
  return 0;
}
