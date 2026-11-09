#include <stdio.h>
#include <string.h>

// dichiarazione: un nuovo tipo fatto di membri di tipo diverso
struct Studente
{
  char nome[50];
  char cognome[50];
  int matricola;
  float media;
};

void stampaStudente(struct Studente s)
{
  printf("%s %s, matricola %d, media %.2f\n", s.nome, s.cognome, s.matricola, s.media);
}

int main()
{
  // 1. operatore di assegnazione, un membro alla volta (per le stringhe serve strcpy!)
  struct Studente mario;
  strcpy(mario.nome, "Mario");
  strcpy(mario.cognome, "Rossi");
  mario.matricola = 123456;
  mario.media = 27.5;

  // 2. lista di inizializzazione (stesso ordine della dichiarazione)
  struct Studente maria = {"Maria", "Bianchi", 654321, 29.5};

  // 3. lista di inizializzazione designata (l'ordine non conta)
  struct Studente anna = {.cognome = "Verdi",
                          .nome = "Anna",
                          .matricola = 111111,
                          .media = 28.7};

  stampaStudente(mario);
  stampaStudente(maria);
  stampaStudente(anna);

  return 0;
}
