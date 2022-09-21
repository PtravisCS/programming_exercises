#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
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

int find_largest(int * arr, const size_t ARR_SIZE, unsigned int starting_indice, unsigned int ending_indice) {

  int largest = 0;

  if (starting_indice > ARR_SIZE || ending_indice > ARR_SIZE) {
    printf("Indice out of bounds, On Line: %i in file: %si\n", __LINE__, __FILE__);
    exit(EXIT_FAILURE);
  }


  for (long unsigned int j = starting_indice; j < ending_indice; j++) {

    if (arr[j] > largest) {

      largest = arr[j];

    }

  }

  return largest;

}

void child_search(int * arr, const size_t ARR_SIZE, int * piperw) {

    int largest = find_largest(arr, ARR_SIZE, ARR_SIZE / 2, ARR_SIZE);
    printf("Child Largest: %i\n", largest);

    close(piperw[0]);
    
    int tries = 0;
    while (write(piperw[1], &largest, sizeof(int)) != sizeof(int) && errno == 0 && tries < 10) 
      tries++;

    close(piperw[1]);
 
    if (tries > 10) {
      
      printf("Failed to write\n");
    
    }

    return; 

}

int parent_search(int * arr, const size_t ARR_SIZE, int * piperw, int buffer) {

    int largest = find_largest(arr, ARR_SIZE, 0, (ARR_SIZE / 2) - 1);
    printf("\nParent Largest: %i\n", largest);

    close(piperw[1]);

    int tries = 0;
    while(read(piperw[0], &buffer, sizeof(int)) != sizeof(int) && errno == 0 && tries < 10)
      tries++;

    close(piperw[0]);

    if (tries > 10) {
      printf("Failed to read\n");
    }

    if (buffer > largest) {
      return buffer;
    } else {
      return largest;
    }

}

int main() {

  srand(time(NULL));

  const size_t ARR_SIZE = 100;
  const int MAX_NUM = 1000;
  int arr[ARR_SIZE];

  generate_array(ARR_SIZE, MAX_NUM, arr);
  printf("\n");

  int piperw[2];
  pid_t my_pid;
  int buffer = 0;

  pipe(piperw);
  my_pid = fork();

  if (my_pid == 0) { //Child program
    
    child_search(arr, ARR_SIZE, piperw);

  } else { //Parent program

    int largest = parent_search(arr, ARR_SIZE, piperw, buffer);

    printf("\nLargest Number is: %i\n", largest);

  }

  return 0;

}
