#include <stdio.h>

// con typedef possiamo scrivere "Pezzo" invece di "struct Pezzo"
typedef struct
{
  char nome[30];
  float peso_kg; // peso di un singolo pezzo
  int quantita;
} Pezzo;

int main()
{
  // un array di struct: i pezzi di una bicicletta
  Pezzo bici[4] = {
      {"Telaio", 2.0, 1},
      {"Ruota", 1.2, 2},
      {"Pedale", 0.3, 2},
      {"Sella", 0.4, 1}
    };

  float peso_totale = 0.0;

  for (int i = 0; i < 4; i++)
  {
    float peso = bici[i].peso_kg * bici[i].quantita;
    peso_totale = peso_totale + peso;

    printf("%-8s x %d -> %.2f kg | tot %.2f kg\n", bici[i].nome, bici[i].quantita, peso, peso_totale);
  }

  printf("Peso totale della bici: %.2f kg\n", peso_totale);

  return 0;
}
