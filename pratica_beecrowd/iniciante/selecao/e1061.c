#include <stdio.h>

int main() {
  int dia_i, h_i, m_i, s_i;
  int dia_f, h_f, m_f, s_f;

  scanf("Dia %d", &dia_i);
  scanf("%d : %d : %d", &h_i, &m_i, &s_i);

  scanf("Dia %d", &dia_f);
  scanf("%d : %d : %d", &h_f, &m_f, &s_f);

  long long inicio_em_segundos = s_i + m_i * 60 + h_i * 3600 + dia_i * 86400;
  long long fim_em_segundos = s_f + m_f * 60 + h_f * 3600 + dia_f * 86400;

  long long duracao = fim_em_segundos - inicio_em_segundos;

  int dias = duracao / 86400;
  duracao %= 86400;
  int horas = duracao / 3600;
  duracao %= 3600;
  int minutos = duracao / 60;
  int segundos = duracao % 60;

  printf("%d dia(s)\n", dias);
  printf("%d hora(s)\n", horas);
  printf("%d minuto(s)\n", minutos);
  printf("%d segundo(s)\n", segundos);

  return 0;
}
