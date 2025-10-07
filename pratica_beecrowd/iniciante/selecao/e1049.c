#include <stdio.h>
#include <string.h>

int main() {

  char genero[20], familia[20], ordem[20];
  scanf("%19s", ordem);
  scanf("%19s", familia);
  scanf("%19s", genero);
  if (strcmp(ordem, "vertebrado") == 0) {
    if (strcmp(familia, "ave") == 0) {
      if (strcmp(genero, "carnivoro") == 0) {
        printf("aguia\n");
      } else {
        printf("pomba\n");
      }
    } else {
      if (strcmp(genero, "onivoro") == 0) {
        printf("homem\n");
      } else {
        printf("vaca\n");
      }
    }
  } else {
    if (strcmp(familia, "inseto") == 0) {
      if (strcmp(genero, "hematofago") == 0) {
        printf("pulga\n");
      } else {
        printf("lagarta\n");
      }
    } else {
      if (strcmp(genero, "hematofago") == 0) {
        printf("sanguessuga\n");
      } else {
        printf("minhoca\n");
      }
    }
  }

  return 0;
}
