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

long long int sum_divis_by(int num, int end) {

  int count_divis_nums = (end - 1) / num;
  int biggest_divis = num * count_divis_nums;
  int sum = (count_divis_nums * (num + biggest_divis)) / 2;

  return sum;

}



int main(int argc, char ** argv) {

  const int NUM_1 = 3;
  const int NUM_2 = 5;

  char str_num[21];

  printf("Please provide a number between 1 and %i: ", INT_MAX);
  scanf("%20s", str_num);

  while (!isPositiveInt(str_num) || INT_MAX < atoi(str_num) || atoi(str_num) < 0) {
  
    printf("Entered string was not valid, please try again.\n");
    printf("Please provide a number between 1 and %i: ", INT_MAX);
    scanf("%20s", str_num);

  } 

  //using long int to avoid wibbling about with unsigned int instead, a bit memory inefficient, but safer than working with unsigned ints.
  long int int_num = atoi(str_num);

  if (int_num > 0 && int_num <= INT_MAX) {

    //Using long long int to ensure we can capture the summation of 1..INT_MAX, it may fit in a long int but better safe than sorry
    long long int first_sum = sum_divis_by(NUM_1, int_num);
    long long int second_sum = sum_divis_by(NUM_2, int_num);
    long long int combined_sum = sum_divis_by(NUM_1 * NUM_2, int_num);
    long long int total = first_sum + second_sum - combined_sum;

    printf("Sum of all multiples of %i and %i between 1 and %li = %lli\n", NUM_1, NUM_2, int_num, total);

  } 

  return 0;

}

