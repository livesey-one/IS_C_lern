#include <stdio.h>

int main() {

  // int b;
  // scanf("%d", &b);
  // for (short a = 0; a < b; a++) {
  //   printf("%d\n", a)
  // }
  // int a = 1;
  // while (a > 0) {
  //   scanf("%d", &a);
  // };

  int chet = 0;
  int nechet = 0;

  for (short i = 0; i < 21; i++) {
    if (i % 2 == 0) {
      chet++;
    } else {
      nechet++;
    }
  }
  printf(" %d, %d\n", chet, nechet);

  return 0;
}
