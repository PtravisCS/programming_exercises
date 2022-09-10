#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_in_range(int min_num, int max_num) {

  return rand() % (max_num + 1 - min_num) + min_num;

}

void grid_print_num(int i, int num, int cols) {

    if (i % cols == 0) {
      printf("\n");
      printf("%i\t", num);
    } else  {
      printf("%i\t", num);
    } 

    return;

}

void generate_array(const size_t ARR_SIZE, const int MAX_NUM, int * buff) {

  int curr_num = 0;

  for (long unsigned int i = 0; i < ARR_SIZE; i++) {

    curr_num = rand_in_range(0, MAX_NUM);
    buff[i] = curr_num;
  
    grid_print_num(i, curr_num, 7);

  }

}

int find_largest(int * arr, const size_t ARR_SIZE) {

  int largest = 0;
  int index = 0;

  for (long unsigned int j = 0; j < ARR_SIZE; j++) {

    if (arr[j] > largest) {

      largest = arr[j];
      index = j;

    }

  }

  return largest;

}

int main() {

  srand(time(NULL));

  const size_t ARR_SIZE = 100;
  const int MAX_NUM = 1000;
  int arr[ARR_SIZE];

  generate_array(ARR_SIZE, MAX_NUM, arr);

  int largest = find_largest(arr, ARR_SIZE);

  printf("\n\nLargest Entry: %i\n\n", largest);

  return 0;

}
