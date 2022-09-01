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

int main(int argc, char * argv) {

  char str_num[21];

  printf("Please provide a number between 1 and %i: ", INT_MAX);
  scanf("%20s", str_num);

  while (!isPositiveInt(str_num) || INT_MAX < atoi(str_num) || atoi(str_num) < 0) {
  
    printf("Entered string was not a number, please try again.\n");
    printf("Please provide a number between 1 and %i: ", INT_MAX);
    scanf("%20s", str_num);

  } 

  //using long int to avoid wibbling about with unsigned int instead, a bit memory inefficient, but safer than working with unsigned ints.
  long int int_num = atoi(str_num);

  if (int_num > 0 && int_num <= INT_MAX) {

    //Using long long int to ensure we can capture the summation of 1..INT_MAX, it may fit in a long int but better safe than sorry
    long long int sum = int_num * (int_num + 1) / 2;  
    printf("Sum of all numbers between 1 and %i = %li\n", int_num, sum);

  } 

  return 0;

}

