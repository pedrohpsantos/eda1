#include <stdio.h>

float MediaDig(int Numero, unsigned int Tamanho, float Soma) {
  if (Numero == 0) {
    if (Tamanho == 0)
      return 0;
    return Soma / Tamanho;
  }
  return MediaDig(Numero / 10, Tamanho + 1, Soma + (Numero % 10));
}

int main() {
  printf("Media dos digitos: %.2f\n", MediaDig(1234, 0, 0));
  printf("Media dos digitos: %.2f\n", MediaDig(12345, 0, 0));
  printf("Media dos digitos: %.2f\n", MediaDig(0, 0, 0));
  return 0;
}
