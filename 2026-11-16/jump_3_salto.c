// Jump, missione 3: con la barra spaziatrice il giocatore salta.

#include <stdio.h>
#include <stdbool.h>
#include "gioco.h"

int main()
{
  int altezza = 0;   // altezza del giocatore: 0 = a terra
  int velocita = 0;  // positiva = sale, negativa = scende
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

    // il salto parte solo se il giocatore è a terra
    if (tasto == ' ' && altezza == 0)
    {
      velocita = 3;
    }

    // la velocità cambia l'altezza, la gravità cambia la velocità
    altezza = altezza + velocita;
    if (altezza > 0)
    {
      velocita = velocita - 1;
    }
    else
    {
      altezza = 0;
      velocita = 0;
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
    printf("JUMP - punti: %d (spazio per saltare, q per uscire)\n", punti);
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
