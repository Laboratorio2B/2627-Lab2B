#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe

// scopo del programma: illustrare il duplice scopo delle 
// variabili char e introdurre il concetto di stringa come
// array di caratteri che termina al primo byte uguale a 0


// stampa un messaggio d'errore e termina il programma
void termina(char *messaggio)
{
  puts(messaggio);
  exit(1);
}


int main(int argc, char *argv[])
{
  char a,b;

  // ---------- esempio di doppio uso dei char -----
  // inizializza le due variabili char a e b l'intero 70
  // e con il codice ascii del carattere x
  a = 70;
  b = 'x';
  // stampo ogni char interpretandolo come codice ascii (modificatore %c) 
  // e come intero (modificatore %d) 
  printf("variabile a: carattere=%c intero=%d\n"a,a);
  printf("variabile b: carattere=%c intero=%d\n",b,b);
  // ----------------------------------------------
  
  // ------- duplicazione e modifica stringa ------
  // creo una copia della stringa "the answer is 42"
  char *z = strdup("the answer is 42");
  printf("stringa originale: %s, lunghezza %zd\n",z,strlen(z));
  // sia per la printf() che per la strlen()
  // la stringa termina quando si incontra il byte 0 
  z[5] = '\0';   //  equivalente a scrivere z[5] = 0;
  printf("scritto byte 0 in posizione 5: %s, lunghezza %zd\n",z,strlen(z));
  // -----------------------------------------------

  // ----- non ancora fatto !!!!! ------
  // dichiaro il puntatore w e ci metto il valore di z;
  char *w = z;
  printf("w:%s, z:%s\n",w,z);
  w[1] = 'X';
  // dato che w e z puntano alla stessa zona di memoria
  // le modifiche su w valgono anche su z e viceversa
  printf("w:%s, z:%s\n",w,z);
  // -----------------------------

  // la strdup esegue una malloc() quindi devo deallocare con free()
  free(z);
  // free(z) dealloca anche la memoria a cui punta w
  // quindi fare anche free(w) sarebbe un errore
  return 0;
}
