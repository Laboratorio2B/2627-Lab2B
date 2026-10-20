#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno


// Scopo del programma:
//   Mostrare come si definiscono e usano le struct
//   e gli array di struct


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);


// keyword typedef: per definire sinonimi di tipi esistenti
// ad esempio posso metetre le istruzioni (fuori da ogni funzione)
typedef int intero;
typedef int *puntatore_a_int;
// e nel resto del programma posso scrivere "intero" invece di "int"
// e "puntatore_a_int" invece di "int *"


// keyword struct: definisce tipi composti da più campi
struct terna {
  int primo;
  int secondo;
  double terzo;
};

// da questo momento possiamo dichiarare variabili di tipo "struct terna"
// esempio:
//    struct terna x,y,z;    


// E' molto frequente l'uso combinato di struct 
// (definisce nuovi tipi) e typedef (definisce un sinonimo)
// Esempio: definisco la struct duetto
// e dico che coppia è sinonimo di struct duetto
typedef struct duetto {
  int primo;
  int secondo;
} coppia;
// nel resto del programma posso usare liberamente "coppia" o "struct duetto"
// nel seguito li useremo entrambi, nella pratica si usa la versione corta "coppia"

// prototipo della funzione mergesort per
// ordinare un array di coppie
void mergesort(coppia a[], int n);


// Esempi di funzioni che utilizzano struct

// funzione che scambia le componenti: il parametro d è passato per valore 
// quindi la funzione opera su una copia locale di d
// e la modifica senza effetti sul chiamante
struct duetto scambia(struct duetto d)
{ 
  intero tmp = d.primo;
  d.primo = d.secondo;
  d.secondo = tmp;
  return d;
}


// stampa su f la coppia passata per valore 
void coppia_stampa(coppia a, FILE *f) {
  fprintf(f,"(%d,%d)\n",a.primo,a.secondo);
}

// stampa su f la coppia passata per indirizzo
// const indica che la funzione non può modificare
// la coppia a cui punta il parametro "a"
// si passa il parametro per indirizzo per evitare di fare 
// una copia della struct che potrebbe avere molti campi ed  
// essere molto grande (in questo caso no: sono 2 interi = 8 byte)
void pcoppia_stampa(const coppia *a, FILE *f) {
  fprintf(f,"(%d,%d)\n",(*a).primo,(*a).secondo);
}


// incrementa di 1 entrambe le componenti della coppia
// il parametro a è passato per indirizzo
// quindi la funzione modifica la coppia a cui punta a
void incrementa(coppia *a) {
  (*a).primo +=1;  // come visto a lezione le parentesi sono necessarie
  a->secondo +=1;  // l'uso di a-> al posto di (*a). è equivalente e molto usato
}


// esempio di costruzione di un array di coppie di uso delle funzioni
// viste sopra e della funzione mergesort per ordinare le coppie
// per somma dei campi crescente
int main(int argc, char *argv[])
{
  coppia *a;

  if(argc <3 || argc%2==0) {
    printf("Uso:\n\t %s un numero positivo e pari di interi\n",argv[0]);
    exit(1);
  } 
  int n = (argc-1)/2;  // n == dimensione di a  == numero coppie
  a = malloc(n*sizeof(coppia));
  if(a==NULL) termina("allocazione fallita");

  // crea l'array e incrementa di 1 entrambe le componenti di ogni coppia
  for(int i=0;i<n;i++) {
    a[i].primo = atoi(argv[2*i+1]);
    a[i].secondo = atoi(argv[2*i+2]);  
    incrementa(&a[i]); // passaggio per riferimento!
  }

  // stampa le coppie: uso entrambe le funzioni di stampa che ho definito
  // di solito si definisce e si usa solo quella che stampa per indirizzo  
  for(int i=0;i<n;i++)
   if(i%2==0)
      coppia_stampa(a[i], stdout);
    else   
      pcoppia_stampa(&a[i], stdout);

  // ordino le coppie con mergesort e stampo array ordinato
  fprintf(stderr,"--- eseguo l'ordinamento\n");
  mergesort(a,n);
  for(int i=0;i<n;i++)
    pcoppia_stampa(&a[i], stdout);
 
  // infine mostriamo l'uso di scambia;
  coppia x,y;
  x = a[0];
  y = scambia(x);
  printf("Coppia x: ");
  pcoppia_stampa(&x, stdout);
  printf("Coppia y: ");
  pcoppia_stampa(&y, stdout);
  // nota: x e y non sono mai da deallocare: 
  // le struct non sono array anche se hanno + componenti!
   
  // abbiamo allocato a[] quindi dobbiamo deallocarlo
  free(a);
  return 0;
}


// stampa su stderr il messaggio che gli passo e termino
void termina(const char *messaggio)
{
  perror(messaggio);
  exit(1);
}

// funzione per il merge di due array in un terzo array già allocato
// merge di a[0...n1-1] e c[0... n2-1] dentro b[]
void merge(coppia a[], int na, coppia c[], int nc, coppia b[])
{
  assert(a!=NULL);
  assert(c!=NULL);
  assert(b!=NULL);
  assert(na>0);
  assert(nc>0);
  
  int i=0; // indice per a[]
  int j=0; // indice per c[]
  int k=0; // indice per b[]
  
  // scorro a[] e c[] e copio il minore in b[]
  while(i<na && j<nc) {
    if(a[i].primo+a[i].secondo <
       c[j].primo+c[j].secondo) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = c[j];
      j++;
    }
    k++;
  }
  
  // copio il resto di a[] in b[]
  while(i<na) {
    b[k] = a[i];
    i++;
    k++;
  }
  
  // copio il resto di c[] in b[]
  while(j<nc) {
    b[k] = c[j];
    j++;
    k++;
  }
  assert(i==na);
  assert(j==nc);
  assert(k==na+nc); 
}

// funzione mergesort ricorsiva
void mergesort(coppia *a, int n)
{
  assert(a!=NULL);
  assert(n>0);
  
  // caso base
  if(n==1) return;
  
  int n1 = n/2;       // dimensione prima parte
  int n2 = n - n1 ;   // dimensione seconda parte
  assert(n1+n2==n);   // verifico che sto considerando tutti gli elementi
  
  // ordino a[0...n1-1]
  mergesort(a,n1);
  // ordino a[n1...n-1]
  mergesort(&a[n1],n2); // &a[n1] potevo scriverlo a+n1
  
  // ora ho le due metà ordinate devo fare il merge
  coppia *b = malloc(n*sizeof(*b));
  if(b==NULL) termina("malloc fallita nel merge");
  merge(a,n1,&a[n1],n2,b);  
  // copio il risultato da b[] ad a[]
  for(int i=0;i<n;i++)
    a[i] = b[i];
  
  free(b); // dealloco array temporaneao b[]
}
