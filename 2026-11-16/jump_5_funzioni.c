// Jump, missione 5: lo stesso gioco, con il disegno e lo scontro in due funzioni.

#include <stdio.h>
#include <stdbool.h>
#include "gioco.h"

// Prototipi
void disegna(int altezza, int oggetto, int punti);
bool scontro(int altezza, int oggetto);

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

    disegna(altezza, oggetto, punti);

    if (scontro(altezza, oggetto))
    {
      break;
    }

    aspetta(80);
  }

  fine_gioco();
  printf("Fine partita! Punti: %d\n", punti);

  return 0;
}

// Riceve una copia dei valori: può leggerli, ma non cambiare quelli del main
void disegna(int altezza, int oggetto, int punti)
{
  torna_in_alto();
  printf("JUMP - punti: %d (spazio per saltare, q per uscire)\n", punti);

  // dalla riga più alta (6) fino a terra (0)
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
}

// Vero se l'oggetto è nella colonna del giocatore e il giocatore è a terra
bool scontro(int altezza, int oggetto)
{
  return oggetto == 5 && altezza == 0;
}
