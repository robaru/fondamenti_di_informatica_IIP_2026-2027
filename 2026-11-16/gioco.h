// gioco.h - funzioni pronte per scrivere un gioco nel terminale.
//
// Non serve leggere questo file: basta sapere cosa fanno queste cinque
// funzioni, come per printf().
//
//   inizia_gioco(colonne, righe);  prepara il terminale (una volta, all'inizio).
//                                  Se il terminale è più piccolo di colonne x righe
//                                  caratteri, stampa un messaggio ed esce.
//   tasto_premuto();               il tasto premuto, oppure 0 se non c'è: non aspetta!
//   torna_in_alto();               riporta il cursore in alto, per ridisegnare
//   aspetta(millisecondi);         mette in pausa il programma
//   fine_gioco();                  rimette a posto il terminale (una volta, alla fine)
//
// Se il terminale resta "strano" dopo un errore: scrivere reset e premere Invio.

#ifndef GIOCO_H
#define GIOCO_H

#include <stdio.h>
#include <stdlib.h>

// Esce se il terminale è più piccolo del necessario (0 = dimensione sconosciuta)
static inline void gioco_controlla_dimensioni(int colonne, int righe,
                                              int colonne_terminale, int righe_terminale)
{
  if (colonne_terminale == 0 || righe_terminale == 0)
  {
    return;
  }

  if (colonne_terminale < colonne || righe_terminale < righe)
  {
    printf("Il terminale è troppo piccolo: servono almeno %d colonne e %d righe,\n",
           colonne, righe);
    printf("ma ce ne sono %d e %d. Allargare la finestra e riprovare.\n",
           colonne_terminale, righe_terminale);
    exit(1);
  }
}

#ifdef _WIN32

// ---------- Windows ----------
#include <conio.h>
#include <windows.h>

static inline void fine_gioco(void)
{
  printf("\033[?25h"); // mostra di nuovo il cursore
  fflush(stdout);
}

static inline void inizia_gioco(int colonne, int righe)
{
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

  CONSOLE_SCREEN_BUFFER_INFO info;
  if (GetConsoleScreenBufferInfo(console, &info))
  {
    gioco_controlla_dimensioni(colonne, righe,
                               info.srWindow.Right - info.srWindow.Left + 1,
                               info.srWindow.Bottom - info.srWindow.Top + 1);
  }

  // attiva i comandi "\033[..." e l'UTF-8 (per le emoji) nella console di Windows
  DWORD modo = 0;
  GetConsoleMode(console, &modo);
  SetConsoleMode(console, modo | 0x0004);
  SetConsoleOutputCP(65001);

  atexit(fine_gioco);
  printf("\033[2J\033[H\033[?25l"); // pulisce lo schermo, nasconde il cursore
  fflush(stdout);
}

static inline char tasto_premuto(void)
{
  char tasto = 0;
  while (_kbhit())
  {
    tasto = (char)_getch();
  }
  return tasto;
}

static inline void aspetta(int millisecondi)
{
  fflush(stdout);
  Sleep(millisecondi);
}

static inline void torna_in_alto(void)
{
  printf("\033[H");
}

#else

// ---------- macOS e Linux ----------
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

static struct termios gioco_terminale_iniziale;
static int gioco_avviato = 0;
static volatile sig_atomic_t gioco_finestra_cambiata = 0;

static inline void fine_gioco(void)
{
  if (gioco_avviato)
  {
    tcsetattr(STDIN_FILENO, TCSANOW, &gioco_terminale_iniziale);
    gioco_avviato = 0;
    printf("\033[?25h"); // mostra di nuovo il cursore
    fflush(stdout);
  }
}

// Ctrl+C o un errore del programma: prima si rimette a posto il terminale
static inline void gioco_interrotto(int segnale)
{
  fine_gioco();
  signal(segnale, SIG_DFL);
  raise(segnale);
}

// La finestra è stata ridimensionata: al prossimo disegno si pulisce lo schermo
static inline void gioco_ridimensionato(int segnale)
{
  (void)segnale;
  gioco_finestra_cambiata = 1;
}

static inline void inizia_gioco(int colonne, int righe)
{
  struct winsize schermo;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &schermo) == 0)
  {
    gioco_controlla_dimensioni(colonne, righe, schermo.ws_col, schermo.ws_row);
  }

  if (tcgetattr(STDIN_FILENO, &gioco_terminale_iniziale) == 0)
  {
    struct termios modo = gioco_terminale_iniziale;
    modo.c_lflag &= ~(ECHO | ICANON); // niente eco, niente attesa di Invio
    modo.c_cc[VMIN] = 0;              // la lettura non aspetta
    modo.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &modo);
    gioco_avviato = 1;

    atexit(fine_gioco);
    signal(SIGINT, gioco_interrotto);
    signal(SIGTERM, gioco_interrotto);
    signal(SIGSEGV, gioco_interrotto);
    signal(SIGFPE, gioco_interrotto);
    signal(SIGWINCH, gioco_ridimensionato);
  }

  printf("\033[2J\033[H\033[?25l"); // pulisce lo schermo, nasconde il cursore
  fflush(stdout);
}

static inline char tasto_premuto(void)
{
  char tasto = 0;
  char letto;

  // se sono stati premuti più tasti, vale l'ultimo
  while (gioco_avviato && read(STDIN_FILENO, &letto, 1) == 1)
  {
    tasto = letto;
  }
  return tasto;
}

static inline void aspetta(int millisecondi)
{
  struct timeval pausa;
  pausa.tv_sec = millisecondi / 1000;
  pausa.tv_usec = (millisecondi % 1000) * 1000;

  fflush(stdout);
  select(0, NULL, NULL, NULL, &pausa);
}

static inline void torna_in_alto(void)
{
  if (gioco_finestra_cambiata)
  {
    gioco_finestra_cambiata = 0;
    printf("\033[2J"); // dopo un ridimensionamento lo schermo va ripulito
  }
  printf("\033[H");
}

#endif

#endif
