// Jump, missione 3: con lo spazio il giocatore salta.
// Il salto dura qualche fotogramma: ricordo in quale fotogramma è partito.

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

  const char oggetto[5] = "🌵";
  const int altezza_oggetto = 1; // l'oggetto sta a terra

  const char tasto_salto = ' ';
  const int altezza_salto = 5;   // riga raggiunta saltando
  const int lunghezza_salto = 5; // per quanti fotogrammi resta in aria, dopo il primo

  inizia_gioco(colonne * 2, righe); // ogni emoji è larga 2 colonne

  int frame = 0; // quanti fotogrammi sono passati
  int punti = 0;

  int altezza_corrente = altezza_giocatore;
  int frame_salto = 0; // fotogramma in cui è partito l'ultimo salto

  int colonna_oggetto = colonne; // parte appena fuori dallo schermo, a destra

  // non so quanti giri farò: while
  while (true)
  {
    pulisci_schermo();

    // giocatore: quando il salto è finito torna a terra
    bool salto_finito = (frame - frame_salto > lunghezza_salto);
    if (salto_finito)
    {
      altezza_corrente = altezza_giocatore;
    }

    // l'oggetto va verso sinistra; quando esce rientra da destra
    colonna_oggetto--;
    if (colonna_oggetto < 0)
    {
      colonna_oggetto = colonne;
      punti++;
    }

    // tastiera: tasto_premuto() non aspetta, se non c'è un tasto dà 0
    char tasto = tasto_premuto();
    if (tasto == 'q')
    {
      break;
    }
    else if (tasto == tasto_salto && salto_finito) // se sta già saltando, non salta di nuovo
    {
      frame_salto = frame;
      altezza_corrente = altezza_salto;
    }

    printf("Menu - punti: %d - frame: %d\n", punti, frame);

    // sfondo, giocatore e oggetto: dalla riga più alta fino alla riga 1
    for (int riga = righe_sfondo; riga > 0; riga--)
    {
      for (int colonna = 0; colonna < colonne; colonna++)
      {
        if (riga == altezza_corrente && colonna == colonna_giocatore)
        {
          printf("%s", giocatore);
        }
        else if (riga == altezza_oggetto && colonna == colonna_oggetto)
        {
          printf("%s", oggetto);
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
