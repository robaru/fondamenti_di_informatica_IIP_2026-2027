// Jump, missione 2: l'oggetto si muove verso sinistra e si contano i punti.

#include <stdio.h>
#include <stdbool.h>
#include "gioco.h"

int main()
{
  int altezza = 0;   // altezza del giocatore: 0 = a terra
  int oggetto = 29; // colonna dell'oggetto: parte da destra
  int punti = 0;

  inizia_gioco(60, 10); // servono 60 colonne (30 caselle larghe 2) e 10 righe

  while (true)
  {
    // tastiera
    char tasto = tasto_premuto();
    if (tasto == 'q')
    {
      break;
    }

    // l'oggetto avanza: quando esce a sinistra rientra da destra
    oggetto--;
    if (oggetto < 0)
    {
      oggetto = 29;
      punti++;
    }

    // disegno: dalla riga più alta (6) fino a terra (0)
    torna_in_alto();
    printf("JUMP - punti: %d (q per uscire)\n", punti);
    for (int riga = 6; riga >= 0; riga--)
    {
      for (int colonna = 0; colonna < 30; colonna++)
      {
        if (riga == altezza && colonna == 5)
        {
          printf("🐸");
        }
        else if (riga == 0 && colonna == oggetto)
        {
          printf("🌵");
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
