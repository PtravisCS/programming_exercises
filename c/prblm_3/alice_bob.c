#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv) {

  const char NAME_1[] = "alice";
  const char NAME_2[] = "bob";

  char name[200];
  printf("Please provide your name: ");
  scanf("%199s", name);

  for (int i = 0; i < strlen(name); ++i) {

    name[i] = tolower(name[i]);

  }

  if (strcmp(name, NAME_1) == 0 || strcmp(name, NAME_2) == 0) {

    printf("Hi %s\n", name);

  } else {

    printf("Nope\n");

  }


  return 0;

}
