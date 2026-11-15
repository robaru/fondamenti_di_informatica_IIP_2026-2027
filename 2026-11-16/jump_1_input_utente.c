// Jump, missione 1: la tastiera. Con q si esce dal gioco.

#include <stdio.h>
#include <stdbool.h>
#include "gioco.h" // libreria per lo schermo e la tastiera

int main()
{
  // impostazioni: scritte una volta sola, qui in cima
  const int righe_menu = 1;
  const int righe_sfondo = 7;
  const int colonne = 30;
  const int righe = righe_menu + righe_sfondo + 2; // + pavimento + riga dove finisce il cursore

  const int altezza_giocatore = 1; // riga del giocatore a terra (sotto c'è il pavimento)
  const int colonna_giocatore = 5;

  const char giocatore[5] = "🐸";   // un'emoji occupa 4 byte, più il '\0'
  const char cella_vuota[3] = "  "; // due spazi, più il '\0'

  inizia_gioco(colonne * 2, righe); // ogni emoji è larga 2 colonne

  int frame = 0; // quanti fotogrammi sono passati

  // non so quanti giri farò: while
  while (true)
  {
    pulisci_schermo();

    // tastiera: tasto_premuto() non aspetta, se non c'è un tasto dà 0
    char tasto = tasto_premuto();
    if (tasto == 'q')
    {
      break;
    }

    printf("Menu - frame: %d (q per uscire)\n", frame);

    // sfondo e giocatore: dalla riga più alta fino alla riga 1
    for (int riga = righe_sfondo; riga > 0; riga--)
    {
      for (int colonna = 0; colonna < colonne; colonna++)
      {
        if (riga == altezza_giocatore && colonna == colonna_giocatore)
        {
          printf("%s", giocatore);
        }
        else
        {
          printf("%s", cella_vuota);
        }
      }
      printf("\n");
    }

    // pavimento
    for (int colonna = 0; colonna < colonne; colonna++)
    {
      printf("--");
    }
    printf("\n");

    // 80 millisecondi: circa 12 fotogrammi al secondo
    frame++;
    aspetta(80);
  }

  fine_gioco();

  return 0;
}
