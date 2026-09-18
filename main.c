#include <stdbool.h>
#include <stdio.h>

int main() {

  // // int b;
  // // scanf("%d", &b);
  // // for (short a = 0; a < b; a++) {
  // //   printf("%d\n", a)
  // // }
  // // int a = 1;
  // // while (a > 0) {
  // //   scanf("%d", &a);
  // // };
  // int arr[5] = {1, 2, 3, 4, 5};
  // int arr1[] = {1, 2, 3, 4, 5}; // любая размерность но ТИП
  // printf("%d\n", arr[2]);       // answer 3

  // float arr3[3];
  // arr3[0] = 1.4f;
  // arr3[1] = 1.2f;
  // arr3[2] = 1.3f;
  // printf("%f\n", arr3[2]);

  // int chet = 0;
  // int nechet = 0;

  // for (short i = 0; i < 21; i++) {
  //   if (i % 2 == 0) {
  //     chet++;
  //   } else {
  //     nechet++;
  //   }
  // }
  // printf(" %d, %d\n", chet, nechet);

  // int x1 = 14;
  // switch (x1) {
  // case 10:
  //   printf("10");
  //   break;
  // case 14:
  //   printf("14");
  //   break;
  // }

  // bool pisya = false;
  // do {
  //   printf("yes\n");
  //   pisya = true;
  // } while (pisya);

  // for (int x = 0; x < 5; x++)
  //   if (x == 3) {
  //       break;

  //   if (x % 2 == 0) {
  //       continue;
  //   }
  // }
  int arr[] = {1, 2, 3, -4, -5};
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]); // удобно out: 1, 2, 3, -4, -5
  }
  // поиск минимального
  int min = arr[0];
  int max = arr[0];
  for (int i = 0; i < 5; i++) {
    if (arr[i] < min)
      min = arr[i];
    if (arr[i] > max)
      max = arr[i];
  }
  printf("%d\n", min);
  return 0;
}
