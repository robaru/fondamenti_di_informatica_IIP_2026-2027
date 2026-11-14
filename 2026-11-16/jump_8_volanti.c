// Jump, missione 8: arrivano gli oggetti volanti. Sotto a quelli si passa senza saltare!
// Basta un membro in più nella struct: la quota.

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <string.h> // strcpy()
#include <time.h>   // time()
#include <stdbool.h>
#include "gioco.h"

typedef struct
{
  int altezza;  // 0 = a terra
  int velocita; // positiva = sale, negativa = scende
} Giocatore;

typedef struct
{
  char nome[20];
  char simbolo[8]; // un'emoji non sta in un char: serve una stringa
  int quota;       // la sua riga più bassa: 0 = a terra, più di 0 = vola
  int altezza;     // quante righe è alto
  int punti;       // quanto vale superarlo
  int colonna;     // dove si trova
} Oggetto;

// Prototipi
Oggetto nuovo_oggetto(int colonna);
int colonna_ultimo(Oggetto oggetti[3]);
void disegna(Giocatore giocatore, Oggetto oggetti[3], int punti, char superato[]);
bool scontro(Giocatore giocatore, Oggetto oggetto);

int main()
{
  srand(time(NULL)); // partita diversa a ogni esecuzione

  Giocatore giocatore = {0, 0};

  // tre oggetti a caso, a 15 colonne uno dall'altro
  Oggetto oggetti[3];
  for (int i = 0; i < 3; i++)
  {
    oggetti[i] = nuovo_oggetto(29 + 15 * i);
  }

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

    for (int i = 0; i < 3; i++)
    {
      oggetti[i].colonna--;

      if (scontro(giocatore, oggetti[i]))
      {
        colpito = true;
      }

      // l'oggetto ha appena superato il giocatore
      if (oggetti[i].colonna == 4)
      {
        punti = punti + oggetti[i].punti;
        strcpy(superato, oggetti[i].nome);
      }

      // quando esce a sinistra ne entra uno nuovo, da 12 a 19 colonne dietro l'ultimo
      if (oggetti[i].colonna < 0)
      {
        oggetti[i] = nuovo_oggetto(colonna_ultimo(oggetti) + 12 + rand() % 8);
      }
    }

    disegna(giocatore, oggetti, punti, superato);

    aspetta(80);
  }

  fine_gioco();
  printf("Fine partita! Punti: %d\n", punti);

  return 0;
}

// Un oggetto di un tipo scelto a caso, nella colonna indicata
Oggetto nuovo_oggetto(int colonna)
{
  // i tipi di oggetto: nome, simbolo, quota, altezza, punti (la colonna si decide dopo)
  Oggetto tipi[5] = {
      {"Fungo", "🍄", 0, 1, 1, 0},
      {"Cactus", "🌵", 0, 2, 2, 0},
      {"Albero", "🌲", 0, 3, 3, 0},
      {"Ape", "🐝", 3, 1, 2, 0},      // vola alla riga 3
      {"Fantasma", "👻", 3, 3, 3, 0}  // vola dalla riga 3 alla 5
    };

  // l'assegnazione copia tutti i membri della struct, anche le stringhe
  Oggetto oggetto = tipi[rand() % 5];
  oggetto.colonna = colonna;

  return oggetto;
}

// La colonna dell'oggetto più a destra: è il massimo di un array
int colonna_ultimo(Oggetto oggetti[3])
{
  int massimo = oggetti[0].colonna;

  for (int i = 1; i < 3; i++)
  {
    if (oggetti[i].colonna > massimo)
    {
      massimo = oggetti[i].colonna;
    }
  }

  return massimo;
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
        // l'oggetto occupa le righe da quota a quota + altezza - 1
        if (colonna == oggetti[i].colonna &&
            riga >= oggetti[i].quota &&
            riga < oggetti[i].quota + oggetti[i].altezza)
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

// Vero se l'oggetto è nella colonna del giocatore e il giocatore è a una delle sue righe
bool scontro(Giocatore giocatore, Oggetto oggetto)
{
  return oggetto.colonna == 5 &&
         giocatore.altezza >= oggetto.quota &&
         giocatore.altezza < oggetto.quota + oggetto.altezza;
}
