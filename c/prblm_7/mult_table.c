#include <stdio.h>

int main(int argc, char * argv) {

  printf("--------------------\n");
  printf("Multiplication table\n");
  printf("--------------------\n");

  for (int i = 1; i < 13; ++i) {

    for (int j = 1; j < 13; ++j) {
    
        printf("%i\t", i * j);

    }

    printf("\n\n");

  }

}
