/* *********************************************************
 * Esempio di uso di qsort per ordinare array di interi 
 * ********************************************************* */
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <errno.h>    // richiesto per usare errno


// stampa un messaggio di errore e termina
void termina(const char *messaggio);

// funzione di confronto, con i tipi corretti
// necessita del casting al tipo __compar_fn_t
// nella chiamata del qsort altrimenti il compilatore
// da un warning
int confronta(int *a, int *b)
{
  if(*a<*b) return -1;
  else if(*a>*b) return 1;
  return 0; 
}

// funzione di confronto con i tipi richiesti da qsort
// ma deve essere fatta una conversione a int * 
// per effettuare la dereferenziazione e il
// confronto degli interi. In questo caso il
// casting alla chiamata del qsort non è necessario. 
// Attenzione che se sbaglio la conversione
// il compilatore non lo può rilevare (ad esempio
// se scrivo `const double *a = aa`) 
int vconfronta(const void *aa, const void *bb)
{
  const int *a = aa;
  const int *b = bb;
  if(*a<*b) return -1;
  else if(*a>*b) return 1;
  return 0; 
}


// funzione di confronto che ordina mettendo prima tutti i pari
// e successivamente tutti i dispari  
int confrontapd(int *a, int *b)
{
  // i pari prima dei dispari
  if(*a%2==0 && *b%2!=0) return -1;
  if(*a%2!=0 && *b%2==0) return 1;
  // ora dovrebbero esere entrambi pari o entrambi dispari
  assert( (*a%2==0 && *b%2==0) || 
          (*a%2!=0 && *b%2!=0));
  // ordinamento in ordine crescente        
  if(*a<*b) return -1;
  else if(*a>*b) return 1;
  return 0; 
}


int main(int argc, char *argv[])
{
  if(argc<=2) {  // input sulla linea di comando non corretto
    printf("Uso: %s i1 i2 i3 ... ik \n",argv[0]);
    return 1;
  }
  int n = argc-1; // Numero argomenti linea di comando
  // alloco array dinamico
  int *a = malloc(n*sizeof(int));
  if(a==NULL) termina("Memoria insufficiente");
  // riempio con interi passati sulla linea di comando
  for(int i=0;i<n;i++) 
    a[i] = atoi(argv[i+1]);

  // stampo array
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  puts(""); // a capo 

  // eseguo il sorting degli interi con qsort()
  // come spiegato a lezione per l'ultimo argomento ci vuole il casting  
  qsort(a,n,sizeof(*a), &vconfronta); 

  // stampo array
  puts("--- qsort 1 eseguito ---");
  for(int i=0;i<n;i++) printf("%d ",a[i]);
  puts(""); // a capo 

  qsort(a,n,sizeof(*a), (__compar_fn_t) &confrontapd); 
  // stampo array
  puts("--- qsort 2 eseguito ---");
  for(int i=0;i<n;i++) printf("%d ",a[i]);
  puts(""); // a capo 


  
  // libero la memoria usata dall'array a[]
  free(a);

  return 0;
}


// stampa su stderr il messaggio che gli passo
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
