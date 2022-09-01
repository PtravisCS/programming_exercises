#include <stdio.h>

int main(int argc, char * argv) {

  char name[200];
  printf("Please provide your name: ");
  scanf("%199s", name);

  printf("Hi %s\n", name);

  return 0;

}
