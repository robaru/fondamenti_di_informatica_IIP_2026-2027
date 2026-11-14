// Jump, missione 1: il ciclo del gioco e il disegno.
// Ad ogni giro: leggo la tastiera, disegno, aspetto.

#include <stdio.h>
#include <stdbool.h>
#include "gioco.h"

int main()
{
  int altezza = 0; // altezza del giocatore: 0 = a terra

  inizia_gioco(60, 10); // servono 60 colonne (30 caselle larghe 2) e 10 righe

  // non so quanti giri farò: while
  while (true)
  {
    // tastiera
    char tasto = tasto_premuto();
    if (tasto == 'q')
    {
      break;
    }

    // disegno: dalla riga più alta (6) fino a terra (0)
    torna_in_alto();
    printf("JUMP (q per uscire)\n");
    for (int riga = 6; riga >= 0; riga--)
    {
      for (int colonna = 0; colonna < 30; colonna++)
      {
        if (riga == altezza && colonna == 5)
        {
          printf("🐸");
        }
        else
        {
          printf("  "); // due spazi: un'emoji è larga due caratteri
        }
      }
      printf("\n");
    }
    printf("------------------------------------------------------------\n");

    aspetta(80);
  }

  fine_gioco();

  return 0;
}
