#include <stdio.h>

int main()
{
  enum Level
  {
    LOW = 1,
    MEDIUM,
    HIGH
  };

  enum Level battery0_level = MEDIUM;
  // int battery0_level = 1; // 1 is low, 2 is medium, 3 is high

  switch (battery0_level)
  {
  case LOW:
    // case 1:
    printf("Warning, the battery is dying\n");
    break;
  case MEDIUM:
    // case 2:
    printf("Bettery status is ok\n");
    break;
  case HIGH:
    // case 3:
    printf("You just recharded it\n");
    break;
  default:
    printf("You cannot be here\n");
  }

  return 0;
}
