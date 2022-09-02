#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int isPositiveInt(const char *string) {

  for (int i = 0; i < strlen(string); ++i) {

    if (isdigit(string[i]) == 0) {
      return 0;
    }

  }

  return 1;

}

long long int factorial(const int n) {

  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);

}

int sum_or_prod(const int int_num, const char str_menu_choice) {

  if (str_menu_choice == '1') {

    //Using long long int to ensure we can capture the summation of 1..INT_MAX, it may fit in a long int but better safe than sorry
    long long int sum = int_num * (int_num + 1) / 2;  
    printf("Sum of all numbers between 1 and %i = %li\n", int_num, sum);

  } else {

    long long int product = factorial(int_num);
    printf("Product of all numbers between 1 and %i = %li\n", int_num, product); 

  }

  return 0;

}

int main(int argc, char * argv) {

  char str_num[21];

  printf("Please provide a number between 1 and %i: ", INT_MAX);
  scanf("%20s", str_num);

  while (!isPositiveInt(str_num) || INT_MAX < atoi(str_num) || atoi(str_num) < 0) {
  
    printf("Entered string was not a number, please try again.\n");
    printf("Please provide a number between 1 and %i: ", INT_MAX);
    scanf("%20s", str_num);

  } 

  //using long int to avoid wibbling about with unsigned int, a bit memory inefficient, but safer than working with unsigned ints.
  long int int_num = atoi(str_num);

  char str_menu_choice[3];
  printf("Choose which value to compute\n1. Sum\n2. Product\n> ");
  scanf("%1s", str_menu_choice);
  
  while (str_menu_choice[0] != '1' && str_menu_choice[0] != '2') {

    printf("Invalid menu selection, please select either 1 or 2.\n");
    printf("Please choose which value to compute\n1. Sum\n2. Product\n> ");
    scanf("%1s", str_menu_choice);

  }

  int error = sum_or_prod(int_num, str_menu_choice[0]);

  return 0;

}

