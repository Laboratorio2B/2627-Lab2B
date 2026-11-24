/* *********************************************************
 * Esempio uso varabili statiche 
 * ********************************************************* */
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // prototipi delle funzioni per la manipolazione delle stringhe

// Scopo del programma:
// mostrare come le variabili statiche mantengano
// il loro valore da una esecuzione all'altra della funzione


// esempio di funzione con variabile statica
int funz(int x)
{
  static int y=3; // questa inizializzazione avviene solo alla prima esecuzione 
  int z = x+y;
  y += 1;         // il valore di y viene incrementato ad ogni esecuzione 
  if(x==0) y=3;   // ma se x==0 y viene riportato a 3 
  return z;
}

// invoca funz() per ogni intero passato sulla linea di comando 
int main(int argc, char *argv[])
{
  for(int i=1;i<argc;i++) {
    int x = atoi(argv[i]); 
    printf("%d\n",funz(x));
  } 
  return 0;
}
 
