// Jump, missione 6: giocatore e oggetti diventano struct, gli oggetti sono tre.
// Ogni oggetto superato dà i suoi punti.

#include <stdio.h>
#include <string.h> // strcpy()
#include <stdbool.h>
#include "gioco.h" // libreria per lo schermo e la tastiera

// impostazioni: fuori da ogni funzione, valgono in tutto il programma
const int righe_menu = 1;
const int righe_sfondo = 7;
const int colonne = 30;

const int altezza_giocatore = 1; // riga del giocatore a terra (sotto c'è il pavimento)
const int colonna_giocatore = 5;

const char giocatore_simbolo[5] = "🐸"; // un'emoji occupa 4 byte, più il '\0'
const char cella_vuota[3] = "  ";       // due spazi, più il '\0'

const char tasto_salto = ' ';
const int altezza_salto = 5;   // riga raggiunta saltando
const int lunghezza_salto = 5; // per quanti fotogrammi resta in aria, dopo il primo

// le variabili che "stanno insieme" diventano un tipo solo
typedef struct
{
  int altezza;     // riga in cui si trova adesso
  int frame_salto; // fotogramma in cui è partito l'ultimo salto
} Giocatore;

typedef struct
{
  char nome[20];
  char simbolo[5]; // un'emoji non sta in un char: serve una stringa
  int altezza;     // quante righe è alto, da terra
  int punti;       // quanto vale superarlo
  int colonna;     // dove si trova
} Oggetto;

// Prototipi
void disegna(Giocatore giocatore, Oggetto oggetti[3], int punti, char superato[]);
bool scontro(Giocatore giocatore, Oggetto oggetto);

int main()
{
  const int righe = righe_menu + righe_sfondo + 2; // + pavimento + riga dove finisce il cursore
  inizia_gioco(colonne * 2, righe);                // ogni emoji è larga 2 colonne

  int frame = 0; // quanti fotogrammi sono passati
  int punti = 0;
  char superato[20] = "nessuno"; // nome dell'ultimo oggetto superato

  Giocatore giocatore = {altezza_giocatore, 0};

  // un array di struct: tre oggetti diversi, a 15 colonne uno dall'altro
  Oggetto oggetti[3] = {
      {"Fungo", "🍄", 1, 1, 30},
      {"Cactus", "🌵", 2, 2, 45},
      {"Albero", "🌲", 3, 3, 60}
    };

  bool collisione = false;

  // si gioca finché il giocatore non tocca un oggetto
  while (!collisione)
  {
    pulisci_schermo();

    // giocatore: quando il salto è finito torna a terra
    bool salto_finito = (frame - giocatore.frame_salto > lunghezza_salto);
    if (salto_finito)
    {
      giocatore.altezza = altezza_giocatore;
    }

    // tastiera: tasto_premuto() non aspetta, se non c'è un tasto dà 0
    char tasto = tasto_premuto();
    if (tasto == 'q')
    {
      break;
    }
    else if (tasto == tasto_salto && salto_finito) // se sta già saltando, non salta di nuovo
    {
      giocatore.frame_salto = frame;
      giocatore.altezza = altezza_salto;
    }

    // lo stesso codice, ripetuto per ogni oggetto
    for (int i = 0; i < 3; i++)
    {
      oggetti[i].colonna--;

      if (scontro(giocatore, oggetti[i]))
      {
        collisione = true;
      }

      // l'oggetto ha appena superato il giocatore: salto riuscito!
      if (oggetti[i].colonna == colonna_giocatore - 1)
      {
        punti = punti + oggetti[i].punti;
        strcpy(superato, oggetti[i].nome);
      }

      // quando esce a sinistra rientra da destra, a 15 colonne dall'ultimo
      if (oggetti[i].colonna < 0)
      {
        oggetti[i].colonna = 45;
      }
    }

    disegna(giocatore, oggetti, punti, superato);

    // 80 millisecondi: circa 12 fotogrammi al secondo
    frame++;
    aspetta(80);
  }

  fine_gioco();
  printf("Fine partita! Punti: %d\n", punti);

  return 0;
}

// Disegna il menu, lo sfondo con giocatore e oggetti, e il pavimento
void disegna(Giocatore giocatore, Oggetto oggetti[3], int punti, char superato[])
{
  printf("Menu - punti: %d - ultimo superato: %-8s\n", punti, superato);

  // dalla riga più alta fino alla riga 1
  for (int riga = righe_sfondo; riga > 0; riga--)
  {
    for (int colonna = 0; colonna < colonne; colonna++)
    {
      char simbolo[5];
      strcpy(simbolo, cella_vuota);

      // l'oggetto occupa le righe da 1 alla sua altezza
      for (int i = 0; i < 3; i++)
      {
        if (colonna == oggetti[i].colonna && riga <= oggetti[i].altezza)
        {
          strcpy(simbolo, oggetti[i].simbolo);
        }
      }

      if (riga == giocatore.altezza && colonna == colonna_giocatore)
      {
        strcpy(simbolo, giocatore_simbolo);
      }

      printf("%s", simbolo);
    }
    printf("\n");
  }

  // pavimento
  for (int colonna = 0; colonna < colonne; colonna++)
  {
    printf("--");
  }
  printf("\n");
}

// Vero se l'oggetto è nella colonna del giocatore e il giocatore non è sopra
bool scontro(Giocatore giocatore, Oggetto oggetto)
{
  return oggetto.colonna == colonna_giocatore && giocatore.altezza <= oggetto.altezza;
}
