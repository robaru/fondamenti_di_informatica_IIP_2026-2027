// Jump, settings

#include <stdio.h>
#include <stdbool.h>
#include "gioco.h" // includiamo libreria per gestione schermo

int main()
{
  const int altezza_giocatore = 1; // altezza del giocatore: 0 = pavimento
  const int colonna_giocatore = 5; // colonna del giocatore

  const int righe_sfondo = 7;
  const int righe_menu = 1;

  const int righe = altezza_giocatore+righe_sfondo+righe_menu+1;
  const int colonne = 30;
  const char cella_vuota[2] = "  ";
  const char giocatore[5] = "🐸";

  const char tasto_jump = ' ';
  const int lunghezza_salto = 5;
  const int altezza_salto = 5;

  const char oggetto[5] = "🌵";
  const char altezza_oggetto = 1;

  inizia_gioco(colonne*2, righe); // gli emoji occupano 2 spazi

  // continamo quanti frames
  unsigned long frame = 0;

  int altezza_corrente = altezza_giocatore;
  unsigned long frame_salto = 0;

  int colonna_oggetto = colonne;

  bool collisione = false;

  // non so quanti giri farò: while
  while (true)
  {
    pulisci_schermo();

    // gestisci giocatore
    bool salto_finito = (frame - frame_salto > lunghezza_salto);

    if (salto_finito)
      altezza_corrente = altezza_giocatore;

    // gestisti oggetti nello scermo
    colonna_oggetto--;
    // torna all'inizio
    if (colonna_oggetto < 0)
      colonna_oggetto = colonne;

    // tastiera
    char tasto = tasto_premuto();

    // esci
    if (tasto == 'q')
    {
      break;
    } else if(tasto == tasto_jump)
    {
      // se sta già saltando, non aggiornare altezza
      if (salto_finito)
      {
        frame_salto = frame;
        altezza_corrente = altezza_salto;
      }
    }

    if ((altezza_corrente == altezza_oggetto) && (colonna_giocatore == colonna_oggetto))
      collisione = true;
    else
      collisione = false;


    // crea frame corrente ora che sappiamo tutto della situazione
    printf("Menu - collisione %i - frame: %lu\n", collisione, frame);

    // stampa background e giocatore
    for(int r = righe_sfondo; r > 0; r--)
    {
      for(int c = 0; c < colonne; c++)
      {
        if (c == colonna_giocatore && r == altezza_corrente)
          printf("%s", giocatore);
        else if(c == colonna_oggetto && r == altezza_oggetto)
          printf("%s", oggetto);
        else
          printf("%s", cella_vuota);
      }

      printf("\n");
    }


    // pavimento
    printf("------------------------------------------------------------\n");

    // come nei video, ci sono circa 25 frames per secondo ~80ms
    frame++;
    aspetta(200);
  }

  fine_gioco();

  return 0;
}
