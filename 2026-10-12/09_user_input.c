#include <stdio.h>

int main()
{
  // int age;
  // printf("How old are you?\n");
  // scanf("%d", &age);
  // printf("You are %d years old\n", age);

  int hh, mm, ss;
  printf("What time is it?\n");
  scanf("%d:%d:%d", &hh, &mm, &ss);

  int minutes_in_hour = 60;
  int seconds_in_minute = 60;
  int tot_secs = seconds_in_minute * (minutes_in_hour * hh + mm) + ss;
  printf("%d seconds have passed since midnight\n", tot_secs);

  return 0;
}
