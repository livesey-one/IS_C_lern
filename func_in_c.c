#include "func.h" // полключили функции и stdio.h

// void info(void);//прототип
void sum(int a, int b);
float mult(float a, float b);

int main() {
  info();
  sum(20, 50);
  float res = mult(2.5, 3.5);
  printf("Result: %f\n", res);

  return 0;
}

// читает сверху вниз

void sum(int a, int b) {
  int result = a + b;
  printf("Sum: %d\n", result);
}

float mult(float a, float b) {
  float result = a * b;
  printf("Mult: %f\n", result);
  return result;
}
