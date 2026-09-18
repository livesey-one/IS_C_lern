#include <stdio.h>
#include <string.h>
struct Car {
  int speed;
  char name[50];
  float weight;
};

int main() {
  struct Car lada;
  lada.speed = 60;
  lada.weight = 1500.0f;
  strcpy(lada.name, "Lada");
  struct Car audi = {300, "Audi", 2000.0f};
  printf("%s %d %.2f\n", lada.name, lada.speed, lada.weight);
  printf("%s %d %.2f\n", audi.name, audi.speed, audi.weight);
  return 0;
}
