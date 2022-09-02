#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int isPrime(int num, int curr_num) {

  if (num % curr_num == 0) {
    return 0;
  } else if (curr_num == 2) {
    return 1;
  }

  return isPrime(num, curr_num - 1);

}

int isPrimePrimer(int num) {

  if (num % (num - 1) == 0) {
    return 0;
  }

  return isPrime(num, num - 2);

}

void empty_stdin_buffer() {

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}

  return;

}

int isPositiveInt(const char *string) {

  for (int i = 0; i < strlen(string); ++i) {

    if (isdigit(string[i]) == 0) {
      return 0;
    }

  }

  return 1;

}

int get_number_s(int lower_bound, int upper_bound, char * prompt, char * fail_message, char * length_specifier, int len) {

  char str_num[len];

  printf(prompt);
  scanf(length_specifier, str_num);

  while (!isPositiveInt(str_num) || upper_bound < atoi(str_num) || atoi(str_num) < lower_bound) {
  
    empty_stdin_buffer();
    printf(fail_message);
    printf(prompt);
    scanf(length_specifier, str_num);

  } 

  long int int_num = atol(str_num);

  return int_num;

}

int main(int argc, char * argv) {

  char prompt[100];
  char fail_message[100];
  char length_specifier[5];

  snprintf(prompt, 100, "Test for primes up to which number: ");
  snprintf(fail_message, 100, "Entered string was not valid, please try again.\n");
  snprintf(length_specifier, 5, "%%20s");

  int int_num = get_number_s(1, 1000000000, prompt, fail_message, length_specifier, 21);

  for (int i = 2; i < int_num ; i++) {

    if (isPrimePrimer(i) == 0) {
      printf("%i is not Prime\n", i); 
    } else {
      printf("%i is Prime\n", i);
    }

  }

}





