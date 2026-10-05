#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// #define DEBUG

enum Ball
{
  POKEBALL = 1,
  GREATBALL,
  ULTRABALL
};

int main()
{
  srand(time(NULL));

  enum Ball ball = POKEBALL;
  unsigned int attempts = 0;
  unsigned int catch_rate_base = 20;
  unsigned int catch_rate_total = 0;

  bool is_shiny = false;
  unsigned int roll = 0;

  unsigned int shiny_roll = rand() % 4096;
  if (shiny_roll == 0)
  {
    is_shiny = true;
    catch_rate_base *= 0.5;
  }

#ifdef DEBUG
  printf("[ shiny_roll = %u ]\n", shiny_roll);
#endif

  printf("Suddenly a wild Pikachu appears");
  if (is_shiny)
  {
    printf("... AND IT'S SHINY!!!\n");
  }
  else
  {
    printf("!\n");
  }

  do
  {
    roll = (rand() % 100) + 1;

#ifdef DEBUG
    printf("[ roll = %u ]\n", roll);
#endif

    printf("\nChoose a ball:\n");
    printf("1. Pokeball\n");
    printf("2. Great ball\n");
    printf("3. Ultra ball\n");
    printf("Choice: ");
    scanf("%d", &ball);

    switch (ball)
    {
    case POKEBALL:
      catch_rate_total = (unsigned)(catch_rate_base * 1);
      break;
    case GREATBALL:
      catch_rate_total = (unsigned)(catch_rate_base * 1.5);
      break;
    case ULTRABALL:
      catch_rate_total = (unsigned)(catch_rate_base * 2);
      break;
    default:
      printf("Wrong ball!\n");
      catch_rate_total = 0;
      break;
    }

    attempts++;

    if (roll <= catch_rate_total)
    {
      printf("\nYou caught it!\n");
      printf("It took %u attempts!\n", attempts);
    }
    else
    {
      printf("\nThe pokemon escaped!\n");
    }
  } while (roll > catch_rate_total);

  return 0;
}
