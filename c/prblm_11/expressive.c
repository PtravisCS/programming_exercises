#include <stdio.h>
#include <math.h>

double kth_term(double k) {

  double val = pow(-1.00, k+1.00) / (2*k-1);

  return val;

}

int main() {

  double sum = 0;
  const int END_TERM = 1000000;

  for (int i = 1; i < END_TERM; i++) {
    
    sum += kth_term(i);

  }

  double product = sum * 4;

  printf("The sum of the series multiplied by 4 is: %f\n", product);

  return 0;

}
