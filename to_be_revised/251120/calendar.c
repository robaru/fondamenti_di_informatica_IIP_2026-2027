#include <stdio.h>

#define AVG_DAYS_PER_MONTH 30.437
#define MONTHS_PER_YEAR 12

enum Month
{
  JAN = 1,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
};

int main()
{
  int dd_born, mm_born, yy_born;
  int dd_today, mm_today, yy_today;

  printf("When were you born    (DD/MM/YYYY)? ");
  scanf("%d/%d/%d", &dd_born, &mm_born, &yy_born);

  if (!(mm_born >= JAN && mm_born <= DEC))
  {
    printf("Error: month out of range\n");
    return 1;
  }

  switch (mm_born)
  {
  case JAN:
  case MAR:
  case MAY:
  case JUL:
  case AUG:
  case OCT:
  case DEC:
    if (!(dd_born >= 1 && dd_born <= 31))
    {
      printf("Error: day out of range\n");
      return 2;
    }
    break;

  case APR:
  case JUN:
  case SEP:
  case NOV:
    if (!(dd_born >= 1 && dd_born <= 30))
    {
      printf("Error: day out of range\n");
      return 2;
    }
    break;

  default:
    if (!(dd_born >= 1 && dd_born <= 29))
    {
      printf("Error: day out of range\n");
      return 2;
    }
    break;
  }

  printf("What's the date today (DD/MM/YYYY)? ");
  scanf("%d/%d/%d", &dd_today, &mm_today, &yy_today);

  if (!(mm_today >= JAN && mm_today <= DEC))
  {
    printf("Error: month out of range\n");
    return 1;
  }

  switch (mm_today)
  {
  case JAN:
  case MAR:
  case MAY:
  case JUL:
  case AUG:
  case OCT:
  case DEC:
    if (!(dd_today >= 1 && dd_today <= 31))
    {
      printf("Error: day out of range\n");
      return 2;
    }
    break;

  case APR:
  case JUN:
  case SEP:
  case NOV:
    if (!(dd_today >= 1 && dd_today <= 30))
    {
      printf("Error: day out of range\n");
      return 2;
    }
    break;

  default:
    if (!(dd_today >= 1 && dd_today <= 29))
    {
      printf("Error: day out of range\n");
      return 2;
    }
    break;
  }

  int yy_diff = yy_today - yy_born;
  int mm_diff = mm_today - mm_born;
  int dd_diff = dd_today - dd_born;
  float dd_age = AVG_DAYS_PER_MONTH * (MONTHS_PER_YEAR * yy_diff + mm_diff) + dd_diff;

  printf("dd_age: %f\n", dd_age);
  printf("\nYou are approximately %d days old!\n", (int)dd_age);

  return 0;
}