#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno

// Scopo del programma:
//   Mostrare come si definiscono e usano i puntatori a struct
//   in particolare gli array di puntatori a struct


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);


// definizione struct che rappresenta
// una città con nome e coordinate 
typedef struct {
  char *nome;
  double lat;
  double lon;
} capitale;

// crea oggetto capitale a partire dai suoi campi
capitale *capitale_crea(char *s, double lat, double lon)
{
  assert(s!=NULL);
  assert(lat>= -90 && lat <= 90);
  assert(lon>= -180 && lon <= 180);
  capitale *a = malloc(sizeof(*a));
  if(a==NULL) termina("Memoria insufficiente");
  a->nome = strdup(s);
  a->lat = lat;
  a->lon = lon;
  return a;
}
// distrugge (dealloca) un oggetto capitale 
void capitale_distruggi(capitale *a)
{
  free(a->nome);
  free(a);
}


#if 0
// Nota: questa parte di codice fino a #endif non viene compilata

// Avendo definito il tipo capitale, ecco due 
// possibili definizione di array di 100 capitali:
// statico (dimensione immutabile)
capitale a[100];  // ogni a[i] = una capitale  = 24 byte
// dinamico
capitale *a = malloc(100*sizeof(*a));
// dopo aver creato a[] in questo modo, posso modificare gli elementi: 
a[0].lat = 34.2;

// In questo esercizio invece di un array di oggetti di tipo capitale
// lavoreremo invece con un array di puntatori a capitale:
// versione statica
capitale *b[100]; // ogni b[i] = un puntatore = 8 byte
// versione dinamica
capitale **b = malloc(100*sizeof(*b));
// ogni b[i] però è solo un puntatore, non esiste lo spazio
// per i tre campi nome, lat, lon è necessario allocarlo:
b[0] = malloc(sizeof(capitale));
// Dato che b[0] è un puntatore, per settare la latitudine devo scrivere: 
(*b[0]).lat = 43.2;  // corretta, ma non si usa
// oppure:
b[0]->lat = 43.2;    // useremo questa;
#endif


// stampa sul file *f i campi della capitale *a
void capitale_stampa(const capitale *a, FILE *f) {
  fprintf(f,"%20s (%f,%f)\n",a->nome,a->lat,a->lon);
}


// legge un oggetto capitale dal file f
// restituisce il puntatore all'oggetto letto
// oppure NULL se è stato letto tutto il file
capitale *capitale_leggi(FILE *f)
{
  assert(f!=NULL);
  char *s;
  double lat, lon;
  int e = fscanf(f,"%ms %lf %lf",&s,&lat,&lon);
  if(e!=3) {
    if(e==EOF) return NULL; // finito il file non ci sono altri dati
    else termina("Formato input file non valido");
  }
  capitale *c = capitale_crea(s,lat,lon);
  free(s);
  return c;
}

//legge e restituisce un array di capitali *
capitale **capitale_leggi_file(FILE *f, int *num)
{
  assert(f!=NULL);
  int size=10; // dimensione attuale dell'array
  int messi=0; // numero di elementi attualmente nell'array
  capitale **a = malloc(size*sizeof(capitale *));
  if(a==NULL)
    termina("Memoria insufficiente");
    
  while(true) {
    capitale *b = capitale_leggi(f);
    if(b==NULL) break;

    if(messi==size) {
        // ingrandisco l'array
        size = size*2;
        a = realloc(a,size*sizeof(capitale *));
        if(a==NULL)
          termina("realloc fallita");
    }
    assert(messi<size);
    a[messi] = b;
    messi += 1;
  }
  // ho messo tutti gli elementi che mi interessavano
  size = messi;
  a = realloc(a,size*sizeof(capitale *));
  if(a==NULL)
    termina("realloc fallita");
  
  // salvo il numero di elementi e restituisco l'array  
  *num = messi;
  return a;  
}


// --------------------------------------------------------
// ordinamento di un array di puntatori a capitale

// funzione di merge adattata dal merge di array di interi
void merge(capitale *a[], int na, 
           capitale *c[], int nc,
           capitale *b[],
           int (*f)(capitale *a, capitale *b))
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
    // guardo se il nome di a[i] è minore del nome c[j]
    if( f(a[i],c[j]) < 0  ) { // ordinamento secondo f
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



// funzione mergesort ricorsiva, adattata dal mergesort di interi
// è stato sufficiente modificare il tipo da int -> capitale * 
void mergesort(capitale *a[], int n,
               int (*f)(capitale *a, capitale *b))
{
  assert(a!=NULL);
  assert(n>0);
  
  // caso base
  if(n==1) return;
  
  int n1 = n/2;     // dimesione prima parte
  int n2 = n - n1;  // dimensione seconda parte
  
  mergesort(a,n1,f);
  mergesort(&a[n1],n2,f); // &a[n1] potevo scriverlo a+n1
  
  // ho le due metà ordinate devo fare il merge
  capitale **b = malloc(n*sizeof(*b));
  if(b==NULL) termina("malloc fallita nel merge");
  merge(a,n1,&a[n1],n2,b,f);  
  // copio il risultato da b[] ad a[]
  for(int i=0;i<n;i++)
    a[i] = b[i];  // sto copiando dei puntatori 
  
  free(b);
}



// -------------------------------------------------------------
// funzioni di confronto fra puntatori a capitale
// usiamo la convenzione (pres da strcmp)
// che se *a è minore di *b la funzione restituisce <0
// se *a  è maggiore di *b la funzione restituisce >0
// altrimenti sono sono "uguali" rispetto all'ordinamento
// la funzione restituisce 0

// oridina lessicograficamente per nomi crescenti
int confronta_nomi(capitale *a, capitale *b)
{
  return strcmp(a->nome,b->nome);
}

// ordina per longitudine crescente
int confronta_longi(capitale *a, capitale *b)
{
  if (a->lon< b->lon) return -1;
  else if (a->lon> b->lon) return 1;
  return 0; 
}

int main(int argc, char *argv[])
{
  if(argc!=2) {
    printf("Uso: %s nomefile\n",argv[0]);
    exit(1);
  }
  // legge i dati sulle capitali dal file 
  FILE *f = fopen(argv[1],"r");
  int n;
  capitale **a = capitale_leggi_file(f, &n);
  fclose(f);
  
  // ordino elenco capitali alfabeticamente
  mergesort(a,n,&confronta_nomi);

  // stampa elenco capitali
  for(int i=0;i<n;i++)
    capitale_stampa(a[i], stdout);

  puts("-------------");

  // ordino elenco capitali ovest-est
  mergesort(a,n,&confronta_longi);

  // stampa elenco capitali
  for(int i=0;i<n;i++)
    capitale_stampa(a[i], stdout);

  puts("-------------");

  // dealloca le singole capitali e l'array
  for(int i=0;i<n;i++)
    capitale_distruggi(a[i]);
  free(a);
  
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

