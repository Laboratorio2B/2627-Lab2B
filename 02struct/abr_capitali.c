#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno
#include <math.h>

// Scopo del programma:
//   imparare a costruire, visualizzare e distruggere 
//   gli alberi binari di ricerca in C 


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);


// definizione struct che rappresenta
// una città con nome, e coordinate 
// + campi left/right per costruire l'albero 
typedef struct capit {
  char *nome;
  double lat;
  double lon;
  struct capit *left, *right;
} capitale;


void capitale_stampa(const capitale *a, FILE *f) {
  fprintf(f,"%-16s (%f,%f)\n",a->nome,a->lat,a->lon);
}

capitale *capitale_crea(char *s, double lat, double lon)
{
  capitale *a  = malloc(sizeof(*a));
  a->lat = lat;
  a->lon = lon;
  a->nome = strdup(s); // creo una copia di s e l'assegno al nome
  a->left = a->right = NULL;
  return a;
}

void capitale_distruggi(capitale *a)
{
  free(a->nome);
  free(a);
}

// stampa tutti gli elementi dell'albero
// che ha come radice root
void abr_capitale_stampa(const capitale *root, FILE *f)
{
  if(root!=NULL) {
    abr_capitale_stampa(root->left,f);
    capitale_stampa(root,f);
    abr_capitale_stampa(root->right,f);
  }
}

// stampa tutti gli elementi dell'albero
// che ha come radice root
// facendo una visita in preorder
// il parametro depth è la profondita di root
void abr_capitale_stampa_preorder(const capitale *root, FILE *f, int depth)
{
  // stampa depth spazi per mostrare la profondità del nodo
  for(int i=0;i<depth;i++) fprintf(f,". ");
  if(root!=NULL) {
    capitale_stampa(root,f);
    abr_capitale_stampa_preorder(root->left,f,depth+1);
    abr_capitale_stampa_preorder(root->right,f,depth+1);
  }
  else fprintf(f,"X\n");
}



// distrugge tutti gli elementi dell'ABR con radice root
void abr_capitale_distruggi(capitale *root)
{
  if(root!=NULL) {
    abr_capitale_distruggi(root->left);
    abr_capitale_distruggi(root->right);
    capitale_distruggi(root);
  }
}


// legge un oggetto capitale dal file f
// restituisce il puntatore all'oggetto letto
// oppure NULL se non riesce a leggere dal file
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

// inserisci il nuovo nodo "c" dentro l'albero 
// con radice "root", non inserisce se c
// è già presente, restituisce la root
// del nuovo albero contenente anche "c"
// il criterio di ordinamento è quello lessicografico
// sul nome della capitale
capitale *abr_inserisci(capitale *root, capitale *c)
{
  assert(c!=NULL);
  c->left=c->right=NULL;
  // caso base albero vuoto
  if(root==NULL) 
    return c;
  int ris = strcmp(c->nome,root->nome);
  if(ris==0) {// i nomi sono uguali
    fprintf(stderr, "Nodo duplicato: ");
    capitale_stampa(c,stderr);
    capitale_distruggi(c);
  }
  else if(ris<0) // c->nome < root->nome
    root->left = abr_inserisci(root->left,c);
  else // c->nome > root->nome
    root->right = abr_inserisci(root->right,c);
  return root;
}    
    

// crea un abr con gli oggetti capitale letti da 
// *f inserendoli usando l'ordinamento dei nomi 
capitale *crea_abr(FILE *f)
{
  capitale *root=NULL;
  while(true) {
    capitale *b = capitale_leggi(f);
    if(b==NULL) break;
    // inserisco b dentro l'ABR
    root = abr_inserisci(root,b);
  }  
  return root;
}

// cerca la città nome dentro l'abr con radice root
// restituisce il puntatore alla città se trovata
// altrimenti NULL
capitale *abr_ricerca(capitale *root, char *nome)
{
  if(root==NULL) return NULL;
  int cfr = strcmp(nome,root->nome);
  if(cfr==0) return root;
  else if(cfr<0) // ricerco a sinistra
    return abr_ricerca(root->left,nome);
  else // ricerca a destra
    return abr_ricerca(root->right,nome);
}

// dato un abr di radice root restituisce
// la sua altezza = numero di livelli =
// profondità massima di una foglia
int abr_altezza(capitale *root)
{
  if(root==NULL) return 0;
  int hl = abr_altezza(root->left);
  int hr = abr_altezza(root->right);
  return (hl>hr) ? hl+1 : hr+1;   // operatore ternario di confronto 
}

// restituisce true se c ha latitudine tra 40 e 43
bool latrange(capitale *c)
{
  assert(c!=NULL);
  return (c->lat>=40.0) && (c->lat <= 43.0);
}

// stampa i nodi dell'albero con radice r 
// per cui la funzione funz restituisce true
void abr_stampa_cond(capitale *r, FILE *f, 
                     bool (*funz)(capitale *))
{
  if(r==NULL) return;
  abr_stampa_cond(r->left,f,funz);
  if(funz(r))
    capitale_stampa(r,f);
  abr_stampa_cond(r->right,f,funz);
}


int main(int argc, char *argv[])
{
  if(argc<2) {
    printf("Uso: %s nomefile [nome1 nome2 ...]\n",argv[0]);
    exit(1);
  } 
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) termina("Errore apertura file");

  // costruzione albero leggendo capitali dal file
  capitale *root=crea_abr(f);
  if(fclose(f)==EOF)
    termina("Errore chiusura");
  puts("--- inizio lista (alfabetica) ---");
  // stampa elenco capitali dall'abr creato
  abr_capitale_stampa(root,stdout);  
  puts("--- fine lista ---");
  puts("--- inizio lista (struttura dell'albero) ---");
  abr_capitale_stampa_preorder(root,stdout,0);  
  puts("--- fine lista ---");
  printf("Altezza albero: %d\n",abr_altezza(root));
  // esegue la ricerca delle città passate sulla linea di comando
  for(int i=2;i<argc;i++) {
    capitale *c = abr_ricerca(root,argv[i]);
    if(c==NULL) 
      printf("%s non trovata\n",argv[i]);
    else {
      printf("Trovata: ");
      capitale_stampa(c,stdout);
    }
  }
  // stampa condizionale
  puts("--- elenco città con latitudine in [40,43] ---");
  abr_stampa_cond(root,stdout,&latrange);
  
  abr_capitale_distruggi(root);

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

