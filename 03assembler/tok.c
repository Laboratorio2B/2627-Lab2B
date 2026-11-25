#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe

// emulazione della funzione strtok in assembler
char *miatok(char *s, int delim);

void termina(const char *messaggio)
{
  puts(messaggio);
  exit(1);
}

// tokenizza la stringa argv[1] passandola a miatok 
int main(int argc, char *argv[])
{
  if(argc==2) {
    char *tok = miatok(argv[1],',');
    while(tok!=NULL) {
      puts(tok);
      tok = miatok(NULL,',');
    }
    // verifico che anche la successiva chiamata a miatok restituisca NULL
    assert(miatok(NULL,',')==NULL);
  }
  else 
    printf("Uso: %s stringa\n",argv[0]);
  return 0;
}


// modello di funzione strtok usato per
// la miatok in tok.s
char *modello(char *r0, int r1) 
{
  static char *sospesa = NULL;
  if(r1=='\0') exit(10);

  if(r0==NULL) {
    r0 = sospesa; // recupera tok precedente
    if(r0==NULL)  // se c'era qualcosa in sospeso
      return NULL;
  }  
  // eseguo parsing da r0 in poi
  while(*r0 == r1) // salta eventuali delimitaori
    r0 += 1 ;      // avanza dentro la stringa
  // ora *r0 non è un delimitatore
  if(*r0=='\0') {
    sospesa = NULL; // non ci sono altri token
    return NULL;
  }
  // trovato carattere diverso da \0 e r1
  char *r3 = r0; //salva copia di r0
  while(true) {  //copia posizione di inizio token
    r3 +=1;
    char r12 = *r3;
    if(r12=='\0') {
      sospesa = NULL; // raggiunto ultimo token
      break;
    }
    if(r12==r1) {  // raggiunto delimitatore
      *r3 = '\0';  // sovrascrivo \0 sul delimitatore
      r3 +=1;
      sospesa = r3;
      break;
    }
  }
  return r0;
}



