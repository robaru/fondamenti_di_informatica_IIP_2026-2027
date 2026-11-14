// Jump, missione 6: giocatore e oggetti diventano struct, gli oggetti sono tre.
// Ogni oggetto superato dà i suoi punti.

#include <stdio.h>
#include <string.h> // strcpy()
#include <stdbool.h>
#include "gioco.h"

// le variabili che "stanno insieme" diventano un tipo solo
typedef struct
{
  int altezza;  // 0 = a terra
  int velocita; // positiva = sale, negativa = scende
} Giocatore;

typedef struct
{
  char nome[20];
  char simbolo[8]; // un'emoji non sta in un char: serve una stringa
  int altezza;     // quante righe è alto
  int punti;       // quanto vale superarlo
  int colonna;     // dove si trova
} Oggetto;

// Prototipi
void disegna(Giocatore giocatore, Oggetto oggetti[3], int punti, char superato[]);
bool scontro(Giocatore giocatore, Oggetto oggetto);

int main()
{
  Giocatore giocatore = {0, 0};

  // un array di struct: tre oggetti diversi, a 15 colonne uno dall'altro
  Oggetto oggetti[3] = {
      {"Fungo", "🍄", 1, 1, 29},
      {"Cactus", "🌵", 2, 2, 44},
      {"Albero", "🌲", 3, 3, 59}
    };

  int punti = 0;
  char superato[20] = "nessuno"; // nome dell'ultimo oggetto superato
  bool colpito = false;

  inizia_gioco(60, 10); // servono 60 colonne (30 caselle larghe 2) e 10 righe

  while (!colpito)
  {
    // tastiera
    char tasto = tasto_premuto();
    if (tasto == 'q')
    {
      break;
    }

    // il salto parte solo se il giocatore è a terra
    if (tasto == ' ' && giocatore.altezza == 0)
    {
      giocatore.velocita = 3;
    }

    // la velocità cambia l'altezza, la gravità cambia la velocità
    giocatore.altezza = giocatore.altezza + giocatore.velocita;
    if (giocatore.altezza > 0)
    {
      giocatore.velocita = giocatore.velocita - 1;
    }
    else
    {
      giocatore.altezza = 0;
      giocatore.velocita = 0;
    }

    // lo stesso codice, ripetuto per ogni oggetto
    for (int i = 0; i < 3; i++)
    {
      oggetti[i].colonna--;

      if (scontro(giocatore, oggetti[i]))
      {
        colpito = true;
      }

      // l'oggetto ha appena superato il giocatore: salto riuscito!
      if (oggetti[i].colonna == 4)
      {
        punti = punti + oggetti[i].punti;
        strcpy(superato, oggetti[i].nome);
      }

      // quando esce a sinistra rientra da destra, a 15 colonne dall'ultimo
      if (oggetti[i].colonna < 0)
      {
        oggetti[i].colonna = 44;
      }
    }

    disegna(giocatore, oggetti, punti, superato);

    aspetta(80);
  }

  fine_gioco();
  printf("Fine partita! Punti: %d\n", punti);

  return 0;
}

void disegna(Giocatore giocatore, Oggetto oggetti[3], int punti, char superato[])
{
  torna_in_alto();
  printf("JUMP - punti: %d - ultimo superato: %-8s\n", punti, superato);

  // dalla riga più alta (6) fino a terra (0)
  for (int riga = 6; riga >= 0; riga--)
  {
    for (int colonna = 0; colonna < 30; colonna++)
    {
      char simbolo[8] = "  "; // casella vuota: due spazi, larga come un'emoji

      for (int i = 0; i < 3; i++)
      {
        if (colonna == oggetti[i].colonna && riga < oggetti[i].altezza)
        {
          strcpy(simbolo, oggetti[i].simbolo);
        }
      }

      if (colonna == 5 && riga == giocatore.altezza)
      {
        strcpy(simbolo, "🐸");
      }

      printf("%s", simbolo);
    }
    printf("\n");
  }
  printf("------------------------------------------------------------\n");
}

// Vero se l'oggetto è nella colonna del giocatore e il giocatore non è sopra
bool scontro(Giocatore giocatore, Oggetto oggetto)
{
  return oggetto.colonna == 5 && giocatore.altezza < oggetto.altezza;
}
