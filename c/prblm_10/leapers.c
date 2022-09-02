#include <stdio.h>
#include <time.h>

int is_leap_year(int year) {

  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {

    return 1;

  } else {

    return 0;

  }

}

int main() {

  time_t unix_time = time(NULL);
  struct tm * current_time = localtime(&unix_time);

  const int CURR_YEAR = current_time->tm_year + 1900;
  const int NUM_YEARS_TO_CHECK = 20;

  for (int i = CURR_YEAR; i < CURR_YEAR + NUM_YEARS_TO_CHECK; i++) {

    if (is_leap_year(i) == 1) {

      printf("%i is a leap year\n", i);

    }

  }

  return 0;

}
