#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>

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

void sum_or_prod(const int int_num, const long int str_menu_choice) {

  if (str_menu_choice == 1) {

    //Using long long int to ensure we can capture the summation of 1..INT_MAX, it may fit in a long int but better safe than sorry
    long long int sum = int_num * (int_num + 1) / 2;  
    printf("Sum of all numbers between 1 and %i = %li\n", int_num, sum);

  } else {

    long long int product = factorial(int_num);
    printf("Product of all numbers between 1 and %i = %li\n", int_num, product); 

  }

}

void empty_stdin_buffer() {

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}

  return;

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

  int int_num = atoi(str_num);

  return int_num;

}

int rand_in_range(int min_num, int max_num) {

  return rand() % (max_num + 1 - min_num) + min_num;

}

int main(int argc, char * argv) {

  srand(time(NULL));
  const int MIN_NUM = 1;
  const int MAX_NUM = 100;

  int r = rand_in_range(MIN_NUM, MAX_NUM);

  char prompt[100];
  char fail_message[100];
  char length_specifier[5];

  snprintf(prompt, 100, "Guess the number between 1 and 100: ");
  snprintf(fail_message, 100, "Entered string was not valid, please try again.\n");
  snprintf(length_specifier, 5, "%%3s");

  int guess = 0;
  int last_guess = -1000;
  int total_guesses = 0;

  while (guess != r) {

    guess = get_number_s(1, INT_MAX, prompt, fail_message, length_specifier, 21);

    if (guess < r) {
      printf("Too Low\n");
    } else if (guess > r) {
      printf("Too high\n");
    }

    if (guess != last_guess) {
      total_guesses++;
    } 

    last_guess = guess;

  }

  printf("Correct, the number was %i\n", r); 
  printf("You win! It took you %i guesses\n", total_guesses);

  return 0;

}
