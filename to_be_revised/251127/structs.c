#include <stdio.h>
#include <string.h>

struct Student
{
  char first_name[50];
  char last_name[50];
  int id;
  float grade_average;
};

void printStudent(struct Student s)
{
  printf("Name:      %s\n", s.first_name);
  printf("Surname:   %s\n", s.last_name);
  printf("ID:        %d\n", s.id);
  printf("Grade avg: %.2f\n", s.grade_average);
}

int main()
{
  struct Student mattia;
  strcpy(mattia.first_name, "Mattia");
  strcpy(mattia.last_name, "Guidolin");
  mattia.id = 123456;
  mattia.grade_average = 27.5;

  printf("Mattia:\n");
  printStudent(mattia);

  struct Student marco = {"Marco", "Bianchi", 54321, 29.5};

  printf("Marco:\n");
  printStudent(marco);

  struct Student francesca = {.last_name = "Lastname", .first_name = "Francesca", .id = 111111, .grade_average = 28.7};

  printf("Francesca:\n");
  printStudent(francesca);

  return 0;
}
