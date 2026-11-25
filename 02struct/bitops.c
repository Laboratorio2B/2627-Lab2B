#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe
#include <errno.h>    // richiesto per usare errno

// Scopo del programma:
//  mostrare le operazioni sui bit in C

static void termina(const char *messaggio);


#if 0
Richiamo operatori logici:
  && ||   And e Or logici
usati per conettere due condizioni nei test (if/while/for etc)

Esempio:
a=2
b=9 
a && b -> true in quanto i valori !=0 sono cinsiderati true

Esistono gli stessi operatori in versione "bitwise"

& | ^ bitwise: and, or, xor bitwise

sono simili alle operazioni aritmetiche:
per calcolare il risultato bisogna considerare 
la rappresentazione binaria degli operandi ed 
eseguire le operazioni logiche singolarimente bit a bit:

a =00000011 
b =00001001

a&b -> 00000001
a|b -> 00001011
a^b => 00001010

esiste anche il ~ (not bitwise)
~a = 11111100

osserviamo che se 
a=2 e b=9, mentre 
  a && b = true
abbiamo
  a & b = 0
  
Gli operatori bitwise sono spesso usati insieme a:
  << shift sin
  >> shift dex
Esempi:

b = 00001001
c = b<<3 risulta uguale a 01001000 (equivalenmte a moltiplicare per 2**3 = 8)
mentre:
  c>>2 risulta uguale a 00010010

Importante: in C lo shift destro può essere aritmetico o logico
il comportamento è implementation dependent
d = 110000....1
d>>2
  possiamo ottenere 00110000....
  ma anche          1111000000
e = 001000....1 (il bit più significativo è 0)
e>>2 ottengo sempre 00001000...

per questo motivo lo shift destro deve essere usato con molta attenzione
#endif


// il seguente programma mostra esempi di uso degli operatori bitwise 
// combinati con lo shift


// converte il primo intero passato sulla linea di comando in binario
// e il secondo da binario a decimale 
int main(int argc, char *argv[])
{
  // verifica siano stati forniti due parametri 
  if(argc!=3) {
    printf("Uso: %s intero stringa01\n",argv[0]);
    return 1;
  }
  int n = atoi(argv[1]);

  // conversione intero -> stringa binaria
  // converte ogni bit di n nei caratteri '1' o '0'
  // legge l'iesimo bit con maschera con un solo 1 in posizione i
  printf("argv[1] in 32 bit: ");
  for(int i=31;i>=0;i--) {
    int mask = 1<<i;
    char c = ( (n&mask) !=0  ) ? '1' : '0';
    printf("%c",c);
  }
  puts("");
  
  // conversione stringa binaria argv[2] in intero
  // esempio argv[2] = "100011"
  if(strlen(argv[2])>31)
    termina("Stringa in input troppo lunga");
  n = 0;
  for(int i=0;i<strlen(argv[2]);i++) {
    if(argv[2][i]=='1') {
      // se trovo un '1' nella stringa vado a settare 
      // il bit corrispondente in n
      int mask = 1 << ( strlen(argv[2])-i-1  );
      n = n | mask;
    }
    else if(argv[2][i]!='0') 
      termina("Carattere non valido in argv[2]");
  }
  printf("argv[2] in decimale: %d\n",n);
  
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
